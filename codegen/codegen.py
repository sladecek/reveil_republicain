# Python script that generates font and string tables.

import os
from PIL import Image, ImageDraw, ImageFont

# Font configuration
FONT_PATH = "/usr/share/fonts/truetype/noto/NotoSansDisplay-CondensedMedium.ttf"
INTERCHAR_SPACE = 1  # Inter-character spacing in pixels

# Custom bitmap for bell emoji (simple bell shape)
BELL_BITMAP_BIG = [
    "      ###       ",
    "     #####      ",
    "    #######     ",
    "   #########    ",
    "  ###########   ",
    "  ###########   ",
    " ############# ",
    " ############# ",
    " ############# ",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    "###############",
    " ############# ",
    " ############# ",
    "  ###########  ",
    "               ",
    "               ",
    "      ###      ",
    "      ###      ",
]

BELL_BITMAP_NORMAL = [
    "   ###   ",
    "  #####  ",
    " ####### ",
    " ####### ",
    "#########",
    "#########",
    "#########",
    "#########",
    "#########",
    "#########",
    "#########",
    "#########",
    "#########",
    "#########",
    " ####### ",
    "         ",
    "   ###   ",
    "   ###   ",
]

class CharTable:
    def __init__(self):
        self.chars = set()  # Set of all characters
 
    def add_char(self, char: str):
        # Add a single character to the char table
        self.chars.add(char)

    def build_mapping(self):
        # Build a mapping from character to index
        # Custom sort: digits '0'-'9' and ':' first, then the rest sorted
        def sort_key(c):
            if c in "0123456789:":
                return (0, "0123456789:".index(c))
            return (1, ord(c))
        self.sorted_chars = sorted(self.chars, key=sort_key)
        
        self.char_to_index = {char: idx for idx, char in enumerate(self.sorted_chars)} 

    def map_char(self, char: str) -> int:
        # Map a character to its index in the char table
        return self.char_to_index[char]
    
    def map_string(self, string: str) -> list[int]:
        # Map a string to a list of character indices
        return [self.map_char(char) for char in string]
    
    def write_declarations(self, file):
        """Write C++ declarations for the character table"""
        pass

class FontTable:
    def __init__(self, char_table: CharTable, name: str, size: int, font_char_count: int | None = None, 
                 scale_factor: float = 1.0, vertical_shift: float = 0.0, horizontal_padding: float = 0.0):
        self.char_table = char_table
        self.name = name
        self.size = size  # Font size in points
        # If font_char_count is specified, use first N characters, otherwise use all
        self.font_char_count = font_char_count if font_char_count is not None else len(char_table.chars)
        self.glyphs = {}  # Dictionary mapping character to glyph bitmap data
        self.height = None  # Actual pixel height, determined during rendering
        
        # Big font adjustments
        self.scale_factor = scale_factor  # Scale the font (e.g., 1.1 for 10% bigger)
        self.vertical_shift = vertical_shift  # Move font up (negative) or down (positive) as fraction of height
        self.horizontal_padding = horizontal_padding  # Add padding on left/right as fraction of width
        
        # Create PIL font object
        try:
            self.font = ImageFont.truetype(FONT_PATH, self.size)
        except Exception:
            # Fallback to default font if specified font is not found
            print(f"Warning: Font '{FONT_PATH}' not found, using default")
            self.font = ImageFont.load_default()
    
    def is_bell_emoji(self, char: str) -> bool:
        """Check if a character is the bell emoji"""
        return char == '🔔'
    
    def get_bell_bitmap(self) -> list[str]:
        """Get the appropriate bell bitmap for this font size"""
        # Use big bitmap for font size >= 30, otherwise normal
        return BELL_BITMAP_BIG if self.size >= 30 else BELL_BITMAP_NORMAL
        
    def render_font(self):
        """Render all characters in the font using PIL"""
        
        # First pass: determine the maximum height and vertical offsets
        max_height = 0
        min_y_offset = 0
        max_y_bottom = 0
        
        for i, char in enumerate(self.char_table.sorted_chars):
            if i >= self.font_char_count:
                break
            
            if self.is_bell_emoji(char):
                # Use custom bitmap height for bell
                bell_bitmap = self.get_bell_bitmap()
                char_height = len(bell_bitmap)
                max_height = max(max_height, char_height)
            else:
                # Measure the character bounding box
                temp_img = Image.new('1', (100, 100), 0)
                temp_draw = ImageDraw.Draw(temp_img)
                bbox = temp_draw.textbbox((0, 0), char, font=self.font)
                # bbox is (left, top, right, bottom)
                min_y_offset = min(min_y_offset, bbox[1])
                max_y_bottom = max(max_y_bottom, bbox[3])
        
        # Calculate the actual height needed to fit all characters
        self.height = max_y_bottom - min_y_offset
        self.y_offset = -min_y_offset  # Offset to apply when rendering
        
        # Second pass: render each character
        for i, char in enumerate(self.char_table.sorted_chars):
            if i >= self.font_char_count:
                break
            
            if self.is_bell_emoji(char):
                # Use custom bell bitmap
                bell_bitmap = self.get_bell_bitmap()
                bell_height = len(bell_bitmap)
                bell_width = len(bell_bitmap[0]) if bell_bitmap else 0
                
                # Convert ASCII art to pixel data
                pixels = []
                ascii_art = []
                for row in bell_bitmap:
                    ascii_art.append(row)
                    for char_pixel in row:
                        pixels.append(1 if char_pixel == '#' else 0)
                
                # Pad to match font height if needed
                while len(pixels) < bell_width * self.height:
                    pixels.append(0)
                    if len(pixels) % bell_width == 0:
                        ascii_art.append(' ' * bell_width)
                
                self.glyphs[char] = {
                    'width': bell_width + INTERCHAR_SPACE,
                    'height': self.height,
                    'data': pixels,
                    'ascii_art': ascii_art
                }
                continue
            
            # Regular font rendering
            # Create image with enough height including offset
            render_height = 100  # Use a larger canvas for rendering
            temp_img = Image.new('1', (100, render_height), 0)
            temp_draw = ImageDraw.Draw(temp_img)
            
            # Draw the character with vertical offset
            temp_draw.text((0, self.y_offset), char, fill=1, font=self.font)
            
            # Apply scaling if needed
            if self.scale_factor != 1.0:
                new_width = int(temp_img.width * self.scale_factor)
                new_height = int(temp_img.height * self.scale_factor)
                temp_img = temp_img.resize((new_width, new_height), Image.Resampling.BILINEAR)
            
            # Find the bounding box of the actual character
            bbox = temp_img.getbbox()
            if bbox is None:
                # Empty character (space, etc.)
                char_width = int(self.size // 4)  # Use quarter of font size as default
                # Add horizontal padding
                padding_pixels = int(char_width * self.horizontal_padding)
                total_width = char_width + 2 * padding_pixels
                self.glyphs[char] = {
                    'width': total_width + INTERCHAR_SPACE,
                    'height': int(self.height),
                    'data': [0] * (total_width * int(self.height)),
                    'ascii_art': []
                }
            else:
                # Crop to actual character width, and use our calculated height
                char_width = bbox[2] - bbox[0]
                
                # Calculate vertical shift in pixels
                shift_pixels = int(int(self.height) * self.vertical_shift)
                # Remove 3 pixels of padding from the top to prevent bottom truncation
                crop_y_start = max(0, int(self.y_offset) + shift_pixels + 3)
                crop_y_end = crop_y_start + int(self.height)
                
                # Crop starting from y_offset (adjusted by shift) to y_offset + height
                char_img = temp_img.crop((bbox[0], crop_y_start, bbox[0] + char_width, crop_y_end))
                
                # Extract pixel data
                pixels = list(char_img.getdata())
                
                # Calculate horizontal padding
                padding_pixels = int(char_width * self.horizontal_padding)
                
                # Add horizontal padding and inter-character spacing pixels
                pixels_with_spacing = []
                for y in range(int(self.height)):
                    # Add left padding
                    for _ in range(padding_pixels):
                        pixels_with_spacing.append(0)
                    # Copy the pixels for this line
                    for x in range(char_width):
                        pixels_with_spacing.append(pixels[y * char_width + x])
                    # Add right padding
                    for _ in range(padding_pixels):
                        pixels_with_spacing.append(0)
                    # Add INTERCHAR_SPACE zero pixels at the end of each line
                    for _ in range(INTERCHAR_SPACE):
                        pixels_with_spacing.append(0)
                
                total_width = char_width + 2 * padding_pixels
                
                # Create ASCII art representation (including spacing)
                ascii_art = []
                for y in range(int(self.height)):
                    row = ""
                    for x in range(total_width + INTERCHAR_SPACE):
                        pixel = pixels_with_spacing[y * (total_width + INTERCHAR_SPACE) + x]
                        row += "#" if pixel else " "
                    ascii_art.append(row)
                
                self.glyphs[char] = {
                    'width': total_width + INTERCHAR_SPACE,
                    'height': int(self.height),
                    'data': pixels_with_spacing,
                    'ascii_art': ascii_art
                }


    def write_declarations(self, file):
        """Write C++ declarations for the font"""
        file.write(f"// Font: {self.name} (size {self.size}pt, height {self.height}px)\n")
        file.write(f"constexpr int {self.name}_font_len = {self.font_char_count};\n")
        file.write(f"constexpr int {self.name}_font_height = {self.height};\n")
        file.write(f"extern const std::array<uint8_t, {self.name}_font_len> {self.name}_font_char_widths;\n")
        file.write(f"extern const std::array<uint16_t, {self.name}_font_len> {self.name}_font_char_begin;\n")
        
        # Calculate total content size (line-by-line packing)
        total_size = 0
        for glyph in self.glyphs.values():
            char_line_bytes = (glyph['width'] + 7) // 8
            total_size += char_line_bytes * glyph['height']
        file.write(f"extern const std::array<uint8_t, {total_size}> {self.name}_font_content;\n\n")

    def write_content(self, file):
        """Write C++ implementation for the font"""
        sorted_chars = self.char_table.sorted_chars[:self.font_char_count]
        
        # Write character widths
        file.write(f"// {self.name} font character widths\n")
        file.write(f"const std::array<uint8_t, {self.name}_font_len> {self.name}_font_char_widths = {{\n")
        for i, char in enumerate(sorted_chars):
            width = self.glyphs.get(char, {'width': 7})['width']
            # Escape the character for display
            char_display = char if char.isprintable() and char not in ['"', '\\'] else f"U+{ord(char):04X}"
            bell_note = " (custom bell bitmap)" if self.is_bell_emoji(char) else ""
            file.write(f"    {width}, // '{char_display}'{bell_note}\n")
        file.write("};\n\n")
        
        # Write character begin positions
        file.write(f"// {self.name} font character begin positions\n")
        file.write(f"const std::array<uint16_t, {self.name}_font_len> {self.name}_font_char_begin = {{\n")
        current_pos = 0
        for i, char in enumerate(sorted_chars):
            glyph = self.glyphs.get(char, {'width': 7, 'height': self.height})
            char_display = char if char.isprintable() and char not in ['"', '\\'] else f"U+{ord(char):04X}"
            bell_note = " (custom bell bitmap)" if self.is_bell_emoji(char) else ""
            file.write(f"    {current_pos}, // '{char_display}'{bell_note}\n")
            # Calculate bytes needed for this glyph (line-by-line packing)
            char_line_bytes = (glyph['width'] + 7) // 8
            bytes_needed = char_line_bytes * glyph['height']
            current_pos += bytes_needed
        file.write("};\n\n")
        
        # Write font content (packed bits)
        total_size = current_pos
        file.write(f"// {self.name} font content (bitmap data, packed)\n")
        file.write(f"const std::array<uint8_t, {total_size}> {self.name}_font_content = {{\n")
        
        # Write bitmap data per character with ASCII art comments
        byte_pos = 0
        for i, char in enumerate(sorted_chars):
            glyph = self.glyphs.get(char, {'width': 7, 'height': self.height, 'data': [], 'ascii_art': []})
            char_line_bytes = (glyph['width'] + 7) // 8
            bytes_needed = char_line_bytes * glyph['height']
            
            char_display = char if char.isprintable() and char not in ['"', '\\'] else f"U+{ord(char):04X}"
            bell_note = " (custom bell bitmap)" if self.is_bell_emoji(char) else ""
            
            # Blank line before each character (except first)
            if i > 0:
                file.write("\n")
            
            # Write ASCII art as comments
            file.write(f"    // '{char_display}'{bell_note}\n")
            for art_line in glyph['ascii_art']:
                file.write(f"    // {art_line}\n")
            
            # Pack bits into bytes (MSB first, line-by-line)
            byte_data = []
            char_width_with_space = glyph['width']
            char_line_bytes = (char_width_with_space + 7) // 8
            
            # Pack each line separately
            for line_y in range(glyph['height']):
                line_start = line_y * char_width_with_space
                line_end = line_start + char_width_with_space
                line_pixels = glyph['data'][line_start:line_end]
                
                # Pack this line's pixels into bytes
                current_byte = 0
                bit_count = 0
                
                for pixel in line_pixels:
                    # Shift byte left to make room for next bit
                    current_byte <<= 1
                    # Set LSB if pixel is set
                    if pixel:
                        current_byte |= 1
                    bit_count += 1
                    
                    if bit_count == 8:
                        byte_data.append(current_byte)
                        current_byte = 0
                        bit_count = 0
                
                # Write remaining bits if any (pad to byte boundary)
                if bit_count > 0:
                    # Shift remaining bits to MSB position
                    current_byte <<= (8 - bit_count)
                    byte_data.append(current_byte)
            
            # Ensure we have the right number of bytes
            while len(byte_data) < bytes_needed:
                byte_data.append(0)
            
            # Write bytes
            for j, byte_val in enumerate(byte_data):
                file.write(f"    0x{byte_val:02X}")
                if byte_pos + j < total_size - 1:
                    file.write(",")
                file.write("\n")
            
            byte_pos += bytes_needed
        
        file.write("};\n\n")


class FragmentTable:
    def __init__(self):
        self.strings = []  # List of all strings
        self.labels = dict()  # Map from label to the index of the first string with that label

    def add_string_list(self, key, string_list: list[str]):
        # Add a list of strings to the fragment table
        self.labels[key] = len(self.strings)
        self.strings.extend(string_list)

    def add_string(self, key: str, value=None):
        # Add a single string to the fragment table
        if value is None:
            value = key
        self.labels[key] = len(self.strings)
        self.strings.append(value)

    def build_char_table(self) -> CharTable:
        char_table = CharTable()
        # Add all characters from all strings to the char table
        for string in self.strings:
            for char in string:
                char_table.add_char(char)
        char_table.build_mapping()
        return char_table
    
    def write_declarations(self, file):
        """Write C++ declarations for the fragment table"""
        file.write("// Fragment table declarations\n")
        file.write(f"constexpr int fragment_count = {len(self.strings)};\n")
        
        # Calculate total content size (all characters from all strings)
        total_chars = sum(len(s) for s in self.strings)
        file.write(f"constexpr int fragment_content_size = {total_chars};\n")
        
        file.write("extern const std::array<uint8_t, fragment_content_size> fragment_content;\n")
        file.write("extern const std::array<uint16_t, fragment_count> fragment_begin;\n")
        file.write("extern const std::array<uint16_t, fragment_count> fragment_len;\n\n")
        
    def write_content(self, file, char_table: CharTable):
        """Write C++ implementation for the fragment table"""
        # Write fragment_content with comments for each fragment
        file.write("// Fragment content (character indices)\n")
        file.write("const std::array<uint8_t, fragment_content_size> fragment_content = {\n")
        
        char_pos = 0
        for frag_idx, string in enumerate(self.strings):
            # Add blank line before each fragment (except first)
            if frag_idx > 0:
                file.write("\n")
            
            # Find fragment name for this index
            frag_name = None
            for key, idx in self.labels.items():
                if idx == frag_idx:
                    frag_name = key
                    break
            
            # Write comment with fragment name and content
            if frag_name:
                # Truncate long strings for display
                display_string = string if len(string) <= 40 else string[:37] + "..."
                file.write(f"    // {frag_name}: \"{display_string}\"\n")
            else:
                display_string = string if len(string) <= 40 else string[:37] + "..."
                file.write(f"    // \"{display_string}\"\n")
            
            # Write character indices for this fragment
            file.write("    ")
            indices = []
            for char in string:
                char_idx = char_table.map_char(char)
                indices.append(str(char_idx))
            file.write(", ".join(indices))
            
            # Add comma if not last fragment
            if frag_idx < len(self.strings) - 1:
                file.write(",")
            file.write("\n")
            
            char_pos += len(string)
        
        file.write("};\n\n")
        
        # Write fragment_begin with comments
        file.write("// Fragment begin positions\n")
        file.write("const std::array<uint16_t, fragment_count> fragment_begin = {\n")
        current_pos = 0
        for frag_idx, string in enumerate(self.strings):
            # Find fragment name
            frag_name = None
            for key, idx in self.labels.items():
                if idx == frag_idx:
                    frag_name = key
                    break
            
            display_string = string if len(string) <= 30 else string[:27] + "..."
            if frag_name:
                file.write(f"    {current_pos}, // {frag_name}: \"{display_string}\"\n")
            else:
                file.write(f"    {current_pos}, // \"{display_string}\"\n")
            
            current_pos += len(string)
        file.write("};\n\n")
        
        # Write fragment_len with comments
        file.write("// Fragment lengths\n")
        file.write("const std::array<uint16_t, fragment_count> fragment_len = {\n")
        for frag_idx, string in enumerate(self.strings):
            # Find fragment name
            frag_name = None
            for key, idx in self.labels.items():
                if idx == frag_idx:
                    frag_name = key
                    break
            
            display_string = string if len(string) <= 30 else string[:27] + "..."
            if frag_name:
                file.write(f"    {len(string)}, // {frag_name}: \"{display_string}\"\n")
            else:
                file.write(f"    {len(string)}, // \"{display_string}\"\n")
        file.write("};\n\n")
    
    def write_index_labels(self, file):
        """Write C++ enum for fragment labels"""
        file.write("// Fragment label indices\n")
        file.write("enum class fragment_index : uint16_t {\n")
        for key, index in sorted(self.labels.items(), key=lambda x: x[1]):
            # Convert key to valid C++ identifier
            cpp_key = key.lower().replace(" ", "_")
            file.write(f"    {cpp_key} = {index},\n")
        file.write("};\n\n")

def main():
    fragments = FragmentTable()

    fragments.add_string_list("nr", ["0","1","2","3","4","5","6","7","8","9"])
    fragments.add_string("colon", ":")
    fragments.add_string("space", " ")
    fragments.add_string("bell", "🔔")
    fragments.add_string("run")
    fragments.add_string("stop")
    fragments.add_string("alarm")
    fragments.add_string("hour")
    fragments.add_string("minute")
    fragments.add_string("set")
    fragments.add_string("day")
    fragments.add_string("month")
    fragments.add_string("year")
    fragments.add_string("annee", "Année ")
    fragments.add_string("decade", " Décade ")
    fragments.add_string("jourdu", "Jour ")
    fragments.add_string("jourepagomene", "Jour épagomène")
    fragments.add_string_list("on_off", ["on", "off"])
    fragments.add_string_list(
        "months",
        [
            "Vendémiaire",
            "Brumaire",
            "Frimaire",
            "Nivôse",
            "Pluviôse",
            "Ventôse",
            "Germinal",
            "Floréal",
            "Prairial",
            "Messidor",
            "Thermidor",
            "Fructidor",
        ],
    )
    fragments.add_string_list(
        "days",
        [
            "Primidi",
            "Duodi",
            "Tridi",
            "Quartidi",
            "Quintidi",
            "Sextidi",
            "Septidi",
            "Octidi",
            "Nonidi",
            "Décadi",
        ],
    )
    fragments.add_string_list(
        "sansculottides",
        [
            "Fête de la Vertu",
            "Fête du Génie",
            "Fête du Travail",
            "Fête de l'Opinion",
            "Fête des Récompenses",
            "Fête de la Révolution",
        ],
    )

    # 360 days of the year with proper French articles: "de la/du/de l'" + day name
    year_days = [
        "du raisin",        # (Vendémiaire, 1)
        "du safran",        # (Vendémiaire, 2)
        "de la châtaigne",     # (Vendémiaire, 3)
        "du colchique",     # (Vendémiaire, 4)
        "du cheval",        # (Vendémiaire, 5)
        "de la balsamine",     # (Vendémiaire, 6)
        "de la carotte",       # (Vendémiaire, 7)
        "de l'amarante",      # (Vendémiaire, 8)
        "du panais",        # (Vendémiaire, 9)
        "de la cuve",          # (Vendémiaire, 10)
        "de la pomme de terre",# (Vendémiaire, 11)
        "de l'immortelle",    # (Vendémiaire, 12)
        "du potiron",       # (Vendémiaire, 13)
        "du réséda",        # (Vendémiaire, 14)
        "de l'âne",           # (Vendémiaire, 15)
        "de la belle de nuit", # (Vendémiaire, 16)
        "de la citrouille",    # (Vendémiaire, 17)
        "du sarrasin",      # (Vendémiaire, 18)
        "du tournesol",     # (Vendémiaire, 19)
        "du pressoir",      # (Vendémiaire, 20)
        "du chanvre",       # (Vendémiaire, 21)
        "de la pêche",         # (Vendémiaire, 22)
        "du navet",         # (Vendémiaire, 23)
        "de l'amaryllis",     # (Vendémiaire, 24)
        "du bœuf",          # (Vendémiaire, 25)
        "de l'aubergine",     # (Vendémiaire, 26)
        "du piment",        # (Vendémiaire, 27)
        "de la tomate",        # (Vendémiaire, 28)
        "de l'orge",          # (Vendémiaire, 29)
        "du tonneau",       # (Vendémiaire, 30)

        "de la pomme",         # (Brumaire, 1)
        "du céleri",        # (Brumaire, 2)
        "de la poire",         # (Brumaire, 3)
        "de la betterave",     # (Brumaire, 4)
        "de l'oie",           # (Brumaire, 5)
        "de l'héliotrope",    # (Brumaire, 6)
        "de la figue",         # (Brumaire, 7)
        "de la scorsonère",    # (Brumaire, 8)
        "de l'alisier",       # (Brumaire, 9)
        "de la charrue",       # (Brumaire, 10)
        "du salsifis",      # (Brumaire, 11)
        "de la macre",         # (Brumaire, 12)
        "du topinambour",   # (Brumaire, 13)
        "de l'endive",        # (Brumaire, 14)
        "du dindon",        # (Brumaire, 15)
        "du chervis",       # (Brumaire, 16)
        "du cresson",       # (Brumaire, 17)
        "de la dentelaire",    # (Brumaire, 18)
        "de la grenade",       # (Brumaire, 19)
        "de la herse",         # (Brumaire, 20)
        "de la bacchante",     # (Brumaire, 21)
        "de l'azerole",       # (Brumaire, 22)
        "de la garance",       # (Brumaire, 23)
        "de l'orange",        # (Brumaire, 24)
        "du faisan",        # (Brumaire, 25)
        "de la pistache",      # (Brumaire, 26)
        "du macjonc",       # (Brumaire, 27)
        "du coing",         # (Brumaire, 28)
        "du cormier",       # (Brumaire, 29)
        "du rouleau",       # (Brumaire, 30)

        "de la raiponce",      # (Frimaire, 1)
        "du turneps",       # (Frimaire, 2)
        "de la chicorée",      # (Frimaire, 3)
        "de la nèfle",         # (Frimaire, 4)
        "du cochon",        # (Frimaire, 5)
        "de la mâche",         # (Frimaire, 6)
        "du chou-fleur",    # (Frimaire, 7)
        "du miel",          # (Frimaire, 8)
        "du génépi",        # (Frimaire, 9)
        "de la pioche",        # (Frimaire, 10)
        "de la cire",          # (Frimaire, 11)
        "du raifort",       # (Frimaire, 12)
        "du cèdre",         # (Frimaire, 13)
        "du sapin",         # (Frimaire, 14)
        "du chevreuil",     # (Frimaire, 15)
        "de l'ajonc",         # (Frimaire, 16)
        "du cyprès",        # (Frimaire, 17)
        "du lierre",        # (Frimaire, 18)
        "de la sabine",        # (Frimaire, 19)
        "de la hoye",          # (Frimaire, 20)
        "de l'érable sucré",  # (Frimaire, 21)
        "de la bruyère",       # (Frimaire, 22)
        "du roseau",        # (Frimaire, 23)
        "de l'oseille",       # (Frimaire, 24)
        "du grillon",       # (Frimaire, 25)
        "du pignon",        # (Frimaire, 26)
        "du liège",         # (Frimaire, 27)
        "de la truffe",        # (Frimaire, 28)
        "de l'olive",         # (Frimaire, 29)
        "de la pelle",         # (Frimaire, 30)

        "de la tourbe",        # (Nivôse, 1)
        "de la houille",       # (Nivôse, 2)
        "du bitume",        # (Nivôse, 3)
        "du soufre",        # (Nivôse, 4)
        "du chien",         # (Nivôse, 5)
        "de la lave",          # (Nivôse, 6)
        "de la terre végétale",# (Nivôse, 7)
        "du fumier",        # (Nivôse, 8)
        "du salpêtre",      # (Nivôse, 9)
        "du fléau",         # (Nivôse, 10)
        "du granite",       # (Nivôse, 11)
        "de l'argile",        # (Nivôse, 12)
        "de l'ardoise",       # (Nivôse, 13)
        "du grès",          # (Nivôse, 14)
        "du lapin",         # (Nivôse, 15)
        "du silex",         # (Nivôse, 16)
        "de la marne",         # (Nivôse, 17)
        "de la pierre à chaux",# (Nivôse, 18)
        "du marbre",        # (Nivôse, 19)
        "du van",           # (Nivôse, 20)
        "de la pierre à plâtre",# (Nivôse, 21)
        "du sel",           # (Nivôse, 22)
        "du fer",           # (Nivôse, 23)
        "du cuivre",        # (Nivôse, 24)
        "du chat",          # (Nivôse, 25)
        "de l'étain",         # (Nivôse, 26)
        "du plomb",         # (Nivôse, 27)
        "du zinc",          # (Nivôse, 28)
        "du mercure",       # (Nivôse, 29)
        "du crible",        # (Nivôse, 30)

        "de la lauréole",      # (Pluviôse, 1)
        "de la mousse",        # (Pluviôse, 2)
        "du fragon",        # (Pluviôse, 3)
        "de la pervenche",     # (Pluviôse, 4)
        "du taureau",       # (Pluviôse, 5)
        "du laurier-tin",   # (Pluviôse, 6)
        "de l'amatyste",      # (Pluviôse, 7)
        "du mézéréon",      # (Pluviôse, 8)
        "du peuplier",      # (Pluviôse, 9)
        "de la coignée",       # (Pluviôse, 10)
        "de l'ellébore",      # (Pluviôse, 11)
        "du brocoli",       # (Pluviôse, 12)
        "du laurier",       # (Pluviôse, 13)
        "de l'avelinier",     # (Pluviôse, 14)
        "de la vache",         # (Pluviôse, 15)
        "du buis",          # (Pluviôse, 16)
        "du lichén",        # (Pluviôse, 17)
        "de l'if",            # (Pluviôse, 18)
        "de la pulmonaire",    # (Pluviôse, 19)
        "de la serpette",      # (Pluviôse, 20)
        "du thlaspi",       # (Pluviôse, 21)
        "du thimelé",       # (Pluviôse, 22)
        "du chiendent",     # (Pluviôse, 23)
        "de la traînasse",     # (Pluviôse, 24)
        "du lièvre",        # (Pluviôse, 25)
        "de la guède",         # (Pluviôse, 26)
        "du noisetier",     # (Pluviôse, 27)
        "du cyclamen",      # (Pluviôse, 28)
        "de la chélidoine",    # (Pluviôse, 29)
        "du traîneau",      # (Pluviôse, 30)

        "du tussilage",     # (Ventôse, 1)
        "du cornouiller",   # (Ventôse, 2)
        "du violier",       # (Ventôse, 3)
        "du troène",        # (Ventôse, 4)
        "du bouc",          # (Ventôse, 5)
        "de l'asaret",        # (Ventôse, 6)
        "de l'alaterne",      # (Ventôse, 7)
        "de la violette",      # (Ventôse, 8)
        "du marceau",       # (Ventôse, 9)
        "de la bêche",         # (Ventôse, 10)
        "du narcisse",      # (Ventôse, 11)
        "de l'orme",          # (Ventôse, 12)
        "de la fumeterre",     # (Ventôse, 13)
        "du vélar",         # (Ventôse, 14)
        "de la chèvre",        # (Ventôse, 15)
        "de l'épinard",       # (Ventôse, 16)
        "du doronic",       # (Ventôse, 17)
        "du mouron",        # (Ventôse, 18)
        "du cerfeuil",      # (Ventôse, 19)
        "du cordeau",       # (Ventôse, 20)
        "de la mandragore",    # (Ventôse, 21)
        "du persil",        # (Ventôse, 22)
        "du cochléaria",    # (Ventôse, 23)
        "de la pâquerette",    # (Ventôse, 24)
        "du thon",          # (Ventôse, 25)
        "du pissenlit",     # (Ventôse, 26)
        "de la sylvie",        # (Ventôse, 27)
        "du capillaire",    # (Ventôse, 28)
        "du frêne",         # (Ventôse, 29)
        "du plantoir",      # (Ventôse, 30)

        "de la primevère",     # (Germinal, 1)
        "du platane",       # (Germinal, 2)
        "de l'asperge",       # (Germinal, 3)
        "de la tulipe",        # (Germinal, 4)
        "de la poule",         # (Germinal, 5)
        "de la bette",         # (Germinal, 6)
        "du bouleau",       # (Germinal, 7)
        "de la jonquille",     # (Germinal, 8)
        "de l'aulne",         # (Germinal, 9)
        "du couvoir",       # (Germinal, 10)
        "du perce-neige",   # (Germinal, 11)
        "du crocus",        # (Germinal, 12)
        "du hêtre",         # (Germinal, 13)
        "de la laitue",        # (Germinal, 14)
        "du torillon",      # (Germinal, 15)
        "du lilas",         # (Germinal, 16)
        "de l'anémone",       # (Germinal, 17)
        "de la pensée",        # (Germinal, 18)
        "de la myrtille",      # (Germinal, 19)
        "du greffoir",      # (Germinal, 20)
        "du cerisier",      # (Germinal, 21)
        "de la verveine",      # (Germinal, 22)
        "du grenadier",     # (Germinal, 23)
        "du vernal",        # (Germinal, 24)
        "du cheval",        # (Germinal, 25)
        "de la brenèche",      # (Germinal, 26)
        "du charme",        # (Germinal, 27)
        "de la morille",       # (Germinal, 28)
        "du hêtre enraciné",# (Germinal, 29)
        "de la ruche",         # (Germinal, 30)

        "de la rose",          # (Floréal, 1)
        "du chêne",         # (Floréal, 2)
        "de la fougère",       # (Floréal, 3)
        "de l'aubépine",      # (Floréal, 4)
        "du rossignol",     # (Floréal, 5)
        "de l'ancolie",       # (Floréal, 6)
        "du muguet",        # (Floréal, 7)
        "du champignon",    # (Floréal, 8)
        "de l'hyacinthe",     # (Floréal, 9)
        "du râteau",        # (Floréal, 10)
        "de la rhubarbe",      # (Floréal, 11)
        "du sainfoin",      # (Floréal, 12)
        "du bâton-d'or",    # (Floréal, 13)
        "du chamerisier",   # (Floréal, 14)
        "du ver à soie",    # (Floréal, 15)
        "de la consoude",      # (Floréal, 16)
        "de la pimprenelle",   # (Floréal, 17)
        "de la corbeille d'or",# (Floréal, 18)
        "de l'arroche",       # (Floréal, 19)
        "du sarcloir",      # (Floréal, 20)
        "de la statice",       # (Floréal, 21)
        "de la fritillaire",   # (Floréal, 22)
        "de la bourache",      # (Floréal, 23)
        "de la valériane",     # (Floréal, 24)
        "de la carpe",         # (Floréal, 25)
        "du fusain",        # (Floréal, 26)
        "de la civette",       # (Floréal, 27)
        "de la buglosse",      # (Floréal, 28)
        "du sénevé",        # (Floréal, 29)
        "de la houlette",      # (Floréal, 30)

        "de la luzerne",       # (Prairial, 1)
        "de l'hémérocalle",   # (Prairial, 2)
        "du trèfle",        # (Prairial, 3)
        "de l'angélique",     # (Prairial, 4)
        "du canard",        # (Prairial, 5)
        "de la mélisse",       # (Prairial, 6)
        "du fromental",     # (Prairial, 7)
        "du martagon",      # (Prairial, 8)
        "du serpolet",      # (Prairial, 9)
        "de la faux",          # (Prairial, 10)
        "de la fraise",        # (Prairial, 11)
        "de la bétoine",       # (Prairial, 12)
        "du pois",          # (Prairial, 13)
        "de l'acacia",        # (Prairial, 14)
        "de la caille",        # (Prairial, 15)
        "de l'œillet",        # (Prairial, 16)
        "du sureau",        # (Prairial, 17)
        "du pavot",         # (Prairial, 18)
        "du tilleul",       # (Prairial, 19)
        "de la fourche",       # (Prairial, 20)
        "du barbeau",       # (Prairial, 21)
        "de la camomille",     # (Prairial, 22)
        "du chévrefeuille", # (Prairial, 23)
        "du caille-lait",   # (Prairial, 24)
        "de la tanche",        # (Prairial, 25)
        "du jasmin",        # (Prairial, 26)
        "de la verveine",      # (Prairial, 27)
        "du thym",          # (Prairial, 28)
        "de la pivoine",       # (Prairial, 29)
        "du chariot",       # (Prairial, 30)

        "du seigle",        # (Messidor, 1)
        "de l'avoine",        # (Messidor, 2)
        "de l'oignon",        # (Messidor, 3)
        "de la véronique",     # (Messidor, 4)
        "du mulet",         # (Messidor, 5)
        "de la romaine",       # (Messidor, 6)
        "du concombre",     # (Messidor, 7)
        "de l'échalote",      # (Messidor, 8)
        "de l'absinthe",      # (Messidor, 9)
        "de la faucille",      # (Messidor, 10)
        "de la coriandre",     # (Messidor, 11)
        "de l'artichaut",     # (Messidor, 12)
        "de la girofle",       # (Messidor, 13)
        "de la lavande",       # (Messidor, 14)
        "du chamois",       # (Messidor, 15)
        "du tabac",         # (Messidor, 16)
        "de la groseille",     # (Messidor, 17)
        "de la gesse",         # (Messidor, 18)
        "de la cerise",        # (Messidor, 19)
        "du parc",          # (Messidor, 20)
        "de la menthe",        # (Messidor, 21)
        "du cumin",         # (Messidor, 22)
        "du haricot",       # (Messidor, 23)
        "de l'orcanète",      # (Messidor, 24)
        "de la pintade",       # (Messidor, 25)
        "de la sauge",         # (Messidor, 26)
        "de l'ail",           # (Messidor, 27)
        "de la vesce",         # (Messidor, 28)
        "du blé",           # (Messidor, 29)
        "de la chalémie",      # (Messidor, 30)

        "de l'épeautre",      # (Thermidor, 1)
        "du bouillon-blanc",# (Thermidor, 2)
        "du melon",         # (Thermidor, 3)
        "de l'ivraie",        # (Thermidor, 4)
        "du bélier",        # (Thermidor, 5)
        "de la prêle",         # (Thermidor, 6)
        "de l'armoise",       # (Thermidor, 7)
        "du carthame",      # (Thermidor, 8)
        "de la mûre",          # (Thermidor, 9)
        "de l'arrosoir",      # (Thermidor, 10)
        "du panis",         # (Thermidor, 11)
        "de la salicorne",     # (Thermidor, 12)
        "de l'abricot",       # (Thermidor, 13)
        "du basilic",       # (Thermidor, 14)
        "de la brebis",        # (Thermidor, 15)
        "de la guimauve",      # (Thermidor, 16)
        "du lin",           # (Thermidor, 17)
        "de l'amande",        # (Thermidor, 18)
        "de la gentiane",      # (Thermidor, 19)
        "de l'écluse",        # (Thermidor, 20)
        "de la carline",       # (Thermidor, 21)
        "du câprier",       # (Thermidor, 22)
        "de la lentille",      # (Thermidor, 23)
        "de l'aunée",         # (Thermidor, 24)
        "de la loutre",        # (Thermidor, 25)
        "du myrte",         # (Thermidor, 26)
        "du colza",         # (Thermidor, 27)
        "du lupin",         # (Thermidor, 28)
        "du coton",         # (Thermidor, 29)
        "du moulin",        # (Thermidor, 30)

        "de la prune",         # (Fructidor, 1)
        "du millet",        # (Fructidor, 2)
        "du lycoperdon",    # (Fructidor, 3)
        "de l'escourgeon",    # (Fructidor, 4)
        "du saumon",        # (Fructidor, 5)
        "de la tubéreuse",     # (Fructidor, 6)
        "du sucrion",       # (Fructidor, 7)
        "de l'apocyn",        # (Fructidor, 8)
        "de la réglisse",      # (Fructidor, 9)
        "de l'échelle",       # (Fructidor, 10)
        "de la pastèque",      # (Fructidor, 11)
        "du fenouil",       # (Fructidor, 12)
        "de l'épine-vinette", # (Fructidor, 13)
        "de la noix",          # (Fructidor, 14)
        "de la truite",        # (Fructidor, 15)
        "du citron",        # (Fructidor, 16)
        "de la cardère",       # (Fructidor, 17)
        "du nerprun",       # (Fructidor, 18)
        "de la tagette",       # (Fructidor, 19)
        "de la hotte",         # (Fructidor, 20)
        "de l'églantier",     # (Fructidor, 21)
        "de la noisette",      # (Fructidor, 22)
        "du houblon",       # (Fructidor, 23)
        "du sorgho",        # (Fructidor, 24)
        "de l'écrevisse",     # (Fructidor, 25)
        "de la bigarade",      # (Fructidor, 26)
        "de la verge d'or",    # (Fructidor, 27)
        "du maïs",          # (Fructidor, 28)
        "du marron",        # (Fructidor, 29)
        "du panier",        # (Fructidor, 30)
    ]

    fragments.add_string_list("day_of_year", year_days)
    char_table = fragments.build_char_table()
    char_table.build_mapping()
    
    # Create a separate character table for the big font (only digits and colon)
    big_char_table = CharTable()
    for char in "0123456789:":
        big_char_table.add_char(char)
    big_char_table.build_mapping()
    
    # Big font only has digits and colon (11 characters)
    # Apply 10% scale, shift down to avoid truncation, and 10% horizontal padding
    big_font = FontTable(big_char_table, "big", 36, None, 
                        scale_factor=1.1, vertical_shift=0.15, horizontal_padding=0.1)
    big_font.render_font()
    
    # Normal font has all characters (no special adjustments)
    normal_font = FontTable(char_table, "normal", 18, None)
    normal_font.render_font()

    with open("../src/generated/drawing_objects.h", "w", encoding="utf-8") as header_file:
        with open("../src/generated/drawing_objects.cpp", "w", encoding="utf-8") as source_file:
            # Write C++ header and source file preambles
            header_file.write("#pragma once\n\n")
            header_file.write("#include <cstdint>\n")
            header_file.write("#include <array>\n\n")
            header_file.write("namespace rr::ui {\n\n")
            
            source_file.write("#include \"drawing_objects.h\"\n\n")
            source_file.write("namespace rr::ui {\n\n")

            # Write fragment table
            fragments.write_declarations(header_file)
            fragments.write_content(source_file, char_table)
            fragments.write_index_labels(header_file)

            # Write character table
            char_table.write_declarations(header_file)
            
            # Write font tables
            big_font.write_declarations(header_file)
            normal_font.write_declarations(header_file)
            big_font.write_content(source_file)
            normal_font.write_content(source_file)
            
            # Close namespaces
            header_file.write("} // namespace rr::ui\n")
            source_file.write("} // namespace rr::ui\n")


    # Generate concrete_fonts.h with correct sizes
    with open("../src/generated/concrete_fonts.h", "w", encoding="utf-8") as concrete_file:
        concrete_file.write("/// Font definitions\n")
        concrete_file.write("#pragma once\n\n")
        concrete_file.write("#include \"generated/drawing_objects.h\"\n")
        concrete_file.write("#include \"font.h\"\n\n")
        concrete_file.write("namespace rr::ui\n")
        concrete_file.write("{\n\n")
        
        # Calculate actual content sizes
        normal_content_size = 0
        for glyph in normal_font.glyphs.values():
            char_line_bytes = (glyph["width"] + 7) // 8
            normal_content_size += char_line_bytes * glyph["height"]
        
        big_content_size = 0
        for glyph in big_font.glyphs.values():
            char_line_bytes = (glyph["width"] + 7) // 8
            big_content_size += char_line_bytes * glyph["height"]
        
        concrete_file.write("// Wrapper for the normal font to match Font template structure\n")
        concrete_file.write("struct NormalFont {\n")
        concrete_file.write("    static constexpr size_t font_len = normal_font_len;\n")
        concrete_file.write("    static constexpr size_t font_height = normal_font_height;\n")
        concrete_file.write(f"    static constexpr size_t font_content_size = {normal_content_size};\n\n")
        concrete_file.write("    const std::array<uint8_t, normal_font_len>& char_widths = normal_font_char_widths;\n")
        concrete_file.write("    const std::array<uint16_t, normal_font_len>& char_begin = normal_font_char_begin;\n")
        concrete_file.write(f"    const std::array<uint8_t, {normal_content_size}>& content = normal_font_content;\n")
        concrete_file.write("};\n\n\n")
        concrete_file.write("// Wrapper for the big font to match Font template structure\n")
        concrete_file.write("struct BigFont {\n")
        concrete_file.write("    static constexpr size_t font_len = big_font_len;\n")
        concrete_file.write("    static constexpr size_t font_height = big_font_height;\n")
        concrete_file.write(f"    static constexpr size_t font_content_size = {big_content_size};\n\n")
        concrete_file.write("    const std::array<uint8_t, big_font_len>& char_widths = big_font_char_widths;\n")
        concrete_file.write("    const std::array<uint16_t, big_font_len>& char_begin = big_font_char_begin;\n")
        concrete_file.write(f"    const std::array<uint8_t, {big_content_size}>& content = big_font_content;\n")
        concrete_file.write("};\n\n")
        concrete_file.write("}\n")


if __name__ == "__main__":
    main()

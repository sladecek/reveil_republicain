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
                crop_y_start = max(0, int(self.y_offset) + shift_pixels)
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
    fragments.add_string("jourdu", "Jour du ")
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

    # 360 days of the year: "day name (Month, Day)"
    year_days = [
        "raisin",        # (Vendémiaire, 1)
        "safran",        # (Vendémiaire, 2)
        "châtaigne",     # (Vendémiaire, 3)
        "colchique",     # (Vendémiaire, 4)
        "cheval",        # (Vendémiaire, 5)
        "balsamine",     # (Vendémiaire, 6)
        "carotte",       # (Vendémiaire, 7)
        "amarante",      # (Vendémiaire, 8)
        "panais",        # (Vendémiaire, 9)
        "cuve",          # (Vendémiaire, 10)
        "pomme de terre",# (Vendémiaire, 11)
        "immortelle",    # (Vendémiaire, 12)
        "potiron",       # (Vendémiaire, 13)
        "réséda",        # (Vendémiaire, 14)
        "âne",           # (Vendémiaire, 15)
        "belle de nuit", # (Vendémiaire, 16)
        "citrouille",    # (Vendémiaire, 17)
        "sarrasin",      # (Vendémiaire, 18)
        "tournesol",     # (Vendémiaire, 19)
        "pressoir",      # (Vendémiaire, 20)
        "chanvre",       # (Vendémiaire, 21)
        "pêche",         # (Vendémiaire, 22)
        "navet",         # (Vendémiaire, 23)
        "amaryllis",     # (Vendémiaire, 24)
        "bœuf",          # (Vendémiaire, 25)
        "aubergine",     # (Vendémiaire, 26)
        "piment",        # (Vendémiaire, 27)
        "tomate",        # (Vendémiaire, 28)
        "orge",          # (Vendémiaire, 29)
        "tonneau",       # (Vendémiaire, 30)

        "pomme",         # (Brumaire, 1)
        "céleri",        # (Brumaire, 2)
        "poire",         # (Brumaire, 3)
        "betterave",     # (Brumaire, 4)
        "oie",           # (Brumaire, 5)
        "héliotrope",    # (Brumaire, 6)
        "figue",         # (Brumaire, 7)
        "scorsonère",    # (Brumaire, 8)
        "alisier",       # (Brumaire, 9)
        "charrue",       # (Brumaire, 10)
        "salsifis",      # (Brumaire, 11)
        "macre",         # (Brumaire, 12)
        "topinambour",   # (Brumaire, 13)
        "endive",        # (Brumaire, 14)
        "dindon",        # (Brumaire, 15)
        "chervis",       # (Brumaire, 16)
        "cresson",       # (Brumaire, 17)
        "dentelaire",    # (Brumaire, 18)
        "grenade",       # (Brumaire, 19)
        "herse",         # (Brumaire, 20)
        "bacchante",     # (Brumaire, 21)
        "azerole",       # (Brumaire, 22)
        "garance",       # (Brumaire, 23)
        "orange",        # (Brumaire, 24)
        "faisan",        # (Brumaire, 25)
        "pistache",      # (Brumaire, 26)
        "macjonc",       # (Brumaire, 27)
        "coing",         # (Brumaire, 28)
        "cormier",       # (Brumaire, 29)
        "rouleau",       # (Brumaire, 30)

        "raiponce",      # (Frimaire, 1)
        "turneps",       # (Frimaire, 2)
        "chicorée",      # (Frimaire, 3)
        "nèfle",         # (Frimaire, 4)
        "cochon",        # (Frimaire, 5)
        "mâche",         # (Frimaire, 6)
        "chou-fleur",    # (Frimaire, 7)
        "miel",          # (Frimaire, 8)
        "génépi",        # (Frimaire, 9)
        "pioche",        # (Frimaire, 10)
        "cire",          # (Frimaire, 11)
        "raifort",       # (Frimaire, 12)
        "cèdre",         # (Frimaire, 13)
        "sapin",         # (Frimaire, 14)
        "chevreuil",     # (Frimaire, 15)
        "ajonc",         # (Frimaire, 16)
        "cyprès",        # (Frimaire, 17)
        "lierre",        # (Frimaire, 18)
        "sabine",        # (Frimaire, 19)
        "hoye",          # (Frimaire, 20)
        "érable sucré",  # (Frimaire, 21)
        "bruyère",       # (Frimaire, 22)
        "roseau",        # (Frimaire, 23)
        "oseille",       # (Frimaire, 24)
        "grillon",       # (Frimaire, 25)
        "pignon",        # (Frimaire, 26)
        "liège",         # (Frimaire, 27)
        "truffe",        # (Frimaire, 28)
        "olive",         # (Frimaire, 29)
        "pelle",         # (Frimaire, 30)

        "tourbe",        # (Nivôse, 1)
        "houille",       # (Nivôse, 2)
        "bitume",        # (Nivôse, 3)
        "soufre",        # (Nivôse, 4)
        "chien",         # (Nivôse, 5)
        "lave",          # (Nivôse, 6)
        "terre végétale",# (Nivôse, 7)
        "fumier",        # (Nivôse, 8)
        "salpêtre",      # (Nivôse, 9)
        "fléau",         # (Nivôse, 10)
        "granite",       # (Nivôse, 11)
        "argile",        # (Nivôse, 12)
        "ardoise",       # (Nivôse, 13)
        "grès",          # (Nivôse, 14)
        "lapin",         # (Nivôse, 15)
        "silex",         # (Nivôse, 16)
        "marne",         # (Nivôse, 17)
        "pierre à chaux",# (Nivôse, 18)
        "marbre",        # (Nivôse, 19)
        "van",           # (Nivôse, 20)
        "pierre à plâtre",# (Nivôse, 21)
        "sel",           # (Nivôse, 22)
        "fer",           # (Nivôse, 23)
        "cuivre",        # (Nivôse, 24)
        "chat",          # (Nivôse, 25)
        "étain",         # (Nivôse, 26)
        "plomb",         # (Nivôse, 27)
        "zinc",          # (Nivôse, 28)
        "mercure",       # (Nivôse, 29)
        "crible",        # (Nivôse, 30)

        "lauréole",      # (Pluviôse, 1)
        "mousse",        # (Pluviôse, 2)
        "fragon",        # (Pluviôse, 3)
        "pervenche",     # (Pluviôse, 4)
        "taureau",       # (Pluviôse, 5)
        "laurier-tin",   # (Pluviôse, 6)
        "amatyste",      # (Pluviôse, 7)
        "mézéréon",      # (Pluviôse, 8)
        "peuplier",      # (Pluviôse, 9)
        "coignée",       # (Pluviôse, 10)
        "ellébore",      # (Pluviôse, 11)
        "brocoli",       # (Pluviôse, 12)
        "laurier",       # (Pluviôse, 13)
        "avelinier",     # (Pluviôse, 14)
        "vache",         # (Pluviôse, 15)
        "buis",          # (Pluviôse, 16)
        "lichén",        # (Pluviôse, 17)
        "if",            # (Pluviôse, 18)
        "pulmonaire",    # (Pluviôse, 19)
        "serpette",      # (Pluviôse, 20)
        "thlaspi",       # (Pluviôse, 21)
        "thimelé",       # (Pluviôse, 22)
        "chiendent",     # (Pluviôse, 23)
        "traînasse",     # (Pluviôse, 24)
        "lièvre",        # (Pluviôse, 25)
        "guède",         # (Pluviôse, 26)
        "noisetier",     # (Pluviôse, 27)
        "cyclamen",      # (Pluviôse, 28)
        "chélidoine",    # (Pluviôse, 29)
        "traîneau",      # (Pluviôse, 30)

        "tussilage",     # (Ventôse, 1)
        "cornouiller",   # (Ventôse, 2)
        "violier",       # (Ventôse, 3)
        "troène",        # (Ventôse, 4)
        "bouc",          # (Ventôse, 5)
        "asaret",        # (Ventôse, 6)
        "alaterne",      # (Ventôse, 7)
        "violette",      # (Ventôse, 8)
        "marceau",       # (Ventôse, 9)
        "bêche",         # (Ventôse, 10)
        "narcisse",      # (Ventôse, 11)
        "orme",          # (Ventôse, 12)
        "fumeterre",     # (Ventôse, 13)
        "vélar",         # (Ventôse, 14)
        "chèvre",        # (Ventôse, 15)
        "épinard",       # (Ventôse, 16)
        "doronic",       # (Ventôse, 17)
        "mouron",        # (Ventôse, 18)
        "cerfeuil",      # (Ventôse, 19)
        "cordeau",       # (Ventôse, 20)
        "mandragore",    # (Ventôse, 21)
        "persil",        # (Ventôse, 22)
        "cochléaria",    # (Ventôse, 23)
        "pâquerette",    # (Ventôse, 24)
        "thon",          # (Ventôse, 25)
        "pissenlit",     # (Ventôse, 26)
        "sylvie",        # (Ventôse, 27)
        "capillaire",    # (Ventôse, 28)
        "frêne",         # (Ventôse, 29)
        "plantoir",      # (Ventôse, 30)

        "primevère",     # (Germinal, 1)
        "platane",       # (Germinal, 2)
        "asperge",       # (Germinal, 3)
        "tulipe",        # (Germinal, 4)
        "poule",         # (Germinal, 5)
        "bette",         # (Germinal, 6)
        "bouleau",       # (Germinal, 7)
        "jonquille",     # (Germinal, 8)
        "aulne",         # (Germinal, 9)
        "couvoir",       # (Germinal, 10)
        "perce-neige",   # (Germinal, 11)
        "crocus",        # (Germinal, 12)
        "hêtre",         # (Germinal, 13)
        "laitue",        # (Germinal, 14)
        "torillon",      # (Germinal, 15)
        "lilas",         # (Germinal, 16)
        "anémone",       # (Germinal, 17)
        "pensée",        # (Germinal, 18)
        "myrtille",      # (Germinal, 19)
        "greffoir",      # (Germinal, 20)
        "cerisier",      # (Germinal, 21)
        "verveine",      # (Germinal, 22)
        "grenadier",     # (Germinal, 23)
        "vernal",        # (Germinal, 24)
        "cheval",        # (Germinal, 25)
        "brenèche",      # (Germinal, 26)
        "charme",        # (Germinal, 27)
        "morille",       # (Germinal, 28)
        "hêtre enraciné",# (Germinal, 29)
        "ruche",         # (Germinal, 30)

        "rose",          # (Floréal, 1)
        "chêne",         # (Floréal, 2)
        "fougère",       # (Floréal, 3)
        "aubépine",      # (Floréal, 4)
        "rossignol",     # (Floréal, 5)
        "ancolie",       # (Floréal, 6)
        "muguet",        # (Floréal, 7)
        "champignon",    # (Floréal, 8)
        "hyacinthe",     # (Floréal, 9)
        "râteau",        # (Floréal, 10)
        "rhubarbe",      # (Floréal, 11)
        "sainfoin",      # (Floréal, 12)
        "bâton-d'or",    # (Floréal, 13)
        "chamerisier",   # (Floréal, 14)
        "ver à soie",    # (Floréal, 15)
        "consoude",      # (Floréal, 16)
        "pimprenelle",   # (Floréal, 17)
        "corbeille d'or",# (Floréal, 18)
        "arroche",       # (Floréal, 19)
        "sarcloir",      # (Floréal, 20)
        "statice",       # (Floréal, 21)
        "fritillaire",   # (Floréal, 22)
        "bourache",      # (Floréal, 23)
        "valériane",     # (Floréal, 24)
        "carpe",         # (Floréal, 25)
        "fusain",        # (Floréal, 26)
        "civette",       # (Floréal, 27)
        "buglosse",      # (Floréal, 28)
        "sénevé",        # (Floréal, 29)
        "houlette",      # (Floréal, 30)

        "luzerne",       # (Prairial, 1)
        "hémérocalle",   # (Prairial, 2)
        "trèfle",        # (Prairial, 3)
        "angélique",     # (Prairial, 4)
        "canard",        # (Prairial, 5)
        "mélisse",       # (Prairial, 6)
        "fromental",     # (Prairial, 7)
        "martagon",      # (Prairial, 8)
        "serpolet",      # (Prairial, 9)
        "faux",          # (Prairial, 10)
        "fraise",        # (Prairial, 11)
        "bétoine",       # (Prairial, 12)
        "pois",          # (Prairial, 13)
        "acacia",        # (Prairial, 14)
        "caille",        # (Prairial, 15)
        "œillet",        # (Prairial, 16)
        "sureau",        # (Prairial, 17)
        "pavot",         # (Prairial, 18)
        "tilleul",       # (Prairial, 19)
        "fourche",       # (Prairial, 20)
        "barbeau",       # (Prairial, 21)
        "camomille",     # (Prairial, 22)
        "chévrefeuille", # (Prairial, 23)
        "caille-lait",   # (Prairial, 24)
        "tanche",        # (Prairial, 25)
        "jasmin",        # (Prairial, 26)
        "verveine",      # (Prairial, 27)
        "thym",          # (Prairial, 28)
        "pivoine",       # (Prairial, 29)
        "chariot",       # (Prairial, 30)

        "seigle",        # (Messidor, 1)
        "avoine",        # (Messidor, 2)
        "oignon",        # (Messidor, 3)
        "véronique",     # (Messidor, 4)
        "mulet",         # (Messidor, 5)
        "romaine",       # (Messidor, 6)
        "concombre",     # (Messidor, 7)
        "échalote",      # (Messidor, 8)
        "absinthe",      # (Messidor, 9)
        "faucille",      # (Messidor, 10)
        "coriandre",     # (Messidor, 11)
        "artichaut",     # (Messidor, 12)
        "girofle",       # (Messidor, 13)
        "lavande",       # (Messidor, 14)
        "chamois",       # (Messidor, 15)
        "tabac",         # (Messidor, 16)
        "groseille",     # (Messidor, 17)
        "gesse",         # (Messidor, 18)
        "cerise",        # (Messidor, 19)
        "parc",          # (Messidor, 20)
        "menthe",        # (Messidor, 21)
        "cumin",         # (Messidor, 22)
        "haricot",       # (Messidor, 23)
        "orcanète",      # (Messidor, 24)
        "pintade",       # (Messidor, 25)
        "sauge",         # (Messidor, 26)
        "ail",           # (Messidor, 27)
        "vesce",         # (Messidor, 28)
        "blé",           # (Messidor, 29)
        "chalémie",      # (Messidor, 30)

        "épeautre",      # (Thermidor, 1)
        "bouillon-blanc",# (Thermidor, 2)
        "melon",         # (Thermidor, 3)
        "ivraie",        # (Thermidor, 4)
        "bélier",        # (Thermidor, 5)
        "prêle",         # (Thermidor, 6)
        "armoise",       # (Thermidor, 7)
        "carthame",      # (Thermidor, 8)
        "mûre",          # (Thermidor, 9)
        "arrosoir",      # (Thermidor, 10)
        "panis",         # (Thermidor, 11)
        "salicorne",     # (Thermidor, 12)
        "abricot",       # (Thermidor, 13)
        "basilic",       # (Thermidor, 14)
        "brebis",        # (Thermidor, 15)
        "guimauve",      # (Thermidor, 16)
        "lin",           # (Thermidor, 17)
        "amande",        # (Thermidor, 18)
        "gentiane",      # (Thermidor, 19)
        "écluse",        # (Thermidor, 20)
        "carline",       # (Thermidor, 21)
        "câprier",       # (Thermidor, 22)
        "lentille",      # (Thermidor, 23)
        "aunée",         # (Thermidor, 24)
        "loutre",        # (Thermidor, 25)
        "myrte",         # (Thermidor, 26)
        "colza",         # (Thermidor, 27)
        "lupin",         # (Thermidor, 28)
        "coton",         # (Thermidor, 29)
        "moulin",        # (Thermidor, 30)

        "prune",         # (Fructidor, 1)
        "millet",        # (Fructidor, 2)
        "lycoperdon",    # (Fructidor, 3)
        "escourgeon",    # (Fructidor, 4)
        "saumon",        # (Fructidor, 5)
        "tubéreuse",     # (Fructidor, 6)
        "sucrion",       # (Fructidor, 7)
        "apocyn",        # (Fructidor, 8)
        "réglisse",      # (Fructidor, 9)
        "échelle",       # (Fructidor, 10)
        "pastèque",      # (Fructidor, 11)
        "fenouil",       # (Fructidor, 12)
        "épine-vinette", # (Fructidor, 13)
        "noix",          # (Fructidor, 14)
        "truite",        # (Fructidor, 15)
        "citron",        # (Fructidor, 16)
        "cardère",       # (Fructidor, 17)
        "nerprun",       # (Fructidor, 18)
        "tagette",       # (Fructidor, 19)
        "hotte",         # (Fructidor, 20)
        "églantier",     # (Fructidor, 21)
        "noisette",      # (Fructidor, 22)
        "houblon",       # (Fructidor, 23)
        "sorgho",        # (Fructidor, 24)
        "écrevisse",     # (Fructidor, 25)
        "bigarade",      # (Fructidor, 26)
        "verge d'or",    # (Fructidor, 27)
        "maïs",          # (Fructidor, 28)
        "marron",        # (Fructidor, 29)
        "panier",        # (Fructidor, 30)
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

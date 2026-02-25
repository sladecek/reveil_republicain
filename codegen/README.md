# Code Generation Implementation

## Overview

The `codegen.py` script generates C++ header and source files containing:
- Font glyph bitmaps for display rendering
- String fragment tables for UI text
- Character mapping tables

## Implemented Classes and Methods

### CharTable Class

**Purpose**: Manages the set of all unique characters used in the application.

**Methods**:
- `__init__()` - Initialize empty character set
- `add_char(char: str)` - Add a character to the table
- `build_mapping()` - Build character-to-index mapping
- `map_char(char: str) -> int` - Get index for a character
- `map_string(string: str) -> list[int]` - Map string to character indices
- `write_declarations(file)` - Write C++ declarations to header file

**Output**: 
- Character count constant
- Character names array
- Character Unicode value array

### FontTable Class

**Purpose**: Renders font glyphs for different character sets and sizes.

**Constructor**: `FontTable(char_table, name, size=8)`
- `char_table`: CharTable containing characters to render
- `name`: Font identifier (e.g., "big", "normal")
- `size`: Font size in pixels

**Methods**:
- `render_font()` - Render all characters using PIL/Pillow
  - Tries multiple font paths (DejaVu, Liberation, etc.)
  - Falls back to default font if none found
  - Generates bitmap data for each character
- `write_declarations(file)` - Write C++ glyph struct and array declarations
- `write_content(file)` - Write bitmap data arrays and glyph table

**Font Paths Tried**:
1. `/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf` (Linux)
2. `/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf` (Linux)
3. `/System/Library/Fonts/Helvetica.ttc` (macOS)
4. `C:\\Windows\\Fonts\\arial.ttf` (Windows)

**Output**:
- Glyph struct definition with width, height, and data pointer
- Bitmap data arrays for each character
- Glyph table array

### FragmentTable Class

**Purpose**: Manages text fragments (strings) used throughout the UI.

**Methods**:
- `__init__()` - Initialize empty fragment list
- `add_string_list(key, string_list)` - Add multiple strings with a label
- `add_string(key, value=None)` - Add single string with a label
- `build_char_table() -> CharTable` - Extract all unique characters
- `write_declarations(file)` - Write C++ declarations
- `write_content(file)` - Write string array
- `write_index_labels(file)` - Write enum for fragment labels
- `write_index(file)` - Write fragment length array

**Output**:
- Fragment count constant
- Fragment string array
- Fragment indices array (lengths)
- FragmentLabel enum for named access

## Generated Files

The script generates two files:

### `drawing_objects.h`
- C++ header with all declarations
- Wrapped in `rr::ui` namespace
- Contains:
  - Constants (CHAR_COUNT, FRAGMENT_COUNT)
  - External declarations for all arrays
  - Glyph struct definitions
  - FragmentLabel enum

### `drawing_objects.cpp`
- C++ source with all implementations
- Wrapped in `rr::ui` namespace
- Contains:
  - All array definitions with data
  - Character names and Unicode values
  - Font glyph bitmap data
  - Fragment strings

## Data Included

### Fragments
- Numbers 0-9
- UI labels (bell, colon, run, stop, alarm, etc.)
- French Republican calendar month names (12 months)
- French Republican calendar day names (10 days)
- Sansculottides festival names (6 days)
- All 360 days of the year with their names

### Fonts
- **Big font**: Size 11, for headings
- **Normal font**: Size 8, for regular text

## Dependencies

- **Pillow (PIL)**: For font rendering
- **unicodedata**: For character name lookup (built-in)

Install dependencies:
```bash
sudo apt-get install python3-pil  # Debian/Ubuntu
# or
pip install -r requirements.txt   # If using virtual environment
```

## Usage

```bash
cd codegen
python3 codegen.py
```

This generates `drawing_objects.h` and `drawing_objects.cpp` in the same directory.

## Integration with C++ Project

Add the generated files to your CMake project:

```cmake
add_library(ui_resources
    codegen/drawing_objects.cpp
)

target_include_directories(ui_resources
    PUBLIC
        ${CMAKE_SOURCE_DIR}/codegen
)
```

Then use in your code:

```cpp
#include "drawing_objects.h"

using namespace rr::ui;

// Access fragments
const char* alarm_text = fragments[static_cast<int>(FragmentLabel::ALARM)];

// Access font glyphs
const big_font_glyph_t& glyph = big_font[char_index];
```

## Future Enhancements

1. Add command-line arguments for font sizes
2. Support multiple output formats (JSON, binary)
3. Add compression for glyph data
4. Generate inline documentation
5. Add validation and error reporting

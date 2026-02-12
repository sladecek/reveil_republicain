# Reveil Republicain

A C++ project demonstrating CMake, Clang, Google Test, and ImGui integration.

## References

- https://quantum5.ca/2022/03/09/art-of-time-keeping-part-4-french-republican-calendar/
- https://github.com/Mubelotix/calendrier?tab=readme-ov-file

## Project Structure

```
reveil_republicain/
├── CMakeLists.txt          # Root CMake configuration
├── src/                    # Source code
│   ├── CMakeLists.txt
│   ├── reveil.h            # Library header
│   └── reveil.cpp          # Library implementation
├── tests/                  # Test code
│   ├── CMakeLists.txt
│   └── reveil_test.cpp     # Unit tests
└── emulator/               # ImGui GUI application
    ├── CMakeLists.txt
    └── main.cpp            # Emulator application
```

## Prerequisites

- CMake (>= 3.14)
- Clang compiler
- Git (for fetching dependencies)
- OpenGL development libraries
- X11 development libraries (Linux):
  ```bash
  sudo apt-get install libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev
  ```

## Building the Project

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build
cmake --build . -j$(nproc)
```

## Running Tests

```bash
# From the build directory
ctest --output-on-failure

# Or run the test executable directly
./tests/reveil_tests
```

## Running the Emulator

The emulator is an ImGui-based graphical application that demonstrates the library functionality:

```bash
# From the build directory
./emulator/emulator
```

The emulator provides:
- **Calculator interface**: Add, subtract, and multiply numbers using the Calculator class
- **Greeting generator**: Generate greeting messages with custom names
- Real-time FPS display

## Library Features

The `reveil` library provides:

- **Calculator class**: Simple arithmetic operations (add, subtract, multiply)
- **greet function**: Generate greeting messages

## Example Usage

```cpp
#include "reveil.h"
#include <iostream>

int main() {
    reveil::Calculator calc;
    std::cout << "2 + 3 = " << calc.add(2, 3) << std::endl;
    std::cout << reveil::greet("Developer") << std::endl;
    return 0;
}
```

## License

MIT License

cmake_minimum_required(VERSION 4.2)
project(emulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Emit compile_commands.json so clangd / the IDE know how to compile each file.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- Emulator core (the CPU/interpreter) ---
# A STATIC library builds fine even while the opcode handlers are still stubs:
# unresolved symbols are only reported when linked into an executable later.
add_library(chip8_core STATIC
        src/core/chip8.cpp
)

# Register include/ as a header search root. PUBLIC = this library AND anything
# that links it (the future executable, tests) both inherit the path, which is
# what makes #include "chip8/chip8.h" resolve.
target_include_directories(chip8_core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
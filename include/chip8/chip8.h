#pragma once

#include <cstdint>
#include <chrono>
#include <random>

/*
 *	This code/class members were inspired from austinmorlan.com
 *	Most of the references come from there on this learning experience
 */

class Chip8
{
public:
	Chip8();

	void LoadROM(char const* filename); // copy a program file into memory
	void Cycle();
	uint8_t  registers[16]{};   // V0..VF; VF doubles as a flag register (bc of hexadecimal)
	uint8_t  memory[4096]{};    // 4 KB address space (0x000 to 0xFFF)
	uint16_t index{};           // used to store memory addresses for use in operations
	uint16_t pc{};              // program counter (holds address of next instruction to run)
	uint16_t stack[16]{};       // return addresses for CALL/RET
	uint8_t  sp{};              // stack pointer (index into stack[])
	uint8_t  delayTimer{};
	uint8_t  soundTimer{};
	uint8_t  keypad[16]{};      // 1 = key held down (16 input keys)
	uint32_t video[64 * 32]{};  // one 32-bit pixel each: 0xFFFFFFFF on, 0 off. This is also the framebuffer
	uint16_t opcode{};          // the instruction currently being run

private:
	// Randomness for the RND instruction.
	std::default_random_engine randGen;
	std::uniform_int_distribution<unsigned int> randByte;

	void Table0();
	void Table8();
	void TableE();
	void TableF();
	static void OP_NULL(); // no-op for undefined opcodes

	// Instruction handlers. The name encodes the opcode pattern:
	// n = nibble, x/y = register numbers, kk = a byte, nnn = an address.
	void OP_00E0(); void OP_00EE();
	void OP_1nnn() const; void OP_2nnn(); void OP_3xkk(); void OP_4xkk(); void OP_5xy0();
	void OP_6xkk(); void OP_7xkk();
	void OP_8xy0(); void OP_8xy1(); void OP_8xy2(); void OP_8xy3(); void OP_8xy4();
	void OP_8xy5(); void OP_8xy6(); void OP_8xy7(); void OP_8xyE();
	void OP_9xy0(); void OP_Annn(); void OP_Bnnn(); void OP_Cxkk(); void OP_Dxyn();
	void OP_Ex9E(); void OP_ExA1();
	void OP_Fx07(); void OP_Fx0A(); void OP_Fx15(); void OP_Fx18(); void OP_Fx1E();
	void OP_Fx29(); void OP_Fx33(); void OP_Fx55(); void OP_Fx65();

	// A pointer to a Chip8 member function taking no args and returning void.
	typedef void (Chip8::*Chip8Func)();
	Chip8Func table[0xF + 1];    // indexed by the 1st nibble (0x0..0xF)
	Chip8Func table0[0xE + 1];   // sub-table for opcodes starting 0x0
	Chip8Func table8[0xE + 1];   // sub-table for opcodes starting 0x8
	Chip8Func tableE[0xE + 1];   // sub-table for opcodes starting 0xE
	Chip8Func tableF[0x65 + 1];  // sub-table for opcodes starting 0xF
};

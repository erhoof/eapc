#include <stdint.h>
#include <stdlib.h>

#include "include/cpu.h"

struct TwoBytes { // for regs
        uint8_t l;
        uint8_t h;
};

struct Flags { // for regs
        // [Status flags]

        // 8085 part
        // https://www.geeksforgeeks.org/flag-register-8085-microprocessor/
        char cy; // Carry Flag
        char n_f0; // Null
        char p; // Parity Flag 
        char n_f1; // Null
        char ac; // Auxiliary Carry Flag
        char n_f2; // Null
        char z; // Zero Flag
        char s; // Sign Flag
        
        // 8086 part
        // https://www.geeksforgeeks.org/flag-register-8086-microprocessor/
        char o; // Overflow Flag

        // [Control flags]
        char d; // Directional Flag
        char i; // Interrupt Flag
        char t; // Trap Flag

};

// Single Register

union Register {
    uint16_t w; // Full TwoBytes word
    struct TwoBytes b; // Parts of it
    struct Flags f; // Flags
};

struct Registers {

    // General Propose
    reg_t ax; // Primary Accumulator
    reg_t bx; // Base Registers
    reg_t cx; // Counter Register
    reg_t dx; // Data Register

    // Segment Registers
    reg_t cs; // Code Segment (base loc of code)
    reg_t ds; // Data Segment (base loc for vars)
    reg_t ss; // Stack Segment (of stack)
    reg_t es; // Additional base location for wars

    // Index Registers
    reg_t bp; // Base Pointer (offset from SS reg to locate vars on the stack)
    reg_t sp; // Stack Pointer (offset from SS as to the location of the stacks top)
    reg_t si; // Source Index (for copying)
    reg_t di; // Destination Index (for copying (ex. strings or segments))

    // Control Registers
    reg_t ip;
    reg_t flags;

    void nullRegs() {

        // Init regs
        ax.w = 0;
        bx.w = 0;
        cx.w = 0;
        dx.w = 0;

        cs.w = 0;
        ds.w = 0;
        ss.w = 0;
        es.w = 0;

        bp.w = 0;
        sp.w = 0;
        si.w = 0;
        di.w = 0;

        ip.w = 0;
        flags.w = 0;
    }

};

struct Operand {
    uint8_t code : 4;
    uint16_t lhr;
    uint16_t rhr;
};

struct CPU {
    void *mem;
    regs_t regs;

    bool running;
};

cpu_t* cpu_create(int memSize) {
    cpu_t* cpu = (cpu_t*)malloc(sizeof(cpu_t));
    cpu->mem = malloc(sizeof(uint8_t) * memSize);

    cpu->running = false;
    cpu->regs.nullRegs();
}

void cpu_delete(cpu_t* cpu) {
    free(cpu->mem);
    free(cpu);
}

void cpu_loadRom(cpu_t* cpu, const char* code) {
    // loader
}

uint16_t cpu_nextWord(cpu_t* cpu) {
    uint16_t state = cpu->regs.ip.w;
    cpu->regs.ip.w = 
}

void cpu_getOperand(cpu_t* cpu, opt_t* op, uint8_t val) {

}

void cpu_setOperand(cpu_t* cpu, opt_t* op, uint16_t val) {

}

void cpu_tick(cpu_t *cpu) {

}

void cpu_loop(cpu_t *cpu) {

}
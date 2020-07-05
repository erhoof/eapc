#define EC1_RAM 32 // by 2 bytes

// registers
typedef union Register {
    uint16_t W;
    
    union SB {
        uint8_t L;
        uint8_t H;
    } b_t;

} reg_t;

typedef struct Registers {

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

} regs_t;

typedef struct Flags {
    bool IF; // Interrupt Enable Flag
} flags_t;

typedef struct CPU {
    uint16_t ram[EC1_RAMSIZE];
    flags_t flags;
    regs_t regs;

    

} cpu_t;
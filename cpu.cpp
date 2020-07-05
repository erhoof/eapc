#define EC1_RAM 32 // by 2 bytes

// registers
typedef union Register {
    uint16_t W;
    
    struct SB {
        uint8_t l;
        uint8_t h;
    } b_t;

    struct F {
        // [Status flags]

        // 8085 part
        // https://www.geeksforgeeks.org/flag-register-8085-microprocessor/
        char cy; // Carry Flag
        char n_f0: // Null
        char p; // Parity Flag 
        char n_f1: // Null
        char ac; // Auxiliary Carry Flag
        char n_f2: // Null
        char z; // Zero Flag
        char s; // Sign Flag
        
        // 8086 part
        // https://www.geeksforgeeks.org/flag-register-8086-microprocessor/
        char o; // Overflow Flag

        // [Control flags]
        char d; // Directional Flag
        char i; // Interrupt Flag
        char t; // Trap Flag

    } f_t;

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
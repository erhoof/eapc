
// registers
typedef struct Registers {
    uint16_t ax; // Primary Accumulator
    uint16_t bx; // Base Registers
    uint16_t cx; // Counter Register
} regs_t;

typedef struct Flags {
    bool IF; 
}
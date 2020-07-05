#ifndef CPU_H_FILE
#define CPU_H_FILE

#define EC1_RAM 32 // by 2 bytes

typedef struct TwoBytes b_t;
typedef struct Flags f_t;
typedef union  Register reg_t;
typedef struct Registers regs_t;
typedef struct Operand opt_t;

typedef struct CPU cpu_t;

cpu_t* cpu_create(int memSize);
void cpu_delete(cpu_t*);
void cpu_loadRom(cpu_t*, const char *);
uint16_t cpu_nextWord(cpu_t*);
void cpu_getOperand(cpu_t*, opt_t*, uint8_t);
void cpu_setOperand(cpu_t*, opt_t*, uint16_t);
void cpu_tick(cpu_t *);
void cpu_loop(cpu_t *);

#endif
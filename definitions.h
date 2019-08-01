#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define TAM_PALAVRA 4
#define START_ADDRESS_DATA 0x4000000
#define TAM_UNIDADE_FUNC 5
//#define DATA_AMOUNT 400

//#define FLAG_EXIT  17
#define FLAG_VAZIO -1
#define FLAG_READY -3
#define FLAG_BUSY  -2
#define DISPONIVEL -4

#define REG_PG 28 /*GP*/
#define REG_PS 29 /*SP*/
#define REG_RA 31
#define REG_HI 32
#define REG_LO 33

#define SPECIAL 000000
#define SPECIAL2 011100
#define DEFAULT 111111

#define QTD_BARRAMENTOS 4
#define TRUE 1000

#define ISSUE 0
#define READ 1
#define EXECUTE 2
#define WRITEBACK 3

#define TYPE_R -6
#define TYPE_I -7
#define TYPE_J -8

#define ADD 100000
#define ADDI 001000
#define AND 100100
#define ANDI 001100
#define B 000100
#define BEQ 000100
#define BEQL 010100
#define BGEZ 000001
#define BGTZ 000111
#define BLEZ 000110
#define BLTZ 000001 //00000
#define BNE 000101
#define DIV 011010
#define J 000010
#define JR 001000
#define LUI 001111
#define MADD 000000
#define MFHI 010000
#define MFLO 010010
#define MOVN 001011
#define MOVZ 001010
#define MSUB 000100
#define MTHI 010001
#define MTLO 010011
#define MUL 000010
#define MULT 011000
#define NOP 000000
#define NOR 100111
#define OR 100101
#define ORI 001101
#define SUB 100010
#define XOR 100110
#define XORI 001110

typedef struct instruction{
    int rs;
    int rt;
    int rd;
    int type;
    int operation;
}instruction;

#endif
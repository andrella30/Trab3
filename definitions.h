#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define TAM_PALAVRA 4
#define START_ADDRESS_DATA 0x4000000
//#define DATA_AMOUNT 400

//#define FLAG_EXIT  17
#define FLAG_READY -3
#define FLAG_BUSY  -2
#define DISPONIVEL -4

#define REG_PG 28 /*GP*/
#define REG_PS 29 /*SP*/
#define REG_RA 31
#define REG_HI 32
#define REG_LO 33

extern int QUANTIDADE_ESTACOES_RESERVA_ADD, QUANTIDADE_ESTACOES_RESERVA_MUL, QUANTIDADE_ESTACOES_RESERVA_LOAD, QUANTIDADE_ESTACOES_RESERVA_STORE;
extern int QUANTIDADE_ESTACOES_RESERVA;





#endif
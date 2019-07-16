#ifndef REGISTRADOR_H
#define REGISTRADOR_H

#include <stdlib.h>
#include <stdio.h>
#include "definitions.h"

typedef struct{
  int Qi, valor;
}Registrador;

Registrador banco_registradores[34]; //32 por padrão + LO E HI

Registrador PC, IR, NPC; //Program Counter, Instruction Register e Next program Counter

void inicializar_registradores();

int reg_write(int w, int registrador);
int reg_read(int registrador);
int reg_get_status(int registrador);
int reg_change_status(int registrador, int indice_ER);
char * reg_get_name(int registrador);

void reg_print(int reg);
void reg_banco_print();

#endif
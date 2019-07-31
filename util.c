#include <stdio.h>
#include "util.h"

int getTipoInst(int opcode){
    switch (opcode){
        case ADD:
            return TYPE_R;
        break;
        case ADDI:
            return TYPE_I;
        break;
        case AND:
            return TYPE_R;
        break;
        case ANDI:
            return TYPE_I;
        break;
        case B || BEQ:
            return TYPE_I;
        break;
        case BEQL:
            return TYPE_I;
        break;
        case BGEZ || BLTZ:
            return TYPE_I;
        break;
        case BGTZ:
            return TYPE_I;
        break;
        case BLEZ:
            return TYPE_I;
        break;
        case BNE:
            return TYPE_I;
        break;
        case DIV:
            return TYPE_R;
        break;
        case J:
            return TYPE_J;
        break;
        case JR:
            return TYPE_R;
        break;
        case LUI:
            return TYPE_I;
        break;
        case MADD:
            return TYPE_R;
        break;
        case MFHI:
            return TYPE_R;
        break;
        case MFLO:
            return TYPE_R;
        break;
        case MOVN:
            return TYPE_R;
        break;
        case MSUB:
            return TYPE_R;
        break;
        case MTHI:
            return TYPE_R;
        break;
        case MTLO:
            return TYPE_R;
        break;
        case MUL:
            return TYPE_R;
        break;
        case MULT:
            return TYPE_I;
        break;
        case NOP:
            return TYPE_R;
        break;
        case NOR:
            return TYPE_R;
        break;
        case OR:
            return TYPE_R;
        break;
        case ORI:
            return TYPE_I;
        break;
        case SUB:
            return TYPE_R;
        break;
        case XOR:
            return TYPE_R;
        break;
        case XORI:
            return TYPE_I;
        break;
    }
}
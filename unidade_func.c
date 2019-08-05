#include <stdio.h>
#include "unidade_func.h"

//por convenção, as unidades funcionais 0 e 1 são de mult,
//a unidade funcional 2 é de div,
//a unidade funcional 3 é de add e
//a unidade funcional 4 é de int

void next(int type, void* instrucao, int pos){
    BUS[pos].type = type;
    BUS[pos].instrucao = instrucao;
    BUS[pos].valida = TRUE;
}

unidade_func* init_unidade_func(){
    unidades_funcionais = (unidade_func*)malloc(sizeof(unidade_func)*TAM_UNIDADE_FUNC);
    for (int i = 0; i<TAM_UNIDADE_FUNC; i++){
        unidades_funcionais[i].busy = FLAG_READY;
        unidades_funcionais[i].operacao = i;
        unidades_funcionais[i].dest_register = FLAG_VAZIO;
        for (int j = 0; j<2; j++){
            unidades_funcionais[i].source_register[j] = FLAG_VAZIO;
            unidades_funcionais[i].q[j] = FLAG_VAZIO;
            unidades_funcionais[i].ready[j] = FLAG_VAZIO;
        }
        unidades_funcionais[i].instr_type = FLAG_VAZIO;
        unidades_funcionais[i].instr_valida = FLAG_VAZIO;
        unidades_funcionais[i].Res = FLAG_VAZIO;
        unidades_funcionais[i].Res11 = FLAG_VAZIO;
        unidades_funcionais[i].cycle_counter = FLAG_VAZIO;
    }
    return unidades_funcionais;
}

int getUF(int opcode){
    if (opcode == ADD || opcode == ADDI || opcode == SUB)
        return 3;
    else if (opcode == MUL || opcode == MULT) //tem mais ainda
        return 1;
    else if (opcode == DIV)
        return 2;
    else
    {
        return 4;
    }
}

int issue(){
    int unidadefuncional = getUF(BUS[0].opcode);
    BUS[0].unidade_func = unidadefuncional;
    if(unidadefuncional == 1){
        if(unidades_funcionais[0].busy == FLAG_BUSY && unidades_funcionais[1].busy == FLAG_READY)
            unidadefuncional == 1;
        else if(unidades_funcionais[1].busy == FLAG_BUSY && unidades_funcionais[0].busy == FLAG_READY)
            unidadefuncional == 0;
        else if(unidades_funcionais[0].busy == FLAG_READY && unidades_funcionais[1].busy == FLAG_READY)
            unidadefuncional == 0;
        else{
            unidadefuncional == 1;
        }
    }
    if(unidades_funcionais[unidadefuncional].busy != FLAG_BUSY && unidades_funcionais[unidadefuncional].Res == FLAG_VAZIO && unidades_funcionais[unidadefuncional].Res11 == FLAG_VAZIO){
        unidades_funcionais[unidadefuncional].busy = FLAG_BUSY;
        unidades_funcionais[unidadefuncional].operacao = BUS[0].opcode;
        int dst,src1,src2 = BUS[0].instrucao;
        unidades_funcionais[unidadefuncional].dest_register = dst >> 11 &11111;
        unidades_funcionais[unidadefuncional].source_register[0] = src1 >> 16 &11111;
        unidades_funcionais[unidadefuncional].source_register[1] = src2 >> 21 &11111;
        unidades_funcionais[unidadefuncional].q[0] = reg_get_status(unidades_funcionais[unidadefuncional].source_register[0]);
        unidades_funcionais[unidadefuncional].q[1] = reg_get_status(unidades_funcionais[unidadefuncional].source_register[1]);                unidades_funcionais[unidadefuncional].q[1] = reg_get_status(unidades_funcionais[unidadefuncional].source_register[1]);
        unidades_funcionais[unidadefuncional].ready[0] = unidades_funcionais[unidadefuncional].q[0];
        unidades_funcionais[unidadefuncional].ready[1] = unidades_funcionais[unidadefuncional].q[1];
    }
}

void read_operands(){
    int unidadefuncional = BUS[1].unidade_func;
    if(unidades_funcionais[unidadefuncional].ready[0] == FLAG_READY && unidades_funcionais[unidadefuncional].ready[1] == FLAG_READY){
        unidades_funcionais[unidadefuncional].ready[0] = FLAG_BUSY;
        unidades_funcionais[unidadefuncional].ready[1] = FLAG_BUSY;
    }
}

void execute(){
    switch (TAM_UNIDADE_FUNC){
        case 0:
            //MUL e MULT
            banco_registradores[unidades_funcionais[0].dest_register].valor = ula_mult(unidades_funcionais[0].source_register[0],unidades_funcionais[0].source_register[1]);
        break;
        case 1:
            //MUL E MULT
            banco_registradores[unidades_funcionais[1].dest_register].valor = ula_mult(unidades_funcionais[1].source_register[0],unidades_funcionais[1].source_register[1]);
        break;
        case 2:
            //DIV
            banco_registradores[unidades_funcionais[2].dest_register].valor = ula_div(unidades_funcionais[2].source_register[1],unidades_funcionais[2].source_register[0]);
        break;
        case 3:
            //ADD, ADDI, MADD (verificar o instruction type)
            banco_registradores[unidades_funcionais[3].dest_register].valor = ula_somador(unidades_funcionais[3].source_register[0], unidades_funcionais[3].source_register[1]);
        break;
        case 4:
            //B, J, BEQ, BEQL, BGEZ, BGTZ, BLEZ, BLTZ, BNE, SUB, MSUB, MFHI, MFLO, MOVN, MOVZ, MTHI, MTLO
            //(verificar o instruction type)
            
    }
}

void write_back(unidade_func* unidades){
    /* wait until (∀f {(Fj[f]≠Fi[FU] OR Rj[f]=No) AND (Fk[f]≠Fi[FU] OR Rk[f]=No)})
    foreach f do
        if Qj[f]=FU then Rj[f] ← Yes;
        if Qk[f]=FU then Rk[f] ← Yes;
    Result[Fi[FU]] ← 0; // 0 means no FU generates the register's result
    RegFile[Fi[FU]] ← computed value;
    Busy[FU] ← No; */
}
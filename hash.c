#include "hash.h"

void init_hash(){
    Hash_Table = (Hash*)malloc(sizeof(Hash)*HASH_SIZE);
    for(int i = 0; i < HASH_SIZE; ++i){
        Hash_Table[i].data = NONE;
    }
}

unsigned int hash(char* key){
    unsigned int h = 0;
	char c;
    while(c = *key++) h = h*9^c;
    return h % HASH_SIZE;
}

int insert_label(char* key, int data){
    key[strlen(key) - 1] = '\0';
    if (Hash_Table[hash(key)].data != NONE) return 0;
    Hash_Table[hash(key)].key = key;
    Hash_Table[hash(key)].data = data;
}

int get_data(char* key){
    if (Hash_Table[hash(key)].data == NONE){
        //printf("Erro: Label não existente.\n");
        //exit(EXIT_FAILURE);
        return 0;
    }
    //printf("%d\n", Hash_Table[hash(key)].data);
    return Hash_Table[hash(key)].data;
}
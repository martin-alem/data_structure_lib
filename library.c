//
// Created by Martin Alemajoh on 9/14/2020.
//
#include "library.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int checkType(const char *type){

    char *types[] = {"int", "double", "float", "char", "string"};
    unsigned int len = sizeof(types)/sizeof(char *);
    short flag = 0;

    for(register int i = 0; i < len; i++){
        if(strcmp(type, types[i]) != 0){
            continue;
        }
        else{
            flag = 1;
        }
    }

    return flag;
}


void init(SLinkedList *list, char *type){
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    if(checkType(type)){
        list->type = type;
    }
    else{
        fprintf(stderr, "%s", "Error: Invalid Type\n");
        exit(0);
    }
}


void freeNode(void **node){

    if(node != NULL && *node != NULL){
        free(*node);
        *node = NULL;
    }
}


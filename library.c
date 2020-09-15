//
// Created by Martin Alemajoh on 9/14/2020.
//
#include "library.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * DEF: determines a correct datatype
 * PARAM1: const char *type *list - data type passed in by user
 * RETURN: returns 1 if type is correct and 0 otherwise
*/
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

/*
 * DEF: Initialize SLinkedList
 * PARAM1: SLinkedList *list - single linkedlist structure to be initialize
 * PARAM2: char *type - object datatype stored in list
 * RETURN: returns void
*/
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


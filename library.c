//
// Created by Martin Alemajoh on 9/14/2020.
//
#include "library.h"

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
    list->type = type;
}


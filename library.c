//
// Created by Martin Alemajoh on 9/14/2020.
//
#include "library.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void init(SLinkedList *list){
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}


void freeNode(void **node){

    if(node != NULL && *node != NULL){
        free(*node);
        *node = NULL;
    }
}

void clear(SLinkedList *list){

    Node *node = list->head;
    Node *nextNode;

    while(node != NULL){
        nextNode = node->next;
        freeNode((void **)&node);
        node = nextNode;
    }
    list->head = NULL;
    list->tail = NULL;
}


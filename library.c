//
// Created by Martin Alemajoh on 9/14/2020.
//
#include "library.h"
#include <stdlib.h>
#include <string.h>

void init(SLinkedList *list){
    list->head = NULL;
    list->tail = NULL;
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

Node *add(SLinkedList *list, const void *data){

    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL){
        return NULL;
    }
    node->data = data;
    node->next = NULL;

    if(list->head == NULL){
        list->head = node;
    }
    else{
        list->tail->next = node;
    }
    list->tail = node;
    return node;
}

void *get(SLinkedList *list, int index){

    if(list->head != NULL){

        if(index >= getSize(list)){
            return NULL;
        }
        Node *node = list->head;
        void *n;
        unsigned int i = 0;

        do {
            n = (void *)node->data;
            node = node->next;
            i += 1;
        }while (i <= index);

        return n;
    }
    return NULL;
}

unsigned int getSize(SLinkedList *list){

    unsigned int len = 0;

    if(list->tail != NULL){
        Node *node = list->head;
        while(node != NULL){
            len += 1;
            node = node->next;
        }
        return len;
    }
    return len;
}


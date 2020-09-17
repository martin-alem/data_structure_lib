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
    // update size of list
    getSize(list);
    return node;
}

unsigned int getSize(SLinkedList *list){

    unsigned int len = 0;

    if(list->tail != NULL){
        Node *node = list->head;
        while(node != NULL){
            len += 1;
            node = node->next;
        }
        list->size = len;
        return len;
    }
    return len;
}


//
// Created by Martin Alemajoh on 9/14/2020.
//
#include "singly_linked_list.h"
#include <stdlib.h>

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

void removeFront(SLinkedList *list){

    if(list->head != NULL){

        Node *nextNode = list->head->next;
        if(list->head == list->tail){
            list->tail = NULL;
        }
        freeNode((void **)&list->head);
        list->head = nextNode;
    }
}

void removeNext(SLinkedList *list, int index){

    if(list->head != NULL){

        if(index >= getSize(list) - 1 || index < 0){
            return;
        }
        unsigned int i = 0;
        Node *node, *tempNode = list->head,*nextNode;

        do{
            nextNode = tempNode->next;
            node = tempNode;
            tempNode = tempNode->next;
            i += 1;
        }while(i <= index);

        node->next = nextNode->next;
        freeNode((void **)&nextNode);
    }
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


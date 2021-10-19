//
//  Preg_2_First_Exam.cpp
//  Solución_Lab2_DataStructure
//
//  Created by Gabriel on 19/10/21.
//

// Question 1

int count(LinkedList L,int x){
    int count=0;
    Node* ptr=L.ini;
    while(ptr!=NULL){
        if(ptr->data == x){
        count = count +1;
        }
        ptr =ptr->next;
    }
    return count;
}

//Question 2

float mean(LinkedList L,int x){
    int sum = 0;
    int count=0;
        Node* ptr=L.ini;
        while(ptr != NULL){
            sum = sum + ptr->data;
            count = count + 1;
        ptr = ptr->next;
        }
    float mean = ((float)sum)/((float)count);
    return mean;
}


//3 Doubly Linked List
#include <stdio.h>
#include <iostream>
using namespace std;

void remove(DLinkedList *L, Node *ptr){
    if(ptr == L->ini){
        Node* remove = L->ini;
        L->ini = L->next;
        L->ini->prev = NULL;
        free(remove);
    }else{
        Node *remove = ptr;
        remove->prev->next = remove->next;
        if(remove->next != NULL){
            remove->next->prev = remove->prev;
        }
        free(remove)
    }
}

//Incremento

void increment(DLinkedList *L, int delta){
    Node *ptr = L->head;
    //incrementar delta
    while(ptr != NULL){
        ptr->data = ptr->data + delta;
        ptr = ptr->next;
    }
    //eliminar
    ptr = L->head;
    while(ptr != NULL && ptr->data = 0){
        remove(L,ptr);
        ptr=L->head;
    }
    while(ptr != NULL){
        if(ptr->data==0){
            Node* aux = ptr->next;
            remove(L,ptr);
            ptr=aux;
        }else{
            ptr=ptr->next;
        }
    }
}


// 4.- Concatenación sin elementos repetidos

void insert(LinkedList *L, int x){
    Node* _new_node = new Node();
    _new_node->data = x;
    if(L->head == NULL){
        L->head = _new_node;
    }else{
        _new_node->next = L->head;
        L->head = _new_node;
    }
}

LinkedList intersect(LinkedList L1, LinkedList L2){
    LinkedList L;
    Node* ptr_L1 = L1.head;
    Node* ptr_L2 = L2.head;
    
    while(ptr_L1 != NULL && ptr_L2 != NULL){
        if(ptr_L1->data < ptr_L2->data){
            ptr_L1 = ptr_L1->next;
        }else if(ptr_L1->data > ptr_L2->data){
            ptr_L2 = ptr_L2->next;
        }else{
            insert(&L.ptr_L1->data)
            ptr_L1 = ptr_L1->next;
            ptr_L2 = ptr_L2->next;
        }
    }
    return L;
}


//Question 5

Struct LinkedLsit{
    Node* head = NULL;
    Node* tail = NULL;
};

void insertTail(LinkedList *L, int x){
    Node* _new_node = new Node();
    _new_node->data = x;
    if(L->head == NULL){
        L->head = _new_node;
        L->Tail = _new_node;
    }else{
        L->tail->next = _new_node;
        L->tail = _new_node;
    }
}

LinkedList merge(LinkedList L1, LinkedList L1, LinkedList L2){
    LinkedList L;
    Node* ptr_L1 = L1.head;
    Node* ptr_L2 = L2.head;
    while(ptr_L1 != NULL && ptr_L2 != NULL){
        if(ptr_L1->data < ptr_L2->data){
            insertTail(&L,ptr_L1->data);
            ptr_L1 = ptr_L2->next;
        }
    }
    while(ptr_L1 != NULL){
        insertTail(&L,ptr_L1->data);
        ptr_L1 = ptr_L1->next;
    }

    while(ptr_L2 != NULL){
        insertTail(&L,ptr_L2->data);
        ptr_L2 = ptr_L2->next;
    }
    return L;
}

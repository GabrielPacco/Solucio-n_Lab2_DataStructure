//
//  Dequeue.cpp
//  Solución_Lab2_DataStructure
//
//  Created by Gabriel on 19/10/21.
//

#include <stdio.h>
#include <iostream>

template <class T>
class Node{
public:
    T data; //contenido
    Node* next; //puntero a siguiente
    Node *prev; //puntero a anterior
    Node(){
        next=nullptr;
        prev=nullptr;
    }
    
    Node(const T& x, Node* ptr_next = nullptr, Node * ptr_prev = nullptr){
        data=x;
        next=ptr_next;
        prev=ptr_prev;
    }
};

//clase Dequeue
template <class T>
class Dequeue{
private:
    Node<T> *head;
    Node<T> *tail;
public:
    Dequeue(){
        head = nullptr;
        tail = nullptr;
    }
    
    bool isEmpty(){
        return (head==nullptr);
    }
    
    void pushFront(const T&);
    void pushBack(const T&);
    T popFront(const T&);
    T popBack(const T&);
};

//Implementation
template <class T>
void Dequeue<T>::pushFront(<#const T &#> x){
    Node<T>* _new_node = new Node<T>(x,nullptr,head);
    if(head == nullptr){
        head = _new_node;
        tail = _new_node;
    }else{
        head->prev = _new_node;
        head = _new_node;
    }
}

template <class T>
void Dequeue<T>::pushBack(<#const T &#> x){
    Node<T>* _new_node = new Node<T>(x,tail,nullptr);
    if(tail==nullptr){
        
        tail = _new_node;
        head = _new_node;
    }else{
        tail->next = _new_node;
        head = _new_node;
    }
}

template <class T>
T Dequeue<T>::popFront(){
    Node<T>* removed = head;
    T elem = head->data;
    if(head==tail){
        head=nullptr;
        tail=nullptr;
    }else{
        head = head->next;
        head->prev=nullptr;
    }
    delete removed;
    return elem;
}

template <class T>
T Dequeue<T>::popBack(){
    Node<T>* removed = tail;
    T elem = tail->data;
    if(head ==)
}

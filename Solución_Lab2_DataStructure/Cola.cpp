//
//  Cola.cpp
//  Solución_Lab2_DataStructure
//
//  Created by Gabriel on 19/10/21.
//

#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
class Node{
public:
    T data; //contenido
    Node* next; // puntero a siguiente
    
    Node(){
        next = nullptr;
    }
    
    Node(const T& x, Node* ptr = nullptr){
        data = x;
        next = ptr;
    }
};

//Clase cola
template <class T>
class Queue{
private:
    Node<T> *head;
    Node<T> *tail;
public:
    Queue(){
        head = nullptr;
        tail = nullptr;
    }
    bool isEmpty(){
        return (head == nullptr);
    }
    void push(const T&);
    T pop();
    T top();
};

//Implementación de funciones
template <class T>
void Queue<T>::push(<#const T &#>x){
    Node<T> _new_node = new Node<T>(x);
    if(head == nullptr){
        head = _new_node;
        tail = _new_node;
    }else{
        tail->next = _new_node;
        tail = _new_node;
    }
}

template <class T>
T Queue<T>::pop(){
    T elem = head->data;
    Node<T> *tmp = head;
    if(head==tail){
        tail=nullptr;
    }
    head=head->next;
    delete tmp;
    return elem;
}

template <class T>
T Queue<T>::top(){
    return head->data;
}

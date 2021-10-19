//
//  main.cpp
//  Solución_Lab2_DataStructure
//
//  Created by Gabriel on 19/10/21.
//

#include <iostream>

template <class T>
class Node{
public:
    T data; //contenido
    Node* next; //puntero al siguiente
    
    Node(){
        next=nullptr;
    }
    
    Node(const T& x, Node* ptr=nullptr){
        data = x;
        next = ptr;
    }
};

// Clase Pila
template <class T>
class Stack{
private:
    Node<T> *top; //cima de la pila
public:
    Stack(){
        top = nullptr;
    }
    bool isEmpty(){
        return (head==nullptr);
    }
    void push(const T&);
    T pop();
    T top();
};

//Implementación de las funciones
template <class T>
void Stack<T>::push(const T& x){
    top = new Node<T>(x,top);
}

template <class T>
T Stack<T>::pop(){
    T elem = top->data;
    Node<T> *tmp = top;
    top = top->next;
    delete tmp;
    return elem;
}

template <class T>
T Stack<T>::top(){
    return top->data;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

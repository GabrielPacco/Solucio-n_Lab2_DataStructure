//
//  Binary_Tree.cpp
//  Solución_Lab2_DataStructure
//
//  Created by Gabriel on 19/10/21.
//

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int data; //contenido
    TreeNode* left; // hijo izquierdo
    TreeNode* right; // hijo derecho
};

struct Tree{
    TreeNode * root;
};

void Preorder(TreeNode* root){
    if(root != NULL){
        printf(" %d", root->data); //contenido de la raiz
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct TreeNode* root)
{
    if (root == NULL)
        return;
 
    // primer recurso en el subárbol de la izquierda
    Postorder(root->left);
 
    // y luego recorrer al subárbol de la derecha
    Postorder(root->right);
 
    printf(" %d", root->data); //contenido de la raiz
}

void iterativePreorder(TreeNode* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Crear una pila vacía y empujar la raíz a ella
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
 
    /* Haga saltar todos los elementos uno por uno. Haga lo siguiente para cada elemento que aparezca
     a) imprimirlo
     b) empujar su hijo derecho
     c) empujar su hijo izquierdo
    Tenga en cuenta que el hijo derecho se empuja primero para que el izquierdo se procese primero */
    while (nodeStack.empty() == false) {
        // Sacar el elemento superior de la pila e imprimirlo
        struct TreeNode* node = nodeStack.top();
        printf("%d ", node->data);
        nodeStack.pop();
 
        // Empuja los hijos derecho e izquierdo del nodo saltado a la pila
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}


int main(){
    TreeNode* root;
    
    cout << "\nPostorder traversal of binary tree is \n";
    Postorder(root);
 
    return 0;
}

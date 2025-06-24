#include "binary_tree.h"

void printTree_rec(Node* tree, unsigned int iProfondeur){

    if (tree == NULL) return;

    printTree_rec(tree->right, iProfondeur + 1);

    for(unsigned int i = 0; i < iProfondeur; i++)
        printf("\t");

    printf("Key : %d\n", tree->key);

    printTree_rec(tree->left, iProfondeur + 1);
}

void printTree(Node* tree){
    printTree_rec(tree, 0);
}

   
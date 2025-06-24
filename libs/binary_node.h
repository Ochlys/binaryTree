#ifndef __BINARY_NODE_H__
#define __BINARY_NODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
    unsigned int key;
    struct Node* right;
    struct Node* left;
} Node;


Node* createNode(unsigned int iKey, Node* iLeft, Node* iRight);

void addNode(Node** tree, unsigned int iKey);
void searchNode(Node* tree, unsigned int iKey);
void clearNodeTree(Node* tree);

#endif // __BINARY_NODE_H__
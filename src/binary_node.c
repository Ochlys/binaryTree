#include "binary_node.h"

Node* createNode(unsigned int iKey, Node* iLeft, Node* iRight){

    Node* newNode = (Node*) malloc(sizeof(Node));
    // Si il est impossible d'allouer de la mémoire
    assert(newNode);

    newNode->key = iKey;
    newNode->left = iLeft;
    newNode->right = iRight;

    return newNode;
}

void insertLeft(Node* node, Node* elem){

    if(node->left != NULL){
        insertLeft(node->left, elem);
    } else {
        node->left = elem;
    }
}

void insertRight(Node* node, Node* elem){

    if(node->right != NULL){
        insertRight(node->right, elem);
    } else {
        node->right = elem;
    }
}

void addNode(Node** tree, unsigned int key) {
    Node* elem = createNode(key, NULL, NULL);

    if (*tree == NULL) {
        *tree = elem;
        return;
    }

    Node* tmpTree = *tree;

    if (key < tmpTree->key) {
        insertLeft(tmpTree, elem);
    } else {
        insertRight(tmpTree, elem);
    }
}


void searchNode(Node *tree, unsigned int key){

    while (tree != NULL) {

        if(key > tree->key){
            tree = tree->right;
        } else {
            tree = tree -> left;
        }

        if (key == tree->key){
           printf("Valeur recherchée : %d\n", key);
           break;
        } else {
            printf("La valeur %d a pas été trouvée.\n", key);
            break;
        }
    }
    
}

void clearNodeTree(Node* tree){

    if (tree->left != NULL) {
        free(tree->left);
    }

    if (tree->right != NULL) {
        free(tree->right);
    }

    printf("Noeud avec la clé %d à été supprimé.\n", tree->key);

    free(tree);
}

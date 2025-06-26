#include "libs/binary_tree.h"
#include "libs/binary_node.h"

int main(){

    Node *MyTree = NULL;

    addNode(&MyTree, 30);
    addNode(&MyTree, 20);
    addNode(&MyTree, 50);
    addNode(&MyTree, 45);
    addNode(&MyTree, 25);
    addNode(&MyTree, 80);
    addNode(&MyTree, 40);
    addNode(&MyTree, 70);
    addNode(&MyTree, 25);
    addNode(&MyTree, 10);
    addNode(&MyTree, 60);

    searchNode(MyTree, 20);
    printf("==============\n");
    searchNode(MyTree, 47);
    printf("==============\n");
    printTree(MyTree);
    printf("==============\n");
    int d = depth(MyTree);
    printf("Profondeur de l'arbre : %d\n", d);
    printf("==============\n");
    clearNodeTree(MyTree);


    return 0;


}


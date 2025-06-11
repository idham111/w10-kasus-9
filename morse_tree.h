
#ifndef MORSE_TREE_H
#define MORSE_TREE_H

#define MAX_NODES 100

typedef struct {
    char symbol;
    int left;
    int right;
} MorseNode;

typedef struct {
    MorseNode nodes[MAX_NODES];
    int root;
    int size;
} MorseTree;

void initTree(MorseTree *tree);
int addNode(MorseTree *tree, char symbol);
void buildMorseTree(MorseTree *tree);
void printTree(MorseTree *tree, int idx, int depth);

#endif

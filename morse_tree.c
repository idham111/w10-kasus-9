
#include <stdio.h>
#include "morse_tree.h"

void initTree(MorseTree *tree) {
    tree->size = 0;
    tree->root = -1;
}

int addNode(MorseTree *tree, char symbol) {
    if (tree->size >= MAX_NODES) return -1;

    tree->nodes[tree->size].symbol = symbol;
    tree->nodes[tree->size].left = -1;
    tree->nodes[tree->size].right = -1;

    return tree->size++;
}

void buildMorseTree(MorseTree *tree) {
    initTree(tree);

    int root = addNode(tree, '\0');
    tree->root = root;

    int T = addNode(tree, 'T');
    int E = addNode(tree, 'E');
    tree->nodes[root].left = T;
    tree->nodes[root].right = E;

    struct {
        char symbol;
        const char *code;
    } morseMap[] = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
        {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
        {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
        {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
        {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
        {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
        {'8', "---.."}, {'9', "----."}, {'0', "-----"}, {' ', "......."},
    };

    int len = sizeof(morseMap) / sizeof(morseMap[0]);

    for (int i = 0; i < len; i++) {
        int current = tree->root;
        const char *code = morseMap[i].code;

        for (int j = 0; code[j] != '\0'; j++) {
            if (code[j] == '.') {
                if (tree->nodes[current].left == -1) {
                    tree->nodes[current].left = addNode(tree, '\0');
                }
                current = tree->nodes[current].left;
            } else if (code[j] == '-') {
                if (tree->nodes[current].right == -1) {
                    tree->nodes[current].right = addNode(tree, '\0');
                }
                current = tree->nodes[current].right;
            }
        }
        tree->nodes[current].symbol = morseMap[i].symbol;
    }
}

void printTree(MorseTree *tree, int idx, int depth) {
    if (idx == -1) return;

    for (int i = 0; i < depth; i++) printf("  ");
    printf("(%c)\n", tree->nodes[idx].symbol == '\0' ? '-' : tree->nodes[idx].symbol);

    printTree(tree, tree->nodes[idx].left, depth + 1);
    printTree(tree, tree->nodes[idx].right, depth + 1);
}

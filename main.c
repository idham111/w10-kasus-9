
#include <stdio.h>
#include "morse_tree.h"

int main() {
    MorseTree tree;
    buildMorseTree(&tree);

    printf("Morse Tree (versi kamu):\n");
    printTree(&tree, tree.root, 0);

    return 0;
}

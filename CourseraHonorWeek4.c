#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

typedef node *bTree;

/// traverser l'arbre binaire et afficher
///  tout les valeurs de chaque Noeuds
void inorder(bTree root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/// @brief
/// @param
/// @return
/// allocation de mémoire pour l'arbre
bTree new_node(void) {
    return (malloc(sizeof(node)));
}

/// @brief
/// @param data1
/// @param pointer1
/// @param pointer2
/// @return
/// initialiser l'arbre binaire
bTree initNode(int data1, bTree pointer1, bTree pointer2) {
    bTree tree = new_node();
    tree->data = data1;
    tree->left = pointer1;
    tree->right = pointer2;
    return tree;
}

/// @brief
/// @param data
/// @param index
/// @param size
/// @return
/// Création de l'arbre
bTree createTree(int data[], int index, int size) {
    if (index >= size) return NULL;
    else return (initNode(data[index],
                          createTree(data, index * 2 + 1, size),
                          createTree(data, index * 2 + 2, size)));
}

void freeTree(bTree root) {
    if (root != NULL) {
        freeTree(root->left);   // Recursively free the left subtree
        freeTree(root->right);  // Recursively free the right subtree
        free(root);             // Free the current node
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int size;
    fscanf(file, "%d", &size);

    int *data = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &data[i]);
    }

    fclose(file);

    bTree root = createTree(data, 0, size);

    printf("Binary Tree in order traversal: ");
    inorder(root);
    printf("\n");

    free(data);
    freeTree(root);

    return 0;
}

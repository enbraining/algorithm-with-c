#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left_node, *right_node;
} Node;

Node* create_node(int data);
void print_preorder(Node* root_node);
void print_inorder(Node* root_node);
void print_postorder(Node* root_node);

int main() {
    Node* first_node = create_node(10);
    Node* second_node = create_node(20);
    Node* third_node = create_node(30);

    first_node->left_node = second_node;
    first_node->right_node = third_node;

    print_inorder(first_node);

    free(first_node);
    free(second_node);
    free(third_node);
}

Node* create_node(int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
}

void print_preorder(Node* root_node) {
    if(root_node != NULL) {
        printf("%d\n", root_node->data);
        print_preorder(root_node->left_node);
        print_preorder(root_node->right_node);
    }
}

void print_inorder(Node* root_node) {
    if(root_node != NULL) {
        print_inorder(root_node->left_node);
        printf("%d\n", root_node->data);
        print_inorder(root_node->right_node);
    }
}

void print_postorder(Node* root_node) {
    if(root_node != NULL) {
        print_postorder(root_node->left_node);
        print_postorder(root_node->right_node);
        printf("%d\n", root_node->data);
    }
}
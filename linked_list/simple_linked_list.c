#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode {
    int data;
    struct LinkedListNode *next_node;
} Node;

int get_node(const Node* head_node, int index);
Node* create_node(int new_data);
void append_node(Node** head_node, Node* new_node);

int main() {
    Node* head_node = create_node(10);
    Node* node_1 = create_node(20);
    Node* node_2 = create_node(30);

    append_node(&head_node, node_1);
    append_node(&head_node, node_2);

    printf("%d\n", get_node(head_node, 0)); // 10
    printf("%d\n", get_node(head_node, 1)); // 20
    printf("%d\n", get_node(head_node, 2)); // 30

    free(head_node);
    free(node_1);
    free(node_2);
}

int get_node(const Node* head_node, int index) {
    while (index-- > 0) {
        head_node = head_node->next_node;
    }
    return head_node->data;
}

Node* create_node(const int new_data) {
    Node* new_node = malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next_node = NULL;

    return new_node;
}

void append_node(Node** head_node, Node* new_node) {
    if (*head_node == NULL) {
        *head_node = new_node;
    } else {
        Node* tail = *head_node;

        while (tail->next_node != NULL) {
            tail = tail->next_node;
        }

        tail->next_node = new_node;
    }
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* new_Node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* MergeLists(struct Node* x, struct Node* y) {
    if (x == NULL) 
    return y;
    if (y == NULL) 
    return x;

    if (x->data <= y->data) {
        x->next = MergeLists(x->next, y);
        return x;
    } else {
        y->next = MergeLists(x, y->next);
        return y;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* x = new_Node(5);
    x->next = new_Node(6);
    x->next->next = new_Node(7);

    struct Node* y = new_Node(2);
    y->next = new_Node(4);
    y->next->next = new_Node(8);

    printf("List One: ");
    printList(x);
    printf("List Two: ");
    printList(y);

    struct Node* mergedList = MergeLists(x, y);

    printf("The Merged List: ");
    printList(mergedList);

    return 0;
}
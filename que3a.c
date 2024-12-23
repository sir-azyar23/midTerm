#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node  *Newnode(int data) {
    struct Node  *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* RemoveDuplicates(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        struct Node* runner = current;
        while (runner->next != NULL) {
            if (current->data == runner->next->data) {
                struct Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
    return head;
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
    struct Node* head = Newnode(5);
    head->next = Newnode(11);
    head->next->next = Newnode(14);
    head->next->next->next = Newnode(14);
    head->next->next->next->next = Newnode(5);
    head->next->next->next->next->next = Newnode(17);
    head->next->next->next->next->next->next = Newnode(10);

    printf("Linked list before removing duplicates Numbers:\n");
    printList(head);

    head = RemoveDuplicates(head);

    printf("\nLinked list after removing duplicates Numbers:\n");
    printList(head);

    return 0;
}
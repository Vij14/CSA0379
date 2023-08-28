#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of a linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to merge two linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            mergedList = insertEnd(mergedList, list1->data);
            list1 = list1->next;
        } else {
            mergedList = insertEnd(mergedList, list2->data);
            list2 = list2->next;
        }
    }

    while (list1 != NULL) {
        mergedList = insertEnd(mergedList, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        mergedList = insertEnd(mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
}

// Function to display a linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    list1 = insertEnd(list1, 2);
    list1 = insertEnd(list1, 5);
    list1 = insertEnd(list1, 7);

    struct Node* list2 = NULL;
    list2 = insertEnd(list2, 3);
    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 6);

    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    struct Node* mergedList = mergeLists(list1, list2);
    printf("Merged List: ");
    displayList(mergedList);

    return 0;
}

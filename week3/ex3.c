#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} LinkedList;

LinkedList *createNode(int data) {
    LinkedList *result = malloc(sizeof(LinkedList));
    
    result->data = data;
    result->next = NULL;
    return result;
}

void print_list(LinkedList *ll){
    LinkedList *temp = ll;
    
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

LinkedList *findNode(LinkedList *ll, int index) {
    LinkedList *temp = ll;
    
    for(int i = 0; i < index; i++) {
        if (temp == NULL) {
            return NULL;
        }
        temp = temp -> next;
    }
    
    return temp;
}

void insert_node(LinkedList *ll, int data, int index) {
    LinkedList *node = createNode(data);
    LinkedList *temp = findNode(ll, index);
    
    if(node != NULL) {
        if(temp != NULL) {
            node->next = temp->next;
            temp->next = node;
        }
    }
}

void delete_node(LinkedList *ll, int index) {
    LinkedList *existNode = findNode(ll, index);
    LinkedList *beforeNode = findNode(ll, index - 1);
    
    if(existNode != NULL) {
        beforeNode -> next = existNode -> next;
    }
    
}

int main()
{
    LinkedList *ll1 = createNode(1);
    LinkedList *ll2 = createNode(2);
    LinkedList *ll3 = createNode(3);
    LinkedList *ll4 = createNode(4);
    LinkedList *head;

    head = ll4;
    ll4->next = ll3;
    ll3->next = ll2;
    ll2->next = ll1;
    ll1->next = NULL;
    
    print_list(head);
    insert_node(head, 5, 1);
    print_list(head);
    delete_node(head, 2);
    print_list(head);
    return 0;
}

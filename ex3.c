#include <stdio.h>

struct node{

    int value;
    struct node* next;
};

void print_list(struct node* head){

    struct node* elem = head;
    while (elem!=0){
        printf("%d\n", elem->value);
        elem = elem->next;
    }
}

void insert_node(struct node* newnode, struct node* prevnode) {

    struct node* aftnode = prevnode->next;
    prevnode->next = newnode;
    newnode->next = aftnode;
}

void delete_node(struct node* head, struct node* delnode){
    struct node* elem = head;
    if (delnode==head) *head = *head->next;
    else{
    while (elem->next!=delnode){
        elem = elem->next;
    }
    elem->next = delnode->next;}
}

int main(){
    struct node linked_list = {.value = 0, .next = 0};
    struct node node1 = {.value = 1, .next = 0};
    struct node node2 = {.value = 2, .next = 0};
    struct node node3 = {.value = 3, .next = 0};
    struct node node4 = {.value = 4, .next = 0};

    insert_node(&node1, &linked_list);
    insert_node(&node2, &node1);
    insert_node(&node3, &node2);
    insert_node(&node4, &node2);

    printf("Initial list:\n");
    print_list(&linked_list);

    printf("After deleting 2:\n");
    delete_node(&linked_list, &node2);
    print_list(&linked_list);

}
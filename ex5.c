#include <stdio.h>

struct node{

    int value;
    struct node* next;
    struct node* before;
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
    newnode->before = prevnode;
    if (aftnode!=0) aftnode->before = newnode;
}

void delete_node(struct node* delnode){

    if (delnode->before==0) *delnode = *delnode->next;
    else {
        delnode->before->next = delnode->next;
        delnode->next->before = delnode->before;
    }
}

int main(){

    struct node linked_list = {.value = 0, .next = 0, .before = 0};
    struct node node1 = {.value = 1, .next = 0, .before = 0};
    struct node node2 = {.value = 2, .next = 0, .before = 0};
    struct node node3 = {.value = 3, .next = 0, .before = 0};
    struct node node4 = {.value = 4, .next = 0, .before = 0};

    insert_node(&node1, &linked_list);
    insert_node(&node2, &node1);
    insert_node(&node3, &node2);
    insert_node(&node4, &node2);

    printf("Initial list:\n");
    print_list(&linked_list);

    printf("After deleting 2:\n");
    delete_node(&node2);
    print_list(&linked_list);

}
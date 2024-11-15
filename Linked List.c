
#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* link;
};


struct node* add_at_end(struct node* ptr, int data){
    ///printf("hello worl");
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;

    return temp;
}
struct node* add_beg(struct node* head, int d){
    struct node* ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;

    ptr->link = head;

    head = ptr;
    return head;
}

void add_at_certain_pos(struct node* head,int da, int pos){

struct node *ptr = head;
struct node *ptr2 = malloc(sizeof(struct node));
ptr2->data = da;
ptr2->link = NULL;

pos--;
while(pos!=1){
    ptr = ptr->link;
    pos--;
}

ptr2->link = ptr->link;
ptr->link = ptr2;

}





int main(){
struct node *head = malloc(sizeof(struct node));
head -> data = 56;
head -> link = NULL;

struct node *ptr = head;


ptr = add_at_end(ptr,90);
ptr = add_at_end(ptr,89);

ptr = add_at_end(ptr,45);
int  d= 300;
head = add_beg(head , d);

int dat = 79;
int position = 3;
 add_at_certain_pos(head,dat,position);


ptr = head;
while(ptr != NULL){
    printf("%d\n",ptr->data);
    ptr = ptr -> link;
}



}

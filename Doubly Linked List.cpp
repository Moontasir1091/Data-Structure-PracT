#include<bits/stdc++.h>
using namespace std;

struct node{
node* prev;
int data;
node* next;
};
node* ADD_empty(node* head, int data){
    node* temp = new node;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    head = temp;
    return head;
}

node* ADD_END(node* head, int data){

    node* temp = new node;
    node* tp = head;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    while(tp->next!=nullptr){
        tp = tp->next;
    }

    tp->next = temp;
    temp->prev = tp;
    return head;
}
node* ADD_BEG(node* head, int data){

    node* temp = new node;
    node* tp = head;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}




struct node* CREATE_FULL_list(node* head){
    int n,data,i;
    printf("Enter Number of NODE:-  ");
    cin >> n;

    if(n==0)return 0;

    printf("Enter data for node 1:- ");cin >> data;

head = ADD_empty(head,data);

for(int i=1;i<n;++i){
    cout << "Enter data for node " << i+1 << ":- ";
    cin >> data;
    head = ADD_END(head,data);
}
return head;
}

void print(node* head){
node* ptr = head;
cout << endl;
cout << "Here is your Full LIST " << endl;
while(ptr!=NULL){
        cout << " " <<  ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl << endl ;
}





int main(){

    node* head = NULL;
    head = CREATE_FULL_list(head);
    print(head);

    head = ADD_BEG(head, 1998);
    print(head);


    return 0;


}

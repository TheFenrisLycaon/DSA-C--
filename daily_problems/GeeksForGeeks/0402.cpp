#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void moveZeroes(struct Node **head);

void display(struct Node *head) {
    while (head != NULL) {
	    cout << head->data << " ";
	    head = head->next;
    }
    cout <<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q;
        struct Node *Head=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>q;
            push(&Head,q);
        }
        moveZeroes(&Head);
        display(Head);
    }
}

void moveZeroes(struct Node **head)
{
    int num =0;
    while(*head){
        if((*head)->data==0)*head = (*head)->next;
        else break;
        num++;
    }
    Node *curr = *head;
    while(curr && curr->next){
        if(curr->next->data==0){
            num++;
            curr->next = curr->next->next;
        }
        else curr = curr->next;
    }
    while(num--){
        Node *t = new Node(0);
        t->next = *head;
        *head = t;
    }
}
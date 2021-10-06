#include<bits/stdc++.h>
using namespace std;
#include"header.h"
using namespace doublyLinkedList;
int main()
{
    int entries;
    cout<<"How many nodes do you want to create?"<<" ";
    cin>>entries;
    struct node *head = DLLcreate(entries);
    DLLprint(head);
    cout<<endl;
    cout<<DLLlength(head)<<endl;
    int pos, data;
    cout<<"Enter Position and Value of the data you want to insert assuming 0 indexing: ";
    /**0 means insertion at the beginning and length means at the end of linkedlist*/
    cin>>pos>>data;
    DLLinsertNode(head, pos, data);
    DLLprint(head);
    cout<<DLLlength(head)<<endl;
    cout<<"Enter Position of data you want to delete: ";
    cin>>pos;
    DLLdeleteNodeByPos(head, pos);
    DLLprint(head);
    cout<<"Enter Value you want to delete from list: ";
    cin>>data;
    DLLdeleteNodeByVal(head, data);
    DLLprint(head);
    cout<<DLLlength(head)<<endl;
    DLLreverse(head);
    DLLprint(head);
    DLLprintReverse(head);
    return 0;
}


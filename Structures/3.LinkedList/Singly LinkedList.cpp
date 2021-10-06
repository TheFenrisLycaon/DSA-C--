#include<bits/stdc++.h>
using namespace std;
#include"header.h"
using namespace singlyLinkedList;
int main()
{
    int entries;
    cout<<"How many nodes do you want to create?"<<" ";
    cin>>entries;
    struct node *head = createSLL(entries);
    printSLL(head);
    cout<<lengthSLL(head)<<endl;
    int pos, data;
    cout<<"Enter Position and Value of the data you want to insert assuming 0 indexing: ";
    /**0 means insertion at the beginning and length means at the end of linkedlist*/
    cin>>pos>>data;
    insertNodeInSLL(head, pos, data);
    printSLL(head);
    cout<<lengthSLL(head)<<endl;
    cout<<"Enter Position of data you want to delete: ";
    cin>>pos;
    deleteNodeFromSLLByPos(head, pos);
    printSLL(head);
    cout<<"Enter Position of data you want to delete: ";
    cin>>pos;
    deleteNodeFromSLLByPos(head, pos);
    printSLL(head);
    cout<<"Enter Position of data you want to delete: ";
    cin>>pos;
    deleteNodeFromSLLByPos(head, pos);
    printSLL(head);
    cout<<"Enter Position of data you want to delete: ";
    cin>>pos;
    deleteNodeFromSLLByPos(head, pos);
    printSLL(head);
    cout<<"Enter Value you want to delete from list: ";
    cin>>data;
    deleteNodeFromSLLByVal(head, data);
    printSLL(head);
    cout<<"Enter Value you want to delete from list: ";
    cin>>data;
    deleteNodeFromSLLByVal(head, data);
    printSLL(head);
    cout<<"Enter Value you want to delete from list: ";
    cin>>data;
    deleteNodeFromSLLByVal(head, data);
    printSLL(head);
    cout<<"Enter Value you want to delete from list: ";
    cin>>data;
    deleteNodeFromSLLByVal(head, data);
    printSLL(head);
    cout<<lengthSLL(head)<<endl;
    reverseSLL(head);
    printSLL(head);
    printReverseSLL(head);
    return 0;
}

namespace singlyLinkedList
{
    struct node
    {
        int data;
        struct node *next;
    };

    struct node* createSLL(int entries){
        struct node *head = 0, *newnode, *temp;
        int i = 1;
        while(entries--)
        {
            newnode = new struct node;
            if(head == 0 && newnode != NULL)
            {
                head = temp = newnode;
            }else{
                temp->next = newnode;
                temp = newnode;
            }
            cout<<"Enter "<<"#"<<i<<" node data: "<<endl;
            cin>>temp->data;
            temp->next = NULL;
            i++;
        }
        return head;
    }

    void printSLL(struct node* head){
        struct node *temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void printReverseSLL(struct node* link){
        if(link){
            printReverseSLL(link->next);
            cout<<link->data<<" ";
            }
    }

    int lengthSLL(struct node *head){
        struct node *temp = head;
        int length = 0;
        while(temp){
            temp = temp->next;
            length++;
        }
        return length;
    }

    bool insertNodeInSLL(struct node* &head, int position, int value){
        int length = lengthSLL(head);
        if(position < 0 || position > length) return false;
        struct node *newnode, *temp = head;
        newnode = new struct node;
        newnode->data = value;
        newnode->next = NULL;
        if(newnode != NULL){//Validating allocation
            if(position == 0){//At beginning
                newnode->next = head;
                head = newnode;
            }else if(position == length){//At end
                    while(temp->next)
                        temp = temp->next;
                    temp->next = newnode;
            }else{
                for(int i=1; i<position; i++){
                    temp = temp->next;
                }
                newnode->next = temp->next;
                temp->next = newnode;
            }
            return true;
        }
        else return false;
    }

    bool deleteNodeFromSLLByPos(struct node* &head, int position){
    if(!head || position < 0 || position > (lengthSLL(head) - 1)) return false;
    struct node* temp = head, *nextNode = 0;
        if(position == 0){
            nextNode = head;
            head = head->next;
        }else if(position == lengthSLL(head) - 1){
            for(int i=1; i<position; i++)
                temp = temp->next;
            nextNode = temp->next;
            temp->next = NULL;
        }else{
            for(int i=1; i<position; i++)
                temp = temp->next;
            nextNode = temp->next;
            temp->next = temp->next->next;
        }
        //free((void*)(nextNode->next));
        //delete  nextNode->next;//Deallocating dynamic memory
        //delete nextNode;
        return true;
    }

    bool deleteNodeFromSLLByVal(struct node* &head, int value){
        if(!head) return false;
        struct node *temp = head, *prevTemp = head;
        int i=0;
        for(; i<lengthSLL(head);){
            if(temp->data == value){
                break;
            }
            prevTemp = temp;
            temp = temp->next;
            i++;
        }
        if(i == lengthSLL(head)) return false;
        if(i == 0){
            head = head->next;
        }else if(temp->next == 0){
            prevTemp->next = 0;
        }else{
             prevTemp->next = temp->next;
        }
        return true;
    }

    bool reverseSLL(struct node* &head){
        if(!head || !head->next) return false;
        struct node *temp = head, *headNext = head;
        while(headNext){
            if(temp == head){
                head = head->next;
                headNext = head->next;
                temp->next = NULL;
            }else{
                head->next = temp;
                temp = head;
                head = headNext;
                headNext = headNext->next;
            }
            if(head->next == NULL) head->next = temp;
        }
        return true;
    }

}

namespace doublyLinkedList
{
    struct node {
        int data;
        struct node *prev;
        struct node *next;
    };

    struct node* DLLcreate(int nodes){
        struct node *head = 0, *prevnode = 0, *newnode;
        int i = 1;
        while(nodes--){
            newnode = new struct node;
            if(head == 0){
                head = prevnode = newnode;
                newnode->prev = 0;
            }else{
                prevnode->next = newnode;
                newnode->prev = prevnode;
            }
            cout<<"Enter "<<"#"<<i<<" node data: "<<endl;
            cin>>newnode->data;
            newnode->next = 0;
            prevnode = newnode;
            i++;
        }
        return head;
    }

    void DLLprint(struct node *head){
        struct node *temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        } cout<<endl;
    }

    void DLLprintReverse(struct node* link){
        if(link){
            DLLprintReverse(link->next);
            cout<<link->data<<" ";
            }
    }

    int DLLlength(struct node *head){
        struct node *temp = head;
        int length = 1;//temp already pointing to head
        while(temp->next){
            length++;
            temp = temp->next;
        }
        return length;
    }

    bool DLLinsertNode(struct node* &head, int pos, int value){
        int length = DLLlength(head);
        if(pos < 0 || pos > length) return false;
        struct node *temp = head, *newnode;
        newnode = new struct node;
        newnode->data = value;
        newnode->next = newnode->prev = NULL;
        if(newnode){
            if(pos == 0){
                head->prev = newnode;
                newnode->next = head;
                head = newnode;
            }else if(pos == length){
                while(temp->next)
                    temp = temp->next;
                temp->next = newnode;
                newnode->prev = temp;
            }else{
                for(int i=1; i<pos; i++) temp = temp->next;
                newnode->prev = temp;
                newnode->next = temp->next;
                temp->next->prev = newnode;
                temp->next = newnode;
            }
        } else return false;
        return true;
    }

    bool DLLdeleteNodeByPos(struct node* &head, int pos){
        if(!head || pos < 0 || pos > (DLLlength(head) - 1)) return false;
        struct node *temp = head;
        if(pos == 0){
            head = head->next;
            head->prev = 0;
            temp->next = 0;
        }else if(pos == DLLlength(head) - 1){
            for(int i=1; i<pos; i++) temp = temp->next;
            temp->next->prev = 0;
            temp->next = 0;
        }else{
            for(int i=1; i<pos; i++) temp = temp->next;
            temp->next->next->prev = temp;
            temp->next = temp->next->next;
        }
        return true;
    }

    bool DLLdeleteNodeByVal(struct node* &head, int value){
        if(!head) return false;
        struct node *temp = head;
        int i = 0;
        for(; i<DLLlength(head);){
            if(temp->data == value) break;
            temp = temp->next;
            i++;
        }
        if(i == DLLlength(head)) return false;
        if(i == 0){
            head = head->next;
            head->prev = 0;
            temp->prev = temp->next = 0;
        }else if(!temp->next){
            temp->prev->next = 0;
            temp->prev = temp->next = 0;
        }else{
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }
        return true;
    }

    bool DLLreverse(struct node * &head){
        if(!head || !head->next) return false;
        struct node* temp = head, *reverseLink;
        while(temp){
            reverseLink = temp->prev;
            temp->prev = temp->next;
            temp->next = reverseLink;
            if(temp->prev) temp = temp->prev;
            else{
                head = temp;
                temp = temp->prev;
            }
        }
        return true;
    }
}















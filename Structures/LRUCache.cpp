// A data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

// SET x y : sets the value of the key x with value y
// GET x : gets the key of x if present else returns -1.

// The LRUCache class has two methods get() and set() which are defined as follows.

// * get(key)   : returns the value of the key if it already exists in the cache otherwise returns -1.

// * set(key, value) : if the key is already present, update its value. If not present, add the key-value pair to the cache.
//   If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.

// * In the constructor of the class the capacity of the cache should be intitialized.

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{

    public:
    struct node{
    int data;
    int key;
    node* next;
    node* pre;
    node(int k, int val){
        key=k;
        data=val;
        next=NULL;
        pre=NULL;
    }
  };

 node* head=new node(-1,-1);
 node* tail=new node(-1,-1);

 int c;
 map<int,node*>m;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
       c=cap;
       head->next=tail;
       tail->pre=head;
    }

    void addnode(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        newnode->pre=head;
        head->next=newnode;
        temp->pre=newnode;
    }

    void deletenode(node* delnode){
        node* delpre=delnode->pre;
        node* delnext=delnode->next;
        delpre->next=delnext;
        delnext->pre=delpre;
    }
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(m.find(key)!=m.end()){
            node* temp=m[key];
            int res=temp->data;
            m.erase(key);
            deletenode(temp);
            addnode(temp);
            m[key]=head->next;
            return res;
        }
        return -1;

    }

    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here  
         if(m.find(key)!=m.end()){
            node* temp=m[key];
            m.erase(key);
            deletenode(temp);
        }
        if(m.size()==c){
            m.erase(tail->pre->key);
            deletenode(tail->pre);
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
};

int main()
{
        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    return 0;
}

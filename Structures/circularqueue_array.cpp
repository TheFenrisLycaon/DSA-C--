#include<iostream>
using namespace std;
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N == front){
        cout<<"OverFlow"<<endl;
    }
    else{
        rear = (rear+1)%N;
        queue[rear]=x;
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"UnderFlow"<<endl;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        cout<<"Deleted: "<<queue[front]<<endl;
        front=(front+1)%N;
    }
}

void display(){
    if(front==-1 && rear==-1){
        cout<<"Empty"<<endl;
    }
    for(int i=front; i!=rear; i=(i+1)%N){
        cout<<queue[i]<<endl;
    }
    cout<<queue[rear];
}

int main(){
    for(int i=2; i<12; i+=2){
        enqueue(i);
    }
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(20);
    display();
}
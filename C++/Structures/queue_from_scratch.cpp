#include<bits/stdc++.h>
using namespace std;

int A[10];
int front = -1;
int rear = -1;

bool isFull(){
  if(rear == 10)
    return true;
  else
    return false;
}

bool isEmpty(){
  if(front == -1 && rear == -1)
    return true;
  else
    return false;
}

void printQueue(int data){
  for(int i = front; i <= rear; i++)
    cout << A[i] << " ";
  cout << endl;
}

void enqueue(int data){
  if(isFull()){
    cout << "Queue is full" << endl;
  }
  else if(isEmpty()){
  front = 0;
  rear = 0;
  A[rear] = data;
  }
  else{
    rear++;
    A[rear] = data;
  }
}

void dequeue(){
  if(isEmpty()){
    cout << "Queue is empty" << endl;
  }
  else if(front == rear){
    front = -1;
    rear = -1;
  }
  else{
    front++;
  }
}

int main(){
  enqueue(10);
  enqueue(20);
  enqueue(30);
  printQueue();
  dequeue();
  dequeue();
  printQueue();
  cout << isFull() << endl;
  dequeue();
  cout << isEmpty() << endl;
  return 0;
}

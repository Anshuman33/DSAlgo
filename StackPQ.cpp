#include<iostream>
#include"PQueue.cpp"
using namespace std;

#define MAX_SIZE 10

template<typename T>
class Stack{
    PQueue<T> * q;
    int pCounter;
    public:
    Stack(){
        q = new PQueue<T>();
        pCounter = 0;
    }

    bool isFull(){
        if(q->heapSize == MAX_SIZE)
            return true;
        else
            return false;
    }

    bool isEmpty(){
        if(q->heapSize == 0)
            return true;
        return false;
    }
    void push(T el){
        if(!isFull()){
            q->heapInsert(el,pCounter++);
        }
    }
    T pop(){
        if(!isEmpty()){
            return q->heapExtractMax();
            pCounter--;
        }
    }

};
int main(){
    
    Stack<int> stck;
    stck.push(6);
    stck.push(4);
    stck.push(3);
    stck.push(1);
    stck.push(8);
    cout<<"\nPopped:"<<stck.pop();
    cout<<"\nPopped:"<<stck.pop();
    cout<<"\nPopped:"<<stck.pop();
    cout<<"\nPopped:"<<stck.pop();
    cout<<"\nPopped:"<<stck.pop();
    cout<<"\nPopped:"<<stck.pop();
    



}
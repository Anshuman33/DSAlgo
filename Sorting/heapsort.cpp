#include<iostream>
using namespace std;

#define MAX_SIZE 50

void printArr(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}

int left(int i){
        return 2*(i)+1;
}

int right(int i){
        return 2*(i+1);
}

int parent(int i){
    if(i%2==0){
        return i/2-1;
    }
    else{
        return i/2;
    }
}

int exchange(int A[],int i,int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void maxHeapify(int A[],int heapSize,int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l<heapSize && A[l]>A[i])
        largest = l;
    if(r<heapSize && A[r]>A[largest])
        largest = r;
    if(largest!=i){
        exchange(A,i,largest);
        maxHeapify(A,heapSize,largest);
    }
}

void buildMaxHeap(int A[],int heapSize){
    for(int i=heapSize/2-1;i>=0;i--){
        maxHeapify(A,heapSize,i);
    }
} 

void heapSort(int A[],int n){
    buildMaxHeap(A,n);
    int heapSize = n;
    for(int i=n-1;i>=1;i--){
        exchange(A,0,i);
        cout<<"\n";
        printArr(A,n);
        heapSize--;
        maxHeapify(A,heapSize,0);
    }
}


int main(){
    int A[MAX_SIZE];
    int heapSize;

    cin>>heapSize;
    for(int i=0;i<heapSize;i++){
        cin>>A[i];
    }

    cout<<"\nInput Arr:";printArr(A,heapSize);
    heapSort(A,heapSize);
    //buildMaxHeap(A,heapSize);
    cout<<"\nSorted Arr:";printArr(A,heapSize);




}
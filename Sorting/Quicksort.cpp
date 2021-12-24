#include<iostream>
using namespace std;
#define MAX_SIZE 50 

void exchange(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}

int partition(int A[],int low,int high){
    int i = low-1;
    int x = A[high];
 
    for(int j=low;j<=high-1;j++){
        if(A[j]<=x){
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }    
    int temp = A[i+1];
    A[i+1] = A[high];
    A[high] = temp;
    return i+1;
}

void quickSort(int A[],int low,int high){
    if(low<high){
        int partitionIndex = partition(A,low,high);
        quickSort(A,low,partitionIndex-1);
        quickSort(A,partitionIndex+1,high);
    }
}

void printArr(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}
int main(){
    int n,A[MAX_SIZE];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    quickSort(A,0,n-1);
    printArr(A,n);
    

}
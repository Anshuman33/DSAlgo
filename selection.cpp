#include<iostream>
using namespace std;

void insertionSort(int A[],int n){
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

}
int main(){
    int n;
    int A[50];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    insertionSort(A,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}
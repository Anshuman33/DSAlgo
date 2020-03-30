#include<iostream>
using namespace std;

void printArr(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}
void countSort(int A[],int B[],int max,int n,int digits[]){
    int C[max+1] = {0};
    for(int j=0;j<n;j++){
        C[digits[j]]+=1;
    }
    for(int i=1;i<max+1;i++){
        C[i] = C[i] + C[i-1];
    }
    
    for(int i=n-1;i>=0;i--){
        C[digits[i]]-=1;
        B[C[digits[i]]] = A[i];
        
    }
}
int ithDigit(int n,int i){
    while(i>0){
        n /= 10;
        i--;
    }
    return n%10;
}

void radixSort(int A[],int n,int d){
    int B[n]={0};
    for(int i=0;i<d;i++){
        int digits[n] = {0};
        for(int j=0;j<n;j++){
            digits[j] = ithDigit(A[j],i); 
        }
        countSort(A,B,9,10,digits);
        for(int i=0;i<n;i++){
            A[i] = B[i];
        }
    }
    
}
int main(){
    int B[10] = {0};
    int A[10] =  {94,42,70,31,35,27,33,12,66,74};
    radixSort(A,10,2);
    printArr(A,10);
    cout<<"\n";
    
}
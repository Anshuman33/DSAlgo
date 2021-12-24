#include<iostream>
using namespace std;
void printArr(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}
void merge(int A[],int first,int mid,int last){
    int n1=mid-first+1;
    int n2=last-mid;
    //int left[n1+1],right[n2+1];
    
    /*for(int i=0;i<n1;i++){
        left[i] = A[first+i];  
    }
    for(int j=0;j<n2;j++){
        right[j] = A[mid+j+1];
    }
    
    left[n1] = INT32_MAX;
    right[n2] = INT32_MAX;
    cout<<"\nLeft:";
    printArr(left,n1+1);
    cout<<"\nRight:";
    printArr(right,n2+1);
    int i=0,j=0;
    for(int k=first;k<=last;k++){
        if(left[i]<right[j]){
            A[k] = left[i];
            i++;
        }
        else{
            A[k] = right[j];
            j++;
        }
    }*/
}
void mergeSort(int A[],int first,int last){
    if(first>last)
        return;
    int m = (first+last)/2;
    mergeSort(A,first,m);
    mergeSort(A,m+1,last);
    merge(A,first,m,last);  
}


int main(){

    int A[] = {6,3,9,1,7,4};
    int n = 6;
    mergeSort(A,0,4);
    

}
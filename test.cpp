#include<iostream>
using namespace std;
int findPos(int A[],int p,int r){
    if(p<=r){
        int m = (p+r)/2;

        cout<<"\n----DEBUG----";
        cout<<"\nm="<<m;
        cout<<"\nA[m]="<<A[m];
        cout<<"\nA[m+1]="<<A[m+1];
        if(A[m]==1){
            if(A[m+1]==0)
                return m;
            else{
                return findPos(A,m+1,r);
            }
        }
        else{
            return findPos(A,p,m-1);
        } 
    }
    return -1;
}
int main(){
    int A[] = {1,1,1,1,0,0,0,0,0,0};
    cout<<findPos(A,0,9);
}
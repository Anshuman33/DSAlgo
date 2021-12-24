#include<iostream>
#include<vector>
#include "../Utils/PrintUtils.h"
using namespace std;

/*
    Given : An unsorted array which consists of atmost 2 unique characters.
    Aim : To write a function that sorts this array.
    Observations about the problem :- 
        * Using any comparison based sorting algorithm would take atleast O(nlogn) time.
        * We know beforehand that there are only 2 unique characters in the array.
        * The above information can be used to develop a faster algorithm.
*/

void sortTwoElArr_1(vector<int>& arr){
/*
    Approach 1
    ----------
    Description: 
    - Let the smaller element be X and larger element be Y. 
    - We first find the first index of the larger element Y, say i.
    - We try to maintain two windows, one consisting of the Xs and one with Ys only.
    - Using index j we loop through all the elements after i. For each value of j there can be two possibilities:-
        1. If A[j]=Y, we simply increment j and the Ys window size will increase.
        2. If A[j]=X, we swap A[i] with A[j], and increment both i and j. In other words, we swap the A[j]
            with the first element in window. This way the A[j] is inserted in the Xs window and X-window size is increased.
            There is no change in Ys window size, but the window is shifted one place to the right.
    - After j reaches the end of array, the entire X-window will be on left and Y-window on the right part of the array (XXX...XY...YYYY). 
    
    This way the algorithm successfully sorts the array in one pass.  

    Time complexity: O(n) Space Complexity: O(1)
*/
    int i = 0, j = 1;

    // Find the first index of the element different from the first element.
    while(j < arr.size() && arr[i] == arr[j])
        j++;
    
    // If all the elements are same as first element, return.
    if(j == arr.size())
        return;

    else if(arr[i] < arr[j]){
        // If the ith element is less than jth element, this means that
        // all elements before jth index are are of the smaller value.
        // Thus assign j to i and then increment j;
        i = j;
        j++;
    }
    // After the above steps i will point to first index of the larger element.
    // The window between i to j-1 will contain all the occurences of the larger element discovered yet.

    // Loop until j is less than size of array.
    // If at jth index smaller element is found, swap the ith and jth element and increment i.
    while(j < arr.size()){
        if(arr[i] != arr[j]){
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
}



// Driver code
int main(){
    int t, n;
    cin >> t;
    while(t > 0){
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n;i++){
            cin >> arr[i];
        }
        sortTwoElArr_1(arr);
        printArray(arr);
        cout << "\n";
        t--;
    }
}


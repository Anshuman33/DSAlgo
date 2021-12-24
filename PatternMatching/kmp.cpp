#include<iostream>
#include<bits/stdc++.h>

using namespace std;
/*
    Implementation of Knuth-Morris-Pratt (KMP) algorithm for pattern matching.
*/
vector<int> computeLPSArray(string pattern){
    int M = pattern.size();
    int i=1, len = 0;
    vector<int> lps(M, 0);

    lps[0] = 0;
    while(i < M){
        if(pattern[i] == pattern[len]){
            lps[i] = len + 1;
            i++;
            len++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }       
        }
    }
    return lps;
}

vector<int> patternSearch(string str, string pattern){
    vector<int> lps = computeLPSArray(pattern);
    int i=0, j=0, n = str.size(), m = pattern.size();
    vector<int> indices;
    while(i < n){
        if(str[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }

        if(j == m){
            indices.push_back(i-j);
            j = lps[j-1];
        }
    }
    return indices;
}
int main(){

    string mainStr, pattern;
    cin >> mainStr;
    cin >> pattern;
    vector<int> indices = patternSearch(mainStr, pattern);
    if(indices.size() == 0){
        cout << "\nPattern not found.";
    }
    else{
        cout << "\nPattern found at "<< indices.size() << " indices ";
        for(int i=0;i<indices.size();i++){
            cout << indices[i] << " ";
        }    
    }
    
}


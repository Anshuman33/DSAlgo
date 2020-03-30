#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Graph{
    public:
    int adj[10][10];
    int n;
    int d[10];
    int pi[10];
    Graph(int n){
        this->n = n;
    }
    void inputAdjMat(){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>adj[i][j];
            }
        }
    }

    void bfsTraverse(int s){
        char color[n];
        for(int u=0;u<n;u++){
            d[u] = INT32_MAX;
            pi[u] = -1;
            color[u] = 'w';
        }

        d[s] = 0;
        color[s] = 'g';
        pi[s] = -1;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout<<"\nVisited vertex:"<<u;
            for(int v=0;v<n;v++){
                if(adj[u][v] > 0){
                    if(color[v]=='w'){
                        q.push(v);
                        d[v] = d[u] + 1;
                        pi[v] = u; 
                        color[v] = 'g';
                    }
                }
            }
            color[u] = 'b';
        }
    }
};
int main(){
    int n;
    cin>>n;
    Graph g(n);
    g.inputAdjMat();
    g.bfsTraverse(3);

}

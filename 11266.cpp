#include <bits/stdc++.h>

using namespace std;

int o;
bool *djj;

int dfs(int id, bool isRoot, int parent, vector<int> &order, vector<vector<int> > &graph){
    order[id]=o;
    o++;
    int ret=order[id];
    int child=0;
    for (int i=0; i<graph[id].size(); i++){
        int now=graph[id][i];
        if (now==parent){
            continue;
        }
        if (order[now]==0){
            child++;
            int low=dfs(now, false, id, order, graph);
            if (!isRoot && low>=order[id]){
                djj[id]=true;
            }
            ret=min(ret, low);
        }
        else{
            ret=min(ret, order[now]);
        }
    }
    if (isRoot && child>=2){
        djj[id]=true;
    }   
    return ret;
}


int main(){
    int V, E;
    int A, B;
    cin>>V>>E;
    vector<vector<int> > graph(V+1);
    vector<int> order(V+1);
    djj=new bool[V+1];
    for (int i=0; i<E; i++){
        cin>>A>>B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    o=1;
    for (int i=1; i<V+1; i++){
        if (order[i]==0){
            dfs(i,true,0,order,graph);
        }
    }
    string s="";
    int cnt=0;
    for (int i=1; i<=V; i++){
        if (djj[i]){
            cnt++;
            s+=to_string(i)+" ";
        }
    }
    cout<<cnt<<"\n";
    cout<<s;
    delete[] djj;
}
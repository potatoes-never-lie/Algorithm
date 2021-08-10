#include <bits/stdc++.h>

using namespace std;

int **parent;


void dfs(vector<vector<int> > &graph, vector<int> &depth, int id, int cnt){
    depth[id]=cnt;
    for (int i=0; i<graph[id].size(); i++){
        int now=graph[id][i];
        if (depth[now]==0){
            dfs(graph, depth, now, cnt+1);
            parent[0][now]=id;
        }
    }
}

int lca(int a, int b, vector<int> &depth, int K){
    if (depth[a] < depth[b]){
        int temp=a;
        a=b;
        b=temp;
    }       //depth(a)>=depth(b)
    for (int i=K-1; i>=0; i--){     //depth 맞추기
        if (pow(2,i)<=depth[a]-depth[b]){
            a=parent[i][a];
        }
    }
    if (a==b){
        return a;
    }
    for (int i=K-1; i>=0; i--){
        if (parent[i][a]!=parent[i][b]){        //조상 다르면 점프하며 올려줌
            a=parent[i][a];
            b=parent[i][b];
        }
    }
    return parent[0][a];
}


int main(){
    int N, M, a, b;
    vector<int> depth(N+1);
    vector<int> ans;
    int K=0;
    int s=1;
    cin>>N;
    vector<vector<int> > graph(N+1);
    while (s<=N){
        s*=2;
        K+=1;
    }
    parent=new int*[K];
    for (int i=0; i<K; i++){
        parent[i]=new int[N+1];
    }
    for (int i=0; i<N-1; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(graph, depth, 1, 1);
    for (int i=1; i<K; i++){            //fill parents
        for (int j=1; j<=N; j++){
            parent[i][j]=parent[i-1][parent[i-1][j]];
        }
    }
    cin>>M;
    for (int i=0; i<M; i++){
        cin>>a>>b;
        ans.push_back(lca(a,b,depth,K));
    }
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
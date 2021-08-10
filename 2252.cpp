#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M, a, b;
    cin>>N>>M;
    vector<int> v(N+1);
    vector<vector<int> > edge(N+1);
    queue<int> q;
    vector<int> ans;
    for (int i=0; i<M; i++){
        cin>>a>>b;
        v[b]++;
        edge[a].push_back(b);
    }
    for (int i=1; i<=N; i++){
        if (v[i]==0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int now=q.front();
        ans.push_back(now);
        q.pop();
        for (int i=0; i<edge[now].size(); i++){
            int x=edge[now][i];
            v[x]--;
            if (v[x]==0){
                q.push(x);
            }
        }
    }
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
}
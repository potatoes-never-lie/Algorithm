#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, c, earliest, end;
    cin>>N;
    vector<int> indegree(N+1);
    vector<vector<int> > neighbors(N+1);
    vector<vector<int> > edges(N+1);
    vector<long> cost(N+1);
    queue<int> q;
    for (int i=1; i<N+1; i++){
        cin>>c;
        cost[i]=c;
        cin>>earliest;
        while (earliest!=-1){
            indegree[i]++;
            edges[earliest].push_back(i);
            neighbors[i].push_back(earliest);
            cin>>earliest;
        }
    }
    for (int i=1; i<N+1; i++){
        if (indegree[i]==0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int now=q.front();
        q.pop();
        for (int i=0; i<edges[now].size(); i++){
            int x=edges[now][i];
            indegree[x]--;
            long maxVal=0;
            if (indegree[x]==0){        //우선순위 있는 애들 다 건설된 경우
                q.push(x);
                for (int j=0; j<neighbors[x].size(); j++){
                    maxVal=max(maxVal, cost[neighbors[x][j]]);
                }
                cost[x]+=maxVal;
            }
        }
    }
    for (int i=1; i<N+1; i++){
        cout<<cost[i]<<"\n";
    }
}
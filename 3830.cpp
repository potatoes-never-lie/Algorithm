#include <bits/stdc++.h>

using namespace std;

int find(int a, vector<int> &parents){
    if (parents[a]==a){
        return a;
    }
    int pId=find(parents[a], parents); //root가 아닌 경우 root를 찾아서
    dist[a]+=dist[pId]      //
    return parents[a]=pId; 
}

void union_(int a, int b, vector<int> &parents, long *dist, long w){
    int pa=find(parents[a], parents);
    int pb=find(parents[b], parents);
    if (pa<pb){
        parents[pb]=pa;
        dist[b]=dist[a]+w;
    }
    else{
        parents[pa]=pb;
        dist[a]=dist[b]-w;
    }
}


int main(){
    int N=2, M=2;
    char c;
    int a,b,w;
    vector<string> ans;
    while (N!=0 || M!=0){
        cin>>N>>M;
        vector<int> parents(N+1);
        long dist[N+1];     //parents 와의 무게 차이
        for (int i=1; i<=N; i++){
            parents[i]=i;
            dist[i]=0;
        }
        for (int i=0; i<M; i++){
            cin>>c;
            if (c=='!'){        //무게 잼(union)
                cin>>a>>b>>w;
                union_(a,b,parents,dist,w);
            }
            else{
                cin>>a>>b;
                //다른 그룹이면 unknown
                if (find(a, parents)!=find(b, parents)){
                    ans.push_back("UNKNOWN");
                }
                else{
                //아니면 출력
                    ans.push_back(to_string(dist[b]-dist[a]));
                }
            }
        }
    }
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
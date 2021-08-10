#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;

class Edge{
    public:
        int start;
        int end;
        long cost;
    Edge(int start, int end, long cost){
        this->start=start;
        this->end=end;
        this->cost=cost;
    }
};

int main(){
    int N, M, A, B;
    long C;
    cin>>N>>M;
    vector<Edge> eList;
    long dist[N+1];
    bool flag=false;
    dist[1]=0;
    for (int i=0; i<M; i++){
        cin>>A>>B>>C;
        eList.push_back(Edge(A,B,C));
    }
    for (int i=2; i<=N; i++){
        dist[i]=MAX;
    }
    for (int i=1; i<=N; i++){      //V 번 모든 간선 탐색
        for (int j=0; j<eList.size(); j++){
            int start=eList[j].start;
            int end=eList[j].end;
            int cost=eList[j].cost;
            if (dist[start]==MAX){
                continue;
            }
            int temp=dist[end];
            dist[end]=min(dist[start]+cost, dist[end]);
            if (i==N && temp!=dist[end]){       //N번째 갱신이 되면
                flag=true;
                break;
            }
        }
    }

    if (flag){
        cout<<"-1"<<"\n";
    }
    else{
        for (int i=2; i<=N; i++){
            if (dist[i]==MAX){
                cout<<"-1"<<"\n";
            }
            else{
                cout<<dist[i]<<"\n";
            }
        }
    }
    return 0;
}
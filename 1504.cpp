#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

class Node{
    public:
        int target;
        int cost;
        Node(int target, int cost){
            this->target=target;
            this->cost=cost;
        }
};

struct cmp{
    bool operator()(const Node &a, const Node &b){      //최소 힙을 위한 비교자
        return a.cost>b.cost;
    }
};

int main(){
    int N, E;
    cin>>N>>E;
    vector<vector<Node> > adjList(N+1);
    priority_queue<Node, vector<Node>, cmp> pq;
    for (int i=0; i<E; i++){

    }

}
#include <bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(pair<long long,long long> a, pair<long long,long long> b){  //가격별 내림차순
        return a.second < b.second;
    }
};

bool comp(pair<long long,long long> a, pair<long long,long long> b){    //무게순 정렬(오름차순)
    return a.first < b.first;
}

int main(){
    long long N,K;
    long long M,V,C;
    long long ans=0;
    cin>>N>>K;
    vector<pair<long long, long long> > jewels;
    vector<long long> bags;
    priority_queue<pair<long long,long long>, vector<pair<long long,long long> >, compare> pq;
    for (long long i=0; i<N; i++){
        cin>>M>>V;
        jewels.push_back(make_pair(M,V));
    }
    for (long long i=0; i<K; i++){
        cin>>C;
        bags.push_back(C);
    }
    sort(bags.begin(), bags.end());
    sort(jewels.begin(), jewels.end(), comp);
    long long count=0;
    for (long long i=0; i<K; i++){
        while(true){
            if (count>=N || jewels[count].first>bags[i]){       //무게 넘치면
                break;
            }
            pq.push(jewels[count]);
            count++;
        }
        if (!pq.empty()){
            ans+=pq.top().second;
            pq.pop();
        }
    }
    cout<<ans<<endl;
}
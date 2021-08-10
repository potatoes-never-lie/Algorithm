#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll *tree;

/* 데이터가 중간에 바뀔 경우는 index tree 쓰는거 고려해보기. */


void update(ll left, ll right, ll node, ll target, ll diff){
    ll mid;
    if (left<=target && target<=right){
        tree[node]+=diff;
        if (left!=right){
            mid=(left+right)/2;
            update(left, mid, node*2, target, diff);
            update(mid+1, right, node*2+1, target, diff);
        }
    }
}

ll query(ll left, ll right, ll node, ll count){
    if (left==right){
        return left;
    }
    ll mid=(left+right)/2;
    if (tree[node*2]>=count){       //왼쪽으로
        return query(left, mid, node*2, count);
    }
    else{                           //오른쪽으로
        return query(mid+1, right, node*2+1, count-tree[node*2]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    ll n, A, S, ans;
    ll B,C;
    vector<int> answers;
    cin>>n;
    S=1;
    while (S<1000000){
        S*=2;
    }
    tree=new ll[2*S];
    for (int i=0; i<2*S; i++){
        tree[i]=0;
    }
    for (int i=0; i<n; i++){
        cin>>A;
        if (A==2){              //update
            cin>>B>>C;
            update(1,S,1,B,C);
        }
        else{                   //query & update
            cin>>B;
            ans=query(1,S,1,B);
            answers.push_back(ans);
            update(1,S,1,ans,-1);
        }
    }

   for (int i=0; i<answers.size(); i++){
       cout<<answers[i]<<"\n";
   }

   delete[] tree;
}
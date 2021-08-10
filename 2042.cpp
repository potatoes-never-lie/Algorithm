#include <bits/stdc++.h>
using namespace std;

long* tree;

void initBU(long S){
    for (long i=S-1; i>=1; i--){
        tree[i]=tree[i*2]+tree[i*2+1];
    }
}

long query(long left, long right, long node, long queryLeft, long queryRight){
    long mid;
    if (queryLeft<=left && right<=queryRight){
        return tree[node];
    }
    else if (queryRight<left || queryLeft>right){ 
        return 0;
    }
    else{
        mid=(left+right)/2;
        return query(left,mid,node*2,queryLeft,queryRight)+query(mid+1, right, node*2+1, queryLeft, queryRight);
    }
}

void update(long left, long right, long node, long target, long diff){
    long mid;
    if (left<=target && target<=right){
        tree[node]+=diff;
        if (left!=right){
            mid=(left+right)/2;
            update(left, mid, node*2, target, diff);
            update(mid+1, right, node*2+1, target, diff);
        }
    }
}

void updateBU(long target, long value, long S){
    long node=S+target-1;
    tree[node]=value;
    while (node>=1){
        node/=2;
        tree[node]=tree[node*2+1]+tree[node*2];
    }
}

long queryBU(long queryLeft, long queryRight, long S){
    long nodeLeft=(S+queryLeft)-1;
    long nodeRight=(S+queryRight)-1;
    long sum=0;
    while (nodeLeft <= nodeRight){
        if (nodeLeft%2!=0){
            sum+=tree[nodeLeft++];
        }
        if (nodeRight%2==0){
            sum+=tree[nodeRight--];
        }
        nodeLeft/=2;
        nodeRight/=2;
    }
    return sum;
}

int main(){
    long N,M,K;
    long a,b,c;
    long S=1;
    long input;
    long temp, ans;
    cin>>N>>M>>K;
    while (S<N){
        S*=2;
    }
    tree=new long[S*2];
    tree[0]=0;
    for (long i=0; i<N; i++){
        cin>>temp;
        tree[S+i]=temp;
    }
    initBU(S);
    for (long i=S+N; i<S*2; i++){
        tree[i]=0;
    }
    for (long i=0; i<M+K; i++){
        cin>>a>>b>>c;
        if (a==1){      //update
            update(1,S,1,b,c-tree[S+b-1]);
        }
        else if (a==2){ //query 
            ans=query(1,S,1,b,c);
            cout<<ans<<endl;
        }
    }
    delete [] tree;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M, item;
    int left, right;
    int sum=0;
    int ans=0;
    cin>>N>>M;
    int A[N+1];
    for (int i=1; i<N+1; i++){
        cin>>item;
        A[i]=item;
    }
    left=1;
    right=1;
    sum=A[0];
    while (true){
        if (sum>M){
            sum-=A[left++];
        }
        else if (sum==M){
             sum-=A[left++];
             ans++;
        }
        else{
            sum+=A[++right];
        }
        if (right==N+1){
            break;
        }
    }
    cout<<ans<<endl;

}
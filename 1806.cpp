#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M, item;
    int left, right;
    int min=100000;
    bool flag=false;
    int sum;
    cin>>N>>M;
    int A[N+1];
    for (int i=1; i<N+1; i++){
        cin>>item;
        A[i]=item;
    }
    left=1;
    right=1;
    sum=A[1];
    while (true){
        if (sum>=M){
            if (right-left+1 < min){
                flag=true;
                min=right-left+1;
            }
            sum-=A[left++];
        }
        else{
            sum+=A[++right];
        }
        if (right==N+1){
            break;
        }
    }
    if (flag){
        cout<<min<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
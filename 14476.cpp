#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){          //gcd(a,b)==gcd(b,a%b) stop when a%b==0
    while (b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    int temp;
    int ans=-1;
    int K=0;
    int N, num;
    cin>>N;
    int nums[N];
    int LR[N];
    int RL[N];
    for (int i=0; i<N; i++){
        cin>>num;
        nums[i]=num;
    }
    LR[0]=nums[0];
    for (int i=1; i<N; i++){
        LR[i]=gcd(LR[i-1],nums[i]);
    }
    RL[N-1]=nums[N-1];
    for (int i=N-2; i>=0; i--){
        RL[i]=gcd(RL[i+1],nums[i]);
    }
    for (int i=0; i<N; i++){
        if (i>=1 && i<=N-2){
            temp=gcd(LR[i-1], RL[i+1]);
        }
        else if (i==0){
            temp=RL[1];
        }
        else{
            temp=LR[i-1];
        }
        if (nums[i]%temp!=0){
            if (ans<temp){
                ans=temp;
                K=nums[i];
            }
        }
    }
    if (ans!=-1){
        cout<<ans<<" "<<K;
    }
    else{
        cout<<ans;
    }
}
#include <bits/stdc++.h>

using namespace std;

bool desc(long a, long b){
    return a>b;
}

int main(void){
    long T,n,m, val, rest;
    long a, b;
    long ans=0;
    cin>>T>>n;
    long A[n];
    long subA[n*(n+1)/2];
    long sum, cnt=0;
    for (long i=0; i<n; i++){
        cin>>val;
        A[i]=val;
    }
    cin>>m;
    long B[m];
    long subB[m*(m+1)/2];
    for (long i=0; i<m; i++){
        cin>>val;
        B[i]=val;
    }
    for (long i=0; i<n; i++){
        sum=0;
        for (long j=i; j<n; j++){
            sum+=A[j];
            subA[cnt++]=sum;
        }
    }
    cnt=0;
    for (long i=0; i<m; i++){
        sum=0;
        for (long j=i; j<m; j++){
            sum+=B[j];
            subB[cnt++]=sum;
        }
    }
    sort(subA, subA+(n*(n+1)/2));
    sort(subB, subB+(m*(m+1)/2), desc);
    a=0; 
    b=0;
    while (a<n*(n+1)/2 && b<m*(m+1)/2){
        rest=T-subA[a];
        if (rest<subB[b]){
            b++;
        }
        else if (rest==subB[b]){
            long sames_A=0;
            long cur_A=subA[a];
            while (a<n*(n+1)/2 && subA[a]==cur_A){
                sames_A++;
                a++;
            }
            long sames_B=0;
            long cur_B=subB[b];
            while (b<m*(m+1)/2 && subB[b]==cur_B){
                sames_B++;
                b++;
            }
            ans+=(sames_A*sames_B);
        }
        else{
            a++;
        }
    }
    cout<<ans<<endl;
}
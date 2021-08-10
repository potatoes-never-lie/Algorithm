#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;

long EG[3];

void extendedGcd(long a, long b){
    long s0=1, t0=0, r0=a;
    long s1=0, t1=1, r1=b;
    long temp;

    while(r1!=0){
        long q=r0/r1;
        temp=r0-q*r1;
        r0=r1;
        r1=temp;

        temp=s0-q*s1;
        s0=s1;
        s1=temp;

        temp=t0-q*t1;
        t0=t1;
        t1=temp;
    }
    EG[0]=s0; EG[1]=t0; EG[2]=r0;
}

int main(){
    int t;
    long A,B;       //A: 참가인원수, B: 한봉지사탕수
    long x,y,k;
    cin>>t;
    for (int i=0; i<t; i++){
        cin>>A>>B;
        extendedGcd(A, B);
        if (EG[2]!=1){
            cout<<"IMPOSSIBLE\n";
        }
        else{
            long kFromY=ceil((double)EG[1]/(double)A)-1;
            long kFromX=ceil((double)-1*EG[0]/(double)B)-1;
            k=min(kFromX, kFromY);
            y=EG[1]-A*k;  
            if (y>MAX){
                cout<<"IMPOSSIBLE\n";
                continue;
            }
            cout<<y<<"\n";
        }
    }

}
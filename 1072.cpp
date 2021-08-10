#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void){
    ll X, Y, Z; 
    ll left, right, mid,victory;
    cin>>X>>Y;
    Z=(ll)(100*(double)Y/(double)X);
    left=1; 
    right=X;
    if (Z>=99){     //99이상부터는 최대 X번 해도 승률이 변하지 x
        cout<<-1<<endl;
    }
    else{
        while (left<right){
            mid=(left+right)/2;
            victory=(ll)(100*(double)(Y+mid)/(double)(X+mid));
            if (victory==Z){        //victory가 줄어드는 케이스는 존재하지 않음.
                left=mid+1;
            }
            else{       //victory가 증가 so mid 값 살리자.(mid 값 따로 저장 후 right=mid-1 해줘도 Ok.)
                right=mid;
            }
        }
        cout<<right<<endl;
    }
}

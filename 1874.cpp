#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n;
    int tindex=0;
    int cindex=0;
    stack<int> s;
    vector<string> v;
    cin>>n;
    int *tarr=new int[n];       //target array
    int *carr=new int[n];       //container array
    for (int i=0; i<n; i++){
        cin>>tarr[i];
        carr[i]=i+1;
    }
    while (tindex<n){
        if (s.empty() || tarr[tindex]>s.top()){
            while (carr[cindex]<=tarr[tindex] && cindex<n){
                s.push(carr[cindex]);
                v.push_back("+");
                cindex++;
            }
            s.pop();
            v.push_back("-");
        }
        else if (tarr[tindex]==s.top()){
            s.pop();
            v.push_back("-");
        }
        else{
            cout<<"NO"<<endl;
            break;
        }
        tindex++;
    }

    if (tindex==n){
        for (int i=0; i<v.size(); i++){
            cout<<v.at(i)<<"\n";
        }
    }
    delete[] tarr;
    delete[] carr;
    return 0;
}
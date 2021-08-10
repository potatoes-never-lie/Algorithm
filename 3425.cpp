#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define MAX 1000000000
#define ll long long
using namespace std;

typedef struct Instruction{
    string inst;
    ll num;
} Instruction;

Instruction makeInstruction(string s, ll num){
    Instruction i;
    i.inst=s;
    i.num=num;
    return i;
}

bool NUM(stack<long>& s, ll num){
    s.push(num);
    return true;
}

bool POP(stack<long> &s){
    if (s.empty()){
        return false;
    }
    s.pop();
    return true;
}

bool INV(stack<long> &s){
    if (s.empty()){
        return false;
    }
    ll n=s.top();
    s.pop();
    s.push(-n);
    return true;
}

bool DUP(stack<long> &s){
    if (s.empty()){
        return false;
    }
    s.push(s.top());
    return true;
}


bool SWP(stack<long> &s){
    if (s.size()<2){
        return false;
    }
    ll a=s.top();
    s.pop();
    ll b=s.top();
    s.pop();
    s.push(a);
    s.push(b);
    return true;
}

bool ADD(stack<long> &s){
    if (s.size()<2){
        return false;
    }
    ll first=s.top();
    s.pop();
    ll second=s.top();
    s.pop();
    s.push(first+second);
    return true;
}

bool SUB(stack<long> &s){
    if (s.size()<2){
        return false;
    }
    ll first=s.top();
    s.pop();
    ll second=s.top();
    s.pop();
    s.push(second-first);
    return true;
}

bool MUL(stack<long> &s){
    if (s.size()<2){
        return false;
    }
    ll first=s.top();
    s.pop();
    ll second=s.top();
    s.pop();
    s.push(second*first);  
    return true;
}

bool DIV(stack<long> &s){
    if (s.size()<2){
        return false;
    }
    ll first=s.top();
    if (first==0){
        return false;
    }
    s.pop();
    ll second=s.top();
    s.pop();
    s.push(second/first);
    return true;
}

bool MOD(stack<long> &s){
    if (s.size()<2){
        return false;
    }
    ll first=s.top();
    if (first==0){
        return false;
    }
    s.pop();
    ll second=s.top();
    s.pop();
    s.push(second%first);
    return true;
}

int main(void){
    string input;
    ll n, num_input;
    int cnt;
    vector<Instruction> inst_list;
    while(true){
        inst_list.clear();
        while(true){
            cin>>input;
            if (input=="QUIT"){
                return 0;
            }
            if (input=="END"){
                break;
            }
            if (input=="NUM"){
                cin>>n;
                inst_list.push_back(makeInstruction(input,n));
            }
            else{
            inst_list.push_back(makeInstruction(input, 0));
            }
        }
        cin>>cnt;
        while (cnt--){
            bool flag=true;
            stack<long> s;
            cin>>num_input;
            s.push(num_input);
            for (int i=0; i<inst_list.size(); i++){
                if (inst_list[i].inst=="NUM"){
                    flag=NUM(s,inst_list[i].num);
                }
                else if (inst_list[i].inst=="POP"){
                    flag=POP(s);
                }
                else if (inst_list[i].inst=="INV"){
                    flag=INV(s);
                }
                else if (inst_list[i].inst=="DUP"){
                    flag=DUP(s);
                }
                else if (inst_list[i].inst=="SWP"){
                    flag=SWP(s);
                }
                else if (inst_list[i].inst=="ADD"){
                    flag=ADD(s);
                }
                else if (inst_list[i].inst=="SUB"){
                    flag=SUB(s);
                }
                else if (inst_list[i].inst=="MUL"){
                    flag=MUL(s);
                }
                else if (inst_list[i].inst=="DIV"){
                    flag=DIV(s);
                }
                else if (inst_list[i].inst=="MOD"){
                    flag=MOD(s);
                }
                if (!s.empty() && abs(s.top())>MAX){
                    flag=false;
                }
                if (!flag){
                    break;
                }
            }
            if (s.size()!=1){
                flag=false;
            }
            if (!flag){
                cout<<"ERROR"<<endl;
            }
            else{
                cout<<s.top()<<endl;
            }
        }
        cout<<"\n";
    }
}
/* 마저 풀기! */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int>& a, pair<char, int>& b){
    return a.second>b.second;
}

void sort(map<char, int>& M, vector<pair<char,int> >&v){
    for (auto& it: M){
        v.push_back(it);
    }
    sort(v.begin(), v.end(), cmp);
}

bool isRight(string s, vector<pair<char,int> >&v){
    for (int j=0; j<v.size(); j++){
        if (s.find(v[j].first)>=s.length()){
            return false;
        }
    }
    return true;
}

int main(void){
    int N, K;
    int max=0;
    int count=0;
    string s;
    bool right;
    vector<string> str_list;
    vector<pair<char,int> >v;
    map<char, int> m;
    cin>>N>>K;
    K=K-5;
    for (int i=0; i<N; i++){
        cin>>s;
        str_list.push_back(s);
        for (int j=4; j<s.length()-4; j++){
            if (s[j]=='a' || s[j]=='n' || s[j]=='t' || s[j]=='i' || s[j]=='c'){
                continue;
            }
            m[s[j]]++;
        }
    }
    sort(m,v);
    while (K>0){
        for (int i=0; i<N; i++){
            if (isRight(str_list[i], v)){
                count++;
            }
        }
        if (count>max){

    }
    cout<<max<<endl;
    return 0;
}
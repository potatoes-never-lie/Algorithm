#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int find(int a){
    if (v[a]==a){
        return a;
    }
    return v[a]=find(v[a]);
}

void union_(int a, int b){
    int pa=find(v[a]);
    int pb=find(v[b]);
    v[pa]=pb;
}


int main(){
    int n, m, command, a, b;
    cin>>n>>m;
    vector<string> ans;
    for (int i=0; i<n+1; i++){
        v.push_back(i);
    }
    for (int i=0; i<m; i++){
        cin>>command>>a>>b;
        if (command==0){        //union 
            union_(a,b);
        }
        else{
            if (find(a)==find(b)){
                ans.push_back("YES");
            }
            else{
                ans.push_back("NO");
            }
        }
    }
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
}

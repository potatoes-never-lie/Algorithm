#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(void){
    int n,m,input;
    cin>>n>>m;
    vector<vector<int> > office(n);
    for (int i=0; i<n; i++){
       for (int j=0; j<m; j++){
           cin>>input;
           office[i].push_back(input);
       }
    }

}
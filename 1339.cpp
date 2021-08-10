#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    int n, len;
    string temp;
    cin>>n;
    vector<string> words;
    vector<char> digits[8];
    for (int i=0; i<n; i++){
        cin>>temp;
        words.push_back(temp);
        len=temp.length();
        for (int j=len; j>0; j--){
            digits[j].push_back(temp[len-j]);
        }
    }
    for (int i=0; i<8; i++){
        
    }

}
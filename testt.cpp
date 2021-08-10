#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

vector<string> three_letters={"one","two","six"};
vector<string> four_letters={"zero","four","five","nine"};
vector<string> five_letters={"three","seven","eight"};
map<string, string> m={{"zero","0"}, {"one","1"},{"two","2"},{"three","3"},{"four","4"},
                      {"five","5"},{"six","6"},{"seven","7"},{"eight","8"},{"nine","9"}};

int solution(string s) {
    int answer = 0;
    string num="";
    vector<string>::iterator it;
    int i=0;
    while (i<s.length()){
        if ('0'<=s[i] and s[i]<='9'){
            num+=s[i];
            i+=1;
        }
        else{
            it=find(three_letters.begin(), three_letters.end(), s.substr(i,3));
            if (it!=three_letters.end()){
                num+=m[*it];
                i+=3;
                continue;
            }
            it=find(four_letters.begin(), four_letters.end(), s.substr(i,4));
            if (it!=four_letters.end()){
                num+=m[*it];
                i+=4;
                continue;
            }
            it=find(five_letters.begin(), five_letters.end(), s.substr(i,5));
            if (it!=three_letters.end()){
                num+=m[*it];
                i+=5;
                continue;
            }
        }
    }
    answer=stoi(num);
    return answer;
}


int main(){
    cout<<solution("23four5six7")<<endl;
}
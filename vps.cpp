#include <iostream>
#include <cstdio>
#include <stack>
using namespace std; 

void isValid(void);

int main(void){
	int num;
	cin>>num;
	for (int i=0; i<num; i++){
		isValid();
	}
	return 0;
}

void isValid(){
	char letter[51];
	int needpair=0;
	stack<char> s;
	cin>>letter;
	for (int i=0; letter[i]!='\0'; i++){
		s.push(letter[i]);
	}
	if (s.top()=='('){cout<<"NO"<<endl; return;}
	else{
		while(!s.empty()){
			if (s.top()==')') {needpair++;}
			else {needpair--;}
			s.pop();
		}
		if (open==close) {cout<<"YES"<<endl;}
		else {cout<<"NO"<<endl;}
	}


}
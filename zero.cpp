#include <iostream>
#include <stack>
using namespace std; 

int main(void){
	stack<int> s; 
	int num, count=0;
	int item;
	int sum=0;
	cin>>num;
	for (int i=0; i<num; i++){
		cin>>item;
		if (item==0) {s.pop();}		//최근꺼 삭제 
		else {s.push(item);}
	}
	while (!s.empty()){
		sum+=s.top();
		s.pop();
	}
	cout<<sum<<endl;
	return 0;
}

//acmicpc #10773
#include <iostream>
#include <string>
using namespace std;

int main(void){
	string s;
	while(true){
		getline(cin, s, '\n');  //띄어쓰기까지 읽을 수 있는 함수!!!
		if (cin.eof()==true)
			break;
		cout<<s<<endl;;
	}
	return 0;
}
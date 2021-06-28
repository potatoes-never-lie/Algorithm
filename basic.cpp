#include <iostream>
using namespace std;

int main(void){
	int n,m;
	while(1){
		cin>>n>>m;
		if(cin.eof()==true)			//입력 버퍼가 파일의 끝임을 종료조건으로!!
			break;
		cout<<n+m<<endl;
	}
	return 0;
}

/*10951*/
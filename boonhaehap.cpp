#include <iostream>
using namespace std;

int main(void){
	int n,i;
	int temp,sum;
	int flag;
	cin>>n;
	for (i=1; i<=n; i++){
		sum=i; 
		temp=i;
		flag=0;
		while(temp!=0){
			sum+=temp%10;
			temp/=10;
		}
		if (sum==n){
			flag=1;
			cout<<i<<endl;
			break;
		}
		if (i==n && flag==0)
			cout<<0<<endl;			
	}
	return 0;
}

/*baekjoon 2231*/

/*https://itadventure.tistory.com/158 참조!!
	sprintf 이용하여 각 자릿수마다 더해주는 기법도 사용!!
	자릿수는 10 나누는 걸로 해서 9*자릿수 해서 그쪽부터 찾아주기 */ 
#include <iostream>
using namespace std;

int main(void){
	int i,j;
	int n;
	cin>>n;
	for (i=1; i<=n; i++){
		for (j=0; j<i; j++)
			cout<<"*";
		for (j=0; j<2*(n-i); j++)
			cout<<" ";
		for (j=0; j<i; j++)
			cout<<"*";
		cout<<"\n";
	}
	for (i=1; i<=n-1; i++){
		for (j=0; j<n-i; j++)
			cout<<"*";
		for (j=0; j<2*i; j++)
			cout<<" ";
		for (j=0; j<n-i; j++)
			cout<<"*";
		cout<<"\n";
	}
	return 0;
}

/*

#include <stdio.h>

int main(void)
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= 2 * n - 1; i++) {
		for (j = 1; j <= (i < n ? i : 2 * n - i); j++) {
			printf("*");
		}
		for (j = 1; j <= (i < n ? 2 * (n - i) : 2 * (i - n)); j++) {
			printf(" ");
		}
		for (j = 1; j <= (i < n ? i : 2 * n - i); j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

서로 이렇게 케이스 다를때 ? : 문으로 처리해줘서 다로 구할 수!!!!ㅋ8/ 이렇게 비효율적으로 다 포문 쓸필요 xxxx
?: 적극이요!! 조건 따로 처리할때!!!
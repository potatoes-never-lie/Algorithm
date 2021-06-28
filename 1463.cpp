#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	int N; int minVal;
	cin>>N;
	int arr[N+1]; arr[0]=0; arr[1]=0; 
	int toSort[3];
	for (int i=2; i<=N; i++){
		if (i%2==0 && i%3!=0){
			minVal=min(arr[i/2], arr[i-1]);
			arr[i]=minVal+1;
		} 
		else if (i%3==0 && i%2!=0){
			minVal=min(arr[i/3], arr[i-1]);
			arr[i]=minVal+1;
		}
		else if (i%2==0 && i%3==0){
			toSort[0]=arr[i/2]; toSort[1]=arr[i/3]; toSort[2]=arr[i-1];
			sort(toSort,toSort+3);
			arr[i]=toSort[0]+1;
		}
		else
			arr[i]=arr[i-1]+1;
	}
	cout<<arr[N]<<endl;
	return 0;
}

/* 이렇게 복잡한 처리가 없어도
일단 -1을 뺀다음 %2, %3 해서 min 으로 서서히 비교해주는 식으로 하면 된다

arr[i]=arr[i-1]+1;
if (i%2==0) arr[i]=min(arr[i], arr[i/2]+1)
if (i%3).. 이런식으루!!! */ /*서서히 Min 으로 비교해줘도 되는겨!! */
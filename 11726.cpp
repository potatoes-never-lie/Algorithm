#include <iostream>
using namespace std;

int main(void){
	int n;
	cin>>n;
	int *dpArray=new int[n+1];
	dpArray[0]=1; dpArray[1]=1;	dpArray[2]=2; 
	if (n>2){
		for (int i=3; i<=n; i++){
			dpArray[i]=(dpArray[i-2]+dpArray[i-1])%10007;
		}
	}
 	cout<<dpArray[n]<<endl;
	delete[] dpArray;
	return 0;
}
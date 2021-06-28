#include <iostream>
#include <cmath>
using namespace std;


int main(void){
	int i,j;
	int num, stunum, above_p;
	int sum;
	cin>>num;
	int *array[num];
	int average[num]; int size[num];
	for (i=0; i<num; i++){
		sum=0;
		cin>>stunum;
		size[i]=stunum;
		array[i]=new int[stunum];
		for (j=0; j<stunum; j++){
			cin>>array[i][j];
			sum+=array[i][j];
		}
		average[i]=sum/size[i];
	}

	for (i=0; i<num; i++){
		above_p=0;
		for (j=0; j<size[i]; j++){
			if (array[i][j]>average[i]){
				above_p++;
			} 
		}
		cout<<(above_p/size[i])*100<<endl; 
	}  

	return 0;

}

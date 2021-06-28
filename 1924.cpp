#include <iostream>
using namespace std;

int main(void){
	int n, m;
	int pastDays=0;
	cin>>n>>m;
	pastDays+=m;
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	string yoil[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
	for (int i=1; i<n; i++){
		pastDays+=days[i-1];
	}
	cout<<yoil[pastDays%7]<<endl;
	return 0;
}
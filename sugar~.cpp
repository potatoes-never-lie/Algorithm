#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int n,i,j;
	vector<int> v;
	cin>>n;
	for (i=0; i*3<=n; i++){
		if ((n-(i*3))%5==0){
			j=(n-(i*3))/5;
			v.push_back(i+j);
		}
	}
	if (!v.empty()){
		sort(v.begin(), v.end());
		cout<<v[0]<<endl;
	}
	else
		cout<<-1<<endl;
	return 0;
}

/*baekjoon 2839*/
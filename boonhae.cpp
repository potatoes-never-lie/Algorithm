#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int n, m;
	int item; int max;
	vector<int> sum; 
	cin>>n; cin>>m;
	vector<int> v;
	for (int i=0; i<n; i++){
		cin>>item;
		v.push_back(item);
	}
	for (int i=0; i<n-2; i++){
		for (int j=i+1; j<n-1; j++){
			for (int k=j+1; k<n; k++){
				sum.push_back(v[i]+v[j]+v[k]);
			}
		}
	}
	sort(sum.begin(), sum.end());
	for (vector<int>::reverse_iterator r_itr=sum.rbegin(); r_itr!=sum.rend(); r_itr++){
		if ((*r_itr)<=m) {cout<<(*r_itr)<<endl; break;}
	}

	return 0;
}	

/*baekjoon 2798 */
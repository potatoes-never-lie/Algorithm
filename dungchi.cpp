#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(void){
	int n,i,j; cin>>n;
	int x,y;
	int rank;
	vector<pair<int,int> > pv;
	vector<int> res;
	for (i=0; i<n; i++){
		cin>>x; cin>>y;
		pv.push_back(make_pair(x,y));
	}
	for (i=0; i<n; i++){
		rank=1;
		for (j=0; j<pv.size(); j++){
			if ((pv[j].first>pv[i].first) && (pv[j].second>pv[i].second)){
				rank++;
			}
		}
		res.push_back(rank);
	}
	for (i=0; i<res.size(); i++){
		cout<<res[i]<<' ';
	}
	return 0;
}

/* baekjoon 7568 */ 
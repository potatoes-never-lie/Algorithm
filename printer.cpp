#include <iostream>
#include <queue>
using namespace std;

int main(void){
	int case_; cin>>case_;
	int num, docnum, x, count;
	int i,j,k;
	for (i=0; i<case_; i++){
		count=0;
		priority_queue<int> pq;
		queue<pair<int,int> > q;
		cin>>num; cin>>docnum;
		for (j=0; j<num; j++){		//insert items into queue
			cin>>x;
			pq.push(x);
			q.push(pair<int,int>(j,x)) ;
		}	
		while(!q.empty()){
			int index=q.front().first; int value=q.front().second;
			q.pop();
			if (pq.top()==value){
				pq.pop();
				count++;
				if (index==docnum){
					cout<< count <<endl;
					break;
				}
			}
			else{q.push(pair<int,int>(index,value)) ;}
		}

	} 
}
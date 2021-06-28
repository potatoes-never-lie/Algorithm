#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int main(void){
	int num, docnum, target, item;
	int count;
	int i,j;
	int index,content;
	cin>>num;
	for (i=0; i<num; i++){
		queue<pair<int,int> > printer;
		priority_queue<int> order;
		count=0;
		cin>>docnum; cin>>target;
		for (j=0; j<docnum; j++){
			cin>>item;
			printer.push(make_pair(j,item));
			order.push(item);
		}
		while(1){
			index=printer.front().first; content=printer.front().second;
			printer.pop();
			if (content==order.top()){
				count++;
				order.pop();
				if (index==target){
					cout<<count<<endl;
					break;
				}
			}
			else{
				printer.push(make_pair(index,content));
			}
		}
		
	}
	return 0;
}

/* baekjoon 1966 */
//# 고민 한 문제들
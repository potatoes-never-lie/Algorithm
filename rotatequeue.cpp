#include <iostream>
#include <deque>
using namespace std;

int moveLeft(deque<int> dq, int index);
int moveRight(deque<int> dq, int index);

int main(void){
	int n, m, item; cin>>n; cin>>m;
	int index, move, sum=0;
	deque<int> dq;
	for (int i=1; i<=n; i++){
		dq.push_back(i);
	}
	for (int i=0; i<m; i++){
		cin>>index;
		if (moveLeft(dq,index)<=moveRight(dq,index)){
			move=moveLeft(dq,index);
			for (int j=0; j<move; j++){
				item=dq.front();
				dq.pop_front();
				dq.push_back(item);
			}
			dq.pop_front();
		}
		else{
			move=moveRight(dq, index);
			for (int j=0; j<move; j++){
				item=dq.back();
				dq.pop_back();
				dq.push_front(item);
			}
			dq.pop_front();
		}
		sum+=move;
	}
	cout<<sum<<endl;
	return 0; 
}



int moveLeft(deque<int> dq, int index){
	int count=0;
	int frontItem;
	while(dq.front()!=index){
		frontItem=dq.front();
		dq.pop_front();
		dq.push_back(frontItem);
		count++;
	}
	return count;
}

int moveRight(deque<int> dq, int index){
	int count=0;
	int backItem;
	while(dq.front()!=index){
		backItem=dq.back();
		dq.pop_back();
		dq.push_front(backItem);
		count++;
	}
	return count;
}

/*baekjoon 1021 */
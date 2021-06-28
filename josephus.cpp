#include <iostream>
#include <queue>
using namespace std;

int main(void){
	int n,k; cin>>n; cin>>k; 
	queue<int> circle; 
	for (int i=1; i<=n; i++){
		circle.push(i);
	}
	cout<<"<";
	while(!circle.empty()){
		for (int i=1; i<k; i++){
			circle.push(circle.front());
			circle.pop();
		}
		if (circle.size()==1) {cout<<circle.front()<<">"<<"\n";}
		else{cout<<circle.front()<<", ";} 
		circle.pop();
	}

	return 0;
}


/* baekjoon 11866 */
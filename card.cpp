#include <iostream>
#include <queue>
using namespace std;

int main(void){
	int num; 
	cin>>num;
	queue<int> cards;
	for (int i=1; i<=num; i++){
		cards.push(i);
	}
	while(1){
		if (cards.size()==1) {break;}
		else{
			cards.pop();
			cards.push(cards.front());
			cards.pop();
		}
	} 
	cout<<cards.front()<<endl;
	return 0;
}

/* baekjoon #2164 */
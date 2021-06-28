#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

const int MAX=50;
const int INF=987654321;
int n,m;

string board[MAX];
string Bfirst[8]={"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB","BWBWBWBW", "WBWBWBWB"};
string Wfirst[8]={"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};


int whiteFirst(int y, int x){
	int count=0;
	for (int i=y; i<y+8; i++){
		for (int j=x; j<x+8; j++){
			if (Wfirst[i-y][j-x]!=board[i][j]) 
				count++;
		}
	}
	return count;
}

int blackFirst(int y, int x){
	int count=0;
	for (int i=y; i<y+8; i++){
		for (int j=x; j<x+8; j++){
			if (Bfirst[i-y][j-x]!=board[i][j]) 
				count++;
		}
	}
	return count;
}


int main(void){
	int i, j;
	int result=INF;
	cin>>n>>m; 
	for (i=0; i<n; i++){
		cin>>board[i];	
	}
	for (i=0; i+7<n; i++){			//여기서 i,j는 시작점!! 즉 하나의 정사각형!
		for (j=0; j+7<m; j++){
			result=min(result, min(whiteFirst(i,j), blackFirst(i,j)));
		}
	}
	cout<<result<<endl;
	return 0;
}
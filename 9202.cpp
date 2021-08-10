#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        Node* children[26];
        bool isEnd;
        bool isHit;
        Node(){
            isEnd=false;
            isHit=false;
        }
        void clearHit(){
            isHit=false;
            for (int i=0; i<26; i++){
                if (children[i]!=NULL){
                    children[i]->clearHit();
                }
            }
        }
        ~Node(){
            for (int i=0; i<26; i++){
                delete children[i];
            }
        }
};

Node* root=new Node();
string sword, answer;
int dy[8]={ -1, 1, 0, 0, -1, 1, -1, 1 };
int dx[8]={ 0, 0, -1, 1, -1, -1, 1, 1 };
bool visited[4][4];
int scores[9]={0,0,0,1,1,2,3,5,11};
int cnt, sum;

void insert(string word){
    Node* current=root;
    for (int i=0; i<word.length(); i++){
        int wordIndex=word[i]-'A';
        if (current->children[wordIndex]==NULL){
            current->children[wordIndex]=new Node();
        }
        current=current->children[wordIndex];
    }
    current->isEnd=true;
}

string compare(string sword, string answer){
    vector<string> v;
    v.push_back(sword); v.push_back(answer);
    if (sword.length() == answer.length()){
        sort(v.begin(), v.end());
        return v[0];
    }
    else if (sword.length()>answer.length()){
        return sword;
    }
    else{
        return answer;
    }
}


void search(int y, int x, int length, Node* node, string board[]){
    visited[y][x]=true; //체크인
    sword.push_back(board[y][x]);
    int nx, ny;
    if (node->isEnd && node->isHit==false){     //목적지인가
        node->isHit=true;
        sum+=scores[length];        //점수
        cnt+=1;                     //개수
        answer=compare(sword, answer);
    }
    //순회
    for (int i=0; i<8; i++){
        nx=x+dx[i];
        ny=y+dy[i];
        char cc=board[ny][nx];
        if (nx<0 || ny<0 || nx>=4 || ny>=4){
            continue;
        }
        if (!visited[ny][nx] && node->children[cc-'A']!=NULL){
            search(ny, nx, length+1, node->children[cc-'A'],board);
        }
    }
    visited[y][x]=false;        //체크아웃
    sword.pop_back();
}


void initialize(bool visited[4][4]){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            visited[i][j]=false;
        }
    }
}

int main(){
    int w, b;
    cin>>w;
    string words[w];
    string s;
    string board[4];
    char n[5];
    initialize(visited);
    for (int i=0; i<w; i++){
        cin>>s;
        words[i]=s;
    }
    cin.getline(n, 20);
    for (int i=0; i<w; i++){        //tree 구성
        insert(words[i]);
    }
    cin>>b;
    for (int i=0; i<b; i++){
        sum=0;
        cnt=0;
        answer="";
        for (int j=0; j<4; j++){
            cin>>s;
            board[j]=s;
        }
        for (int y=0; y<4; y++){
            for (int x=0; x<4; x++){
                if (root->children[board[y][x]-'A']!=NULL){
                    search(y,x,1,root->children[board[y][x]-'A'],board);
                }
            }
        } 
        cout<<sum<<" "<<answer<<" "<<cnt<<"\n";
        initialize(visited);
        root->clearHit();
        if (i!=b-1){
            cin.getline(n, 20);
        }
    }
    delete root;
}
#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    int index;
    int cnt;
    int order;
    bool isin;
    Student(int i, int j){
        index=i;
        order=j;
        cnt=0;
        isin=false;
    }
} ;

bool compare(Student *a, Student *b){
    if (a->cnt==b->cnt){
        return a->order>b->order; //최신일수록 앞 
    }
    return a->cnt > b->cnt;   //많이 득표할수록 앞 
}

bool compare_2(Student *a, Student *b){
    return a->index < b->index;   //많이 득표할수록 앞 
}

int main(){
    int N, recommend, num;
    vector<Student *> rec_list;
    Student* students[101];
    for (int i=0; i<101; i++){
        students[i]=new Student(i,0);
    } 
    cin>>N>>recommend;
    int frames[N];
    for (int i=0; i<recommend; i++){
        cin>>num;
        if (students[num]->isin==true){
            students[num]->cnt++;
        }
        else{
            if (rec_list.size()==N){
                sort(rec_list.begin(), rec_list.end(), compare);  
                rec_list[N-1]->cnt=0;
                rec_list[N-1]->isin=false;
                rec_list.pop_back();
            }
            students[num]->cnt=1;       //최초로 넣을 때 순서를 저장
            students[num]->isin=true;
            students[num]->order=i+1;
            rec_list.push_back(students[num]);
        }
    }
    sort(rec_list.begin(), rec_list.end(), compare_2);
    for (int i=0; i<rec_list.size(); i++){
        cout<<rec_list[i]->index<<" ";
    }
}



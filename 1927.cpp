/* 시간초과 해결해야 */
#include <bits/stdc++.h>
using namespace std;

vector<long> heap;

void insert(int item){
    long temp;
    heap.push_back(item);
    int node=heap.size()-1;
    int parent=node/2;
    while(true){
        if (parent==0 || heap[node]>=heap[parent]){
            break;
        }
        temp=heap[node];
        heap[node]=heap[parent];
        heap[parent]=temp;
        node=parent;
        parent=node/2;
    }
}

long pop(){
    long top, temp;
    if (heap.size()==1){
        return 0;
    }
    else{
        top=heap[1];
        heap[1]=heap.back();
        heap.pop_back();
        int node=1;
        while (true){
            int left=node*2;
            int right=left+1;
            if (left>=heap.size()){
                break;
            }

            long minValue=heap[left];
            int minPos=left;

            if (right<heap.size() && minValue>heap[right]){
                minValue=heap[right];
                minPos=right;
            }
            if (heap[node]>minValue){
                temp=heap[node];
                heap[node]=heap[minPos];
                heap[minPos]=temp;
                node=minPos;
            } else{
                break;
            }
        }
        return top;
    }
}

int main(){
    int N;
    vector<long> items;
    vector<long> ress;
    long res;
    long item;
    cin>>N;
    heap.push_back(0);
    for (int i=0; i<N; i++){
        cin>>item;
        items.push_back(item);
    }
    for (int i=0; i<N; i++){
        item=items[i];
        if (item==0){
            res=pop();
            ress.push_back(res);
        }
        else{               //insert
            insert(item);
        }
    }
    for (int i=0; i<ress.size(); i++){
        cout<<ress[i]<<"\n";
    }
}
#include <bits/stdc++.h>
#define MAX 2147483647
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

class Point{
    public:
        int x;
        int y;
        Point(){
        }
        Point(int y, int x){
            this->y=y;
            this->x=x;
        }
};

class Edge{
    public:
        Point start;
        Point end;
        int cost;
        Edge(Point start, Point end,int cost){
            this->start=Point(start.y, start.x);
            this->end=Point(end.y, end.x);
            this->cost=cost;
        }
};

int main(){
    int W, H, G, E;
    int x1, y1, x2, y2;
    int t;
    cin>>W>>H;
    vector<string> ans;
    while (W!=0 || H!=0){
        bool flag=false;
        vector<Edge> e;
        cin>>G;
        int map[H][W];
        vector<Point> graves;
        int cnt=0;
        int dist[H][W];
        for (int i=0; i<H; i++){
            for (int j=0; j<W; j++){
                dist[i][j]=MAX;
                map[i][j]=0;
            }
        }
        dist[0][0]=0;
        for (int i=0; i<G; i++){
            cin>>x1>>y1;
            //Point p=Point(y1, x1);
            //graves.push_back(p);     //grave 조정해주기
            map[y1][x1]=-1;
        }
        cin>>E;
        for (int i=0; i<E; i++){
            cin>>x1>>y1>>x2>>y2>>t;
            e.push_back(Edge(Point(y1, x1),Point(y2, x2),t));
            map[y1][x1]=1;
        }
        for (int i=0; i<H; i++){
            for (int j=0; j<W; j++){
                if (map[i][j]!=0 || (i==H-1 && j==W-1)){        //ghost 출발, 묘지 출발은 x 이므로
                        continue;
                }
                for (int k=0; k<=3; k++){
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    if (nx>=0 && nx<W && ny>=0 && ny<H && map[ny][nx]>=0){
                        e.push_back(Edge(Point(i,j), Point(ny,nx), 1));
                    }
                }
            }
        }
        for (int i=0; i<W*H; i++){      
            for (int j=0; j<e.size(); j++){
                Point start=e[j].start;
                Point end=e[j].end;
                int cost=e[j].cost;
                if (dist[start.y][start.x]==MAX){
                    continue;
                }
                dist[end.y][end.x]=min(dist[start.y][start.x]+cost, dist[end.y][end.x]);
            }
        }
        for (int i=0; i<e.size(); i++){
            Point start=e[i].start;
            Point end=e[i].end;
            int cost=e[i].cost;
            if (dist[start.y][start.x]==MAX){
                continue;
            }
            if (dist[start.y][start.x]+cost < dist[end.y][end.x]){
                flag=true;
                break;
            }
        }
        if (flag){
            ans.push_back("Never");
        }
        else{
            if (dist[H-1][W-1]==MAX){
                ans.push_back("Impossible");
            }
            else{
                ans.push_back(to_string(dist[H-1][W-1]));
            }
        }
        cin>>W>>H;
    }


    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    } 
    return 0;

}
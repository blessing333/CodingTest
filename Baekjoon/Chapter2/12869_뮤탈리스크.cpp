#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int arr[3];
bool visit[60][60][60];
vector<int> v;
int permu[6][3]={
{1,3,9},
{1,9,3},
{3,1,9},
{3,9,1},
{9,1,3},
{9,3,1}
};

struct p {
    int a,b,c;
};
queue<p> q;

void bfs(int a, int b,int c){
    q.push({a,b,c});
    visit[a][b][c]=true;
    while(!q.empty()){
        cnt++;
        int size=q.size();
        while(size--){
            p cur=q.front();q.pop();
            for(int i=0;i<6;i++){
                int d=max(0,cur.a-permu[i][0]);
                int e=max(0,cur.b-permu[i][1]);
                int f=max(0,cur.c-permu[i][2]);
                if(d==0 && e==0 && f==0) return;
                v.push_back(d);
                v.push_back(e);
                v.push_back(f);
                sort(v.begin(),v.end());

                if(!visit[v[0]][v[1]][v[2]]){
                    visit[v[0]][v[1]][v[2]]=true;
                    q.push({d,e,f});
                }
                v.clear();
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    bfs(arr[0],arr[1],arr[2]);
    cout << cnt;
}
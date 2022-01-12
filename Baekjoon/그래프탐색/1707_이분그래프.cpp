#include<bits/stdc++.h>
using namespace std;
int k, v, e;
bool visited[20001];
int check[20001];
vector<vector<int>> edge(20001);

bool bfs(int s){
    visited[s] = true;
    queue<int> q;
    check[s] = 0;
    q.push(s);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        int color = check[cur];
        int nextColor = (color+1)%2;
        for(auto it : edge[cur]){
            if(check[it] == color){//색이 같으면 이분 그래프가 아님
                visited[it] = true;
                // cout << "same color cur : " << cur << " it : " << it <<"\n";
                // for(int i=1;i<= v;i++) cout << " " << check[i];
                // cout <<"\n";
                return false;
            }
            if(!visited[it]){
                check[it] = nextColor;
                q.push(it);
                visited[it] = true;
                // cout << "cur : " << cur << " it : " << it <<"\n";
                // for(int i=1;i<= v;i++) cout << " " << check[i];
                // cout <<"\n";
            }
            
        }

    }
    return true;
    //방문은 하되, 큐에는 넣지 않고 색만 확인한다.
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cin.tie(NULL);
    cin >> k;
    while(k--){

        bool result = true;
        cin >> v >> e;;
        for(int i=0;i<=v;i++){
            visited[i] = false;
            check[i] = -1; // 0 = red, 1 = blue;
            edge[i].clear();
        }
        

        int a,b;
        for(int i=0;i<e;i++){
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        for(int i=1;i<=v;i++){
            if(visited[i]) continue;
            if(!bfs(i)){
                result = false;
                break;
            }
        }

        if(result) cout << "YES\n";
        else cout << "NO\n";
        
    }
}
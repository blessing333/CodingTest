#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int x,d,k;
struct Command{
    int x;
    int d;
    int k;
    Command(int a,int b,int c){
        x = a;
        d = b;
        k = c;
    }
};
vector<Command> commands;
set<pair<int,int>> candi;
void rotation(vector<int> &tmp,int dir,int dist){
    auto direction = dir == 0 ? tmp.end() : tmp.begin();
    if(dir == 0) dist = -dist;
    rotate(tmp.begin(),direction+dist,tmp.end());

}

void findSamecol(vector<vector<int>> &board,int row,int col){
    int target = board[row][col];
    int next = row +1;
    if(next <= n && target == board[next][col]){
        candi.insert({row,col});
        candi.insert({next,col});
    }
}

void findSamerow(vector<vector<int>> &board,int row,int col){
    int target = board[row][col];
    int next = col +1;
    int prev = col -1;
    if(col == m-1){
        if(board[row][prev] == target){
            candi.insert({row,prev});
            candi.insert({row,col});
        }
        if(board[row][0] == target){
            candi.insert({row,0});
            candi.insert({row,col});
        }
    }
    else{
        if(board[row][next] == target){
            candi.insert({row,col});
            candi.insert({row,next});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t;
    vector<vector<int>> board(n+1,vector<int>(m,0));
    int cnt = n * m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }

    for(int i=0;i<t;i++){
        int a,b,c;
        cin >> a >> b >> c;
        commands.push_back({a,b,c});
    }
    
    for(auto it : commands){
        if(cnt <= 0) break;
        int d = it.d;
        int k = it.k;
        int x = it.x;
        for(int i=1*x;i<=n; i+=x){
            rotation(board[i],d,k); //회전 시키고
        }

        if(cnt != 0 ){ // 인접하면서 수가 같은것을 모두 찾기
            for(int i=1;i<=n;i++){
                for(int j=0;j<m;j++){
                    if(board[i][j] != 0){
                        findSamecol(board,i,j);
                        findSamerow(board,i,j);
                    }
                }
            }
            
            if(candi.size() > 0){ // 인접하면서 수가 같은게 있으면 같은 수 모두 지우기
                for(auto it : candi){
                    board[it.first][it.second] = 0;
                }
                cnt-=candi.size();
                candi.clear();
            }
            else{ //인접하면서 같은수 없으면 평균 구하고 평균보다 큰수에 1빼고 작은수에 1 더하기
                double total = 0;
                int numCnt = 0;
                double avg = 0;
                for(int i=1;i<=n;i++){
                    for(int j=0;j<m;j++){
                        if(board[i][j] == 0) continue;
                        total += board[i][j];
                        numCnt++;
                    }
                }
                avg = total / numCnt;
                for(int i=1;i<=n;i++){
                    for(int j=0;j<m;j++){
                        if(board[i][j] ==0) continue;
                        if(board[i][j] > avg) board[i][j]--;
                        else if(board[i][j] < avg) board[i][j]++;
                    }
                }
            }
        }
    }

    int answer = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            answer+= board[i][j];
        }
    }
    cout << answer;
    
}
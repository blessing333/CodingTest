#include<bits/stdc++.h>
using namespace std;
int n;
int arr[400][5];
int answer;
int board[20][20];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<int> v[401];
struct Info{
    int x;
    int y;
    int blank;
    int prefer;
    Info(int a,int b,int c,int d){
        x=a;
        y = b;
        blank = c;
        prefer = d;
    }
    bool operator>(const Info &a) const{
        if(prefer == a.prefer){
            if(blank == a.blank){
                if(x == a.x){
                    return y < a.y;
                }
                else return x < a.x;
            }
            else return blank > a.blank;
        }
        else return prefer > a.prefer;
    }
};

void setStudent(int target,int idx){
    vector<Info> candi;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 0){
                int prefer = 0;
                int blank = 0;
                for(int k = 0;k<4;k++){// 인접한 칸의 좋아하는 학생과 빈 자리 개수를 구한다
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= n || nx < 0 || ny >=n || ny <0) continue;
                    if(board[nx][ny] == 0){
                        blank++;
                    }
                    else{
                        for(int l=1;l<=4;l++){
                            if(board[nx][ny] == arr[idx][l])
                                prefer++;
                        }
                        
                    }
                    
                }
                candi.push_back(Info(i,j,blank,prefer));
            }
        }
    }
    sort(candi.begin(),candi.end(),greater<>());
    Info info = candi[0];
    board[info.x][info.y] = target;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    // if(target == 9) cout << "blank : " << info.blank <<"    prefer : " << info.prefer <<"\n";
    

}

int main(){
    cin >> n;
    for(int i=0;i<n*n;i++){
        cin >> arr[i][0];
        for(int j=1;j<=4;j++){
            cin >> arr[i][j];
            v[arr[i][0]].push_back(arr[i][j]);
        }
    }

    for(int i=0;i<n*n;i++){
        int target = arr[i][0];
        setStudent(target,i);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int prefer = 0;
            for(int k = 0;k<4;k++){// 인접한 칸의 좋아하는 학생과 빈 자리 개수를 구한다
                int nx = i+dx[k];
                int ny = j + dy[k];
                if(nx >= n || nx < 0 || ny >=n || ny <0) continue;
                for(int l=0;l<4;l++){
                    if(board[nx][ny] == v[board[i][j]][l])
                        prefer++;
                }
            }
            if(prefer == 1) answer += 1;
            else if(prefer == 2) answer +=10;
            else if(prefer == 3) answer +=100;
            else if (prefer == 4) answer +=1000;
        }
    }
    cout << answer;
}
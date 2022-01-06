#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int board[50][50];
int tmp[50][50];

int answer = INT_MAX;
struct Info{
    int r;
    int c;
    int s;
    Info(int x,int y,int z){
        r = x;
        c = y;
        s = z;
    }
    Info(){}
};

void rotation(Info info){
    int r = info.r;
    int c = info.c;
    int s = info.s;
    int row = 2*s+1;
    int col = 2*s+1;
    int sz = min(row,col) / 2;
    int d = 0;
    while(d < sz){   
        int num[3] = {0,0,0};
        num[0] = tmp[r-s+d][c+s-d];
        for(int i=c+s-d;i>c-s+d;i--){
            tmp[r-s+d][i]=tmp[r-s+d][i-1];
        }

        num[1] = tmp[r+s-d][c+s-d];
        for(int i=r+s-d;i>r-s+d+1;i--){
            tmp[i][c+s-d] = tmp[i-1][c+s-d];
        }
        tmp[r-s+d+1][c+s-d] = num[0];
        num[2] = tmp[r+s-d][c-s+d];
        
        for(int i = c-s+d;i<=c+s-d-2;i++){
            tmp[r+s-d][i] = tmp[r+s-d][i+1];
        }
        tmp[r+s-d][c+s-d-1] = num[1];

        for(int i=r-s+d;i<=r+s-d-2;i++){
            tmp[i][c-s+d] = tmp[i+1][c-s+d];
        }
        tmp[r+s-d-1][c-s+d] = num[2];
        d++;
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    vector<Info> arr(k);
    vector<int> permu(k,0);
    for(int i=0;i<k;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        arr[i] = Info(a,b,c);
        permu[i] = i;
    }

    do{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tmp[i][j] = board[i][j];
            }
        }

        for(auto it : permu){
            rotation(arr[it]);
        }
        for(int i=0;i<n;i++){
            int total = 0;
            for(int j=0;j<m;j++){
                total+= tmp[i][j];
            }
            answer = min(answer,total);
        }

    }while(next_permutation(permu.begin(),permu.end()));
    cout << answer;
}
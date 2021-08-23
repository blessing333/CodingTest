#include <bits/stdc++.h>
const int GIDUNG = 0;
const int BO = 1;
int N;
using namespace std;
int board[101][101][2]; // 0 기둥, 1 보;
bool comp(const vector<int> &a,const vector<int> &b){
    if(a[0] == b[0]){
        if(a[1] == b[1]){
            return a[2] < b[2];
        }
        else return a[1] < b[1];
    }
    else return a[0] < b[0];
}

bool checkGidung(int x,int y){
    if(x == N || board[x+1][y][0] || board[x][y][1] || (y-1 >= 0 && board[x][y-1][1])) return true;
    else return false;
}

bool checkBo(int x,int y){
    if(board[x+1][y][0] || board[x+1][y+1][0] || (y-1 >=0 && board[x][y-1][1] && board[x][y+1][1])) return true;
    else return false;
}

bool checkDelete(int x,int y, int kind){
    if(kind == BO) return checkBo(x,y);
    else return checkGidung(x,y);
}

void buildBase(int x,int y,int kind){
    if(kind == GIDUNG){
        board[x][y][0] = 1;
    }
    else if(kind == BO){
        board[x][y][1] = 1;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N=n;
    int idx = -1;
    for(auto info : build_frame){
        idx++;
        int x = n-info[1];
        int y = info[0];
        int kind = info[2];
        int command = info[3];
        
        if(command == 0){ //삭제
            vector<vector<int>>::iterator idx;
            bool shouldDelete = true;
            board[x][y][kind] = 0;
            
            for(auto iter = answer.begin(); iter!=answer.end();iter++){
                vector<int> it = *iter;
                int x2 = n-it[1];
                int y2 = it[0];
                int kind2 = it[2];
                bool canDelete = checkDelete(x2,y2,kind2);
                if(!canDelete){
                    board[x][y][kind] = 1;
                    shouldDelete = false;
                    break;
                }
                if(x== x2 && y==y2 && kind == kind2){
                    idx = iter;
                }
            }
            if(shouldDelete) answer.erase(idx);
        }
        else if(command == 1){ // 설치
            vector<int> v;
            bool result = false;
            if(kind == BO){
                result = checkBo(x,y);
                if(result){
                    buildBase(x,y,kind);
                }
            }
            else if(kind == GIDUNG){
                result = checkGidung(x,y);
                if(result){
                    buildBase(x,y,kind);
                }
            }
            if(result){
                v.push_back(y);
                v.push_back(abs(x-n));
                v.push_back(kind);
                answer.push_back(v);
            }
        }
    }
    sort(answer.begin(),answer.end(),comp);
    return answer;
    
}
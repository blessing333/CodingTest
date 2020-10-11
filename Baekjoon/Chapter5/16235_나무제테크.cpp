#include<bits/stdc++.h>
using namespace std;
int n,m,k,ground[10][10],yangbun[10][10];
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
vector<int> tree_map[10][10];
int main(){
    cin >> n >> m >> k;
    fill(&ground[0][0],&ground[0][0]+100,5);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> yangbun[i][j];
        }
    }

    for(int i=0;i<m;i++){
        //Tree tree;
        int a,b,c;
        cin >> a >> b >> c;
        tree_map[a-1][b-1].push_back(c);
    }
    while(k--){
        //봄, 여름
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(tree_map[i][j].size()==0) continue;
                sort(tree_map[i][j].begin(),tree_map[i][j].end());
                for(int a=0;a<tree_map[i][j].size();a++){
                    if(ground[i][j]>=tree_map[i][j][a]){
                        //cout << "1.cur[a] : " <<tree_map[i][j][a]<<"\n";
                        ground[i][j]-=tree_map[i][j][a];
                        tree_map[i][j][a]=tree_map[i][j][a]+1;
                        //cout << "2.cur[a] : " <<tree_map[i][j][a]<<"\n";
                    }
                    else{
                        int popCount=0;
                        for(int b=a;b<tree_map[i][j].size();b++){
                            ground[i][j]+=(tree_map[i][j][b]/2);
                            popCount++;
                        }
                        for(int b=0;b<popCount;b++){
                            tree_map[i][j].pop_back();
                        }
                        break;
                    }

                    //cout << "k : "<<k <<"ground: "<<ground[i][j] <<"\n";
                }
            }
        }

        //가을
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(tree_map[i][j].size()==0) continue;
                for(int a=0;a<tree_map[i][j].size();a++){
                    if(tree_map[i][j][a]%5==0){ //번식
                        for(int b=0;b<8;b++){
                            int nx=i+dx[b];
                            int ny=j+dy[b];
                            if(nx >=n || nx<0 || ny >=n || ny<0) continue;
                            tree_map[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
        //겨울
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ground[i][j]+=yangbun[i][j];
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum+=tree_map[i][j].size();
        }
    }
    cout << sum<<"\n";

}
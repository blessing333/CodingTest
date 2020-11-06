#include<bits/stdc++.h>
using namespace std;
int board[9][9],avg[9],result[9];
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> board[i][j];
        }
    }

    for(int i=0;i<9;i++){
        int sum=0;
        for(int j=0;j<9;j++){
            sum+=board[i][j];
        }
        avg[i]=sum/9;
    }
    
    for(int i=0;i<9;i++){
        result[i]=INT_MAX;
        for(int j=0;j<9;j++){
            int diff=abs(avg[i]-board[i][j]);
            if(abs(avg[i]-result[i])>diff){
                result[i]=board[i][j];
            }
        }
    }
    for(int i=0;i<9;i++){
        cout << avg[i] <<" "<< result[i]<<"\n";
    }

    
}

2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
#include <bits/stdc++.h>
using namespace std;
const int MAX = 201 * 100000;
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int dist[201][201];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = MAX;
        }
    }
    for(auto it : fares){
        dist[it[0]][it[1]] = min(dist[it[0]][it[1]],it[2]);
        dist[it[1]][it[0]] = dist[it[0]][it[1]];
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int eachOther = dist[s][a] + dist[s][b];
    int caple = MAX;
    for(int i=1;i<=n;i++){
        if(i==s) continue;
        caple = min(caple,dist[s][i] + dist[i][a] + dist[i][b]);
    }
    return min(caple,eachOther);
}
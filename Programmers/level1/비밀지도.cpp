#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=(1<<16)-1;
    int input = a; int mask; while (true) {
        if (input == 0) { break; } for (int i = 31; i >= 0; i--) { mask = 1 << i; printf("%d", input & mask ? 1 : 0); if (i % 8 == 0) printf(" "); } printf("\n"); } return 0;



}
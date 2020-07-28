#include<bits/stdc++.h>
using namespace std;

int a,b,c=0;
int x,y,z=0;
int t1,t2=0;
int total=0;
int t[100]={};

int main(){
    scanf("%d%d%d",&a,&b,&c);
    for(int i=0;i<3;i++){
        scanf("%d%d",&t1,&t2);
        for(int j=t1;j<t2;j++){
            t[j]++;
        }
    }

    for(int e: t){
        if(e==1){
            x++;
        }
        else if(e==2){
            y++;
        }
        else if(e==3){
            z++;
        }
    }

    total= (x*a)+(y*b*2)+(z*c*3);
    printf("%d",total);
}
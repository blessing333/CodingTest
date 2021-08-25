#include<bits/stdc++.h>
using namespace std;
struct Egg{
    int s;
    int w;
    Egg(int a,int b){
        s= a; w=b;
    }
};

int n;
int maximum = 0;
vector<Egg> v;
void func(int cur){ //cur 번째 계란으로 다른 계란들을 친다.
    if(cur == n) {
        int cnt = 0;
        for(auto it : v){
            if(it.s <= 0) cnt++;
        }
        maximum = max(maximum,cnt);
        return;
    }
    Egg *egg = &v[cur];
    if(egg->s <= 0) func(cur+1);
    else{
        bool flag =false;
        for(int i=0;i<n;i++){ //현재 계란으로 i번 계란을 친다
            Egg *target = &v[i];
            if(i == cur || target -> s <= 0) continue;
            target->s -= egg -> w;
            egg -> s -= target->w;
            flag = true;
            func(cur+1);
            target->s += egg -> w;
            egg -> s += target->w;
        }
        if(!flag) func(n);
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back(Egg(a,b));
    }
    func(0);
    cout << maximum;
}
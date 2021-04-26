#include<bits/stdc++.h>
using namespace std;
int n;
int answer = 0;
vector<string> v;
int main(){
    //이미 나온 단어가 뒤에 다시 나오면 안된다
    cin >> n;
    for(int i=0;i<n;i++){
        string a;
        cin >> a;
        v.push_back(a);
    }
    for(auto it :v){
        int size = it.size();
        bool flag = false;
        bool check[26];
        fill_n(check,26,false);
        for(int i=0;i<size;i++){
            char key = it[i];
            if(check[it[i]-'a']){ //이미 나온적이 있으면 조건 불충족
                flag = true;
                break;
            }
            int idx = i;
            while(it[idx] == key && idx<size){ //똑같은 알파벳 스킵
                check[it[idx]-'a'] = true;
                idx++;
                i=idx;
            }
            i--;
        }
        if(flag) continue;
        answer++;
    }
    cout << answer;
}
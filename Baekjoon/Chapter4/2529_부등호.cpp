#include<bits/stdc++.h>
using namespace std;
bool check[15];
int n,checkCnt=-1;
long long minimum=LLONG_MAX, maximum=LLONG_MIN;

vector<char> v;
vector<int> v2;
bool condition(int i){
    if(v2.size()==0){
        return  true;
    }
    else if(v[checkCnt]=='>'){
        if(v2[checkCnt]>i)
            return true;
        else
            return false;
    }
    else{
        if(v2[checkCnt]<i)
            return true;
        else
            return false;
    }
}
void permu(){
    if(v2.size()==n+1){
        string str_number="";
        long long number;
        for(auto it : v2){
            str_number=str_number + to_string(it);
        }
        number=stol(str_number);
        if(maximum<number){
            maximum=number;
        }
        if(minimum>number)
            minimum=number;
        //maximum=max(maximum,number);
        //minimum=min(minimum,number);
        return;
    }

    for(int i=0;i<10;i++){
        if(check[i]) continue;
        if(!condition(i)) continue;
        check[i]=true;
        checkCnt++;
        v2.push_back(i);
        permu();
        check[i]=false;
        checkCnt--;
        v2.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        char c;
        cin >> c;
        v.push_back(c);
    }

    permu();

    string maximum_str=to_string(maximum);
    string minimum_str=to_string(minimum);

    if(maximum_str.size()<n+1)
        maximum_str.insert(0,1,'0');
    if(minimum_str.size()<n+1)
        minimum_str.insert(0,1,'0');

    cout << maximum_str<<"\n";
    cout << minimum_str ;
}
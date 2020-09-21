#include<bits/stdc++.h>
using namespace std;
int n,op1,op2,op3,op4,maximum=-100000001,minimum=1000000001;
bool check[10];
vector<int> v,v2;
vector<char> op,candi;
int caculate(){
    int value=v[0];
    for(int i=0;i<n-1;i++){
        if(candi[i]=='+'){
            value+=v[i+1];
        }
        else if(candi[i]=='-'){
            value-=v[i+1];
        }
        else if(candi[i]=='*'){
            value*=v[i+1];
        }
        else if(candi[i]=='/'){
            value/=v[i+1];
        }
    }
    return value;
}
void permu(){
    if(candi.size()==n-1){
        int value=caculate();
        maximum=max(maximum,value);
        minimum=min(minimum,value);
        return;
    }
    for(int i=0;i<n-1;i++){
        if(check[i]) continue;
        check[i]=true;
        candi.push_back(op[i]);
        permu();
        check[i]=false;
        candi.pop_back();
        
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    cin >> op1 >> op2 >> op3 >> op4;
    for(int i=0;i<op1;i++)
        op.push_back('+');
    for(int i=0;i<op2;i++)
        op.push_back('-');
    for(int i=0;i<op3;i++)
        op.push_back('*');
    for(int i=0;i<op4;i++)
        op.push_back('/');
    
    permu();
    cout << maximum << "\n";
    cout << minimum;

}
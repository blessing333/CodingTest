#include<bits/stdc++.h>

using namespace std;

int t;
deque<int> q;
bool reversed = false;

deque<int> tokenizing(string str){
    str = str.substr(1,str.size()-2);
    stringstream ss(str);
    deque<int> result;
    string token;
    while(getline(ss,token,',')){
        result.push_back(stoi(token));
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    vector<string> answerList;
    for(int i=0;i<t;i++){
        reversed = false;
        string answer;
        string func;
        cin >> func;
        int n;
        cin >> n;
        string num;
        cin >> num;
        q = tokenizing(num);
        int size = func.size();
        bool isError = false;

        for(int j=0;j<size;j++){
            if(func[j] == 'R'){
                reversed = !reversed;
            }
            else{
                if(q.size() > 0){
                    if(!reversed){
                        q.pop_front();
                    }else
                        q.pop_back();
                }
                else{
                    isError = true;
                    break;
                }
            }
        }

        if(isError) cout << "error\n";
        //answerList.push_back("error");
        else{
            answer.push_back('[');
            if(reversed){
                for(auto start = q.rbegin(); start<q.rend();start++){
                    string cur = to_string(*start);
                    answer+=cur;
                    answer.push_back(',');
                }
            }
            else{
                for(auto start = q.begin(); start<q.end();start++){
                    string cur = to_string(*start);
                    answer+=cur;
                    answer.push_back(',');
                }
            }
            if(answer[answer.size()-1] == ',')
                answer[answer.size()-1] = ']';
            else answer.push_back(']');
            //answerList.push_back(answer);
            cout << answer <<"\n";
        }       
    }
    // for(auto it : answerList){
    //     cout << it <<"\n";
    // }
}
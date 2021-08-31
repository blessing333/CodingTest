using namespace std;

long long solution(int price, int money, int count)
{
    long long sum = price;
    for(int i=2;i<=count;i++){
        sum+=(price * i);
    }
    long long answer = money-sum;
    return answer >= 0 ? 0 : -answer;
}
import java.util.*;
class Solution {
    public String solution(int n) {
        Stack<Integer> stk = new Stack<>();
        while(n > 0){
            int mod = n%3;
            n/=3;
            int val = mod;
            if(mod == 0){
                val = 4;
                n--;
            }
            stk.push(val);
        }
        StringBuilder sb = new StringBuilder();
        while(!stk.isEmpty()){
            sb.append(stk.pop());
        }
        return sb.toString();
    }
}
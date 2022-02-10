import java.util.*;
class Solution {
    public String solution(String s) {
        StringBuilder sb = new StringBuilder();
        StringBuilder str = new StringBuilder();
        int sz = s.length();
        for(int i=0;i<sz;i++){
            char c = s.charAt(i);
            if(c == ' ' || i == sz-1){
                str.append(c);
                for(int j =0; j<str.length();j++){
                    char cur = str.charAt(j);
                    if(j == 0){
                        if(Character.isLowerCase(cur)) str.setCharAt(0,Character.toUpperCase(cur));
                    }
                    else{
                        if(Character.isUpperCase(cur)) str.setCharAt(j,Character.toLowerCase(cur));
                    }
                }
                sb.append(str);
                str.delete(0,str.length());
            }
            else str.append(c);
        }
        return sb.toString();
    }
}
class Solution {
    public int solution(String s) {
        int answer = 0;
        int sz = s.length() / 2;
        int length = s.length();
        int minimum = length;
    
        for(int l = 1;l <= sz; l++){
            StringBuilder sb = new StringBuilder();
            int idx = 0;
            int end= idx + l;
            String token = s.substring(idx,end);
            int cnt = 1;
            while(true){
                idx = end;
                end = idx + l; 
                if(end >= length) end = length;
                String comp = s.substring(idx,end);
                
                if(token.equals(comp)) cnt++;
                else if(!token.equals(comp)){
                    if(cnt > 1) sb.append(cnt);
                    cnt = 1;
                    sb.append(token);
                    token = comp;  
                }
                
                if(end == length){
                    if(cnt > 1) sb.append(cnt);
                    sb.append(token);
                    break;
                }
            }
            minimum = Math.min(minimum,sb.length());
        }
        return minimum;
    }
}
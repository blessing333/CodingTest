import java.util.*;
class Solution {
    class Pair{
        int first;
        int second;
        public Pair(int a,int b){
            first = a;
            second = b;
        }
    }
    public int getDist(int r1,int c1,int r2,int c2){
        return Math.abs(r1-r2) + Math.abs(c1-c2);
    }
    
    public boolean check(int r1,int c1,int r2, int c2,String [] place){
        if(r1 == r2 && c1 > c2 ){ // 왼쪽
            if(place[r1].charAt(c1-1) == 'X') return true;
            else return false;
        } 
        else if(r1 < r2 && c1 > c2){ // 왼쪽 대각
            if(place[r1].charAt(c1-1) == 'X' && place[r1+1].charAt(c1) == 'X') return true;
            else return false;
        }
        else if(r2 > r1 && c1 == c2){ // 밑
            if(place[r1+1].charAt(c1) == 'X') return true;
            else return false;
        }
        else if(r2 > r1 && c2>c1){ //오른쪽 대각
            if(place[r1+1].charAt(c1+0) == 'X' && place[r1].charAt(c1+1) == 'X') return true;
            else return false;
        }
        else if(r1 == r2 && c1 < c2){ // 오른쪽
            if(place[r1].charAt(c1+1) == 'X') return true;
            else return false;
        }
        else{
            System.out.println("incorrect ranget");
            return false;
        } 
    }
    
    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        int tc = -1;
        
        while(++tc < 5 ){
            boolean isSafe = true;
            List<Pair> v = new ArrayList<>();
            for(int i=0;i<5;i++){ //사람이 들어있는 좌표 리스트에 저장
                for(int j=0;j<5;j++)
                    if(places[tc][i].charAt(j) == 'P') v.add(new Pair(i,j));
            }
            int sz = v.size();
            for(int i = 0;i<sz-1;i++){
                Pair pos1 = v.get(i);
                for(int j=i+1;j<sz;j++){
                    Pair pos2 = v.get(j);
                    int dist = getDist(pos1.first,pos1.second,pos2.first,pos2.second);
                    if(dist == 1){
                        isSafe = false;
                        break;
                    }
                    else if(dist == 2){
                        if(!check(pos1.first,pos1.second,pos2.first,pos2.second,places[tc])){
                            isSafe = false;
                            break;
                        }
                    }
                }
                if(!isSafe) break;
            }
            
            answer[tc] = isSafe ? 1 : 0;
        }
        
        return answer;
    }
}
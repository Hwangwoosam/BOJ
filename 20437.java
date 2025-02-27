import java.util.*;
import java.io.*;

class Main{
    static int t;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++){
            char[] word = br.readLine().toCharArray();
            int k = Integer.parseInt(br.readLine());
            
            if(k == 1){
                System.out.println("1 1");
                continue;
            }
            
            int[] alp = new int[26];
            Arrays.fill(alp,0);

            for(int j = 0; j < word.length; j++){
                alp[word[j]-'a']++;
            }

            int min = Integer.MAX_VALUE;
            int max = -1;

            for(int j = 0; j < word.length; j++){
                if(alp[word[j]-'a'] < k) continue;

                int cnt = 1;
                for(int m = j+1; m < word.length; m++){
                    if(word[j] == word[m]){
                        cnt++;
                    }
                    
                    if(cnt == k){
                        min = Math.min(min,m-j+1);
                        max = Math.max(max,m-j+1);
                        break;
                    }
                }
            }
            if(min == Integer.MAX_VALUE || max == -1) {
                System.out.println("-1");
            }else{
                System.out.println(min + " " + max);
            }
        }

    }
}
import java.io.*;
import java.util.*;

//acnti
class Main{
    static int n;
    static int k;
    static int ans = 0;
    static String[] words;
    static boolean[] visited; 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        words = new String[n];
        for(int i = 0; i < n; i++){
            words[i] = br.readLine();
            words[i] = words[i].replace("anta", "");
            words[i] = words[i].replace("tica", "");
        }

        if(k < 5){
            bw.append(0 + "\n");
            bw.flush();
            return;
        }else if(k == 26){
            bw.append(n + "\n");
            bw.flush();
            return;
        }

        visited = new boolean[26];
        visited['a'-'a'] = true;
        visited['c'-'a'] = true;
        visited['n'-'a'] = true;
        visited['t'-'a'] = true;
        visited['i'-'a'] = true;
        findCase(0, 0);

        bw.append(ans + "\n");
        bw.flush();


    }

    public static void findCase(int alp, int len){
        if(len == k -5){
            int cnt = 0;
            for(int i = 0; i < n; i++){
                 boolean possible = true;
                 int wordSize = words[i].length();
                 for(int j = 0; j < wordSize; j++){
                    if(!visited[words[i].charAt(j) - 'a']){
                        possible = false;
                        break;
                    }
                 }

                 if(possible) cnt ++;
            }
            ans = Math.max(ans,cnt);
            return ;
        }

        for(int i = alp; i < 26; i++){
            if(visited[i] == false){
                visited[i] = true;
                findCase(i, len+1);
                visited[i] = false;
            }
        }
    }
}
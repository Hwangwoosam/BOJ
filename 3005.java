import java.util.*;
import java.io.*;

class Main{
    static int r,c;
    static PriorityQueue<String> pq = new PriorityQueue<>();

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        String[] row = new String[r];
        String[] col = new String[c];
        for(int i = 0; i < r; i++) row[i] = br.readLine();
        for(int i = 0; i < c; i++){
            String colWord="";
            for(int j = 0; j < r; j++){
                colWord += row[j].charAt(i);
            }
            col[i] = colWord;
        }

        getWords(row,r);
        getWords(col,c);

        bw.append(pq.poll() + "\n");
        bw.flush();
    }

    static void getWords(String[] words,int limit){
        for(int i = 0; i < limit; i++){
            String[] subWords = words[i].split("#");
            for(int j = 0; j < subWords.length; j++){
                if(subWords[j].length() >= 2){
                    pq.add(subWords[j]);
                }
            }
        }
    }
}
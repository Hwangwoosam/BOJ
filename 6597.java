import java.io.*;
import java.util.*;


//pre : Root Right Left
//in : Right Root Left
//post Right Left Root
class Main{

    public static String pre;
    public static String in;
    public static int preorderIdx = 0;


    public static void main(String[] args) {
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st;
            while(true){
                st = new StringTokenizer(br.readLine());
                pre = st.nextToken();
                in = st.nextToken();

                int len = pre.length();

                if(len == 0) break;

                preorderIdx = 0;
                findPost(0, len-1);
                System.out.println();
            }
        }catch (Exception e){

        }
    }

    public static void findPost(int start, int end){
        if(start > end ) return;

        int mid = in.indexOf(pre.charAt(preorderIdx++));
        findPost(start, mid-1);
        findPost(mid+1, end);
        System.out.print(in.charAt(mid));
    }
}
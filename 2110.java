import java.util.*;
import java.io.*;

class Main{
    static int n,c;
    static int[] homes;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        homes = new int[n];
        for(int i = 0; i < n; i++){
            homes[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(homes);

        int left = 1;
        int right = homes[n-1] - homes[0] + 1;

        while(left <= right){
            int mid = (left + right)/ 2;   
            if(getInstall(mid) < c){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        bw.append(left + "\n");
        bw.flush();
    }

    public static int getInstall(int dist){
        int cnt = 1;
        int lastLoc = homes[0];

        for(int i = 1; i < n; i++){
            int curLoc = homes[i];

            if(curLoc - lastLoc > dist){
                cnt++;
                lastLoc = curLoc;
            }
        }

        return cnt;
    }
}
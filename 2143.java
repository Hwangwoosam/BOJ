import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        
        long[] a;
        long[] b;

        int t = Integer.parseInt(br.readLine());

        int n = Integer.parseInt(br.readLine());
        a = new long[n+1];
        a[0] = 0;
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++) a[i] = a[i-1] + Long.parseLong(st.nextToken());

        int m = Integer.parseInt(br.readLine());
        b = new long[m+1];
        b[0] = 0;
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= m; i++) b[i] = b[i-1] + Long.parseLong(st.nextToken());
        
        int sizeA = n*(n+1)/2;
        int sizeB = m*(m+1)/2;
        long[] subA = new long[sizeA];
        long[] subB = new long[sizeB];

        int idx = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                subA[idx++] = a[j] - a[i-1];
            }
        }

        idx = 0;
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                subB[idx++] = b[j] - b[i-1];
            }
        }
        
        Arrays.sort(subA);
        Arrays.sort(subB);

        int left = 0, right = sizeB-1;
        long ans = 0;
        while(left < sizeA && right >= 0){
            long sa = subA[left], sb = subB[right];
            long sum = sa + sb;

            if(sum == t){
                long cntA = 0, cntB = 0;
                while(left < sizeA && sa == subA[left]){
                    left++;
                    cntA++;
                }

                while(right >= 0 && sb == subB[right]){
                    right--;
                    cntB++;
                }
                ans += cntA*cntB;
            }

            if(sum < t) left++;
            else if(sum > t) right--;
        }

        bw.append(ans + "\n");
        bw.flush();
    }
}
import java.util.*;
import java.io.*;

class Main{
    static int[] a,b;
    static int n,m,k;
    static boolean[] visited;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine()); 

        StringTokenizer st;
        for(int i = 0; i < t; i++){
            st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            
            a = new int[m];
            b = new int[n];
            visited = new boolean[n+m];

            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n ; j++) b[j] = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m ; j++) a[j] = Integer.parseInt(st.nextToken());

            Arrays.sort(a);
            Arrays.sort(b);

            ArrayList<Long> a_sums = new ArrayList<>(generate_sum(a));
            ArrayList<Long> b_sums = new ArrayList<>(generate_sum(b));

            Long maxVal = Math.max(Math.abs(a_sums.get(0) - b_sums.get(b_sums.size()-1)), Math.abs(b_sums.get(0) - a_sums.get(a_sums.size()-1)));
            Long minVal = findMin(a_sums,b_sums);

            System.out.println(minVal + " " + maxVal);
        }
    }

    static Set<Long> generate_sum(int[] arr){
        Set<Long> sum = new TreeSet<>();
        findSum(arr,0,0,0L,sum);
        return sum;
    } 

    static void findSum(int[] arr,int start,int cnt, Long curSum, Set<Long> sums){
        if(cnt == k){
            sums.add(curSum);
            return;
        }

        for(int i = start; i < arr.length; i++){
            findSum(arr,i+1,cnt+1,curSum + arr[i],sums);
        }
    }

    static Long findMin( ArrayList<Long> a,  ArrayList<Long> b){
         Long minDiff = Long.MAX_VALUE;

        for (Long num : a) {
            int idx = binSearch(b, num);
            
            // target보다 작거나 같은 값 확인
            if (idx >= 0) {
                minDiff = Math.min(minDiff, Math.abs(b.get(idx) - num));
            }
            
            // target보다 큰 값 확인
            if (idx + 1 < b.size()) {
                minDiff = Math.min(minDiff, Math.abs(b.get(idx + 1) - num));
            }
        }

        return minDiff;
    }

    static int binSearch(ArrayList<Long> arr, Long target){
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (arr.get(mid) <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left - 1;
    }
}
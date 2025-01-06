import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            
            int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int[] b = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            
            List<Integer> sumA = generateSums(a, k);
            List<Integer> sumB = generateSums(b, k);
            
            Collections.sort(sumA);
            Collections.sort(sumB);
            
            int maxDiff = 0;
            int minDiff = Integer.MAX_VALUE;
            
            for (int sa : sumA) {
                int indexB = Collections.binarySearch(sumB, sa);
                if (indexB < 0) indexB = -indexB - 1;
                
                if (indexB < sumB.size()) {
                    int diff = Math.abs(sa - sumB.get(indexB));
                    maxDiff = Math.max(maxDiff, diff);
                    minDiff = Math.min(minDiff, diff);
                }
                if (indexB > 0) {
                    int diff = Math.abs(sa - sumB.get(indexB - 1));
                    maxDiff = Math.max(maxDiff, diff);
                    minDiff = Math.min(minDiff, diff);
                }
            }
            
            System.out.println(maxDiff + " " + minDiff);
        }
    }
    
    static List<Integer> generateSums(int[] arr, int k) {
        List<Integer> sums = new ArrayList<>();
        int n = arr.length;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (Integer.bitCount(mask) == k) {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    if ((mask & (1 << i)) != 0) {
                        sum += arr[i];
                    }
                }
                sums.add(sum);
            }
        }
        return sums;
    }
}

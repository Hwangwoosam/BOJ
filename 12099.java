import java.util.*;
import java.io.*;

class Main{

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        Pair[] spicy = new Pair[n];
        int[] honey = new int[n];

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            spicy[i] = new Pair(Integer.parseInt(st.nextToken()),i);
            honey[i] = Integer.parseInt(st.nextToken());
        }

        CustomComparator cmp = new CustomComparator();    
        Arrays.sort(spicy,cmp);
        
        for(int i = 0; i < q; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            int left = 0, right = n;
            while(left <= right){
                int mid = (left + right)/2;
                if(spicy[mid].value > v){
                    right = mid - 1;
                }else if(spicy[mid].value < u){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            int cnt = 0;
            for(int j = left; j < n; j++){
                if(spicy[j].value > v) break;
                if(honey[spicy[j].idx] >= x && honey[spicy[j].idx] <= y) cnt++;
            }

            bw.append(cnt + "\n");
            bw.flush();
        }

    }



    public static class Pair{
        int value;
        int idx;

        Pair(int value, int idx){
            this.value = value;
            this.idx = idx;
        }
    }

    public static class CustomComparator implements Comparator<Pair>{
        @Override
        public int compare(Pair a, Pair b){
            return a.value - b.value;
        }
    }
}
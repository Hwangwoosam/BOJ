
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Jewely{
    int weight;
    int value;

    Jewely(int weight,int value){
        this.weight = weight;
        this.value = value;
    }
}

class Main {

    public static int n,k;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String inp[] = br.readLine().split(" ");

        n = Integer.parseInt(inp[0]);
        k = Integer.parseInt(inp[1]);
        
        Jewely jewely[] = new Jewely[n];

        for(int i = 0; i < n; i++){
            String jewelyInfo[] = br.readLine().split(" ");
            int w = Integer.parseInt(jewelyInfo[0]);
            int v = Integer.parseInt(jewelyInfo[1]);
            
            jewely[i] = new Jewely(w,v);            
        }

        Arrays.sort(jewely, new Comparator<Jewely>(){
            public int compare(Jewely j1, Jewely j2){
                if(j1.weight == j2.weight) return j2.value - j1.value;
                return j1.weight - j2.weight;
            }
        });

        int bag[] = new int[k];
        for(int i = 0; i < k; i++){
            bag[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(bag);

        long ans = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i = 0,j = 0; i < k; i++){
            while(j < n && jewely[j].weight <= bag[i]){
                pq.offer(jewely[j++].value);
            }

            if(!pq.isEmpty()){
                ans += pq.poll();
            }
        }

        bw.write(ans + "\n");
        bw.flush();
        br.close();
        bw.close();
    }   
    
}
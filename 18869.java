import java.util.*;
import java.io.*;

class Main{
    static int m,n;
    static ArrayList<ArrayList<Integer>> spaces = new ArrayList<>();

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        for(int i = 0; i < m; i++){
            ArrayList<Integer> space = new ArrayList<>();
            Set<Integer> set = new HashSet<>();

            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                int planet = Integer.parseInt(st.nextToken());
                space.add(planet);
                set.add(planet);
            }

            ArrayList<Integer> spaceCopy = new ArrayList<>(set);
            Collections.sort(spaceCopy);

            for(int j = 0; j < n; j++){
                int idx = Collections.binarySearch(spaceCopy,space.get(j));
                space.set(j,idx);
            }
            spaces.add(space);
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = i+1; j<m; j++){
                if(Arrays.equals(spaces.get(i).toArray(),spaces.get(j).toArray())){
                    ans++;
                }
            }
        }

        bw.append(ans +"\n");
        bw.flush();
    }
}
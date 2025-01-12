import java.util.*;
import java.io.*;

class Main{
    static int n,g,k;
    static ArrayList<Ingredient> ingredients = new ArrayList<>();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        g = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            int o = Integer.parseInt(st.nextToken());

            ingredients.add(new Ingredient(s,l,o));
        }

        long left = 0, right = 2_000_000_000L;
        long answer = 0;

        while (left <= right) {
            long mid = (left + right) / 2;
            if (check(mid)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        System.out.println(answer);
    }

    static boolean check(long days) {
        List<Long> optional = new ArrayList<>();
        long totalBacteria = 0;
    
        // 필수 재료와 선택 재료 분리
        for (Ingredient ing : ingredients) {
            long bacteria = ing.s * Math.max(1, days - ing.l);
            if (ing.o == 1) {
                optional.add(bacteria);
            } else {
                totalBacteria += bacteria;
            }
        }
    
        // 선택 재료들을 내림차순 정렬
        Collections.sort(optional, Collections.reverseOrder());
    
        // 선택 재료들 중에서 세균 수가 가장 많은 K개를 제외
        for (int i = k; i < optional.size(); i++) {
            totalBacteria += optional.get(i);
        }
    
        return totalBacteria <= g;
    }
    
    
    
    static class Ingredient{
        int s, l, o;
        Ingredient(int s, int l, int o) {
            this.s = s;
            this.l = l;
            this.o = o;
        }
    }
}
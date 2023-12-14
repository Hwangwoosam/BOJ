import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main{
    static int n,minValue = Integer.MAX_VALUE, maxValue = Integer.MIN_VALUE;
    static String[][] map;
    static int[] dx = {1,0};
    static int[] dy = {0,1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        
        map = new String[n][n];

        for(int i = 0; i < n; i++){
            String[] inp = br.readLine().split(" ");
            for(int j = 0; j < n; j++){
                map[i][j] = inp[j];
            }
        }
        dfs(0,0,0,null);

        System.out.println(maxValue + " " + minValue);
        
    }

    public static void dfs(int x,int y,int result,String oper){
        
        if(isNumber(map[x][y])){
            int value = Integer.parseInt(map[x][y]);

            if(oper == null){
                result = value;
            }else{
                switch (oper) {
                    case "+":
                        result += value;
                        break;
                    case "-":
                        result -= value;
                        break;
                    case "*":
                        result *= value;
                        break;
                    default:
                        break;
                }
            }
        }else{
            oper = map[x][y];
        }

        if(x == n-1 && y == n-1){
            if(maxValue < result) maxValue = result;
            if(minValue > result) minValue = result;
            return;
        }

        for(int i = 0; i < 2; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= n || ny >= n) continue;
            
            dfs(nx, ny, result, oper);
        }
    }

    public static boolean isNumber(String strNum){
        if(strNum == null){
            return false;
        }

        try{
            int tmp = Integer.parseInt(strNum);
        }catch(NumberFormatException e){
            return false;
        }

        return true;
    }
}
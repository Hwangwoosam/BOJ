import java.util.*;
import java.io.*;

class Main{
    static int[] num;
    static int[] numCnt;
    static int[] ngf;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        num = new int[n];
        numCnt = new int[1000001];
        ngf = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            num[i] = Integer.parseInt(st.nextToken());
            numCnt[num[i]]++;
        }

        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < n; i++){
            while(!stack.isEmpty() && numCnt[num[stack.peek()]] < numCnt[num[i]]){
                ngf[stack.pop()] = num[i];
            }
            stack.push(i);
        }

        while(!stack.isEmpty()){
            ngf[stack.pop()] = -1;
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++){
            sb.append(ngf[i]).append(" ");
        }

        System.out.println(sb);

    }
}
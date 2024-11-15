import java.util.*;
import java.io.*;

class Main{
    static int n;
    static ArrayList<Character> oper = new ArrayList<>();

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        String cmds = br.readLine();
        
        boolean printOut = false;

        for(int i = 0; i < cmds.length(); i++){
            if(!Character.isDigit(cmds.charAt(i))){
                oper.add(cmds.charAt(i));
                if(!printOut &&cmds.charAt(i) == 'C') printOut = true;
            }
        }

        if(!printOut){
            bw.append("NO OUTPUT\n");
            bw.flush();
        }else{
            String[] nums = cmds.split("C|S|M|U|P");
            ArrayList<Integer> numbers = new ArrayList<>();
            for(String st: nums){
                if(!st.isEmpty()){
                    numbers.add(Integer.parseInt(st));
                }
            }

            int res = numbers.get(0);
            int numIdx = 1;

            StringBuilder sb = new StringBuilder();

            for(int i = 0; i < oper.size(); i++){
                if(oper.get(i) == 'C'){
                    sb.append(res).append(" ");
                }else{
                    if(numIdx >= numbers.size()) continue;

                    if(oper.get(i) == 'S') res -= numbers.get(numIdx++);
                    else if(oper.get(i) == 'M') res *= numbers.get(numIdx++);
                    else if(oper.get(i) == 'U') res /= numbers.get(numIdx++);
                    else if(oper.get(i) == 'P') res += numbers.get(numIdx++);
                }
            }

            bw.append(sb.toString() + "\n");
            bw.flush();
        }
    }
}
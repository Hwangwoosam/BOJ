import java.util.*;
import java.io.*;

class Main{
    static String expression;
    static Deque<Long> nums;
    static Deque<Character> oper;
    static long ans;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        expression = br.readLine();

        nums = new LinkedList<>();
        oper = new LinkedList<>();
        
        parseNum();
        selectPriority();
        System.out.println(ans);
    }

    static void parseNum(){
        String num = "";

        int idx = 0;
        if(expression.charAt(0) == '-'){
            num += '-';
            idx++;
        }

        boolean zeroCheck = false;

        for(int i = idx; i <expression.length(); i++){
            char curStr = expression.charAt(i);

            if(curStr == '*' || curStr == '/' || curStr == '+' || curStr == '-'){
                if(zeroCheck){
                    nums.add(Long.valueOf(num));
                }else{
                    nums.add(Long.valueOf("0"));
                }
                num = "";
                oper.add(curStr);
                zeroCheck = false;
            }else{
                if(curStr != '0'){
                    zeroCheck = true;
                }

                if(zeroCheck){
                    num += curStr;
                }
            }
        }

        if(!num.equals("-") && !num.equals("")){
            nums.add(Long.valueOf(num));
        }else{
            nums.add(Long.valueOf("0"));
        }
    }

    static void selectPriority(){
        while(oper.size() > 1){
            char firstOp = oper.getFirst();
            char lastOp = oper.getLast();

            long firstNum = nums.removeFirst();
            long lastNum = nums.removeLast();

            long preNum = nums.getFirst();
            long nextNum = nums.getLast();

            if((firstOp == '*' || firstOp == '/') && (lastOp == '+' || lastOp == '-')){
                // 앞선택
                selectFront(lastNum,calc(firstNum,preNum,firstOp));
            }else if((firstOp == '+' || firstOp == '-') && (lastOp == '*' || lastOp == '/')){
                // 뒤선택
                selectBack(firstNum,calc(nextNum,lastNum,lastOp));
            }else{
                long preRes = calc(firstNum,preNum,firstOp);
                long lastRes = calc(nextNum,lastNum,lastOp);

                if(preRes >= lastRes){
                    selectFront(lastNum,calc(firstNum,preNum,firstOp));
                }else if(preRes < lastRes){
                    selectBack(firstNum,calc(nextNum,lastNum,lastOp));
                }
            }
        }

        if(oper.size() == 1){
            ans = calc(nums.removeFirst(),nums.removeFirst(),oper.removeFirst());
        }else{
            ans = nums.removeFirst();
        }
    }

    static void selectFront(long lastNum, long res){
        nums.addLast(lastNum);
        nums.removeFirst();
        nums.addFirst(res);
        oper.removeFirst();
    }

    static void selectBack(long preNum, long res){
        nums.addFirst(preNum);
        nums.removeLast();
        nums.addLast(res);
        oper.removeLast();
    }

    static long calc(long a,long b, char op){
        if(op == '*'){
            return a*b;
        }else if(op == '/'){
            return a/b;
        }else if(op == '+'){
            return a+b;
        }else{
            return a-b;
        }
    }
}
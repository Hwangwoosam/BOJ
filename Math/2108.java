import java.util.*;

public class Main{

    static int n;
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        
        int[] numList = new int[n];
        for(int i = 0; i < n; i++){
            numList[i] = scanner.nextInt();
        }
        Arrays.sort(numList);
        System.out.println(String.valueOf(getAverage(numList)));
        System.out.println(String.valueOf(getMean(numList)));
        System.out.println(String.valueOf(getFrequency(numList)));
        System.out.println(String.valueOf(getRange(numList)));
    }

    public static int getAverage(int[] numList){
        double sum = 0;
        
        for(int num: numList){
            sum += num;
        }
        sum = Math.round(sum/n);
        return (int)sum;
    }

    public static int getMean(int[] numList){
        return numList[n/2];
    }

    public static int getFrequency(int[] numList){
        int[] count = new int[8001];
        
        int max = 0, idx = 0;
        for(int i = 0; i < n; i++){
            count[numList[i]+4000]++;
            if(count[numList[i]+4000] > max){
                max = count[numList[i]+4000];
            }
        }

        int cnt = 0;
        for(int i = 0; i < count.length; i++){
            if(count[i] == max){
                cnt++;
                if(cnt <= 2){
                    max = count[i];
                    idx = i;
                }
            }
        }

        return idx-4000;
    }

    public static int getRange(int[] numList){
        int range = numList[n-1] - numList[0];

        return range;
    }
}
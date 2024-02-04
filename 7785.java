import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static HashMap<String,String> people = new HashMap<>();
    public static void main(String[] args) throws NumberFormatException, IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n =Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            String inp[] = br.readLine().split(" ");
            if(inp[1].equals("enter")){
                people.put(inp[0], inp[1]);
            }else{
                people.remove(inp[0]);
            }
        }
        
        ArrayList<String> list = new ArrayList<>(people.keySet());
        list.sort(Comparator.reverseOrder());
        for(String person : list){
            System.out.println(person);
        }
    }
}

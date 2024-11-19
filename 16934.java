import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        NickNameCnts nickNameCnts = new NickNameCnts();
        Trie trie = new Trie();

        for(int i = 0; i < n; i++){
            String inp = br.readLine();
            nickNameCnts.insert(inp);

            int idx = trie.searchMatchLastIndex(inp);
            if(idx == inp.length()-1){
                int x = nickNameCnts.getCnt(inp);
                sb.append(inp).append(x > 1 ? x : "").append("\n");
            }else if(idx > -1){
                int x = nickNameCnts.getCnt(inp);
                sb.append(inp,0,idx+2).append("\n");
            }else{
                sb.append(inp.charAt(0)).append("\n");
            }
            trie.insert(inp);
        }
        bw.append(sb.toString());
        bw.flush();
    }

    static class Node{
        Map<Character,Node> child = new HashMap<>();
        boolean isTerminated;
    }

    static class Trie{
        Node rootNode = new Node();

        void insert(String str){
            Node node = this.rootNode;
            for(int i = 0; i < str.length(); i++){
                node = node.child.computeIfAbsent(str.charAt(i),key-> new Node());
            }

            node.isTerminated = true;
        }

        int searchMatchLastIndex(String str){
            int idx = -1;
            Node node = this.rootNode;

            for(int i = 0; i < str.length(); i++){
                node = node.child.getOrDefault(str.charAt(i), null);

                if(node == null) break;

                idx++;
            }

            return idx;
        }
    }

    static class NickNameCnts{
        Map<String,Integer> nickNameCnts = new HashMap<>();
        
        void insert(String nickname){
            if(nickNameCnts.containsKey(nickname)){
                nickNameCnts.put(nickname,nickNameCnts.get(nickname)+1);
                return;
            }

            nickNameCnts.put(nickname,1);
        }

        int getCnt(String nickname){
            return nickNameCnts.getOrDefault(nickname,0);
        }
    }
}
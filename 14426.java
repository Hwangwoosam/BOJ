import java.util.*;
import java.io.*;

class Main{
    static int n,m;
    static ArrayList<String>[] words;

    public static void main(String[] args)throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Trie trie = new Trie();
        words = new ArrayList[26];
        for(int i = 0; i < 26; i++) words[i] = new ArrayList<>();

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        for(int i = 0; i < n; i++){
            String inp = br.readLine();
            trie.insert(inp);
        }

        int cnt = 0;
        for(int i = 0; i < m; i++){
            String inp = br.readLine();
            if(trie.search(inp)) cnt++;
        }

        bw.append(cnt + "\n");
        bw.flush();
    }

    static class Node{
        Map<Character,Node> childNode = new HashMap<Character,Node>();
        boolean endOfword;
    }

    static class Trie{
        Node rootNode = new Node();

        void insert(String str){
            Node node = this.rootNode;

            for(int i = 0; i < str.length(); i++){
                node = node.childNode.computeIfAbsent(str.charAt(i), key -> new Node());
            }

            node.endOfword = true;   
        }

        boolean search(String str){
            Node node = this.rootNode;

            for(int i = 0; i < str.length(); i++){
                node = node.childNode.getOrDefault(str.charAt(i),null);
                if(node == null) return false;
            }

            return true;
        }
    }
}
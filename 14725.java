import java.util.*;
import java.io.*;

class Main{
    static int n;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Trie trie = new Trie();
        n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i ++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            String[] names = new String[k];
            int limit = st.countTokens();
            for(int j = 0; j < limit; j++) names[j] = st.nextToken();
            
            trie.insert(names);
        }
        StringBuilder sb = new StringBuilder();
        String prefix = "";
        printAll(trie.rootNode,prefix,sb);

        bw.append(sb.toString());
        bw.flush();
    }

    static void printAll(Node node,String prefix,StringBuilder sb){
        int childNum = node.child.size();
        if(childNum == 0) return;

        List<String> keySet = new ArrayList<>(node.child.keySet());
        Collections.sort(keySet); 

        for(String key : keySet){
            sb.append(prefix).append(key).append("\n");
            printAll(node.child.get(key),prefix+"--",sb);
        }
    }

    static class Node{
        Map<String,Node> child = new HashMap<>();      
    }

    static class Trie{
        Node rootNode = new Node();

        void insert(String[] str){
            Node node = this.rootNode;
            for(int i = 0; i < str.length; i++){
                node = node.child.computeIfAbsent(str[i],key->new Node());
            }
        }
    }
}
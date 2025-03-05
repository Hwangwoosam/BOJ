import java.util.*;
import java.io.*;

class Main{
    static int n,k;
    static Target[] target;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        target = new Target[k];
        for(int i = 0; i < k; i++){
            st = new StringTokenizer(br.readLine());

            int num = Integer.parseInt(st.nextToken());
            int destX = Integer.parseInt(st.nextToken());
            int destY = Integer.parseInt(st.nextToken());

            target[i] = new Target(((num-1)/n) + 1,((num-1)%n) + 1,num,destX,destY);
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < k; i++){
            int moveColCnt = getMoveColCount(target[i]);
            int moveRowCnt = getMoveRowCount(target[i]);
            updateTarget(i,moveColCnt,moveRowCnt);
            sb.append(moveColCnt+ moveRowCnt).append("\n");
        }
        System.out.print(sb.toString());
    }

    static int getMoveRowCount(Target target){
        int moveCnt = 0;
        moveCnt = (n+target.destX - target.x) % n;
        return moveCnt;
    }

    static int getMoveColCount(Target target){
        int moveCnt = 0;
        moveCnt = (n+target.destY - target.y) % n;
        return moveCnt;
    }

    static void updateTarget(int idx, int moveColCnt, int moveRowCnt) {
        Target cur = target[idx];

        int originalX = cur.x;
        int originalY = cur.y;

        cur.x = cur.destX;
        cur.y = cur.destY;
    
        for (int i = idx + 1; i < k; i++) {
            Target next = target[i];

            if (cur.val == next.val) {
                next.x = cur.destX;
                next.y = cur.destY;
                continue;
            }

            if (originalX == next.x) {
                int temp = (next.y + moveColCnt) % n;
                temp = temp != 0 ? temp : n;
                next.y = temp;
                continue;
            }

            if (cur.destY == next.y) {
                int temp = (next.x + moveRowCnt) % n;
                temp = temp != 0 ? temp : n;
                next.x = temp;
                continue;
            }
        }
    }
    

    static class Target{
        int x;
        int y;
        int val;
        int destX;
        int destY;

        public Target(int x,int y, int val, int destX, int destY){
            this.x = x;
            this.y = y;
            this.val = val;
            this.destX = destX;
            this.destY = destY;
        }
    }
}
import java.util.*;
import java.io.*;

class Main {
    static int M, N, P;
    static char[][] map;
    static int[] damage;
    static int bossX, bossY, bossHP;
    static Queue<Player> queue = new LinkedList<>();
    static boolean[][][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());

        map = new char[M][N];
        damage = new int[26];
        visited = new boolean[26][M][N];

        for (int i = 0; i < M; i++) {
            String line = br.readLine();
            for (int j = 0; j < N; j++) {
                map[i][j] = line.charAt(j);
                if (map[i][j] >= 'a' && map[i][j] <= 'z') {
                    int id = map[i][j] - 'a';
                    queue.offer(new Player(i, j, id));
                    visited[id][i][j] = true;
                } else if (map[i][j] == 'B') {
                    bossX = i;
                    bossY = j;
                }
            }
        }

        for (int i = 0; i < P; i++) {
            st = new StringTokenizer(br.readLine());
            char player = st.nextToken().charAt(0);
            int dmg = Integer.parseInt(st.nextToken());
            damage[player - 'a'] = dmg;
        }

        bossHP = Integer.parseInt(br.readLine());

        System.out.println(simulate());
    }

    static int simulate() {
        int totalDamage = 0;
        Set<Integer> attackers = new HashSet<>();

        while (!queue.isEmpty()) {
            int size = queue.size();

            bossHP -= totalDamage;

            // System.out.println(bossHP + " " + totalDamage);
            
            if(bossHP <= 0) break;

            for (int i = 0; i < size; i++) {
                Player p = queue.poll();

                if (p.x == bossX && p.y == bossY) {
                    // System.out.println("attack: " + p.id);
                    attackers.add(p.id);
                    totalDamage += damage[p.id];
                    continue;
                } 
                for (int d = 0; d < 4; d++) {
                    int nx = p.x + dx[d];
                    int ny = p.y + dy[d];
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[nx][ny] != 'X' && !visited[p.id][nx][ny]) {
                        visited[p.id][nx][ny] = true;
                        queue.offer(new Player(nx, ny, p.id));
                    }
                }
            }
        }

        return attackers.size();
    }

    static class Player {
        int x, y, id;
        Player(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }
    }
}

import java.io.*;
import java.util.*;

class Main {
    static int N, M;
    static int[][] wood;
    static boolean[][] visited;
    static int maxStrength = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        wood = new int[N][M];
        visited = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                wood[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(0, 0, 0);

        System.out.println(maxStrength);
    }

    static void dfs(int x, int y, int strength) {
        if (y == M) {
            y = 0;
            x++;
        }

        if (x == N) {
            maxStrength = Math.max(maxStrength, strength);
            return;
        }

        if (!visited[x][y]) {
            if (x + 1 < N && y + 1 < M && !visited[x][y + 1] && !visited[x + 1][y]) {
                visited[x][y] = visited[x][y + 1] = visited[x + 1][y] = true;
                dfs(x, y + 1, strength + wood[x][y] * 2 + wood[x][y + 1] + wood[x + 1][y]);
                visited[x][y] = visited[x][y + 1] = visited[x + 1][y] = false;
            }

            if (x + 1 < N && y - 1 >= 0 && !visited[x][y - 1] && !visited[x + 1][y]) {
                visited[x][y] = visited[x][y - 1] = visited[x + 1][y] = true;
                dfs(x, y + 1, strength + wood[x][y] * 2 + wood[x][y - 1] + wood[x + 1][y]);
                visited[x][y] = visited[x][y - 1] = visited[x + 1][y] = false;
            }

            if (x - 1 >= 0 && y - 1 >= 0 && !visited[x - 1][y] && !visited[x][y - 1]) {
                visited[x][y] = visited[x - 1][y] = visited[x][y - 1] = true;
                dfs(x, y + 1, strength + wood[x][y] * 2 + wood[x - 1][y] + wood[x][y - 1]);
                visited[x][y] = visited[x - 1][y] = visited[x][y - 1] = false;
            }

            if (x - 1 >= 0 && y + 1 < M && !visited[x - 1][y] && !visited[x][y + 1]) {
                visited[x][y] = visited[x - 1][y] = visited[x][y + 1] = true;
                dfs(x, y + 1, strength + wood[x][y] * 2 + wood[x - 1][y] + wood[x][y + 1]);
                visited[x][y] = visited[x - 1][y] = visited[x][y + 1] = false;
            }
        }

        dfs(x, y + 1, strength);
    }
}

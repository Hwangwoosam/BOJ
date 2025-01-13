import java.io.*;
import java.util.*;

class Main {
    static int n;
    static int[][] board;
    static boolean[][] visited;
    static int[] dx = {-1, -1, 1, 1};
    static int[] dy = {-1, 1, -1, 1};
    static int blackAnswer = 0;
    static int whiteAnswer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(0, 0, 0, true);
        dfs(0, 1, 0, false);

        System.out.println(blackAnswer + whiteAnswer);
    }

    static void dfs(int row, int col, int count, boolean isBlack) {
        while (row < n) {
            while (col < n) {
                if ((row + col) % 2 == (isBlack ? 0 : 1) && board[row][col] == 1) {
                    if (canPlace(row, col)) {
                        visited[row][col] = true;
                        dfs(row, col + 1, count + 1, isBlack);
                        visited[row][col] = false;
                    }
                }
                col += 1;
            }
            row += 1;
            col = 0;
        }

        if (isBlack) {
            blackAnswer = Math.max(blackAnswer, count);
        } else {
            whiteAnswer = Math.max(whiteAnswer, count);
        }
    }

    static boolean canPlace(int row, int col) {
        for (int i = 0; i < 4; i++) {
            int nx = row + dx[i];
            int ny = col + dy[i];
            while (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (visited[nx][ny]) return false;
                nx += dx[i];
                ny += dy[i];
            }
        }
        return true;
    }
}

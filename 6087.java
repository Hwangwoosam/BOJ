import java.util.*;
import java.io.*;

public class Main {
    static int W, H;
    static char[][] map;
    static int[][] mirrors;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static Point start, end;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        map = new char[H][W];
        mirrors = new int[H][W];
        boolean foundStart = false;

        for (int i = 0; i < H; i++) {
            String line = br.readLine();
            for (int j = 0; j < W; j++) {
                map[i][j] = line.charAt(j);
                mirrors[i][j] = Integer.MAX_VALUE;
                if (map[i][j] == 'C') {
                    if (!foundStart) {
                        start = new Point(i, j, -1, 0);
                        foundStart = true;
                    } else {
                        end = new Point(i, j, -1, 0);
                    }
                }
            }
        }

        System.out.println(bfs());
    }

    static int bfs() {
        Queue<Point> queue = new LinkedList<>();
        queue.offer(start);
        mirrors[start.x][start.y] = 0;

        while (!queue.isEmpty()) {
            Point cur = queue.poll();

            if (cur.x == end.x && cur.y == end.y) {
                return cur.mirrors;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                
                int newMirrors = (cur.dir == i || cur.dir == -1) ? cur.mirrors : cur.mirrors + 1;

                while (nx >= 0 && nx < H && ny >= 0 && ny < W && map[nx][ny] != '*') {
                    if (newMirrors < mirrors[nx][ny]) {
                        mirrors[nx][ny] = newMirrors;
                        queue.offer(new Point(nx, ny, i, newMirrors));
                    }
                    nx += dx[i];
                    ny += dy[i];
                }
            }
        }

        return -1;
    }

    static class Point {
        int x, y, dir, mirrors;

        Point(int x, int y, int dir, int mirrors) {
            this.x = x;
            this.y = y;
            this.dir = dir;
            this.mirrors = mirrors;
        }
    }
}

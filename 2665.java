import java.io.*;
import java.util.*;

class Pair implements Comparable<Pair> {
    int x, y, blackRooms;

    Pair(int x, int y, int blackRooms) {
        this.x = x;
        this.y = y;
        this.blackRooms = blackRooms;
    }

    @Override
    public int compareTo(Pair other) {
        if (this.blackRooms != other.blackRooms) {
            return this.blackRooms - other.blackRooms;
        }
        if (this.x != other.x) {
            return this.x - other.x;
        }
        return this.y - other.y;
    }
}

public class Main {
    static int n;
    static int[][] maze;
    static int[][] dist;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        maze = new int[n][n];
        dist = new int[n][n];

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                maze[i][j] = line.charAt(j) - '0';
                dist[i][j] = Integer.MAX_VALUE;
            }
        }

        System.out.println(bfs());
    }

    static int bfs() {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.offer(new Pair(0, 0, 0));
        dist[0][0] = 0;

        while (!pq.isEmpty()) {
            Pair cur = pq.poll();
            int x = cur.x;
            int y = cur.y;
            int blackRooms = cur.blackRooms;

            if (x == n - 1 && y == n - 1) return blackRooms;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                int newBlackRooms = blackRooms + (maze[nx][ny] == 0 ? 1 : 0);

                if (newBlackRooms < dist[nx][ny]) {
                    dist[nx][ny] = newBlackRooms;
                    pq.offer(new Pair(nx, ny, newBlackRooms));
                }
            }
        }

        return -1;
    }
}

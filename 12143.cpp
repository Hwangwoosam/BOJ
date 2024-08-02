#include <iostream>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

using namespace std;

unordered_map<string, int> imap;
int V;
#define INF 123456789
#define S 0
#define T 1

struct Edge {
    int to, c, f;
    Edge(int _to, int _c) : to(_to), c(_c), f(0) {}
    int remain() {
        return c - f;
    }
    void add(int _f) {
        f += _f;
    }
};

int idx(string s) {
    if (imap.count(s))
        return imap[s];
    return (imap[s] = imap.size() + 1);
}

void addEdge(vector<vector<int>> &g, vector<Edge> &edges, int u, int v, int c) {
    edges.push_back(Edge(v, c));
    edges.push_back(Edge(u, 0));
    g[u].push_back(edges.size() - 2);
    g[v].push_back(edges.size() - 1);
}

int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        int N;
        cin >> N;
        string line, s;
        cin.ignore(10000, '\n');

        vector<vector<int>> lines(N);
        imap.clear();

        for (int i = 0; i < N; i++) {
            getline(cin, line);
            stringstream ss(line);
            while (ss >> s) {
                lines[i].push_back(idx(s));
            }
        }

        int ans = 0;
        vector<vector<int>> g(imap.size() * 2 + 2);
        vector<Edge> edges;

        for (int x : lines[0]) {
            addEdge(g, edges, S, x * 2, INF);
        }

        for (int x : lines[1]) {
            addEdge(g, edges, x * 2 + 1, T, INF);
        }

        for (int i = 1; i <= imap.size(); i++) {
            addEdge(g, edges, i * 2, i * 2 + 1, 1);
        }

        for (int i = 2; i < N; i++) {
            for (int j = 0; j < lines[i].size(); j++) {
                for (int k = j + 1; k < lines[i].size(); k++) {
                    addEdge(g, edges, lines[i][j] * 2 + 1, lines[i][k] * 2, INF);
                    addEdge(g, edges, lines[i][k] * 2 + 1, lines[i][j] * 2, INF);
                }
            }
        }

        while (true) {
            vector<bool> visited(imap.size() * 2 + 2, false);
            visited[S] = true;
            queue<int> q;
            q.push(S);
            vector<int> parent(imap.size() * 2 + 2, -1);
            vector<int> parentEdge(imap.size() * 2 + 2, -1);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (cur == T)
                    break;
                for (int idx : g[cur]) {
                    Edge &e = edges[idx];
                    if (!visited[e.to] && e.remain() > 0) {
                        visited[e.to] = true;
                        parent[e.to] = cur;
                        parentEdge[e.to] = idx;
                        q.push(e.to);
                    }
                }
            }
            if (!visited[T])
                break;

            int flow = INF;
            for (int i = T; i != S; i = parent[i]) {
                flow = min(flow, edges[parentEdge[i]].remain());
            }
            for (int i = T; i != S; i = parent[i]) {
                edges[parentEdge[i]].add(flow);
                edges[parentEdge[i] ^ 1].add(-flow);
            }
            ans += flow;
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
    return 0;
}

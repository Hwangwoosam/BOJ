#include <iostream>
using namespace std;

int idx[500];
bool chk[500][500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	for (int i = 1; i <= N; i++) chk[i][0] = chk[i][i] = 1;
	chk[1][N] = chk[N][1] = 1;
	int cnt = N * (N - 1) / 2;

	cout << "a1";
	int cur = 1;
	for (int i = 1; i < cnt; i++) {
		int& idxcur = idx[cur];
		while (chk[cur][idxcur]) idxcur++;
		chk[cur][idxcur] = chk[idxcur][cur] = 1;
		cur = idx[cur];
		cout << ' ' << 'a' << cur;
	}

	cout << ' ' << "a1";
}
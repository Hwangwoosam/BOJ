#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,k;
	cin >> n >> k;

	for (int i=0; i<k; i++) {
		int num;
		cin >> num;
		vector<int> cur(num);
		for (int j=0; j<num; j++) {
			cin >> cur[j];
			cur[j]++;
		}

		//1~N까지 인덱스 이므로 +1;
		

		sort(cur.begin(), cur.end());

		//현재 cur값은 다른 집합의 서열이 낮은 개수
		//cur + 현재 서열 위치 = 이전 서열
		for (int j=0; j<num; j++){ 
			cout << cur[j] + j << " ";
		}
		cout << "\n";
	}
}
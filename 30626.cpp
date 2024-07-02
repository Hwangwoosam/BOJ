#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

vector<pair<int,int>> v;

/*  90
180     0
    270
*/

// 중앙 값은 E를 기준으로 각도 = (a + 180) % 360;
// 범위 : 각도 - b <= x <= 각도 + b;

// 최소 -180 < < 최대 540

// n : 1000000
int cnt[721];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;

        cnt[a+180-b] ++;
        cnt[a+181+b] --;
    }

    int answer = 0;
    /*-180 ~ 540*/
    for(int i = 1; i <= 720; i++){
        cnt[i] += cnt[i-1];
    }

    for(int i = 0; i < 360; i++){
        if(cnt[i] || cnt[i+360]){
            answer++;
        }
    }

    cout << answer << "\n";
    return 0;
}
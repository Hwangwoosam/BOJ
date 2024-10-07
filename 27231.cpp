#include <iostream>
#include <climits>
#include <cmath>
#include <set>

using namespace std;

set<int> nums;
string n;
int strSize;

void dfs(int cur, int num, int tmp){
    if(cur == strSize){
        num += tmp;
        nums.insert(num);
        return;
    }

    dfs(cur+1,num + tmp*10 + (n[cur]-'0'),0);
    dfs(cur+1,num, tmp*10+ (n[cur]-'0'));
}

int cal(int m){
    int ret = 0;
    for(int i = 0; i < strSize; i++){
        ret += pow(n[i]-'0',m);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        strSize = n.length();
        bool flag = false;
        for(int i = 0; i < strSize; i++){ 
            if(n[i] >= '2') {
                flag = true;
                break;
            }
        }
        
        if(!flag){
            cout << "Hello, BOJ 2023!\n";
        }else{
            dfs(0,0,0);

            int maxVal = stoi(n);
            int m = 1;
            int ans = 0;
            while(1){
                int calVal = cal(m);
                // cout << "val: " << calVal << "\n";
                if(calVal < 0)break;
                if(nums.find(calVal) != nums.end()) ans++;
                if(calVal > maxVal) break;

                m++;
            }
            cout << ans << "\n";
            nums.clear();
        }
    }

    return 0;
}
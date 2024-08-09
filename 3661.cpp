#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }

    return a.first > b.first;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int p,n;
        cin >> p >> n;
        
        int totalSum = 0, curSum = 0;
        vector<int> money(n,0);
        vector<int> pay(n,0);
        vector<pair<int,int>> morePay;

        int share = p/n;

        for(int i = 0; i < n; i++){
            cin >> money[i];
            totalSum += money[i];

            pay[i] = min(share,money[i]);

            curSum += pay[i];
            if(pay[i] < money[i]){
                morePay.push_back({money[i]-pay[i],i});
            }
        }

        if(p > totalSum){
            cout << "IMPOSSIBLE\n";
        }else if(p == curSum){
            for(int i = 0 ; i < n; i++){
                cout << pay[i] << " ";
            }
            cout << "\n";
        }else{
            sort(morePay.begin(),morePay.end(),cmp);
            queue<pair<int,int>> q(deque<pair<int,int>>(morePay.begin(),morePay.end()));

            while(!q.empty() && curSum < p){
                int idx = q.front().second;
                int curVal = q.front().first;
                q.pop();

                curSum++;
                pay[idx]++;
                curVal--;

                if(pay[idx] < money[idx]){
                    q.push({curVal,idx});
                }

            }

            for(int i = 0; i < n; i++){
                cout << pay[i] << " ";
            }
            cout << "\n";
        }

    }

    return 0;
}
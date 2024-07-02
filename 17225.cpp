#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie();

    int a,b,n;
    cin >> a >> b >> n;
    int maxR = -1, maxB = -1;
    for(int i = 0; i < n; i++){
        int t,m;
        char c;
        cin >> t >> c >> m;

        int cnt = 0;
        if(c == 'B'){
            if(maxB > t)  t = maxB;
            for(int j = t; cnt < m; j += a){
                pq.push(make_pair(j,c));
                cnt += 1;
            }
            maxB = t +m*a;
        }else{
            if(maxR > t)  t = maxR;
            for(int j = t; cnt < m; j += b){
                pq.push(make_pair(j,c));
                cnt += 1;
            }
            maxR = t +m*b;
        }   
    }

    vector<int> ans1,ans2;
    int idx = 1;
    while(!pq.empty()){
        char c = pq.top().second;
        if(c == 'B'){
            ans1.push_back(idx++);
        }else{
            ans2.push_back(idx++);
        }
        pq.pop();
    }

    int s1 = ans1.size();

    cout << s1 << "\n";
    for(int i = 0; i < s1; i++){
        cout << ans1[i] << ' ';
    }
    cout << "\n";

    int s2 = ans2.size();

    cout << s2 << "\n";
    for(int i = 0; i < s2; i++){
        cout << ans2[i] << ' ';
    }
    cout << "\n";


    return 0;
}
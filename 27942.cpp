#include <iostream>
#include <queue>

using namespace std;

//상하좌우
//0123
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int map[3002][3002];

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string ans;
    int sum = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }

    pair<int,int> leftUp = {n/2,n/2};
    pair<int,int> rightDown = {n/2 + 1, n/2 + 1};
 
    while(1){
        int upSide = 0,downSide = 0,leftSide = 0,rightSide = 0;
        int rowVal = rightDown.second - leftUp.second;
        int colVal = rightDown.first - leftUp.first;

        for(int i = 0; i <= rowVal; i++){
            upSide += map[leftUp.first-1][leftUp.second+i];
            downSide += map[rightDown.first+1][leftUp.second+i];
        }

        for(int i = 0; i <= colVal; i++){
            leftSide += map[leftUp.first + i][leftUp.second-1];
            rightSide += map[leftUp.first + i][rightDown.second+1];
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        pq.push({upSide,0});
        pq.push({downSide,1});
        pq.push({leftSide,2});
        pq.push({rightSide,3});

        int next = pq.top().second;
        int nextVal = pq.top().first;

        if(nextVal <= 0) break;

        sum += nextVal;

        if(next == 0){
            if(leftUp.first-1 <= 0) break;
            leftUp.first -= 1;
            ans += "U";
        }else if(next == 2){
            if(leftUp.second-1 <= 0) break;
            leftUp.second -= 1;
            ans += "L";
        }else if(next == 1){
            if(rightDown.first+1 > n) break;
            rightDown.first += 1;
            ans += "D";
        }else if(next == 3){
            if(rightDown.second+1 > n) break;
            rightDown.second += 1;
            ans += "R";
        }
    }

    cout << sum << "\n";
    cout << ans << "\n";
    return 0;
}
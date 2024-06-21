#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int n,k;
int answer = INT_MAX;
vector<pair<int,int>> colors[101];

void findSquare(int idx, int maxX, int maxY, int minX,int minY){
    if(idx > k){
        answer = min(answer, abs(maxX-minX) * abs(maxY-minY));
        return;
    }

    int cSize = colors[idx].size();

    for(int i = 0; i < cSize; i++){
        int nMaxX = max(maxX,colors[idx][i].first);
        int nMaxY = max(maxY,colors[idx][i].second);
        int nMinX = min(minX,colors[idx][i].first);
        int nMinY = min(minY,colors[idx][i].second);
        int nSize = abs(nMaxX-nMinX) * abs(nMaxY - nMinY);

        if(nSize < answer || idx == 1){
            findSquare(idx+1,nMaxX,nMaxY,nMinX,nMinY);
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x,y,k;
        cin >> x >> y >> k;
        colors[k].push_back({x,y});
    }

    findSquare(1,-1001,-1001,1001,1001);
    cout << answer << "\n";

    return 0;
}
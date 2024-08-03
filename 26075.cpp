#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int n,m;

    cin >> n >> m;

    string s,t;
    cin >> s >> t;
    
    vector<int> sIdx,tIdx;
    for(int i = 0; i < n+m; i++){
        if(s[i] == '1') sIdx.push_back(i);
        if(t[i] == '1') tIdx.push_back(i);
    }

    long ans = 0;
    long dist = 0;
    for(int i = 0 ; i < m; i++) dist += abs(sIdx[i] - tIdx[i]);

    if(dist%2 == 0){
        dist = dist >> 1;
        ans = 2*dist*dist;
    }else{
        dist = dist >> 1;
        ans = (dist+1)*(dist+1) + dist*dist;
    }

    cout << ans << "\n";


    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n,m,l;

bool checkValue(int mid){
    int cnt = 0;
    int vSize = v.size();
    for(int i = 1; i < vSize; i++){
        int dist = v[i] - v[i-1];
        cnt += dist/mid;

        if(dist % mid == 0){
            cnt--;
        }
    }

    return cnt > m; 
}

int main(){
    cin >> n >> m >> l;

    v.push_back(0);
    v.push_back(l);

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        v.push_back(k);
    }    

    sort(v.begin(),v.end());

    int st = 1, en = l;
    int mid, ret = 0;
    while(st <= en){
        mid = (st+en)/2;
        if(checkValue(mid)){
            st = mid + 1;
        }else{
            ret = mid;
            en = mid - 1;
        }
    }

    cout << ret << "\n";
    return 0;
}
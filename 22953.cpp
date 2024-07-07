#include <iostream>
#include <climits>
#include <vector>

#define INF 98760000000000

using namespace std;

int n,c;
long long k;
long long ans = INF;
vector<int> cook;

bool possible(long long sec){
    long long sum = 0;
    int cSize = cook.size();
    for(int i = 0; i < cSize; i++){
        sum += (long long)(sec/ max((long long)1,(long long)cook[i]));
    }

    if(sum >= k) return true;
    else return false;
}

void binarySearch(){
    long long low = 1, high = INF;
    long long mid = (low + high) / 2;
    long long tmp = INF;

    while(low <= high){
        // cout << "mid: " << mid << "\n";
        mid = (low + high) / 2;
        if(possible(mid)){
            tmp = min(tmp,mid);
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    
    if(ans > tmp) ans = tmp;
}

void findCase(int chance){
    if(chance == 0){
        binarySearch();
        return;
    }else{
        int cSize = cook.size();
        for(int i = 0; i < cSize; i++){
            cook[i]--;
            findCase(chance-1);
            cook[i]++;
        }
    }
}

int main(){
    cin >> n >> k >> c;

    for(int i = 0; i < n; i++){
        long long t;
        cin >> t;
        cook.push_back(t);
    }

    findCase(c);

    cout << ans << "\n";

    return 0;
}
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int n,t;
vector<long long> c;
vector<long long> d;
long long sum[100001];
bool checkSum(long long testSet){
    
    sum[0] = c[0];
    for(int i = 0; i < n; i++){
        if(sum[i] >= testSet){
            sum[i+1] = c[i+1] + d[i]; // 이전 값이 testSet보다 크기에 di는 다음 것으로 넘김
        }else if(sum[i] + d[i] >= testSet){
            sum[i+1] = c[i+1] + (sum[i]+d[i]-testSet); // testSet보다 클경우 남는 것은 다음 것으로 이동
        }else{
            return false;
        }
    }

    if(sum[n-1] >= testSet) return true;

    return false;
}

long long bSearch(long long start,long long end){
    if(start == end) return start;

    long long mid = (start+end+1)/2;
    // cout << mid << "\n";

    if(checkSum(mid)) return bSearch(mid,end);
    else return bSearch(start,mid-1);
}

int main(){
    cin >> n >> t;

    for(int i = 0; i < t; i++){
        if(!c.empty()) c.clear();
        if(!d.empty()) d.clear();

        for(int j = 0; j < 2*n - 1; j++){
            long long tmp;
            cin >> tmp;
            if(j%2 == 0){
                c.push_back(tmp);
            }
            else{ 
                d.push_back(tmp);
            }
        }

        long long answer = bSearch(0,(long long) 2000000000000);
        cout << answer << "\n";
    }

    return 0;
}
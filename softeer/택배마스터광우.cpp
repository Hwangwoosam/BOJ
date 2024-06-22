#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n,m,k;
int answer = INT_MAX;
vector<int> rail;

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int weight;
        cin >> weight;

        rail.push_back(weight);
    }

    sort(rail.begin(),rail.end());

    do{
        int cnt = 0, sum = 0, idx = 0;

        while(cnt < k){
            int temp = 0;
            while(temp + rail[idx] <= m){
                temp += rail[idx];
                idx = (idx+1)%n;
            }
            sum += temp;
            cnt++;
        }

        if(answer > sum) answer = sum;
    }while(next_permutation(rail.begin(),rail.end()));

    cout << answer << "\n";

    return 0;
}
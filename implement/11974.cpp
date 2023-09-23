#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main(){
    cin >> n;
    vector<int> cows[7];
    
    long long idx = 0;
    for(int i = 0; i < n; i++){
        int cowId;
        cin >> cowId;
        
        idx += cowId;
        idx %= 7;
        cows[idx].push_back(i);
    }

    int cnt = 0;
    if(idx == 0){
        cnt = n;
    }else{
        for(int i = 0; i < 7; i++){
            if(cows[i].size()){
                cnt = max(cnt, cows[i].back() - cows[i].front());
            }
        }
    }

    cout << cnt << "\n";


    return 0;
}
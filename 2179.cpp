#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int bigIdx = 0;
int smallIdx = 0;
int maxScore = 0;

int main(){
    cin >> n;

    vector<string> words(n);

    for(int i = 0; i < n; i++) cin >> words[i];

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(words[i] == words[j]) continue;
 
            int fword = words[i].length();
            int sword = words[j].length();

            int big = fword >= sword ? i : j;
            int small = fword < sword ? i : j;
            int minLen = words[small].length();

            int cnt = 0;
            for(int k = 0; k < minLen; k++){
                if(words[big][k] != words[small][k]) break;
                // cout << words[big][k] << " " << words[small][k] << "\n";  
                cnt++;
            }
            
            if(maxScore < cnt){
                // cout << words[i] << " " << words[j] << " " << cnt << "\n";
                bigIdx = big;
                smallIdx = small;
                maxScore = cnt;
            }
        }
    }

    if(bigIdx > smallIdx){
        int tmp = bigIdx;
        bigIdx = smallIdx;
        smallIdx = tmp;
    }

    cout << words[bigIdx] << "\n" << words[smallIdx] << "\n";

    return 0;
}
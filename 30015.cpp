#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> val;

int main(){
    int n,k;
    int answer = 0;
    cin >> n >> k;

    val.resize(n,0);
    for(int i = 0; i < n; i++) cin >> val[i];

    // vector<int> zeros(n,1);
    // fill_n(zeros.begin(),k,0);
    // do{ 
    //     int ret = -1;
    //     for(int i = 0; i < n; i++){
    //         if(zeros[i] == 0) ret = ret & val[i];
    //     }

    //     if(answer < ret) answer = ret;
    // }while(next_permutation(zeros.begin(),zeros.end()));

    vector<int> valCopy(val.begin(),val.end()), hasBit;
    for(int i = 19; i >= 0; i--){
        int curBit = 1 << i;
        int vSize = valCopy.size();
        hasBit.clear();

        for(int j = 0; j < vSize; j++){
            if(curBit & valCopy[j]){
                // cout << valCopy[j] << " " << curBit << "\n";
                hasBit.push_back(valCopy[j]);
            }
        }

        if(hasBit.size() >= k){
            answer = answer|curBit;
            valCopy = hasBit;
        }
    }

    cout << answer << "\n";
    return 0;
}
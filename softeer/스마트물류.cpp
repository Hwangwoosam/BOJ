#include <iostream>
#include <string>

using namespace std;

int n,k;
string inp;

int main(){
    cin >> n >> k;
    cin >> inp;
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(inp[i] =='P'){
            for(int j = i-k; j <= i+k; j++){
                if(j < 0 || j >= n) continue;
                if(inp[j] == 'H'){
                    inp[j] = '-';
                    answer++;
                    break;
                }
            }

        }

    }

    cout << answer << "\n";
    return 0;
}
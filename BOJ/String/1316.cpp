#include <iostream>
#include <cstring>
#include <string>

bool alp[26];
int n,cnt;

int main(){
    std::string inp;

    std::cin >> n;

    for(int i = 0; i < n; i++){
        memset(alp,0,sizeof(alp));
        std::cin >> inp;
        bool flag = false;
        for(int j = 0; j < inp.length();j++){
            int idx = inp[j] -'a';

            if(alp[idx]){
                flag = true;
                break;        
            }
            
            for(int k= j+1; k < inp.length(); k++){
                if(inp[j] != inp[k]){
                    alp[idx] = true;
                    j = k -1;
                    break;
                }
            }
        }

        if(!flag){
            cnt++;
        }
    }
    std::cout << cnt << "\n";

    return 0;
}
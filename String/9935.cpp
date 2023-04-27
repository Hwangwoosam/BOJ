#include <iostream>
#include <string>

int main(){
    std::string inp,bomb;
    std::string ans = "";

    std::cin >> inp >> bomb;

    int bomb_len = bomb.length();
    int idx = 0;

    while(1){
        if(idx == inp.length()){
            break;
        }
        if(inp[idx] == bomb.back()){
            int j = 0;
            bool checker = false;
            for(j = 1; j < bomb_len; j++){
                if(ans[ans.length()-j] != bomb[bomb_len-1-j]){
                    checker = true;
                    break;
                }
            }

            if(!checker){
                ans.erase(ans.length()-j + 1,ans.length());
            }else{
                ans += inp[idx];
            }
        }else{
            ans += inp[idx];
        }

        idx++;
    }
    if(ans ==""){
        ans = "FRULA";
    }
    std::cout << ans << "\n";
    return 0;
}
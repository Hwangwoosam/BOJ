#include <iostream>
#include <string>
#include <regex>

int n;

int main(){
    std::cin >> n;

    std::regex pattern("(100+1+|01)+");

    for(int i = 0; i < n; i++){
        std::string inp;
        std::cin >> inp;

        if(std::regex_match(inp,pattern)){
            std::cout << "YES\n";
        }else{
            std::cout <<"NO\n";
        }
    }

    return 0;
}
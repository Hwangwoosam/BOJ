#include <iostream>
#include <vector>
#include <string>

int main(){
    std::string inp;

    std::cin >> inp;
    std::vector<std::string> check_word = {"c=","c-","dz=","d-","lj","nj","s=","z="};

    for(int i = 0; i < check_word.size();i++){
        while(1){
            int idx = inp.find(check_word[i]);
            if(idx == std::string::npos){
                break;
            }
            inp.replace(idx,check_word[i].length(),"#");
        }
    }

    std::cout << inp.length() << "\n";
    return 0;
}
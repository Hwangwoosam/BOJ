#include <iostream>

// a + bx = cx
int main(){
    int a,b,c;
    std::cin >> a >> b >> c;
    if(b >= c){
        std::cout << -1 << "\n";
    }else{
        std::cout << a/(c-b) + 1 << "\n";
    }

    
    return 0;
}
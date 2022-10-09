#include <iostream>

int n,m;

std::string arr[105][105];

std::string add(std::string n1, std::string n2){
    std::string num = "";

    int sum = 0;
    int size = std::max(n1.size(),n2.size());
    
    for(int i = 0; i < size || sum; i++){
        if(n1.size() > i) sum += n1[i] -'0';
        if(n2.size() > i) sum += n2[i] -'0';

        num += sum%10 + '0';
        sum /= 10;
    }

    return num;
}

std::string combination(int n, int m){

    if(n == m || m == 0) return "1";

    std::string& ans = arr[n][m];

    if(ans != "") return ans;

    ans = add(combination(n-1,m-1),combination(n-1,m));
    return ans;
}

int main(){
    std::cin >> n >> m;

    combination(n,m);

    for(int i = arr[n][m].size()-1; i >= 0; i--){
        std::cout << arr[n][m][i];
    }

    return 0;
}
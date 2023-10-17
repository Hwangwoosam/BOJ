#include <iostream>
#include <memory.h>

using namespace std;

int b[3];
int dp[500][500][2];

// Turn A : false , Turn B : true
bool checkWinner(int firstBox, int secondBox, bool player){
    if(dp[firstBox][secondBox][player] != -1) return dp[firstBox][secondBox][player];

    for(int i = 0; i < 3; i++){
        if(b[i] <= firstBox && !checkWinner(firstBox-b[i],secondBox,!player)) return dp[firstBox][secondBox][player] = true;
        if(b[i] <= secondBox && !checkWinner(firstBox,secondBox-b[i],!player)) return dp[firstBox][secondBox][player] = true;
    }

    return dp[firstBox][secondBox][player] = false;
}

int main(){
    for(int i = 0; i < 3; i++){
        cin >> b[i];
    }

    for(int i = 0; i < 5; i++){
        memset(dp, -1, sizeof(dp));
        int firstBox,secondBox;
        cin >> firstBox >> secondBox;
        
        if(checkWinner(firstBox,secondBox,false)){
            cout << "A\n";
        }else{
            cout << "B\n";
        }
    }

    return 0;
}
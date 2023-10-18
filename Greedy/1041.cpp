#include <iostream>
#include <algorithm>

using namespace std;

int dice[6];
// (0,5) , (1,4)   (2,3)
// (A,F) , (B,E) , (C,D)
int main(){
    int maxVal = 0;
    long long n;
    long long answer = 0;
    cin >> n;
    
    for(int i = 0; i < 6; i++){
        cin >> dice[i];
        answer += dice[i];
        maxVal = max(maxVal,dice[i]);
    }

    if(n == 1){
        answer -= maxVal;
    }else{
        answer = 0;
        int minValue[3];
        minValue[0] = min(dice[0],dice[5]);
        minValue[1] = min(dice[1],dice[4]);
        minValue[2] = min(dice[2],dice[3]);

        sort(minValue, minValue+3);
        
        int sum1 = minValue[0];
        int sum2 = sum1 + minValue[1];
        int sum3 = sum2 + minValue[2];

    //8개 꼭짓점 중 4개는 3면 4개는 2면
    //2개의 면 보이는 세로 4 (n-1)개 , 윗면 가로 4개는 (n-2)개
    //옆면 4개는 (n-1)*(n-2), 윗면 1개는 (n-2)*(n-2);
        answer += sum3 * 4;
        answer += sum2 * 4 * (2*n - 3);
        answer += sum1 * (4*(n-1)*(n-2) + (n-2)*(n-2));

    }

    cout << answer << "\n";


    return 0;
}
#include <iostream>

using namespace std;

/*
5
5 -- 10
- 10
- 10 -- 20
- - 15
- - 15 -- 30
- - - 20
- - - 20 -- 40
*/

int main(){
    int n;
    cin >> n;

    int left = (n%100);

    for(int dis = 5; dis <= 20; dis+=5){
        if(left < dis){
            cout << (left+4)/5 << "\n";
            break;
        }
        left -= dis;
        if(left < dis){
            cout << (dis - left + 4)/5 << "\n";
            break;
        }
        left -= dis;
    }

    return 0;
}
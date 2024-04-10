#include <iostream>
#include <vector>

using namespace std;

vector<int> room;

int main(){
    long n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        room.push_back(p);
    }
    long b,c;
    long long answer = 0;
    cin >> b >> c;

    for(int i = 0; i < n; i++){
        if(room[i]-b > 0){
            if((room[i]-b) % c == 0){
                answer += (room[i]-b)/c + 1;
            }else{
                answer += (room[i]-b)/c + 2;
            }
        }else{
            answer += 1;
        }
    }

    cout << answer << "\n";

    return 0;
}
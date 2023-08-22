#include <iostream>
#include <vector>

using namespace std;

int n,m,answer;
vector<int> a,b; 

// total,total+distance,speed
int main(){
    cin >> n >> m;

    int distance,speed;
    while(n--){
        cin >> distance >> speed;
        for(int i = 0; i < distance; i++){
            a.push_back(speed);
        }
    }

    while(m--){
        cin >> distance >> speed;
        for(int i = 0; i < distance; i++){
            b.push_back(speed);
        }
    }

    for(int i = 0; i < 100;i++){
        answer = max(answer,b[i]-a[i]);
    }

    cout << answer << "\n";
    return 0;
}
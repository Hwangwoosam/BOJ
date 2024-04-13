#include <iostream>
#include <deque>

using namespace std;
deque<int> dq[4];
// 2: 7 확인

void rotate(int idx,int dir){
    if(dir == 1){
        int num = dq[idx].back();
        dq[idx].pop_back();
        dq[idx].push_front(num);
    }else{
        int num = dq[idx].front();
        dq[idx].pop_front();
        dq[idx].push_back(num);
    }
}

void checkPrev(int idx,int dir){
    // cout << "out-idx: " << idx << "\n";
    if(idx >= 0){
        if(dq[idx][2] != dq[idx+1][6]){
            // cout << "in-idx: " << idx << "\n";
            checkPrev(idx-1,dir*-1);
            rotate(idx,dir);
        }
    }
}

void checkNext(int idx,int dir){
    // cout << "out-idx: " << idx << "\n";
    if(idx < 4){
        if(dq[idx][6] != dq[idx-1][2]){
            // cout << "in-idx: " << idx << "\n";
            checkNext(idx+1,dir*-1);
            rotate(idx,dir);
        }
    }
}

int main(){

    for(int i = 0; i < 4; i++){
        string str;
        cin >> str;
        for(int j = 0; j < 8; j++){
            dq[i].push_back(str[j]-'0');
        }
    }

    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int idx,dir;
        cin >> idx >> dir;
        idx -= 1;
        checkPrev(idx-1,dir*-1);
        checkNext(idx+1,dir*-1);
        rotate(idx,dir);
    }

    int answer = dq[0][0]*1 + dq[1][0]*2 + dq[2][0]*4 + dq[3][0]*8;
    cout << answer <<"\n";

    return 0;
}
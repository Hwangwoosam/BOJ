#include <iostream>
#include <vector>

using namespace std;

vector<int> scores;

int getPercent(int order, int n){
    return (order*100)/ n;
}

int getScore(int percent){
    if(percent >= 0 && percent <= 4) return 1;
    else if(percent > 4 && percent <= 11) return 2;
    else if(percent > 11 && percent <= 23) return 3;
    else if(percent > 23 && percent <= 40) return 4;
    else if(percent > 40 && percent <= 60) return 5;
    else if(percent > 60 && percent <= 77) return 6;
    else if(percent > 77 && percent <= 89) return 7;
    else if(percent > 89 && percent <= 96) return 8;
    else if(percent > 96 && percent <= 100) return 9;

    return 0;
}

int main(){
    int n,k;

    cin >> n >> k;

    for(int i = 0; i < k; i++){
        int num;
        cin >> num;
        scores.push_back(num);
    }

    for(int i = 0; i < k; i++){
        int percent = getPercent(scores[i],n);
        // cout << "percent: " << percent << "\n";
        cout << getScore(percent) << " ";
    }
    cout << "\n";

    return 0;
}
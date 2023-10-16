#include <iostream>
#include <algorithm>

using namespace std;

int n;
double buildings[51];

int getCntForward(int stdIdx, double grad, int curIdx){
    if(curIdx > n) return 0;

    if(buildings[curIdx] > buildings[stdIdx] + grad*(curIdx-stdIdx)){
        return getCntForward(stdIdx,(buildings[curIdx] - buildings[stdIdx])/((double)(curIdx - stdIdx)), curIdx + 1) + 1;
    }
    return getCntForward(stdIdx,grad,curIdx + 1);
}

int getCntBackward(int stdIdx, double grad, int curIdx){
    if(curIdx < 1) return 0;

    if(buildings[curIdx] > buildings[stdIdx] + grad*(stdIdx - curIdx)){
        return getCntBackward(stdIdx,(buildings[curIdx] - buildings[stdIdx])/((double)(stdIdx - curIdx)), curIdx - 1) + 1;
    }
    
    return getCntBackward(stdIdx,grad,curIdx - 1);

}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> buildings[i];
    }

    int maxVal = 0;
    for(int i = 1; i <= n ; i++){
        int a = getCntForward(i,(buildings[i+1] - buildings[i])-1, i+1);
        int b = getCntBackward(i,(buildings[i-1] - buildings[i])-1, i-1);
        // cout << i << ": " << a << " " << b << "\n";
        int sum = a+b;
        maxVal = max(maxVal,sum);
    }

    cout << maxVal << "\n";
    return 0;
}
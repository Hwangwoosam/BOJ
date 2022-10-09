#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    // n이 S보다 클경우 나눌 수 없다.
    if(n > s){
        answer.push_back(-1);
        return answer;
    }
    
    // 균일하게 나누는 것이 곱이 가장 높다.
    for(int i = 0; i < n ; i++){
        int num = s / (n - i); 
        if(s % (n - i) != 0){
            num ++;
        }
        answer.push_back(num);
        s -= num;
    }
    
    //오름차순 정렬
    sort(answer.begin(),answer.end());
    return answer;
}
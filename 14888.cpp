#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;
int oper[4];
int n;
int minVal = INT32_MAX;
int maxVal = INT32_MIN;

void calculation(int numIdx, int result){

    if(numIdx == n){
        if(result > maxVal) maxVal = result;
        if(result < minVal) minVal = result;
        return;
    }else{
        for(int i = 0; i < 4; i++){
            if(oper[i] > 0){
                oper[i]--;

                switch(i){
                    case 0:
                        calculation(numIdx+1,result + numbers[numIdx]);
                        break;
                    case 1:
                        calculation(numIdx+1,result - numbers[numIdx]);
                        break;
                    case 2:
                        calculation(numIdx+1,result * numbers[numIdx]);
                        break;
                    case 3:
                        calculation(numIdx+1,result / numbers[numIdx]);
                        break;
                }

                oper[i]++;
            }
            
        }
    }
}

int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    for(int i = 0; i < 4; i++){
        int times;
        cin >> times;
        oper[i] = times;
    }

    calculation(1,numbers[0]);
    cout << maxVal << "\n" << minVal << "\n";
    return 0;
}
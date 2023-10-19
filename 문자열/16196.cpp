#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>

using namespace std;
vector<string> localNumber;

bool checkLocalNumber(string stdNumber, vector<string> inpNumber){
    bool result = false;

    for(int i = 0; i < inpNumber.size(); i++){
        for(int j = 0; j < 6; j++){
            if(stdNumber[j] != inpNumber[i][j]){
                break;
            }

            if( j == 5){
                result = true;
                break;
            }
        }

        if(result) break;
    }
    // cout << "LocalNumber: " << result << "\n";
    return result;
}

bool checkDate(string inp){
    int year = 0;
    int month = 0;
    int day = 0;

    for(int i = 6; i < 10; i++){
        year = year*10 + (inp[i]-'0');
    }

    month = (inp[10]-'0')*10 + (inp[11]-'0');
    day = (inp[12]-'0')*10 + (inp[13]-'0');
    
    if(year < 1900 || year >2011) return false;

    if(month < 1 || month > 12) return false;

    int maxDay = 0;
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        maxDay = 31;
    }else{
        maxDay = 30;
        if(month == 2){
            if(((year%4 == 0) && (year%100 != 0)) || year%400 == 0){
                maxDay = 29;
            }else{
                maxDay = 28;
            }
        }
    }

    if(day < 1 || day > maxDay){
        return false;
    }
 

    return true;
}

bool caculateChecksum(string inp){
    bool result = false;
    long long x = 0;
    long long mod = pow(2,17);
    
    if(inp[17] == 'X'){
        x = 10;
    }else{
        x = inp[17] - '0';
    }
    for(int i = 0; i < 17; i++){
        x += mod*(inp[i]-'0');
        x = x % 11;
        mod /= 2;
    }

    if(x % 11 == 1){
        result = true;
    }
    // cout << "x: " << x << "\n";
    // cout << "caculateChecksum: " << result << "\n";
    return result;
}

bool checkOrderCode(string inp){
    if(inp[14] == '0' && inp[15] == '0' && inp[16] == '0'){
        return false;
    }

    return true;
}

int main(){
    int n;
    string inp;
    cin >> inp >> n;
    
    for(int i = 0; i < n; i++){
        string localnumber;
        cin >> localnumber;
        localNumber.push_back(localnumber);
    }
    if(checkLocalNumber(inp,localNumber) && caculateChecksum(inp) && checkOrderCode(inp) && checkDate(inp)){
        
        if(inp[16] == 'X' || (inp[16]-'0')%2 == 0){
            cout << "F\n";
        }else{
            cout << "M\n";
        }
    }else{
        cout << "I\n";
    }

    return 0;
}
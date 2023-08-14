#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lines[3];

int main(){
    
    while(1){

        bool flag = false;

        for(int i = 0; i < 3; i++){
            cin >> lines[i];
            if(!flag && lines[i] != 0){
                flag = true;
            }
        }

        if(!flag){
            break;
        }

        sort(lines,lines+3);

        if(lines[2] >= lines[0] + lines[1]){
            cout << "Invalid\n";
        }else if(lines[0] == lines[1] && lines[1] == lines[2]){
            cout <<"Equilateral\n";
        }else if(lines[0] == lines[1] || lines[1] == lines[2]){
            cout <<"Isosceles\n";
        }else{
            cout <<"Scalene\n";
        }
    }


    return 0;
}
#include <iostream>
#include <string>

using namespace std;

bool checkAka(string str){
    int strSize = str.size();
    
    if(strSize == 1) return true;

    int subSize = strSize/2;
    string l = str.substr(0,subSize);
    string r;

    if(strSize % 2 == 1){
        r = str.substr(subSize+1,subSize);
    }else{
        r = str.substr(subSize,subSize);
    }

    // cout << l << " " << r << "\n";

    if( l!=r) return false;
    if(checkAka(l) && checkAka(r)) return true;
    else return false;
}


int main(){
    string inp;
    cin >> inp;

    if(checkAka(inp)){
        cout << "AKARAKA\n";
    }else{
        cout << "IPSELENTI\n";
    }

    return 0;
}
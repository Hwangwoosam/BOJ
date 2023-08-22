#include <iostream>

using namespace std;

int blue = 0, white = 0;

int n;
int map[128][128];

void findPaper(int y,int x,int size){
    int check = map[y][x];
    for(int i = y; i < y+size; i++){
        for(int j = x; j < x+size; j++){

            if (map[i][j] != check){
                findPaper(y,x,size/2);
                findPaper(y+size/2,x,size/2);
                findPaper(y,x+size/2,size/2);
                findPaper(y+size/2,x+size/2,size/2);
                return;
            }
        }
    }

    if(check == 0){
        white++;
    }else{
        blue++;
    }

}

int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    findPaper(0,0,n);

    cout << white << "\n" << blue << "\n";
    return 0;
}
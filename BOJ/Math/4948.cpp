#include <iostream>
#include <cmath>

int n;
int prime_numbers[246912];
int main(){
    int cnt = 0,rt = 0;
    while(1){
        std::cin >> n;
        cnt = 0;

        if(n == 0){
            break;
        }

        for(int i = n + 1; i <= 2*n; i++){
            rt = sqrt(i);

            if(rt == 1 && i != 1){
                cnt++;
                continue;
            }

            if(i % 2){
                for(int j = 2; j <= rt; j++){
                    
                    if((i%j) == 0){
                        break;
                    }
                    
                    if( j == rt){
                        cnt++;
                    }
                }
            }
        }

        std::cout << cnt << "\n";
    }
    return 0;
}
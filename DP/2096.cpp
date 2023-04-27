#include <iostream>

int N;

int input[3];
int prev_max[3];
int prev_min[3];
int r_max[3];
int r_min[3] = {10,};

int main(){
    std::cin >> N;

    std::cin >> prev_max[0] >> prev_max[1] >> prev_max[2];
    for(int i = 0; i < 3; i++){
        prev_min[i] = prev_max[i];
        r_max[i] = prev_max[i];
        r_min[i] = prev_min[i];
    }

    for(int i = 0; i < N-1; i++){
        std::cin >> input[0] >> input[1] >>input[2];
        
        r_max[0] = std::max(prev_max[0],prev_max[1]) + input[0];
        r_max[1] = std::max(std::max(prev_max[0],prev_max[1]),prev_max[2]) +input[1];
        r_max[2] = std::max(prev_max[1],prev_max[2]) + input[2];

        r_min[0] = std::min(prev_min[0],prev_min[1]) + input[0];
        r_min[1] = std::min(std::min(prev_min[0],prev_min[1]),prev_min[2]) +input[1];
        r_min[2] = std::min(prev_min[1],prev_min[2]) + input[2];

        prev_max[0] = r_max[0];
        prev_max[1] = r_max[1];
        prev_max[2] = r_max[2];
    
        prev_min[0] = r_min[0];
        prev_min[1] = r_min[1];
        prev_min[2] = r_min[2];
    }

    std::cout << std::max(r_max[0],std::max(r_max[1],r_max[2])) << " " << std::min(r_min[0],std::min(r_min[1],r_min[2]));

    return 0;
}
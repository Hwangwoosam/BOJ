#include <iostream>

long long n,b;
long long arr[5][5];
long long ans[5][5];


void print_matrix(long long mat[][5]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void multi_mat(long long a[][5],long long b[][5]){
    long long tmp[5][5];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tmp[i][j] = 0;
            for(int k = 0; k < n; k++){
                tmp[i][j] += (a[i][k]*b[k][j]);
            }
            tmp[i][j] %= 1000;
        }
    }

    for(int i=0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = tmp[i][j];
        }
    }
}

int main(){
    std::cin >> n >> b;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> arr[i][j];
        }
        ans[i][i] = 1;
    }

    while(b > 0){
        if(b%2 == 1){
            multi_mat(ans,arr);
        }
        multi_mat(arr,arr);
        b /= 2;
    }

    print_matrix(ans);

    return 0;
}
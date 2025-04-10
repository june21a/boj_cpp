#include <iostream>

using namespace std;


long long arr[2][2] = {{1, 1}, {1, 0}};
long long matrix[2][2];
long long DEV = 1000000007;


long long(*pibo(long long current))[2]{
    if(current == 1) return arr;
    
    long long(*tmp)[2] = pibo(current/2);
    long long tmp2[2][2];
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++) tmp2[i][j] = tmp[i][j] % DEV;
    }
    if(current%2 == 0){
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                long long sum = 0;
                for(int k=0; k<2; k++){
                    sum += tmp2[i][k] * tmp2[k][j] % DEV;
                }
                matrix[i][j] = sum%DEV;
            }
        }
        return matrix;
    }
    else{
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                long long sum = 0;
                for(int k=0; k<2; k++){
                    sum += tmp2[i][k] * tmp2[k][j]%DEV;
                }
                matrix[i][j] = sum%DEV;
            }
        }
        
        long long temp[2][2];
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                long long sum = 0;
                for(int k=0; k<2; k++){
                    sum += matrix[i][k] * arr[k][j]%DEV;
                }
                temp[i][j] = sum%DEV;
            }
        }
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++) matrix[i][j] = temp[i][j]%DEV;
        }
        return matrix;
    }
}

int main()
{
    long long N;
    cin >> N;
    
    if(N == 1 || N == 2) cout << 1;
    else{
        long long(*ans)[2] = pibo(N-1);
        cout << ans[0][0];
    }
}
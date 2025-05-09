#include <iostream>

using namespace std;

int main()
{
    int N; cin >> N;
    int table[N][5];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<5; j++) cin >> table[i][j];
    }
    
    bool check[N][N] = { };
    for(int i=0; i<5; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(k == j) continue;
                if(table[j][i] == table[k][i]) check[j][k] = true;
            }
        }
    }
    
    int cnt[N] = { };
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cnt[i] += check[i][j];
    }
    
    int ans = 0;
    int M = cnt[0];
    for(int i=1; i<N; i++){
        if(M < cnt[i]){
            M = cnt[i];
            ans = i;
        }
    }
    cout << ans+1;
}
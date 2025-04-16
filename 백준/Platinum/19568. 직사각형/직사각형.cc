#include <iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[30][30] = { };
    for(int i=0; i<15; i++) arr[15][i] = 1; // 15개
    for(int i=16; i<30; i++) arr[15][i] = 16; // 14개
    for(int i=0; i<15; i++) arr[i][15] = 16*14 + 15 + 1; // 15개
    for(int i=16; i<30; i++) arr[i][15] = (16*14+16)*15 + 16*14 + 15 + 1;

    for(int i=0; i<30; i++){
        for(int j=0; j<30; j++){
            cout << arr[i][j];
            if(j != 29) cout << ' ';
        }
        if(i != 29) cout << '\n';
    }
}
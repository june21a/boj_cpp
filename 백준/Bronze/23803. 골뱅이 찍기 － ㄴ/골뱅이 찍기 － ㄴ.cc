#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    string ans = "";
    for(int i=0; i<N*4; i++){
        for(int j=0; j<N; j++) ans += "@";
        ans += '\n';
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N*5; j++) ans += "@";
        ans += '\n';
    }

    cout << ans;
}
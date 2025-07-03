#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    while(T--){
        int P, Q, A, B, C, D;
        int ans = 0;
        cin >> P >> Q >> A >> B >> C >> D;
        
        int N = Q/C * D;
        int X;
        if(N > P){
            X = (N-P) / (A+B);
            int new_P = P+A*X;
            int new_N = N-B*X;
            ans = max(ans, min(new_P, new_N));

            new_P += A;
            new_N -= B;
            ans = max(ans, min(new_P, new_N));
        }
        else{
            X = (P-N) / (A+B);
            int new_P = P-A*X;
            int new_N = N+B*X;
            ans = max(ans, min(new_P, new_N));

            new_P -= A;
            new_N += B;
            ans = max(ans, min(new_P, new_N));
        }
        cout << ans << '\n';
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, W; cin >> T >> W;
    int DP[T+1][W+1] = { };
    int ans = 0;
    for(int i=1; i<=T; i++){
        int tree; cin >> tree;

        DP[i][0] = DP[i-1][0] + (tree==1);
        ans = max(ans, DP[i][0]);
        for(int j=1; j<=W; j++){
            DP[i][j] = max(DP[i-1][j], DP[i-1][j-1]) + (tree == (1 + j%2));
            ans = max(ans, DP[i][j]);
        }
    }
    cout << ans;
}
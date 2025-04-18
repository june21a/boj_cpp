#include <iostream>
#define ll long long

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    int DP[N+1];
    DP[0] = DP[1] = 1;
    DP[2] = 2;
    for(int i=3; i<=N; i++) DP[i] = DP[i-1]+DP[i-2];
    
    int s = 1, e = N;
    int ans = 1;
    for(int i=0; i<M; i++){
        int num; cin>>num;
        ans *= DP[num-s];
        s = num+1;
    }
    ans *= DP[max(0, e-s+1)];
    cout << ans;
}
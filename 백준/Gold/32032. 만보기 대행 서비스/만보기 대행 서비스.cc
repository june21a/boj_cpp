#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, D;
    cin >> N >> D;
    ll m=1e9, M=-1e9;
    for(int i=0; i<N; i++){
        ll num; cin >> num;
        m = min(m, num); M = max(M, num);
    }

    if(m >= 0){
        cout << M*2+D;
        return 0;
    }
    if(M <= 0){
        cout << -m*2+D;
        return 0;
    }

    ll ans = (M-m+D)*2;
    ans = min(ans, 2*(M-m)+2*M+D);
    ans = min(ans, 2*(M-m)-2*m+D);
    if(2*(M-m) >= D) ans = min(ans, 4*(M-m));
    else ans = min(ans, 2*(M-m)+D);

    cout << ans;
}
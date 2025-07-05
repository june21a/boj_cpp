#include <bits/stdc++.h>
#define ll long long
#define MAX 500000

using namespace std;

ll road[MAX];
ll traffic = 0;
ll d[MAX] = { };
ll ans[MAX] = { };

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, M; cin >> N >> M;
    
    for(ll i=0; i<N-1; i++) cin >> road[i];
    for(ll i=0; i<M; i++){
        ll a, b, c; cin >> a >> b >> c;
        d[a-1] += c;
        d[b-1] -= c;
    }

    for(ll i=0; i<N-1; i++){
        traffic += d[i];

        ll q = traffic / road[i];
        ll r = traffic % road[i];
        ans[i] += ((q + 1ll) * (q + 1ll)) * r;
        ans[i] += (q*q) * (road[i] - r);
    }

    for(int i=0; i<N-1; i++) cout << ans[i] << '\n';
}
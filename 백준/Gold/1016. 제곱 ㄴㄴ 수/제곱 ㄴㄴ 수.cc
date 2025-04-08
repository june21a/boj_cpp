#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

vector<bool> check;
vector<bool> no_sq;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll m, M; cin >> m >> M;
    ll limit = ceil(sqrt(M));
    ll sub = 0;

    check.resize(limit+1, false);
    no_sq.resize(M-m+1, false);
    for(ll i=2; i<=limit; i++){
        if(check[i]) continue;

        for(ll j=i*i; j<=limit; j += i) check[j] = true;

        ll s = m%(i*i) ? m+(i*i-m%(i*i)):m;
        for(ll j=s; j<=M; j+= i*i) no_sq[j-m] = true;
    }

    ll ans = 0;
    for(bool i : no_sq) ans += (!i);
    cout << ans;
}
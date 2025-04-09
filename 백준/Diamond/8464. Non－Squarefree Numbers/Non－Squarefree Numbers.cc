#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

vector<bool> check;
vector<ll> prime_sq;

ll get_ns(ll e, ll last_value, ll e_idx, int depth, bool is_odd){
    if(depth == 8) return 0;
    
    ll value = 0;
    ll sign = is_odd ? 1:-1;
    
    for(ll i = 0; i<e_idx && last_value*prime_sq[i] <= e; i++){
        value += sign * (e / (last_value*prime_sq[i]));
        value += get_ns(e, last_value*prime_sq[i], i, depth+1, !is_odd);
    }
    return value;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll K; cin >> K;
    ll limit = ceil(sqrt(4*K));

    check.resize(limit+1, false);
    for(ll i=2; i<=limit; i++){
        if(check[i]) continue;
        prime_sq.push_back(i*i);
        for(ll j=i*i; j<=limit; j += i) check[j] = true;
    }
    
    ll left = 1, right=4*K;
    while(left < right){
        ll mid = (left+right)/2;
        if(get_ns(mid, 1, prime_sq.size(), 1, true) < K) left = mid+1;
        else right = mid;
    }
    cout << right;
}
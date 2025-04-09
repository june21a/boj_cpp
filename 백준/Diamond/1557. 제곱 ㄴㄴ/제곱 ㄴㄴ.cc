#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

vector<bool> check;
vector<int> prime_sq;

int get_ns(int e, ll last_value, int s_idx, bool is_odd){
    if(last_value > e) return 0;
    
    int value = 0;
    int ps = prime_sq.size();
    int sign = is_odd ? 1:-1;
    
    for(int i = s_idx; i<ps && last_value*prime_sq[i] <= e; i++){
        value += sign * (e / (last_value*prime_sq[i]));
        value += get_ns(e, last_value*prime_sq[i], i+1, !is_odd);
    }
    return value;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K; cin >> K;
    int limit = ceil(sqrt(2*K));

    check.resize(limit+1, false);
    for(int i=2; i<=limit; i++){
        if(check[i]) continue;
        prime_sq.push_back(i*i);
        for(int j=i*i; j<=limit; j += i) check[j] = true;
    }
    
    ll left = 1, right=2*K;
    while(left < right){
        int mid = (left+right)/2;
        if(mid-get_ns(mid, 1, 0, true) < K) left = mid+1;
        else right = mid;
    }
    cout << right;
}
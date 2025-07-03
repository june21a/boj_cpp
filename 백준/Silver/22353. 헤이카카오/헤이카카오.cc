#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(7);

    ld a, d, k;
    ld ans = 0;
    cin >> a >> d >> k;

    int x = 1;
    d /= 100;
    k /= 100;
    ld fail_rate = 1;
    while(true){
        if(d > 1-1e-6){
            d = 1;
            ans += d*fail_rate*x*a;
            break;
        }
        ans += d*fail_rate*x*a;

        fail_rate *= (1-d);
        x++;
        d *= (1+k);
        
    }
    cout << ans;
}
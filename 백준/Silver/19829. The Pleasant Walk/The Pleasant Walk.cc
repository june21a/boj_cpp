#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];

    if(n==1){
        cout << 1;
        return 0;
    }

    int ans = 1;
    int cur = 1;
    for(int i=1; i<n; i++){
        if(v[i-1] != v[i]) cur += 1;
        else{
            cur = 1;
        }
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}
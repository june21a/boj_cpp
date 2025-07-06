#include <bits/stdc++.h>
#define ll long long
#define MAX 500000

using namespace std;

int N, K;
int a[MAX];
int n1[MAX];
int n2[MAX];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> a[i];

    int ans = INT_MIN;
    n1[0] = a[0];
    for(int i=1; i<N; i++){
        n1[i] = min(n1[i-1], a[i]-K*i);
    }

    for(int i=1; i<N; i++){
        ans = max(ans, a[i]-K*i-n1[i-1]);
    }

    reverse(a, a+N);
    n1[0] = a[0];
    for(int i=1; i<N; i++){
        n1[i] = min(n1[i-1], a[i]-K*i);
    }

    for(int i=1; i<N; i++){
        ans = max(ans, a[i]-K*i-n1[i-1]);
    }
    cout << ans;
}
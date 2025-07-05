#include <bits/stdc++.h>
#define ll long long

using namespace std;



int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, B;
    int T[10000];
    int ans = 0;

    cin >> N >> A >> B;
    for(int i=0; i<N; i++) cin >> T[i];
    sort(T, T+N);

    for(int i=0; i<N; i++){
        for(int j=0; j<A; j++){
            int t = 0;
            int cnt = 0;
            int cost = A;

            for(int k=0; k<N; k++){
                if(k == i){
                    t += B*j;
                    cost -= j;
                }
                if(t+cost <= T[k]){
                    t += cost;
                    cnt += (t <= T[k]);
                }
            }
            ans = max(ans, cnt);
        }
    }


    cout << ans;
}
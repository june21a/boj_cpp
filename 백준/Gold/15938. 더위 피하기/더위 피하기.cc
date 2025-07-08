#include <bits/stdc++.h>
#define ll long long
#define DIV 1000000007

using namespace std;

ll DP[404][404][201] = { };

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x,y; cin >> x >> y;
    int T; cin >> T;
    int tx, ty; cin >> tx >> ty;

    if(abs(tx-x) + abs(ty-y) > T){
        cout << 0;
        return 0;
    }

    // DP에서의 시작지점과 매핑
    int dpx=201, dpy=201;
    int x_diff = dpx-x, y_diff=dpy-y;
    int N; cin >> N;
    tx += x_diff;
    ty += y_diff;
    for(int i=0; i<N; i++){
        int obsx, obsy; cin >> obsx >> obsy;
        obsx += x_diff;
        obsy += y_diff;
        if(obsx >= 0 && obsx < 404 && obsy >= 0 && obsy < 404) DP[obsx][obsy][0] = -1;
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    DP[dpx][dpy][0] = 1;
    int curT = 0;
    while(curT++ < T){
        for(int i=dpx-curT; i<=dpx+curT; i++){
            for(int j=dpy-curT; j<=dpy+curT; j++){
                if(DP[i][j][0] == -1) continue;

                for(int k=0; k<4; k++){
                    int nextx = i+dx[k];
                    int nexty = j+dy[k];
                
                    if(DP[nextx][nexty][0] == -1 || (nextx==tx && nexty==ty)) continue;
                    DP[i][j][curT] = (DP[i][j][curT] + DP[nextx][nexty][curT-1]) % DIV;
                }
            }
        }
    }

    ll ans = 0;
    for(int i=1; i<=T; i++) ans = (ans+DP[tx][ty][i]) % DIV;
    cout << ans;
}
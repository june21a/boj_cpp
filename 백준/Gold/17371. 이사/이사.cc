#include <bits/stdc++.h>
#define ld long double

using namespace std;

ld get_dist(int x1, int y1, int x2, int y2){
    return sqrtl(powl(x1-x2, 2) + powl(y1-y2, 2));
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(9);

    int N; cin >> N;
    vector<pair<int, int>> pos;
    for(int i=0; i<N; i++){
        int hx, hy; cin >> hx >> hy;
        pos.push_back({hx, hy});
    }

    vector<ld> dists(N, 0);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j) continue;
            ld d = get_dist(pos[i].first, pos[i].second, pos[j].first, pos[j].second);
            dists[i] = max(dists[i], d);
            
        }
    }

    int idx = min_element(dists.begin(), dists.end()) - dists.begin();
    pair<int, int> ans = pos[idx];
    cout << ans.first << ' ' << ans.second;
}
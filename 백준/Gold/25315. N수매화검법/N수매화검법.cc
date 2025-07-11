#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>

using namespace std;

int N;
bool cross[2500][2500] = { };
vector<pair<ll, pair<pii, pii>>> line;

int ccw(pii p1, pii p2, pii p3) {
    ll s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1; 
}

bool isIntersect(pair<pii, pii> l1, pair<pii, pii> l2) {
    pii p1 = l1.first;
    pii p2 = l1.second;
    pii p3 = l2.first;
    pii p4 = l2.second;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (p1p2 == 0 && p3p4 == 0) {
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);
        
        return p3 <= p2 && p1 <= p4;
    }
    
    return p1p2 <= 0 && p3p4 <= 0;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        int sx, sy, ex, ey, w;
        cin >> sx >> sy >> ex >> ey >> w;
        line.push_back({w, {{sx, sy}, {ex, ey}}});
    }
    sort(line.begin(), line.end());

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            cross[i][j] = isIntersect(line[i].second, line[j].second);
            cross[j][i] = cross[i][j];
        }
    }

    ll ans = 0;
    for(int i=0; i<N; i++){
        ll cnt = 0;
        for(int j=0; j<N; j++){
            if(cross[i][j]){
                cnt++;
                cross[j][i] = false;
            }
        }
        ans += ((cnt+1)*line[i].first);
    }
    cout << ans;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_VALUE 50001
#define EMPTY -1
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int N, K;
int s=0;
vvi v(200, vi(200, EMPTY));

int get_diff(){
    int m = MAX_VALUE, M=0;
    for(int i=0; i<N; i++){
        m = min(m, v[i][0]);
        M = max(M, v[i][0]);
    }
    return (M-m);
}

void minus_all_min_idx(){
    int m = MAX_VALUE;
    for(int i=0; i<N; i++) m = min(m, v[i][0]);
    for(int i=0; i<N; i++) if(v[i][0] == m) v[i][0]++;
}

bool check_first_lift_up_pos(){
    int l1 = N - s;

    int cnt = 0;
    for(int i=s; i<=N-1; i++) if(v[i][1] != EMPTY) cnt++;

    int l2 = 0;
    for(int i=0; v[s][i] != EMPTY; i++) l2++;

    return (l1 - cnt) >= l2;
}

void first_lift_up(){
    if(!check_first_lift_up_pos()) return;
    v[s+1][1] = v[s][0];
    v[s][0] = EMPTY; s++;

    while(check_first_lift_up_pos()){
        int next_s = s;
        vvi sv;

        for(int i=s; i<=N-1; i++){
            if(v[i][1] == EMPTY) continue;
            next_s = i;

            vi tmp;
            for(int j=0; v[i][j] != EMPTY; j++){
                tmp.push_back(v[i][j]);
                v[i][j] = EMPTY;
            }
            sv.push_back(tmp);
        }

        s = next_s + 1;
        for(int i=0; i<sv.size(); i++){
            int target_line = sv.size()-i;
            for(int j=s; j<s+sv[i].size(); j++){
                v[j][target_line] = sv[i][j-s];
            }
        }
    }
}

void flatten(){
    vi tmp;

    for(int i=s; i<=N-1; i++) {
        for(int j=0; v[i][j] != EMPTY; j++) {
            tmp.push_back(v[i][j]);
            v[i][j] = EMPTY;
        }
    }
    s = 0;
    for(int i=0; i<N; i++){
        v[i][0] = tmp[i];
    }
}

void align(){
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    vvi dv;
    for(int i=s; i<=N-1; i++){
        vi tmp;

        for(int j=0; v[i][j] != EMPTY; j++){
            int diff = 0;
            for(int k=0; k<4; k++){
                int target_i = i + dx[k];
                int target_j = j + dy[k];

                if(target_i < 0 || target_j < 0 || v[target_i][target_j] == EMPTY) continue;
                diff += (v[target_i][target_j] - v[i][j]) / 5;
            }
            tmp.push_back(diff);
        }
        dv.push_back(tmp);
    }

    for(int i=0; i<dv.size(); i++){
        for(int j=0; j<dv[i].size(); j++){
            v[i+s][j] += dv[i][j];
        }
    }
}

void second_lift_up(){
    int next_s = s + N/2;
    for(int i=N/2-1; i>=0; i--){
        v[next_s+(N/2-1-i)][1] = v[i][0];
        v[i][0] = EMPTY;
    }
    s = next_s;

    vector<pair<int, int>> tmp;
    next_s = s + N/4;
    for(int i=next_s-1; i>=s; i--){
        tmp.push_back({v[i][1], v[i][0]});
        v[i][0] = v[i][1] = EMPTY;
    }
    s = next_s;

    for(int i=s; i<=N-1; i++){
        v[i][2] = tmp[i-s].first;
        v[i][3] = tmp[i-s].second;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;

    for(int i=0; i<N; i++) {
        int a; cin >> a;
        v[i][0] = a;
    }

    int cnt = 0;
    while(get_diff() > K){
        minus_all_min_idx();
        first_lift_up();
        align();
        flatten();
        second_lift_up();
        align();
        flatten();
        cnt++;
    }
    cout << cnt;
}
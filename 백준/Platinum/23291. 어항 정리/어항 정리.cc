#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define DIV 5
#define MAX_VALUE 50001
#define EMPTY -1

using namespace std;

int N, K;
int start_idx, end_idx;
vector<vector<int>> v(200, vector<int>(200, EMPTY));

int get_diff(){
    int m = MAX_VALUE, M=0;
    for(int i=0; i<N; i++){
        m = min(m, v[i][0]);
        M = max(M, v[i][0]);
    }
    return (M-m);
}

int get_base_length(){
    return (end_idx - start_idx + 1);
}

void minus_all_min_idx(){
    int m = MAX_VALUE;
    for(int i=0; i<N; i++) m = min(m, v[i][0]);
    for(int i=0; i<N; i++) if(v[i][0] == m) v[i][0]++;
}

bool check_first_list_up_pos(){
    int base_length = get_base_length();

    int cnt = 0;
    for(int i=start_idx; i<=end_idx; i++) if(v[i][1] != EMPTY) cnt++;

    int tate_len = 0;
    for(int i=0; v[start_idx][i] != EMPTY; i++) tate_len++;

    return (base_length - cnt) >= tate_len;
}

void first_lift_up(){
    if(!check_first_list_up_pos()) return;
    v[start_idx+1][1] = v[start_idx][0];
    v[start_idx][0] = EMPTY; start_idx++;

    while(check_first_list_up_pos()){
        int next_start_idx = start_idx;
        vector<vector<int>> sv;

        for(int i=start_idx; i<=end_idx; i++){
            if(v[i][1] == EMPTY) continue;
            next_start_idx = i;

            vector<int> tmp;
            for(int j=0; v[i][j] != EMPTY; j++){
                tmp.push_back(v[i][j]);
                v[i][j] = EMPTY;
            }
            sv.push_back(tmp);
        }

        start_idx = next_start_idx + 1;
        for(int i=0; i<sv.size(); i++){
            int target_line = sv.size()-i;
            for(int j=start_idx; j<start_idx+sv[i].size(); j++){
                v[j][target_line] = sv[i][j-start_idx];
            }
        }
    }
}

void flattening(){
    vector<int> tmp;

    for(int i=start_idx; i<=end_idx; i++) {
        for(int j=0; v[i][j] != EMPTY; j++) {
            tmp.push_back(v[i][j]);
            v[i][j] = EMPTY;
        }
    }
    start_idx = 0;
    for(int i=0; i<N; i++){
        v[i][0] = tmp[i];
    }
}

void adjacent_aligning(){
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    vector<vector<int>> dv;
    for(int i=start_idx; i<=end_idx; i++){
        vector<int> tmp;

        for(int j=0; v[i][j] != EMPTY; j++){
            int diff = 0;
            for(int k=0; k<4; k++){
                int target_i = i + dx[k];
                int target_j = j + dy[k];

                if(target_i < 0 || target_j < 0 || v[target_i][target_j] == EMPTY) continue;
                diff += (v[target_i][target_j] - v[i][j]) / DIV;
            }
            tmp.push_back(diff);
        }
        dv.push_back(tmp);
    }

    for(int i=0; i<dv.size(); i++){
        for(int j=0; j<dv[i].size(); j++){
            v[i+start_idx][j] += dv[i][j];
        }
    }
}

void second_lift_up(){
    int next_start_idx = start_idx + N/2;
    for(int i=N/2-1; i>=0; i--){
        v[next_start_idx+(N/2-1-i)][1] = v[i][0];
        v[i][0] = EMPTY;
    }
    start_idx = next_start_idx;

    vector<pair<int, int>> tmp;
    next_start_idx = start_idx + N/4;
    for(int i=next_start_idx-1; i>=start_idx; i--){
        tmp.push_back({v[i][1], v[i][0]});
        v[i][0] = v[i][1] = EMPTY;
    }
    start_idx = next_start_idx;

    for(int i=start_idx; i<=end_idx; i++){
        v[i][2] = tmp[i-start_idx].first;
        v[i][3] = tmp[i-start_idx].second;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    start_idx = 0, end_idx = N-1;

    for(int i=0; i<N; i++) {
        int a; cin >> a;
        v[i][0] = a;
    }

    int cnt = 0;
    while(get_diff() > K){
        minus_all_min_idx();
        first_lift_up();
        adjacent_aligning();
        flattening();
        second_lift_up();
        adjacent_aligning();
        flattening();
        cnt++;
    }
    cout << cnt;
}
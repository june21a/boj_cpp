#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    string tile[N];
    for(int i=0; i<N; i++){
        string s; cin >> s;
        tile[i] = s;
    }

    int cnt[K][K][26] = { };
    for(int i=0; i<N; i+=K){
        for(int j=0; j<M; j+=K){
            for(int k=i; k<i+K; k++){
                for(int l=j; l<j+K; l++){
                    int alpha_num = tile[k][l] - 'A';
                    cnt[k-i][l-j][alpha_num]++;
                }
            }
        }
    }

    char most_common_char[K][K]; // 가장 많이 나온 알파벳
    int most_common_count[K][K]; // 그 알파벳의 등장 횟수
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            int max_count = 0;
            char max_char = 'A';
            for (int c = 0; c < 26; ++c) {
                if (cnt[i][j][c] > max_count) {
                    max_count = cnt[i][j][c];
                    max_char = 'A' + c;
                }
            }
            most_common_count[i][j] = max_count;
            most_common_char[i][j] = max_char;
        }
    }

    int num_sub_tiles = (N/K) * (M/K);
    int ans_cnt = 0;
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++) ans_cnt += (num_sub_tiles - most_common_count[i][j]);
    }
    cout << ans_cnt << '\n';
    char ans_tile[N][M];
    for(int i=0; i<N; i+=K){
        for(int j=0; j<M; j+=K){
            for(int k=i; k<i+K; k++){
                for(int l=j; l<j+K; l++){
                    ans_tile[k][l] = most_common_char[k-i][l-j];
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cout << ans_tile[i][j];
        cout << '\n';
    }
}
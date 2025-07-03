#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define OUT 1000

using namespace std;

int trivial_ans[20];
int OMR[20];
int N, K;
int ans = 0;

vector<int> pull(int p){
    vector<int> save(20);

    for(int i=0; i<N; i++) save[i] = OMR[i];
    for(int i=p; i<N-1; i++) OMR[i] = save[i+1];
    OMR[N-1] = OUT;
    return save; 
}

vector<int> push(int p){
    vector<int> save(20);

    for(int i=0; i<N; i++) save[i] = OMR[i];
    for(int i=p+1; i<N; i++) OMR[i] = save[i-1];
    OMR[p] = OUT;
    return save;
}

void revert(int p, vector<int> save){
    for(int i=p; i<N; i++) OMR[i] = save[i];
}

int calc_score(){
    int score = 0;
    for(int i=0; i<N; i++) score += (trivial_ans[i] == OMR[i]);
    return score;
}

void solve(){
    ans = max(ans, calc_score());
    if(K == 0) return;

    vector<int> save;
    for(int i=0; i<N; i++){
        save = push(i);
        K--;
        solve();
        K++;
        revert(i, save);

        save = pull(i);
        K--;
        solve();
        K++;
        revert(i, save);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> trivial_ans[i];
    for(int i=0; i<N; i++) cin >> OMR[i];

    solve();
    cout << ans;
}
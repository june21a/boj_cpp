#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define MAX_LEN 10000

using namespace std;
struct Dragon{
	ll D, H;
};
Dragon dragons[MAX_LEN];
bool compare(int i, int j){
    return dragons[i].D < dragons[j].D;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> dragons[i].D >> dragons[i].H;

    vector<int> v;
    for(int i=0; i<N; i++) v.push_back(i);
    sort(v.begin(), v.end(), compare);

    ll ans[N] = { };
    for(int i=N-1; i>-1; i--){
        ll min_index;
        ll min_value = 1e18;
        ll sum = 0;

        for(int j=0; j<v.size(); j++){
            int idx = v[j];
            sum -= dragons[idx].D;
            ans[i] += dragons[idx].D*j + dragons[idx].H;

            if(sum + dragons[idx].D * j + dragons[idx].H < min_value){
                min_value = sum + dragons[idx].D * j + dragons[idx].H;
                min_index = j;
            }
        }
        v.erase(v.begin()+min_index);
    }
    for(ll a : ans) cout << a << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    vector<int> v;
    for(int i=0; i<N; i++){
        int a, b; cin >> a >> b;
        v.push_back(a-b);
    }
    sort(v.begin(), v.end());

    int slope = -v.size()+2;
    int ans = 0;
    if(slope == 1) ans++;
    else if(slope == 0) ans += (v[1] - v[0] + 1);
    else{
        for(int i=1; i<v.size(); i++){
            if(slope == 0){
                ans += (v[i] - v[i-1]) + 1;
                break;
            }
            if(slope > 0){
                ans += 1;
                break;
            }
            slope += 2;
        }
    }
    cout << ans;
}
#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    vector<vector<int>> v(N+1, vector<int>(0));;
    for(int i=1; i<N+1; i++){
        int num;
        while(true){
            cin >> num;
            if(num == 0) break;
            v[i].push_back(num);
        }
    }

    int M; cin >> M;
    int ans[N+1]; memset(ans, -1, sizeof(ans));
    int cnt[N+1] = { };
    queue<int> q;
    for(int i=0; i<M; i++){
        int num; cin >> num;
        ans[num] = 0;
        q.push(num);
        for(auto i : v[num]) cnt[i]++;
    }

    int t = 1;
    while(true){
        bool check = true;
        vector<int> tmp;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto next : v[node]){
                if(ans[next] != -1 || cnt[next] < v[next].size()/2 + v[next].size()%2) continue;
                ans[next] = t;
                tmp.push_back(next);
                check = false;
            }
        }
        for(auto next : tmp){
            for(auto i : v[next]) cnt[i]++;
            q.push(next);
        }
        
        if(check) break;
        t++;
    }

    for(int i=1; i<N+1; i++) cout << ans[i] << ' ';
}
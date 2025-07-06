#include <bits/stdc++.h>
#define ll long long
#define MAX 1000001

using namespace std;

int N, S, D;
vector<vector<int>> tree(MAX, vector<int>(0));
bool visited[MAX] = { };
int ans = 0;

pair<int, int> dfs(int node){
    visited[node] = true;
    int cost = 0;
    int cnt = 0;

    int from_leaf = 0;
    for(int next : tree[node]){
        if(visited[next]) continue;
        cnt++;
        pair<int, int> tmp = dfs(next);
        cost += tmp.second;
        from_leaf = max(from_leaf, tmp.first);
    }

    if(node != S && from_leaf >= D) cost += 2;
    return {(from_leaf+1), cost};
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S >> D;
    for(int i=0; i<N-1; i++){
        int a,b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    cout << dfs(S).second;
}
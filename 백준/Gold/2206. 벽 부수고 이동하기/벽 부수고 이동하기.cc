#include <bits/stdc++.h>

using namespace std;

struct status{
    int y, x;
    bool check;
    int turn;
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    int game_map[1000][1000];
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++) game_map[i][j] = s[j]-'0';
    }
    
    // BFS
    bool visited[1000][1000]; memset(visited, false, sizeof(bool)*1000*1000);
    bool breaker_visited[1000][1000]; memset(breaker_visited, false, sizeof(bool)*1000*1000);
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    queue<status> q;
    q.push({0, 0, false, 1});
    visited[0][0] = true;
    
    
    int cnt;
    bool check = false;
    while(!q.empty()){
        status cur = q.front();
        q.pop();
        
        if(cur.y == N-1 && cur.x == M-1){
            cnt = cur.turn;
            check = true;
            break;
        }
        
        for(int i=0; i<4; i++){
            int y = cur.y+dy[i];
            int x = cur.x+dx[i];
            
            if(y<0 || y>N-1 || x<0 || x>M-1 || ((!cur.check) && visited[y][x]) || (cur.check && breaker_visited[y][x])) continue;
            if((!cur.check) && game_map[y][x]==1){
                visited[y][x] = true;
                q.push({y, x, true, cur.turn+1});
            }
            else if(game_map[y][x] == 0){
                if(cur.check) breaker_visited[y][x] = true;
                else visited[y][x] = true; 
                q.push({y, x, cur.check, cur.turn+1});
            }
        }
    }
    
    if(check) cout << cnt;
    else cout << -1;
}
#include <iostream>
#include <vector>
#include <queue>

#define MAX 701
#define INF 10000000

using namespace std;

int N, M;
int flow[MAX][MAX] = { };
int capacity[MAX][MAX] = { };
int visited[MAX];
vector<int> v[MAX];

int max_flow(int s, int e){
    int result = 0;
    while(true){
        fill(visited, visited+MAX, -1);
        queue<int> q;
        q.push(s);
        
        while(!q.empty()){
            int current = q.front();
            q.pop();
            
            for(int next : v[current]){
                if(capacity[current][next] - flow[current][next] > 0 && visited[next] == -1) {
                    q.push(next);
                    visited[next] = current;
                    if(next == e) break;
                }
            }
        }
        
        if(visited[e] == -1) break;
        
        int current_max_flow = INF;
        for(int i=e; i != s; i = visited[i]) {
            current_max_flow = min(current_max_flow, capacity[visited[i]][i] - flow[visited[i]][i]);
        }
        
        result += current_max_flow;
        for(int i=e; i != s; i = visited[i]) {
            flow[visited[i]][i] += current_max_flow;
            flow[i][visited[i]] -= current_max_flow;
        }
    }
    return result;
}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    
    int from, to, cap;
    for(int i=0; i<M; i++) {
        cin >> from >> to >> cap;
        
        capacity[from][to] += cap;
        capacity[to][from] += cap;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    
    int start, end;
    cin >> start >> end;
    cout << max_flow(start, end);
}
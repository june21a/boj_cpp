#include <bits/stdc++.h>
#define ll long long
#define MAX 100001
#define BOUND 1000001

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool prime[MAX]; memset(prime, 1, sizeof(prime));
    prime[1] = false;
    int limit = ceil(sqrt(MAX));
    for(int i=2; i<limit; i++){
        if(!prime[i]) continue;

        for(int j=i+1; j<MAX; j++){
            if(j%i==0) prime[j] = false;
        }
    }

    int T; cin >> T;
    while(T--){
        int N, A, B;
        cin >> N >> A >> B;

        bool check = false;
        for(int i=A; i<=B; i++){
            if(prime[i]){
                check = true;
                break;
            }
        }

        if(!check){
            cout << -1 << '\n';
            continue;
        }

        if(N >= A && N <= B && prime[N]){
            cout << 0 << '\n';
            continue;
        }

        bool visited[BOUND] = { };
        queue<pair<int, int>> q;
        q.push({N, 0});
        visited[N] = true;
        while(!q.empty()){
            int cur = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(cur >= A && cur <= B && prime[cur]){
                cout << cnt << '\n';
                break;
            }

            int arr[4] = {cur/2, cur/3, cur+1, cur-1};
            for(int next : arr){
                if(next < 0 || next >= BOUND || visited[next]) continue;
                q.push({next, cnt+1});
                visited[next] = true;
            }
        }
    }
}
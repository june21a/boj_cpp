#include <bits/stdc++.h>
#define ll long long
#define MAX 1000001

using namespace std;

ll N, S;
ll place[MAX];
ll fuel[MAX];
bool visited[MAX] = { };

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for(ll i=1; i<N+1; i++) cin >> place[i];
    for(ll i=1; i<N+1; i++) cin >> fuel[i];

    ll l=S, r=S;
    ll last_state = 0;
    visited[S] = true;
    while(true){
        if(r+1 < N+1 && (place[r+1] - place[r]) <= fuel[r] && (place[r+1] - place[l]) <= fuel[l]){
            visited[r+1] = true;
            fuel[r+1] = max(fuel[r+1], fuel[r] - (place[r+1] - place[r]));
            fuel[r+1] = max(fuel[r+1], fuel[l] - (place[r+1] - place[l]));
            r++;
        }
        else if(r+1 < N+1 && (place[r+1] - place[r]) <= fuel[r]){ // r -> r+1
            visited[r+1] = true;
            fuel[r+1] = max(fuel[r+1], fuel[r] - (place[r+1] - place[r]));
            r++;
        }
        else if(r+1 < N+1 && (place[r+1] - place[l]) <= fuel[l]){ // l -> r+1
            visited[r+1] = true;
            fuel[r+1] = max(fuel[r+1], fuel[l] - (place[r+1] - place[l]));
            r++;
        }

        if(l-1 > 0 && (place[l] - place[l-1]) <= fuel[l] && (place[r] - place[l-1]) <= fuel[r]){
            visited[l-1] = true;
            fuel[l-1] = max(fuel[l-1], fuel[r] - (place[r] - place[l-1]));
            fuel[l-1] = max(fuel[l-1], fuel[l] - (place[l] - place[l-1]));
            l--;
        }
        else if(l-1 > 0 && (place[l] - place[l-1]) <= fuel[l]){ // l -> l-1
            visited[l-1] = true;
            fuel[l-1] = max(fuel[l-1], fuel[l] - (place[l] - place[l-1]));
            l--;
        }
        else if(l-1 > 0 && (place[r] - place[l-1]) <= fuel[r]){ // r -> l-1
            visited[l-1] = true;
            fuel[l-1] = max(fuel[l-1], fuel[r] - (place[r] - place[l-1]));
            l--;
        }

        if(last_state == r-l) break;
        last_state = r-l;
    }
    for(ll i=1; i<N+1; i++) if(visited[i]) cout << i << ' ';
}
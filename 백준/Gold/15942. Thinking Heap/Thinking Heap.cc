#include <bits/stdc++.h>
#define ll long long

using namespace std;

int heap[200001] = { };
int N, k, p;
bool visited[200001] = { };
bool check = false;

void fill_heap(int node){
    if(node > N) return;
    if(check) return;

    if(heap[node] == 0){
        int s_value = heap[node/2]+1;
        while(s_value <= N && visited[s_value]) s_value++;
        if(s_value > N){
            check = true;
            return;
        }

        heap[node] = s_value;
        visited[s_value] = true;
    }
    fill_heap(node*2);
    fill_heap(node*2+1);
}

void print_heap(){
    for(int i=1; i<N+1; i++) cout << heap[i] << '\n';
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> k >> p;

    heap[p] = k;
    visited[k] = true;

    // depth를 통해 가능 여부 판별
    int depth = 0;
    int tmp = p;
    int tmp_2 = k;
    while(tmp != 1){
        depth++;
        tmp /= 2;
    }
    if(k - depth <= 0){
        cout << -1;
        return 0;
    }

    // 가능한 케이스에 heap 구성
    tmp = p;
    while(tmp != 1){
        tmp /= 2;
        heap[tmp] = depth;
        visited[depth] = true;
        depth--;
    }

    fill_heap(1);
    if(check) cout << -1;
    else print_heap();
}
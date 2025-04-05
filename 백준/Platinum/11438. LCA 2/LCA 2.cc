#define MAX 100001
#include <iostream>
#include <cmath>
#include <memory.h>
#include <vector>

using namespace std;

int N;
int depth[MAX];
int parents[MAX][17];
vector<int> tree[MAX];

void init(int current, int curDepth, int myparent){
    depth[current] = curDepth;
    parents[current][0] = myparent;
    
    int last_parents = parents[current][0];
    for(int i=1; i<17; i++){
        if(parents[last_parents][i-1] == -1) break;
        parents[current][i] = parents[last_parents][i-1];
        last_parents = parents[current][i];
    }
    
    for(int i=0; i<tree[current].size(); i++){
        if(depth[tree[current][i]] == -1) init(tree[current][i], curDepth+1, current);
    }
}

int LCA(int node1, int node2){
    if(depth[node1] < depth[node2]){
        int tmp = node1;
        node1 = node2;
        node2 = tmp;
    }
        
    int diff = depth[node1] - depth[node2];
    int k = 0;
    while(diff){
        if(diff % 2) node1 = parents[node1][k];
        diff /= 2;
        k++;
    }
    
    if(node1 == node2) return node1;
    int num = ceil(log2(depth[node1]));
    for(int i=num; i>-1; i--){
        if(parents[node1][i] != parents[node2][i]){
            node1 = parents[node1][i];
            node2 = parents[node2][i];
        }
    }
    
    return parents[node1][0];
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    memset(depth, -1, sizeof(depth));
		memset(parents, -1, sizeof(parents));
    int node1, node2;
    for(int i=0; i<N-1; i++){
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
    
    init(1, 0, -1);
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> node1 >> node2;
        cout << LCA(node1, node2) << '\n';
    }
}
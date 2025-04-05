#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, input;
    priority_queue <int, vector<int>, greater<int>> m_pq;
    priority_queue<int> M_pq;
    
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> input;
        
        if(M_pq.size() == m_pq.size()) M_pq.push(input);
        else m_pq.push(input);
        
        if(m_pq.size() && M_pq.top() > m_pq.top()){
            int M = M_pq.top();
            int m = m_pq.top();
            
            M_pq.pop(); m_pq.pop();
            M_pq.push(m); m_pq.push(M);
        }
        
        cout << M_pq.top() << '\n';
    }
}
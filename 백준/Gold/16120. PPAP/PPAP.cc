#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> st;
    string s; cin >> s;

    bool check = true;
    string tmp1 = "PPAP";
    string tmp2 = "PAPP";
    string cur = "";
    for(int i=0; i<s.length(); i++){
        st.push(s[i]);
        if(st.size() >= 4){
            int cnt = 4;
            string tmp = "";
            while(cnt--){
                tmp += st.top();
                st.pop();
            }

            if(tmp == tmp2) st.push('P');
            else{
                reverse(tmp.begin(), tmp.end());
                for(auto i : tmp) st.push(i);
            }
        }
    }

    if(st.top() == 'P' && st.size() == 1) cout << "PPAP";
    else cout << "NP";
}
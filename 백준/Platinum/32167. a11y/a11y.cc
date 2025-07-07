#include <bits/stdc++.h>
#define ll long long
#define MAX 100000

using namespace std;

bitset<MAX> bits[26];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;
    int s_len = s.length();

    string bits_str[26] = { };
    for(int i='a'; i<'z'+1; i++){
        for(int j=0; j<s_len; j++){
            if(s[j] == i) bits_str[i - 'a'] += '1';
            else bits_str[i - 'a'] += '0';
        }
    }

    for(int i=0; i<26; i++) bits[i] = bitset<MAX>(bits_str[i]);

    int Q; cin >> Q;
    while(Q--){
        string query; cin >> query;
        char s = query[0];
        char e = query[query.length()-1];
        string tmp = "";
        for(int i=1; i<query.length()-1; i++) tmp += query[i];
        int cnt = stoi(tmp);

        cout << ((bits[s-'a']>>(cnt+1)) & bits[e-'a']).count() << '\n';
    }
}
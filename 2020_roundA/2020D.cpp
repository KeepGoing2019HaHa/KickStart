#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    unordered_map<char, Trie*>next;
    int cnt=0;
public:
    Trie(){}
    void insert(string word) {
        Trie *root = this;
        for(char c:word) {
            if(!root->next.count(c)) {
                root->next[c] = new Trie();
            }
            root->next[c]->cnt += 1;
            root = root->next[c];
        }
    }
    int search(int k) {
        int res=0;
        deque<Trie *>q{this};
        while(!q.empty()){
            Trie *s=q.front();
            q.pop_front();
            res+=s->cnt/k;
            for(auto &kv:s->next) {
                q.push_back(kv.second);
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        Trie *trie = new Trie();
        int n,k;
        cin>>n>>k;
        string s;
        for(int i=0;i<n;i++) {
            cin>>s;
            trie->insert(s);
        }
        int ans = trie->search(k);
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
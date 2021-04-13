#include "unordered_map"
#include "vector"
#include "iostream"
#include "queue"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        int r,c;
        char a[31][31];
        cin>>r>>c;
        for(int i=0;i<r;i++)cin>>a[i];
        unordered_map<char, vector<char> > before,after;
        unordered_map<char, int> indegree;
        for(int j=0;j<c;j++) {
            for(int i=0;i<r-1;i++) {
                int s=a[i][j],t=a[i+1][j];
                if(before.count(s)==0) before[s]=vector<char>{},after[s]=vector<char>{},indegree[s]=0;
                if(before.count(t)==0) before[t]=vector<char>{},after[t]=vector<char>{},indegree[t]=0;
                if(s!=t) before[s].push_back(t),after[t].push_back(s),indegree[s]++;
            }
        }

        string ans = "";
        queue<char>q;
        for(auto kv:indegree) if(kv.second==0) q.push(kv.first);
        while(!q.empty()) {
            char c=q.front();
            q.pop();
            ans.push_back(c);
            for(char t:after[c]){
                indegree[t]--;
                if(indegree[t]==0) q.push(t);
            }
        }

        if(ans.size()!=indegree.size()) ans="-1";
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
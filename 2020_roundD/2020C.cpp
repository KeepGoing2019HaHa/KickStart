#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "queue"
#include <utility>
#include "numeric"
using namespace std;
typedef long long ll;

int n,A,B,tmp;
int degree1[500001],degree2[500001],prob1[500001],prob2[500001];
int parent[500001];

void get_prob(int *degree, int *prob, int target) {
    for(int i=1;i<=n;i++)prob[i]=1;
    queue<tuple<int,int,int>>q;
    for(int i=1;i<=n;i++) if(degree[i]==0) q.push({i,i,0});
    while(!q.empty()){
        auto s = q.front();
        q.pop();
        int s0=get<0>(s),s1=get<1>(s),s2=get<2>(s);

        int p=parent[s0];
        if((s2+1)==target) prob[p]+=prob[s1];
        else q.push({p,s1,s2+1});
        if(s2==0) {
            degree[p]--;
            if(degree[p]==0) q.push({p,p,0});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        cin>>n>>A>>B;

        memset(degree1, 0, n*sizeof(degree1[0]));
        memset(degree2, 0, n*sizeof(degree2[0]));
        memset(prob1, 0, n*sizeof(prob1[0]));
        memset(prob2, 0, n*sizeof(prob2[0]));
        memset(parent, 0, n*sizeof(parent[0]));

        for(int i=2;i<=n;i++) {
            cin>>tmp;
            parent[i]=tmp;
            degree1[tmp]++;
            degree2[tmp]++;
        }

        get_prob(degree1, prob1, A);
        get_prob(degree2, prob2, B);

        double ans = 0;
        for(int i=1;i<=n;i++) ans+=1-(1-prob1[i]/(n+0.0))*(1-prob2[i]/(n+0.0));
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "map"
using namespace std;
typedef long long ll;

int N,M,K;
map<vector<int>,double>memo;

double dfs(vector<int> status, vector<int> target) {
    if(memo.find(status)!=memo.end()) return memo[status];
    double num_can_place=0, prob_multi=0;
    int i=0,j=0;
    while(i<M) {
        j=i;
        while(j+1<M && status[j+1]==status[i]) j++;
        if(status[j] < target[j]) {
            status[j]++;
            num_can_place += j-i+1;
            prob_multi += dfs(status, target)*(j-i+1);
            status[j]--;
        }
        i = j+1;
    }
    double res = M/num_can_place + prob_multi/num_can_place;
    return memo[status]=res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int case_ = 1;  case_<= T; case_ += 1) {
        cin>>N>>M>>K;
        vector<int>target(M, 0), status(M, 0);
        for(int i=0;i<K;i++) cin>>target[M-K+i];
        memo.clear();
        memo[target] = 0;

        printf("Case #%d: %.7f\n", case_, dfs(status, target));
    }
    return 0;
}
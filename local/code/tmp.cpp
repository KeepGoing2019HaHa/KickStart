#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "queue"
#include <utility>
#include "numeric"
#include "algorithm"
#include "bitset"
#include "exception"
using namespace std;
typedef long long ll;

int S,RA,PA,RB,PB,C,CA,CB;
const int max_p=36;
unordered_map<ll,int>memo[max_p][max_p][2];
int dirs[4][2]={{0,-1},{0,1},{-1,-1},{1,1}};

int get_pos(int x1,int y1) {
//    cout << x1 << " "<< y1 <<" "<< (x1-1)*(x1-1)+y1-1<<endl;
    return (x1-1)*(x1-1)+y1-1;
}

int solve(ll st, int x1,int y1, int x2,int y2, int who) {
    try {

        int pos1 = get_pos(x1, y1), pos2 = get_pos(x2, y2);
        if (memo[pos1][pos2][who].count(st)) return memo[pos1][pos2][who][st];
        if (who == 0) {
            vector<int> cands;
            for (int i = 0; i < 4; i++) {
                if (y1 % 2 == 1 && i == 2) continue;
                if (y1 % 2 == 0 && i == 3) continue;
                int xx = x1 + dirs[i][0], yy = y1 + dirs[i][1];
                if (xx < 1 || xx > S || yy < 1 || yy >= 2 * xx) continue;
                ll st2 = st | (ll(1) << get_pos(xx, yy));
                if (st2 != st) cands.push_back(solve(st2, xx, yy, x2, y2, 1));
            }
            if (cands.size() == 0) return memo[pos1][pos2][who][st] = solve(st, x1, y1, x2, y2, 1);
            else return memo[pos1][pos2][who][st] = *max_element(cands.begin(), cands.end()) + 1;
        } else {
            vector<int> cands;
            for (int i = 0; i < 4; i++) {
                if (y2 % 2 == 1 && i == 2) continue;
                if (y2 % 2 == 0 && i == 3) continue;
                int xx = x2 + dirs[i][0], yy = y2 + dirs[i][1];
                if (xx < 1 || xx > S || yy < 1 || yy >= 2 * xx) continue;
                ll st2 = st | (ll(1) << get_pos(xx, yy));
                if (st2 != st) cands.push_back(solve(st2, x1, y1, xx, yy, 0));
            }
            if (cands.size() == 0) return memo[pos1][pos2][who][st] = solve(st, x1, y1, x2, y2, 0);
            else return memo[pos1][pos2][who][st] = *min_element(cands.begin(), cands.end()) - 1;
        }
    } catch(exception e)  {
        cout << st<<x1<<y1<<x2<<y2<<who<<endl;
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int case_ = 1; case_ <= T; case_ += 1) {
        cin>>S>>RA>>PA>>RB>>PB>>C;
        ll st = (1<<get_pos(RA,PA)) | (1<<get_pos(RB,PB));
        for(int i=0;i<C;i++) cin>>CA>>CB,st|=(1<<get_pos(CA,CB));
        for(int i=0;i<max_p;i++) for(int j=0;j<max_p;j++) for(int k=0;k<2;k++) memo[i][j][k].clear();

        cout << "Case #" << case_ << ": " << solve(st, RA,PA, RB,PB, 0) << endl;
    }
    return 0;
}
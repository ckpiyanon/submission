#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define iii tuple<int, int, int>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};


class TaskA {
private:
public:
    void solve(istream& cin, ostream& cout) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        bool st = true;
        if(a != d) st = false;
        if(c) if(a == 0) st = false;
        cout << (st ? 1 : 0 )<< endl;
    }
};
/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author win11905
 * I reduce from f(x1, x2, ..., xn) = (x1 + x2 + ... + xn)^4 + 2*(x1 + x2 + ... + xn)^2 mod 5 + 1
 * to g(k) = k^4 + 2*k^2 mod 5 + 5 , k = x1 + x2 + ... + xn
 * and find each k, how many number k that x1 + x2 + ... + xn = k
 * I divide and conquer find each number k
 * last ans = sum of cnt[k] * g(k)
 */

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 1<<10;
int n;

class modsum {
private:
    int v[N], w[N];
    int mnk[N << 1];
    vector<long> vec[N << 1];
    long ans;
    void rec(int p = 1, int l = 1, int r = n) {
        if(l == r) {
            mnk[p] = v[l];
            vec[p] = vector<long>(w[r] - v[l] + 1, 1);
            return;
        }
        int m = l + r >> 1;
        rec(p<<1, l, m), rec(p<<1|1, m+1, r);
        mnk[p] = mnk[p<<1] + mnk[p<<1|1];
        vec[p] = vector<long>(vec[p<<1].size() + vec[p<<1|1].size() - 1, 0);
        for(int i = 0; i < vec[p<<1].size(); ++i) for(int j = 0; j < vec[p<<1|1].size(); ++j)
            vec[p][i+j] += vec[p<<1][i] * vec[p<<1|1][j];
    }

public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
        rec();
        for(int i = 0; i < vec[1].size(); ++i) {
            long now = i + mnk[1];
            now = now * now % 5;
            now = now * (now + 2) % 5;
            ans += vec[1][i] * (now + 1);
        }
        cout << ans << endl;
    }
};

class Solver {
public:
    void solve(std::istream& in, std::ostream& out) {
        modsum *obj = new modsum();
        obj->solve(in, out);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solver solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}

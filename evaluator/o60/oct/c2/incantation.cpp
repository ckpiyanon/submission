/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author win11905
 */

#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
#define mem(x) memset(x, 0, sizeof x)
#define pii pair<int, int>
#define x first
#define y second
#define input() (*istream_iterator<int>(cin))
using namespace std;
const long LINF = 1e18 + 1e16;
const int MOD = 1e9+7;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};


class incantation {
private:
	int n, m;
public:
	void solve(istream& cin, ostream& cout) {
		cin >> n >> m;
		int lm = 1 << m, im = 1 << (m-1);
		vector<vector<long> > dp(lm, vector<long>(lm, -LINF));
		for(int i = 0; i < lm; ++i) dp[i>>1][i] = dp[im|i>>1][i] = input();
		vector<long> vec(lm);
		for(n -= m-1; n; n >>= 1) {
			if(n & 1) {
				vector<long> now(lm);
				for(int i = 0; i < lm; ++i) for(int j = 0; j < lm; ++j)
					if(now[j] < vec[i] + dp[i][j]) now[j] = vec[i] + dp[i][j];
				vec = now;
			}
			vector<vector<long> > rdp(lm, vector<long>(lm));
			for(int k = 0; k < lm; ++k) for(int i = 0; i < lm; ++i) for(int j = 0; j < lm; ++j)
			rdp[i][j] = max(rdp[i][j], dp[i][k] + dp[k][j]);
			dp = rdp;
		}
		cout << *max_element(all(vec)) << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	incantation solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}

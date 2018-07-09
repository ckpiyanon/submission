#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define mem(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
#ifdef INPUT
#define dbg(x) cout << "debug : " <<  x << endl
#define dbg2(x, xx) cout << "debug : " << x << " : " << xx << endl 
#else
#define dbg(x)
#define dbg2(x, xx)
#endif
using namespace __gnu_pbds;
using namespace std;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.tie(0);
	cin.sync_with_stdio(false);
}

const int MAXN = 2e5+5;

int n, t, c, A[MAXN];

int main() {
	red();
	scanf("%d %d %d", &n, &t, &c);
	int pv = 0, ans = 0;
	for(int i = 1; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		if(now > t) {
			ans += max(i-pv-c, 0);
			pv = i;
		}
	}
	ans += max(n+1-pv-c, 0);
	cout << ans;
}
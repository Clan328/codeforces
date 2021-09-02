#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define nL '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll MOD = 1e9 + 7;

void settings()__attribute__((constructor));

void eval(bool condition) { cout << (condition ? "yes" : "no") << nL; }
void Eval(bool condition) { cout << (condition ? "Yes" : "No") << nL; }
void EVAL(bool condition) { cout << (condition ? "YES" : "NO") << nL; }

int ipow(int a, int n) {
    if (n == 0) return 1;
    int x = ipow(a, n/2);
    if (n % 2 == 0) return x*x;
    return x*x*a;
}

template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
	for (auto elem : v) 
		stream << elem << " ";
	return stream;
}

template <typename T>
istream& operator>>(istream& stream, vector<T>& v){
    for(auto &elem : v)
    	stream >> elem;
    return stream;
}

void settings() {
	#ifdef LOCAL
		freopen("io/input.txt", "r", stdin);
		freopen("io/output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
}

int n;
vector<unsigned long long> a;

struct segmentTree {
	vector<unsigned long long> a, t;

	segmentTree() {

	}

	segmentTree(int n, const vector<unsigned long long>& a) {
		t = vector<unsigned long long>(4*n);
		this->a = a;
	}

	void build(int v, int tl, int tr) {
		if (tl == tr)
			t[v] = a[tl];
		else {
			int tm = (tl+tr)/2;

			build(2*v, tl, tm);
			build(2*v+1, tm+1, tr);

			t[v] = __gcd(t[2*v], t[2*v+1]);
		}
	}

	void update(int v, int tl, int tr, int pos, unsigned long long x) {
		if (tl == tr)
			t[v] = x;
		else {
			int tm = (tl+tr)/2;

			if (tm <= pos)
				update(2*v, tl, tm, pos, x);
			else
				update(2*v+1, tm+1, tr, pos, x);

			t[v] = __gcd(t[2*v], t[2*v+1]);
		}
	}

	unsigned long long get(int v, int tl, int tr, int l, int r) {
		if (l > r)
			return 0;
		else if (tl == l && tr == r)
			return t[v];
		else {
			int tm = (tl+tr)/2;

			return __gcd(get(2*v, tl, tm, l, min(r, tm)), get(2*v+1, tm+1, tr, max(l, tm+1), r));
		}
	}
};

segmentTree tree;

bool check(ll mid) {
	bool flag = false;

	for (int i = 0; i+mid-1 < n-1 && !flag; i++) {
		flag = flag || tree.get(1, 0, n-2, i, i+mid-1) > 1;
	}

	return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
    	cin >> n;
    	a = vector<unsigned long long>(n-1);
    	for (int i = 0; i < n; i++) {
    		ll x;
    		cin >> x;

    		if (i < n-1)
    			a[i] = x;
    		if (i > 0)
    			a[i-1] = abs((ll)a[i-1]-x);
    	}

    	if (n == 1) {
    		cout << 1 << nL;
    		continue;
    	} else if (n == 2) {
    		cout << ((a[0] != 1)? 2 : 1) << nL;
    		continue;
    	}

    	tree = segmentTree(n-1, a);
    	tree.build(1, 0, n-2);
    	
    	ll res = 0;
    	for (int i = 0; i < n-1; i++) {
    		if (a[i] == 1) continue;
    		int lo = i+1, hi = n-2;
    		ll ans = i, mid;
    		while (lo <= hi) {
    			mid = (lo+hi)/2;
    			if (tree.get(1, 0, n-2, i, mid) > 1) {
    				ans = mid;
    				lo = mid + 1;
    			} else
    				hi = mid - 1;
    		}

    		res = max(res, ans-i+1);
    	}

    	// ll lo = 1, hi = n-1, res = 0, mid;
    	// while (lo <= hi) {
    	// 	mid = (lo+hi)/2;
    	// 	if (check(mid)) {
    	// 		res = mid;
    	// 		lo = mid + 1;
    	// 	} else
    	// 		hi = mid - 1;
    	// }

    	cout << res+1 << nL;
    }

	return 0;
}

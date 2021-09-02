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

vi p1, p2;

int findSet(vi& p, int i) {
    if(p[i] != i) p[i] = findSet(p, p[i]);
    return p[i];
}

void unionSet(vi& p, int u, int v) {
    p[findSet(p, u)] = findSet(p, v);
}

int main() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    p1 = vi(n), p2 = vi(n);
    vpii res;
    iota(all(p1), 0);
    iota(all(p2), 0);
    while (m1--) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	unionSet(p1, u, v);
    }

    while (m2--) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	unionSet(p2, u, v);
    }

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (i == j) continue;
    		if (findSet(p1, i) != findSet(p1, j) && findSet(p2, i) != findSet(p2, j)) {
    			res.pb({i, j});
    			unionSet(p1, i, j);
    			unionSet(p2, i, j);
    		}
    	}
    }

    cout << res.size() << nL;
    for (int i = 0; i < res.size(); i++)
    	cout << res[i].first+1 << " " << res[i].second+1 << nL;

   	// for (int i = 0; i < n; i++)
   	// 	cout << findSet(p1, i) << " ";
   	// cout << nL;
   	// for (int i = 0; i < n; i++)
   	// 	cout << findSet(p2, i) << " ";
   	// cout << nL;

	return 0;
}
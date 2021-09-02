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

int cnt;
vl cntLoses;

void add(int u, int v) {
	if (cntLoses[min(u, v)] <= 0) {
		cnt--;
	}
	cntLoses[min(u, v)]++;
}

void erase(int u, int v) {
	cntLoses[min(u, v)]--;
	if (cntLoses[min(u, v)] <= 0)
		cnt++;
}

int main() {
    int n, m;
    cin >> n >> m;

    cnt = n;
    cntLoses = vl(n);
    while (m--) {
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	add(u, v);
    }

    int q;
    cin >> q;
    while (q--) {
    	int type;
    	cin >> type;
    	if (type == 1) {
    		int u, v;
	    	cin >> u >> v;
	    	u--;
	    	v--;
	    	add(u, v);
    	} else if (type == 2) {
    		int u, v;
	    	cin >> u >> v;
	    	u--;
	    	v--;
    		erase(u, v);
    	} else {
    		cout << cnt << nL;
    	}
    }

	return 0;
}
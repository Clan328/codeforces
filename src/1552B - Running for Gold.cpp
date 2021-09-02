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

int main() {
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vvi r(n, vi(5));
    	for (int i = 0; i < n; i++) {
    		cin >> r[i];
    	}

    	vi a(n);
    	iota(all(a), 1);
    	
    	sort(all(a), [&](int x, int y) {
    		int cntX = 0;
    		for (int i = 0; i < 5; i++) {
    			cntX += (r[x-1][i] < r[y-1][i]);
    		}
    		
    		return cntX >= 3;
    	});

    	bool isPos = true;
    	int res = a[0];
    	for (int i = 1; i < n && isPos; i++) {
    		int cntX = 0;
    		for (int j = 0; j < 5; j++) {
    			cntX += (r[a[0]-1][j] < r[a[i]-1][j]);
    		}

    		isPos = (cntX >= 3);
    	}

    	if (isPos)
    		cout << res << nL;
    	else
    		cout << -1 << nL;
    }

	return 0;
}

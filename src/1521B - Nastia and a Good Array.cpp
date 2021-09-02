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
    	vl a(n);
    	int minIdx = 0;
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
    		if (a[i] < a[minIdx])
    			minIdx = i;
    	}

    	cout << n-1 << nL;

    	ll minN = a[minIdx];
    	ll skip = minIdx;
    	for (int i = 0; i < n; i++) {
    		if (i == skip) continue;
    		if (i == 0) {
    			cout << i+1 << " " << minIdx+1 << " " << minN << " " << (minN+minIdx) << nL;
    			minIdx = 0;
    		}
    		else
    			cout << minIdx+1 << " " << i+1 << " " << minN << " " << (minN +i) << nL;
    	}

    	// for (int i = 0; i < n; i++)
    	// 	cout << a[i].first << " " << a[i].second << nL;
    }

	return 0;
}
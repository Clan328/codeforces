#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define nL '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef unsigned long long ll;
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

ll operation(ll x, ll y) {
	ll res = 0;
	ll i = 0;
	while ((x>>i) != 0) {
		if ( ((x>>i) & 1) && !((y>>i)&1) ) {
			res += (1<<i);
		}
		i++;
	}
	return res;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
    	ll n;
    	cin >> n;
    	vl x(n);
    	cin >> x;

    	vl y(n);
    	for (ll i = 1; i < n; i++) {
    		if ( (x[i-1]&x[i]) == x[i-1])
    			y[i] = 0;
    		else {
    			y[i] = operation(x[i-1], x[i]);
    			x[i] = x[i]^y[i];
    		}
    	}

    	cout << y << nL;
    }

	return 0;
}
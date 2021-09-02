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
    ll q;
    cin >> q;
    while (q--) {
    	ll n, k;
    	cin >> n >> k;
    	vpll t(k);
    	for (int i = 0; i < k; i++) {
    		ll temp;
    		cin >> temp;
    		t[i].first = temp;
    	}
    	for (int i = 0; i < k; i++) {
    		ll temp;
    		cin >> temp;
    		t[i].second = temp;
    	}

    	sort(all(t));

    	vl L(n);
    	ll prev = INT_MAX, idx = 0;
    	for (int i = 0; i < n; i++) {
    		if (idx < k && t[idx].first == i+1) {
    			prev = min(prev+1, t[idx].second);
    			idx++;
    		} else
    			prev = min(prev+1, (ll)INT_MAX);
    		L[i] = prev;
    	}

    	vl R(n);
    	prev = INT_MAX, idx = k-1;
    	for (int i = n-1; i >= 0; i--) {
    		if (idx >= 0 && t[idx].first == i+1) {
    			prev = min(prev+1, t[idx].second);
    			idx--;
    		} else
    			prev = min(prev+1, (ll)INT_MAX);
    		R[i] = min(L[i], prev);
    	}

    	cout << R << nL;
    }

	return 0;
}
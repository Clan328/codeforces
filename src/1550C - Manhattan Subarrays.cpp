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
    	cin >> a;

    	ll res = 2*n-1;

    	if (n > 2) {
	    	for (int i = 0; i < n; i++) {
	    		bool good = true;
	    		for (int j = i+1; j < n && j <= i+2; j++) {
	    			for (int k = j+1; k < n && k <= i+3; k++) {
	    				ll pr = abs(a[i]-a[j])+abs(j-i);
		    			ll pq = abs(a[i]-a[k])+abs(k-i);
		    			ll qr = abs(a[j]-a[k])+abs(k-j);

		    			//cout << i+1 << ", " << j+1 << ", " << k+1 << ": " << pr << ", " << pq << ", " << qr << ": ";

		    			good = good && ((pr!=pq+qr) && (pq != pr+qr) && (qr != pq+pr));
		    			if (i == j-1 && j == k-1) {
		    				res += good;
		    			}
		    			//cout << ((pr!=pq+qr) && (pq != pr+qr) && (qr != pq+pr)) << nL;
	    			}
	    		}
	    		if (i+3 < n) {
	    			ll pr = abs(a[i+1]-a[i+2])+abs(1);
		    		ll pq = abs(a[i+1]-a[i+3])+abs(2);
		    		ll qr = abs(a[i+2]-a[i+3])+abs(1);
	    			res += good && ((pr!=pq+qr) && (pq != pr+qr) && (qr != pq+pr));
	    		}
	    	}
	    }

    	cout << res << nL;
    }

	return 0;
}
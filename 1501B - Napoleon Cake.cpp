#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <set>
#include <numeric>

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

const ll MOD = 10e9 + 7;

void settings()__attribute__((constructor));

void eval(bool condition) { cout << (condition ? "yes" : "no") << nL; }
void Eval(bool condition) { cout << (condition ? "Yes" : "No") << nL; }
void EVAL(bool condition) { cout << (condition ? "YES" : "NO") << nL; }

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
	#ifndef ONLINE_JUDGE
		freopen("io/input.txt", "r", stdin);
		freopen("io/output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
    	ll n;
    	cin >> n;
    	vector<ll> a(n);
    	cin >> a;

    	/*vi cake;
    	
    	for (int i = 0; i < n; i++) {
    		cake.pb(0);
    		for (int j = a[i]; j > 0; j--) {
    			if (i+1-j >= 0)
    				cake[i+1-j] = 1;
    		}
    	}*/

    	vector<ll> cake(n);
    	ll stack = 0;
    	for (ll i = n-1; i >= 0; i--) {
    		stack = max(stack, a[i]);
    		if (stack > 0) {
	    		stack--;
	    		cake[i] = 1;
	    	}
    	}

    	cout << cake << nL;
    }

	return 0;
}
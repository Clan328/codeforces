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
    	int n0, n1, n2;
    	cin >> n0 >> n1 >> n2;

    	if (n0) {
    		for (int i = 0; i < n0+1; i++)
    			cout << "0";
    	}

    	if (n2) {
    		for (int i = 0; i < n2 + 1; i++)
    			cout << "1";
    		if (n0)
    			n1--;
    	}

    	if (n1 > 0) {
    		if (n2) {
    			for (int i = 0; i < n1; i++) {
					if (i % 2== 0)
						cout << "0";
					else
						cout << "1";
				}
    		} else if (n0) {
    			for (int i = 0; i < n1; i++) {
					if (i % 2== 0)
						cout << "1";
					else
						cout << "0";
				}
    		}else {
    			for (int i = 0; i < n1+1; i++) {
					if (i % 2== 0)
						cout << "1";
					else
						cout << "0";
				}
    		}
    	}

    	cout << nL;
    }

	return 0;
}
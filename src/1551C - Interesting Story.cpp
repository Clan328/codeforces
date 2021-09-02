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
    	vvi abc(n, vi(6));
    	for (int i = 0; i < n; i++) {
    		string s;
    		cin >> s;
    		for (int j = 0; j < s.size(); j++) {
    			abc[i][s[j]-97]++;
    			abc[i][5]++;
    		}
    	}

    	int res = 0;
    	for (int i = 0; i < 5; i++) {
    		int temp = 0, letters = 0, others = 0;
    		vector<pair<int, pii>> next;
    		for (int j = 0; j < n; j++)
    			next.pb({abc[j][i]-(abc[j][5]-abc[j][i]), {abc[j][i], abc[j][5]-abc[j][i]}});
    		
    		sort(all(next));

    		// for (int j = 0; j < next.size(); j++) {
    		// 	cout << next[j].second.first << " " << next[j].second.second << nL;
    		// }

    		int j = next.size()-1;
    		pii curr = next[j].second;
    		while (j >= 0 && letters+curr.first > others+curr.second) {
    			temp++;
    			letters+=curr.first;
    			others+=curr.second;
    			j--;
    			curr = next[j].second;
    		}
    		
    		res = max(res, temp);
    	}

    	cout << res << nL;
    }

	return 0;
}
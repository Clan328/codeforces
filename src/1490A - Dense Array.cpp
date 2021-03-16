#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define nL '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const ll MOD = 10e9 + 7;

void settings()__attribute__((constructor));

void eval(bool condition) { cout << (condition ? "Yes" : "No") << nL; }
void EVAL(bool condition) { cout << (condition ? "YES" : "NO") << nL; }

void settings() {
	#ifndef ONLINE_JUDGE
		freopen("io/input.txt", "r", stdin);
		freopen("io/output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
}


int main() {
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vi v;
    	for (int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		v.pb(a);
    	}

    	int res = 0;
    	for (int i = 0; i < v.size()-1; i++) {
    		if ((float)max(v[i], v[i+1]) / min(v[i], v[i+1]) > 2) {
    			int minV = min(v[i], v[i+1]);
    			v.insert(v.begin() + i+1, min(v[i], v[i+1])*2);
    			res++;
    			if (minV == v[i+2])
 		   			i--;
    		}
    	}

    	cout << res << nL;
    }

	return 0;
}
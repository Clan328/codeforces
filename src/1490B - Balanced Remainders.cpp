#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>

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
    	vi v = {0, 0, 0};
    	for (int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		v[a%3]++;
    	}

    	int cnt = 0;
    	while (!(v[0] == v[1] && v[1] == v[2])) {
    		int i = max_element(all(v))-v.begin();
    		v[i]--;
    		v[(i+1)%3]++;
    		cnt++;
    	}

    	cout << cnt << nL;
    }

	return 0;
}
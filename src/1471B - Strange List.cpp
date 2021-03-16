#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<pair<ll, ll> > a;
        for (int i = 0; i < n; i++) {
            ll in;
            cin >> in;
            a.push_back( make_pair(in, 1) );
        }

        int i = 0;
        bool add = true;
        ll sum = 0;
        while (i < a.size()) {
            if (a[i].first % x == 0 && add) {
                a.push_back( make_pair(a[i].first/x , x*a[i].second) );
            } else
                add = false;
            sum+=a[i].first*a[i].second;
            i++;
        }
        
        cout << sum << "\n";
    }

    return 0;
}
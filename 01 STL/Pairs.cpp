
#include <bits/stdc++.h>
#include <utility> // library used to use pairs
using namespace std;
int main() {
    // simple pair
    pair<int, int> p = {1, 2};
    cout << "p.first: " << p.first << '\n';
    cout << "p.second: " << p.second << "\n\n";

    // nested pair 
    pair<int, pair<int, int>> np = {1, {2, 3}};
    cout << "np.first: " << np.first << '\n';
    cout << "np.second.first: " << np.second.first << '\n';
    cout << "np.second.second: " << np.second.second << "\n\n";

    // array of pairs
    pair<int, int> arr[] = {{1, 2}, {3, 4}};
    cout << "arr[0].first: " << arr[0].first << "  arr[0].second: " << arr[0].second << '\n';
    cout << "arr[1].first: " << arr[1].first << "  arr[1].second: " << arr[1].second << '\n';
    return 0;
}

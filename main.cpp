#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D;
    long long n;
    if (!(cin >> D >> n)) return 0;

    int num_nodes = (1 << D) - 1;
    vector<long long> k(num_nodes + 1, 0);
    k[1] = n;

    // Calculate the number of balls reaching each node
    for (int i = 1; i < (1 << (D - 1)); ++i) {
        k[2 * i] = (k[i] + 1) / 2;
        k[2 * i + 1] = k[i] / 2;
    }

    // Find the path of the n-th ball
    int pos = 1;
    long long m = n;
    while (pos < (1 << (D - 1))) {
        if (m % 2 == 1) {
            pos = 2 * pos;
            m = (m + 1) / 2;
        } else {
            pos = 2 * pos + 1;
            m = m / 2;
        }
    }

    // Output the final position of the n-th ball
    cout << pos << "\n";

    // Output the state of all leaf nodes
    int start_leaf = 1 << (D - 1);
    int end_leaf = (1 << D) - 1;
    for (int i = start_leaf; i <= end_leaf; ++i) {
        cout << (k[i] % 2) << (i == end_leaf ? "" : " ");
    }
    cout << "\n";

    return 0;
}

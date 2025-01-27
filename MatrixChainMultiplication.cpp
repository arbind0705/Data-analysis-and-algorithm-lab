#include <iostream>
using namespace std;

#define INF 100000000

int matrixChainMultiplication(int dims[], int n) {
    int dp[100][100];

    // Initialize the diagonal to 0, as multiplying a single matrix costs 0
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // Iterate over the chain length
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INF; // Initialize the minimum cost to a very large value

            for (int k = i; k < j; k++) {
                // Cost of splitting at k
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost; // Update the minimum cost
                }
            }
        }
    }

    return dp[1][n - 1]; // Return the minimum cost for the entire chain
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int dims[n + 1];
    cout << "Enter the dimensions of matrices: ";
    for (int i = 0; i < n + 1; i++) {
        cin >> dims[i];
    }

    cout << "Minimum number of scalar multiplications is: "
         << matrixChainMultiplication(dims, n + 1) << endl;

    return 0;
}

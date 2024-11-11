//Write a program to implement 0/1 knapsack using dynamic algorithm 
// Name : Kalash Malge 
// Roll No. : TIA31
// Batch : B

#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of objects: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<int> weights(n), values(n);

    
    cout << "Enter the weights and corresponding values of the objects:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Object " << i + 1 << " - Weight: ";
        cin >> weights[i];
        cout << "Object " << i + 1 << " - Value: ";
        cin >> values[i];
    }

    
    int max_value = knapsack(W, weights, values, n);

    
    cout << "The maximum value that can be obtained is: " << max_value << endl;

    return 0;
}


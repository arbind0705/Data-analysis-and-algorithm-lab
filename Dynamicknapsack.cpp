#include<iostream>
using namespace std;

struct item {
    int profit;
    int weight;
};

void knapsack(int capacity, int n, item items[]) {
    int dp[n+1][capacity+1];

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= capacity; w++) {
            if(i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if(items[i-1].weight <= w) {
                dp[i][w] = max(dp[i-1][w], items[i-1].profit + dp[i-1][w - items[i-1].weight]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << "Maximum profit: " << dp[n][capacity] << endl;
    
    int w = capacity;
    cout << "Selected items: ";
    for(int i = n; i > 0 && w > 0; i--) {
        if(dp[i][w] != dp[i-1][w]) {
            cout << i << " ";
            w -= items[i-1].weight;
        }
    }
    cout << endl;
}

int main() {
    int n, capacity;
    
    cout << "Enter the number of items: ";
    cin >> n;
    
    item items[n];
    
    cout << "Enter the profit of the items: ";
    for(int i = 0; i < n; i++) {
        cin >> items[i].profit;
    }
    
    cout << "Enter the weight of the items: ";
    for(int i = 0; i < n; i++) {
        cin >> items[i].weight;
    }
    
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    
    knapsack(capacity, n, items);
    
    return 0;
}

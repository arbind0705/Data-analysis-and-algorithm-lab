#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
};

bool compare(Item a, Item b) {
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
}

double fractionalknapsack(int W, Item Items[], int n) {
    sort(Items, Items + n, compare);

    double max_value = 0.0;
    for (int i = 0; i < n; i++) {
        if (W >= Items[i].weight) {
            max_value += Items[i].profit;
            W -= Items[i].weight;
        } else {
            max_value += Items[i].profit * ((double)W / Items[i].weight);
            break;
        }
    }
    return max_value;
}

int main() {
    int n, w;
    cout << "Enter the number of items and knapsack capacity:\n";
    cin >> n >> w;

    Item Items[n];
    cout << "Enter the profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> Items[i].profit >> Items[i].weight;
    }

    double result = fractionalknapsack(w, Items, n);
    cout << "Maximum profit: " << result << endl;

    return 0;
}

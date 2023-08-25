// coins.cpp

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// Globals

vector<int> COINS = {1, 3, 4};

// Functions

vector<int> compute_table(int n, const vector<int>& coins = COINS) {
    // Initialize table to n
    vector<int> table(n + 1, INT_MAX);

    // Initialize base cases (ie. coins)
    for (auto coin : coins) {
    	table[coin] = 1;
    }

    // For each entry i in table, compute the following recurrence relation:
    //
    //	table[i] = min(table[i - coin] + 1 for coin in coins if (i - coin) >= 0)
    for (int i = 1; i <= n; i++) {
    	if (table[i] != INT_MAX) {
    	    continue;
	}

	for (auto coin : coins) {
	    if ((i - coin) >= 0) {
		table[i] = min(table[i], table[i - coin] + 1);
	    }
	}
    }

    return table;
}

vector<int> compute_table_forward(int n, const vector<int>& coins = COINS) {
    // Initialize table to n
    vector<int> table(n + 1, n);

    // Initialize base cases (ie. coins)
    for (auto coin : coins) {
    	table[coin] = 1;
    }

    // For each entry i in table, generate success values:
    //
    //	table[i + coin] = min(table[i] + 1, table[i + coin])
    for (int i = 1; i <= n; i++) {
	for (auto coin : coins) {
	    if ((i + coin) <= n) {
		table[i + coin] = min(table[i + coin], table[i] + 1);
	    }
	}
    }

    return table;
}

// Main Execution

int main(int argc, char *argv[]) {
    //vector<int> table = compute_table(100);
    vector<int> table = compute_table_forward(100);
    int n;

    while (cin >> n) {
    	cout << n << " = " << table[n] << endl;
    }

    return 0;
}

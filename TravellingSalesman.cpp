#include<bits/stdc++.h>
using namespace std;


// Hamilitonian Cycle - DP and Bit masking

int n = 4;
int dp[16][4];
int dist[10][10] = {
	{0, 20, 45, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};

int VISITED_ALL  = (1 << n) - 1;

int tsp(int mask , int pos) {
	if (mask == VISITED_ALL) {
		return dist[pos][0];
	}
	if (dp[mask][pos] != -1) {
		return dp[mask][pos];
	}

	int ans = INT_MAX;
	//unvisited cities
	for (int city = 0; city < n; city++) {
		if ((mask & (1 << city)) == 0) {
			int newAns = dist[pos][city] + tsp(mask | (1 << city), city); //
			// mask | (1<<city)  is to mark the current city visited
			ans  = min(ans, newAns);
		}
	}

	return dp[mask][pos]  = ans;
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	cout << tsp(1, 0);

	return 0;
}
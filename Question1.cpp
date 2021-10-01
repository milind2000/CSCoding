#include<bits/stdc++.h>
using namespace std;

int solution(int n) {
	int val = n / 3;
	if (n % 3 == 0)return val + val;
	else return val + val + 1;
}

/*  Do not edit below code */
int main() {
	int n;
	cin >> n;
	int answer = solution(n);
	cout << answer << endl;
}

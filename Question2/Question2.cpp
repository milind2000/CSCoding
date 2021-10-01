#include <bits/stdc++.h>
using namespace std;

int main() {

    int z;
    cin >> z;
    vector<int> input_data;
    string buffer;
    int data;
    getline(cin, buffer);
    getline(cin, buffer);
    istringstream iss(buffer);


    while (iss >> data)
        input_data.push_back(data);

    int n = input_data.size();


    int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }



    int no_of_stocks = 0;

    vector<pair<int, int>> vp;


    for (int i = 0; i < n; i++) {
        vp.push_back({security_value[i], i + 1});
    }

    sort(vp.begin(), vp.end());

    for (int i = 0; i < n; i++) {
        int val = min(vp[i].second, z / vp[i].first);
        no_of_stocks = no_of_stocks + val ;
        z = z - (vp[i].first * val);
    }

    cout << no_of_stocks;

}



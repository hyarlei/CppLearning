#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<int> freq(queries.size(), 0);

    for (int i = 0; i < queries.size(); i++) {
        for (int j = 0; j < strings.size(); j++) {
            if (queries[i] == strings[j]) {
                freq[i]++;
            }
        }
    }

    return freq;
}

int main() {
    int n, m;
    cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    cin >> m;
    vector<string> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    vector<int> res = matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

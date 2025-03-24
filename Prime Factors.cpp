#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> retis(int max) {
    vector<int> p(max + 1, 0);
    p[1] = 1;
    for (int i = 2; i <= max; i++) {
        if (p[i] == 0) {
            p[i] = i;
            for (int j = i; j <= max; j += i) if (!p[j])p[j] = i;
        }
    }

    return p;
}

int search(int i, vector<int>& pdl) {
    int d;
    int a = 0;
    while (i > 1) {
        i = i / pdl[i];
        a++;
    }
    return a;
}

int main() {
    int n, k, c;
    int maxel = 0;
    int maxdal = 0;
    cin >> n >> k;
    if (k > 0) {
        vector<int> pdl = retis(k);
        for (int i = n; i <= k; i++) {
            c = search(i, pdl);
            if (c >= maxdal) {
                maxel = i;
                maxdal = c;
            }
        }
        cout << maxel;
    }
    else cout << k;

    return 0;
}
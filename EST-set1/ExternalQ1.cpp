//smallest substring of s that contain all character of t string

#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    string s, t;
    if (!(cin >> s >> t)) return 0;

    vector<int> need(256, 0);
    for (char c : t) need[(unsigned char)c]++;

    int required = 0;
    for (int x : need) if (x > 0) required++;

    vector<int> window(256, 0);
    int formed = 0;
    int l = 0, r = 0;
    int minLen = INT_MAX, minL = 0;

    while (r < (int)s.size()) {
        char c = s[r];
        window[(unsigned char)c]++;
        if (need[(unsigned char)c] > 0 && window[(unsigned char)c] == need[(unsigned char)c]) {
            formed++;
        }

        // try to contract from left while window is valid
        while (l <= r && formed == required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                minL = l;
            }
            char cl = s[l];
            window[(unsigned char)cl]--;
            if (need[(unsigned char)cl] > 0 && window[(unsigned char)cl] < need[(unsigned char)cl]) {
                formed--;
            }
            l++;
        }
        r++;
    }

    if (minLen == INT_MAX) {
        cout << "-1\n"; // no valid window
    } else {
        cout << size(s.substr(minL, minLen) )<< "\n";
    }

    return 0;
}




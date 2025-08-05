#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int E=0, G=0, Y=0, P=0, T=0;
    for (char c : s) {
        c = toupper(c);
        if (c == 'E') E++;
        if (c == 'G') G++;
        if (c == 'Y') Y++;
        if (c == 'P') P++;
        if (c == 'T') T++;
    }
    cout << min({E, G, Y, P, T});
}


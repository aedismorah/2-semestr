#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, int> a;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        a[tmp] = tmp.length();
    }

    set<int> dl;
    for (auto num : a) {
        dl.insert(num.second);
    }

    int j = 0;
    set<string> ans;
    for (int i = 0; i < N; i++) {
        for (auto num : a) {
            if (i > 1) {
                if (num.second == i) {
                    for (int k = 1; k < i/ 2 + 2; ++k) // int k = 1;
                    {
                        if (dl.find(i - k) != dl.end()) {
                            string s1, s2, s3, s4;
                            s1 = num.first.substr(0, i);
                            s2 = num.first.substr(i);
                            s3 = num.first.substr(0, k);
                            s4 = num.first.substr(k);
                            if (((a.find(s1) != a.end()) && (a.find(s2) != a.end())) || ((a.find(s3) != a.end()) && (a.find(s4) != a.end()))) {
                                if (ans.find(num.first) == ans.end())
                                {
                                ans.insert(num.first);
                                break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //  cout << j << endl;
   // cout << endl;
    for (auto num : ans) {
        cout << num << endl;
    }
}

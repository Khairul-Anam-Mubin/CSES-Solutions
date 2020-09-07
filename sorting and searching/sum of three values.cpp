#include <bits/stdc++.h>
using namespace std;

int Binary_Search(long long ar[] , int low , int high, long long val) {
    while (low < high) {
        int mid = (low + high) / 2;
        if (ar[mid] == val) return mid;
        else if (ar[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n; cin >> n;
    long long x , ar[n + 1] , br[n + 1];
    cin >> x;
    vector <pair <int , int>> vec;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        vec.emplace_back(ar[i] , i);
    }
    sort(vec.begin() , vec.end());
    for (int i = 0; i < n; i++) ar[i] = vec[i].first;
    vector <pair <long long , pair <long long , long long>>> v;
    map <long long , long long> freq , id;
    for (int i = 0; i < n; i++) {
        freq[ar[i]]++;
        if (freq[ar[i]] == 1) id[ar[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ar[i] + ar[j] < x) {
                v.emplace_back(make_pair(ar[i] + ar[j], make_pair( i , j)));
            }
        }
    }
    bool flag = 0;
    int a , b , c;
    for (auto it : v) {
        long long last = x - it.first;
        int now = Binary_Search(ar , 0 , n - 1, last);
        if (now == -1) continue;
        int so = id[ar[now]];
        int frq = freq[ar[now]];
        for (int j = so; j < so + frq; j++) {
            if (j != it.second.second && j != it.second.first) {
                flag = 1;
                a = j;
                b = it.second.second;
                c = it.second.first;
                a = vec[a].second + 1;
                b = vec[b].second + 1;
                c = vec[c].second + 1;
                break;
            }
        }
    } 
    if (flag) {
        cout << a << " " << b << " " << c << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
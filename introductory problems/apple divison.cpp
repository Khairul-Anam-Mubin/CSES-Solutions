#include <bits/stdc++.h>
using namespace std;

#define INF18 1000000000000000000

bool IsSet(int num , int pos) {
    return (num & (1 << pos));
}
long long AllSubset(long long ar[] , int n , long long sum) {
    int tot = 1 << n;
    long long ans = INF18;
    for (int i = 0; i < tot; i++) {
        long long cur = 0;
        for (int j = 0; j < n; j++) {
            if (IsSet(i , j)) {
                cur += ar[j];
            } 
        }
        long long now = sum - cur;
        ans = min(ans , max(now , cur) - min(now , cur));
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    long long ar[n + 1];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }
    cout << AllSubset(ar , n , sum) << "\n";
    return 0;
}
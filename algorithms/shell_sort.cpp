#include <bits/stdc++.h>

using namespace std;

void shellSort(long long arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            long long key = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
    }
}

int main() {
    int n;
    cin >> n;

    long long v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    shellSort(v, n);
}
#include <bits/stdc++.h>

using namespace std;

void countingSortForRadix(long long arr[], int n, long long exp) {
    long long output[n], count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(long long arr[], int n) {
    long long maxVal = *std::max_element(arr, arr + n);

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(arr, n, exp);
    }
}

int main() {
    int n;
    cin >> n;

    long long v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    radixSort(v, n);
}
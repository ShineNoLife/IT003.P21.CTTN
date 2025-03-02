#include <bits/stdc++.h>

using namespace std;

void countingSort(long long arr[], int n) {
    long long maxVal = *std::max_element(arr, arr + n);
    long long minVal = *std::min_element(arr, arr + n);
    int range = maxVal - minVal + 1;

    std::vector<int> count(range, 0), output(n);

    for (int i = 0; i < n; i++) count[arr[i] - minVal]++;

    for (int i = 1; i < range; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

int main() {
    int n;
    cin >> n;

    long long v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    countingSort(v, n);
}
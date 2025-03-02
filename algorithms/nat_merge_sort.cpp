#include <bits/stdc++.h>

using namespace std;

void merge(long long arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    long long L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void naturalMergeSort(long long arr[], int n) {
    std::vector<std::pair<int, int>> runs;
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            runs.push_back({start, i - 1});
            start = i;
        }
    }
    runs.push_back({start, n - 1});

    while (runs.size() > 1) {
        std::vector<std::pair<int, int>> newRuns;
        for (size_t i = 0; i < runs.size(); i += 2) {
            if (i + 1 < runs.size()) {
                merge(arr, runs[i].first, runs[i].second, runs[i + 1].second);
                newRuns.push_back({runs[i].first, runs[i + 1].second});
            } else {
                newRuns.push_back(runs[i]);
            }
        }
        runs = newRuns;
    }
}

int main() {
    int n;
    cin >> n;

    long long v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
        
    naturalMergeSort(v, n);
}
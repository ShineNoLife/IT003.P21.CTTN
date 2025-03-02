#include <bits/stdc++.h>

using namespace std;

struct HeapNode {
    long long value;
    int arrayIndex, elementIndex;
    bool operator>(const HeapNode &other) const {
        return value > other.value;
    }
};

void kWayMergeSort(long long arr[], int n, int k) {
    if (n <= 1) return;

    int partSize = (n + k - 1) / k;
    std::vector<std::vector<long long>> subarrays(k);

    for (int i = 0; i < n; i++)
        subarrays[i / partSize].push_back(arr[i]);

    for (int i = 0; i < k; i++)
        std::sort(subarrays[i].begin(), subarrays[i].end());
    
    std::priority_queue<HeapNode, std::vector<HeapNode>, std::greater<>> minHeap;
    for (int i = 0; i < k; i++) {
        if (!subarrays[i].empty()) {
            minHeap.push({subarrays[i][0], i, 0});
        }
    }

    int index = 0;
    while (!minHeap.empty()) {
        HeapNode node = minHeap.top();
        minHeap.pop();
        arr[index++] = node.value;

        if (node.elementIndex + 1 < subarrays[node.arrayIndex].size()) {
            minHeap.push({subarrays[node.arrayIndex][node.elementIndex + 1], node.arrayIndex, node.elementIndex + 1});
        }
    }
}

int main() {
    int n;
    cin >> n;

    long long v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    kWayMergeSort(v, n, (int)sqrt(n));
}
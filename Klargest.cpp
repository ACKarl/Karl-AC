#include <queue>
#include <vector>

int kth_largest(std::vector<int> values, int k) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

  for (int val : values) {
    if (pq.size() < k) {
      pq.push(val);
    } else if (val > pq.top()) {
      pq.pop();
      pq.push(val);
    }
  }

  return pq.top();
}

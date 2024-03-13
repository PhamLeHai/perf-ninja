#include "solution.hpp"

#include <algorithm>
#include <cstdint>

bool ready = false;
std::array<uint8_t, 100> vals;

#ifdef SOLUTION
static std::size_t mapToBucket(std::size_t v) {    // diff
  if(v < 0 || v >= 100) {
    return -1;
  }
  return vals[v];
}
#else
static std::size_t mapToBucket(std::size_t v) {    // diff
  if (v >= 0 && v < 13)        return 0; // 13
  else if (v >= 13 && v < 29)  return 1; // 16
  else if (v >= 29 && v < 41)  return 2; // 12
  else if (v >= 41 && v < 53)  return 3; // 12
  else if (v >= 53 && v < 71)  return 4; // 18
  else if (v >= 71 && v < 83)  return 5; // 12
  else if (v >= 83 && v < 100) return 6; // 17
  return -1;  // let it crash
}
#endif

void init() {
  std::fill(vals.begin(), vals.begin() + 13, 0);
  std::fill(vals.begin() + 13, vals.begin() + 29, 1);
  std::fill(vals.begin() + 29, vals.begin() + 41, 2);
  std::fill(vals.begin() + 41, vals.begin() + 53, 3);
  std::fill(vals.begin() + 53, vals.begin() + 71, 4);
  std::fill(vals.begin() + 71, vals.begin() + 83, 5);
  std::fill(vals.begin() + 83, vals.begin() + 100, 6);
}

std::array<std::size_t, NUM_BUCKETS> histogram(const std::vector<int> &values) {
  std::array<std::size_t, NUM_BUCKETS> retBuckets{0};
  if(!ready) {
    init();
  }
  for (auto v : values) {
    retBuckets[mapToBucket(v)]++;
  }
  return retBuckets;
}

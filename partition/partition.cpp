// This program shows off the basics of using the partition algorithms in C++
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <array>
#include <iostream>

using std::array;
using std::cout;
using std::endl;
using std::is_partitioned;
using std::partition;
using std::partition_copy;
using std::partition_point;
using std::stable_partition;

// Helper function for printing
template <size_t SIZE>
void print(const array<int, SIZE> &a) {
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  // Create an array for our examples;
  array<int, 10> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << "Before partition" << endl;
  print(a);

  // Partition divides a range of elements into two groups based on a predicate
  // Returns an iterator pointing to the first element of the group where the
  // predicate was false
  auto mid_1 =
      partition(begin(a), end(a), [](auto &em) { return em % 2 == 0; });
  cout << "After partition" << endl;
  print(a);

  // We can use is_partitioned to check if our container is already partitioned
  bool b =
      is_partitioned(begin(a), end(a), [](auto &em) { return em % 2 == 0; });
  cout << "Partitioned? " << b << endl;

  // We can also use partition_point to get the iterator past the first range
  // (same as returned by partition)
  auto p =
      partition_point(begin(a), end(a), [](auto &em) { return em % 2 == 0; });
  cout << "mid == p? " << (mid_1 == p) << endl;

  // Reset the array
  a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Stable partition works in a similar way as partition, but retains the
  // relative ordering of the elements
  auto mid_2 =
      stable_partition(begin(a), end(a), [](auto &em) { return em % 2 == 0; });
  cout << "After stable_partition" << endl;
  print(a);

  // Reset the array
  a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Create two output arrays
  array<int, 5> out_1;
  array<int, 5> out_2;

  // Partition copy does the same thing as partition, but copies the result to
  // two different ranges
  // Returns a pair of iterators to the end of the true and false ranges
  auto pair = partition_copy(begin(a), end(a), begin(out_1), begin(out_2),
                             [](auto &em) { return em % 2 == 0; });
  cout << "True partition range" << endl;
  print(out_1);
  cout << "False partition range" << endl;
  print(out_2);

  return 0;
}

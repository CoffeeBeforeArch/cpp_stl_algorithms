// This program shows the STL algorithms related to sorting
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::is_sorted;
using std::is_sorted_until;
using std::nth_element;
using std::partial_sort;
using std::partial_sort_copy;
using std::sort;
using std::stable_sort;
using std::string;
using std::vector;

// Helper function to print all the elements in a vector
void print(vector<int> &v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
}

// Struct for stable sort example
struct Employee {
  int ID;
  string name;
};

int main() {
  // Create a vector with "random" numbers
  vector<int> v = {49, 21, 24, 18, 94, 1, 12, 38, 44};
  print(v);

  // Sorting is a very common operation, so it's unsurprising that there's an
  // STL algorithm that does it
  sort(begin(v), end(v));
  print(v);

  // We can test to see if a our vector is in sorted order
  bool b = is_sorted(begin(v), end(v));
  cout << "Is sorted: " << b << endl;

  // Reset the vector, and partially sort it
  v = {49, 21, 24, 18, 94, 1, 12, 38, 44};
  partial_sort(begin(v), begin(v) + 3, end(v));
  print(v);

  // We may have an input (such as above) that is partially sorted
  // We can get the last iterator for which the range is sorted!
  auto it_1 = is_sorted_until(begin(v), end(v));
  cout << "First element not in sorted order: " << *it_1 << endl;

  // If we Don't want to modify the original array we can copy the sorted
  // elements to a new vector
  // Will copy until the output vector is full (first 3 elements in this case)
  // it_2 points to the end of the copied range
  v = {49, 21, 24, 18, 94, 1, 12, 38, 44};
  vector<int> copy(3);
  auto it_2 = partial_sort_copy(begin(v), end(v), begin(copy), end(copy));
  print(v);
  print(copy);

  // We can use stable sort if we want to retain the relative order of elements
  // with the same value. While this isn't relevant for integers, it can be for
  // sorting objects
  vector<Employee> v_2 = {{50, "Bill"}, {20, "Mollie"}, {50, "Nick"}};
  stable_sort(begin(v_2), end(v_2), [](const Employee &e1, const Employee &e2) {
    return e1.ID < e2.ID;
  });

  // Dump the sorted vector
  for (auto i : v_2) {
    cout << i.ID << " " << i.name << endl;
  }

  // We can use nth_element to place one element in sorted order, and partition
  // the other elements around it
  // Here's a simple way we can find the median element
  nth_element(begin(v), begin(v) + v.size() / 2, end(v));
  print(v);

  return 0;
}

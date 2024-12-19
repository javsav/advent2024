#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class ProblemOne {
 public:
  static std::vector<int>& mergeSort(std::vector<int>& list) {
    int end = list.size() - 1;
    int start = 0;
    mSort(list, start, end);
    return list;
  }

  static void mSort(std::vector<int>& list, int start, int end) {
    if (start >= end) {
      return;
    }
    int mid = (start + end) / 2;
    mSort(list, start, mid);
    mSort(list, mid + 1, end);
    int lSize = mid - start + 1;
    int rSize = end - mid;
    int left[lSize];
    int right[rSize];

    for (int i = 0; i < lSize; i++) {
      left[i] = list[i + start];
    }

    for (int i = 0; i < rSize; i++) {
      right[i] = list[i + mid + 1];
    }

    int l = 0;
    int r = 0;
    int p = 0;
    while (l < lSize && r < rSize) {
      if (left[l] <= right[r]) {
        list[start + l + r] = left[l];
        l++;
      } else {
        list[start + l + r] = right[r];
        r++;
      }
    }

    while (l < lSize) {
      list[start + l + r] = left[l];
      l++;
    }

    while (r < rSize) {
      list[start + l + r] = right[r];
      r++;
    }
  }

  static int p1() {
    std::ifstream infile("problem1.txt");
    std::string line;
    std::vector<int> list1;
    list1.reserve(1000);
    std::vector<int> list2;
    list2.reserve(1000);

    while (std::getline(infile, line, '\n')) {
      std::stringstream ss(line);
      int num1;
      ss >> num1;
      list1.push_back(num1);
      int num2;
      ss >> num2;
      list2.push_back(num2);
    }

    mergeSort(list1);
    mergeSort(list2);

    // Count distances
    int distance = 0;
    for (int i = 0; i < 1000; i++) {
      distance += abs(list1[i] - list2[i]);
    }

    return distance;
  }
};



int main() {
  std::cout << ProblemOne::p1() << '\n';
}
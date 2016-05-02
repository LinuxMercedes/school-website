#include<numeric>
#include<iostream>
#include<vector>
#include"print_vector.h"
using namespace std;

template<class T, class Func>
bool all(vector<T> v, Func pred) {
  return accumulate(
      v.begin(),
      v.end(),
      true,
      [&] (bool acc, T val) {
        return acc && pred(val);
      }
    );
}

int main() {
  vector<int> nums = {1,2,3,4,5,6};

  cout << all(nums, [] (int n) { return n > 0; }) << endl;
  cout << all(nums, [] (int n) { return n % 2 == 0; }) << endl;
  return 0;
}
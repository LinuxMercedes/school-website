#include<vector>
#include<iostream>

template<class Item>
class Vector {
  public:
    Vector(const unsigned int size) : v(size) {}

    unsigned int size() { return v.size(); }

    Item& operator[](const unsigned int idx) {
      return v[idx];
    }

    template<class Func>
    Vector map(Func f) {
      Vector ret(size());

      for(unsigned int i = 0; i < size(); i++) {
        ret[i] = f(v[i]);
      }

      return ret;
    }

  private:
    std::vector<Item> v;
};

int main() {
  Vector<int> nums(5);
  for(int i = 0; i < 5; i++) {
    nums[i] = i;
  }

  Vector<int> doubled = nums.map([] (int n) { return n * 2; });

  for(int i = 0; i < 5; i++) {
    std::cout << nums[i] << " * 2 = " << doubled[i] << std::endl;
  }

  return 0;
}

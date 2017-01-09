int function (int a) {
  return a + 3;
}

class Functor {
  public:
    int operator()(int a) {
      return a + 3;
    }
};

int main() {
  auto lambda = [] (int a) { return a + 3; };

  Functor functor;

  volatile int y1 = function(5);
  volatile int y2 = functor(5);
  volatile int y3 = lambda(5);

  return 0;
}
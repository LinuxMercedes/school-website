class Functor {
  public:
    Functor(int& x): m_x(x) {}

    int operator()(int a) {
      return a + m_x++;
    }

  private:
    int& m_x;
};

int main() {
  int x = 3;

  auto lambda = [&] (int a) { return a + x++; };

  Functor functor(x);

  volatile int y1 = functor(5);
  volatile int y2 = lambda(5);

  return 0;
}

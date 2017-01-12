/* Let's pretend we want to write a crappy Vector class that's not very fancy.
 * In fact, all it's going to do is wrap std::vector...
 *
 * BUT, it's going to have a map() member function that takes some function, applies
 * it to every element of the vector, and returns a vector that contains the return
 * values of this function.
 *
 * Naturally, our Vector is templated. We could write the declaration for map() like so:
 * template<class Func>
 * Vector<T> map(Func f) const;
 *
 * This would work perfectly fine for a Func that takes a T and returns a T, like
 * example #1 below in main().
 *
 * BUT, what if we have a Func that returns something other than a T, like example #2?
 *
 * Well, that's where std::result_of comes in!
 *
 * Behold:
 */

#include<vector> // screw writing all that array crap
#include<string> // cheese, yum
#include<iostream> // My C++ students taught me my code won't compile without this

template<class T>
class Vector
{
  public:
    Vector(const unsigned int size) : my_vec(size) {}

    T& operator[](const unsigned int idx) { return my_vec[idx]; }

    unsigned int size() const { return my_vec.size(); }

    /* C++11 introduced templated type aliases with the 'using' keyword.
     * To cut down on repitition, I'll use one here.
     */
    template<class Func>
    using Ret_t = typename std::result_of<Func(T)>::type;
    /* Here's the magic: the return type of map() depends
     * on the return type of f!
     * Ret_t<Func> gives us f's return type.
     */
    template<class Func>
    Vector<Ret_t<Func>> map(Func f) const
    {
      Vector<Ret_t<Func>> result(size());

      for(unsigned int i = 0; i < size(); i++)
      {
        result[i] = f(my_vec[i]);
      }

      return result;
    }

  private:
    std::vector<T> my_vec;

};

std::string int_to_str(const int i)
{
  switch(i)
  {
    case 0:
      return "zero";
    case 1:
      return "one";
    case 2:
      return "three";
    case 3:
      return "tres";
    case 4:
      return "fahr";
    case 5:
      return "funf";
    case 6:
      return "[censored]";
    case 7:
      return "the best number";
    case 8:
      return "actually, infinity";
    case 9:
      return "none";
    default:
      return "a big number";
  }
}

int main()
{
  Vector<int> ints(5);

  for(int i = 0; i < 5; i++)
    ints[i] = i;

  // EXAMPLE #1
  auto doubles = ints.map([] (int i)  { return i * 2; });

  // EXAMPLE #2
  auto words = doubles.map(int_to_str);

  for(int i = 0; i < 5; i++)
    std::cout << words[i] << std::endl;

  return 0;
}

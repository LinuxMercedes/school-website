#ifndef VECTOR_H
#define VECTOR_H

#include<stdexcept> // for invalid_argument
using namespace std;

/*! A (very neat) vector.
 *
 * It's a vector. You put stuff in it, you get stuff out of it, that's about it.
 *
 * \pre T must support assignment (T = T)
 */
template<class T>
class Vector
{
  public:
    /*! Constructs an empty vector.
     *
     * \post The underlying storage is allocated with 4 elements.
     */
    Vector();

    /*! Copy Constructor
     *
     * \post Creates a new vector with copies of elements from v
     *       and underlying storage size equal to that of v's storage.
     */
    Vector(const Vector<T>& v);

    //! Destructor
    ~Vector();

    /*! Add elements to the vector.
     *
     * \pre None.
     * \post The element is added to the end of the vector.
     *       If need be, the size of the underlying storage is doubled.
     */
    void push_back(T v);

    /*! Reads an element of the vector.
     *
     * \param idx the index of the element to read.
     * \return The element at position idx is returned.
     *
     * \pre idx is within the range [0, length()).
     * \throws std::invalid_argument is thrown if idx is out of range.
     */
    T& operator[](const unsigned int idx);

    /*! The number of items stored in the vector.
     *
     * \return the number of items stored in the vector.
     */
    unsigned int length() const;

    /*! The size of the underlying storage.
     *
     * \return the size of the underlying storage.
     */
    unsigned int size() const;

  private:
    unsigned int sz;
    unsigned int max;
    T* array;
};

#include"vector.hpp"
#endif

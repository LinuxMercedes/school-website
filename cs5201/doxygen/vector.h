/*! \file
 *
 * A Vector library.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include<stdexcept>
using std::invalid_argument;
#include<iostream>
using std::ostream;

#ifndef DOXYGEN
template<class FUN>
class Vector;
#endif

/*! Stream insertion operator for `Vector`.
 *
 * \pre Stream insertion operator is defined for `FUN`.
 * \post The contents of the vector are printed to the ouptut stream.
 * \return the modified output stream.
 *
 * \relatesalso Vector
 */
template<class FUN>
ostream& operator<<(ostream& out, const Vector<FUN>& v);

/*! A (very neat) vector.
 *
 * It's a vector. You put stuff into it, you get stuff out of it, that's about it.
 *
 * \pre FUN must support assignment (FUN = FUN)
 */
template<class FUN>
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
    Vector(const Vector<FUN>& v);

    //! Destructor
    ~Vector();

    /*! Add elements to the vector.
     *
     * \pre None.
     * \post The element is added to the end of the vector.
     *       If need be, the size of the underlying storage is doubled.
     */
    void push_back(FUN v);

    /*! Reads an element of the vector.
     *
     * \param idx the index of the element to read.
     * \return The element at position idx is returned.
     *
     * \pre idx is within the range [0, length()).
     * \throws std::invalid_argument is thrown if idx is out of range.
     */
    FUN& operator[](const unsigned int idx);

    /*! Reads an element of the vector.
     *
     * \param idx the index of the element to read.
     * \return The element at position idx is returned.
     *
     * \pre idx is within the range [0, length()).
     * \throws std::invalid_argument is thrown if idx is out of range.
     */
    const FUN& operator[](const unsigned int idx) const;

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

#ifndef DOXYGEN
    /* Doxygen appears to have a couple bugs related to template classes and friend functions.
     * At this point, the best fix I see is to set
     * PREDEFINED = DOXYGEN
     * in your Doxyfile, then use #ifndef DOXYGEN / #endif to remove code that confuses Doxygen.
     *
     * Note that this function is documented at the top of the file and uses the \relatesalso
     * command so that it will be included on the Vector class docs page.
     *
     * Also note that the implementation of this function doesn't require it to be a friend of Vector;
     * in practice, I'd probably not bother with making it a friend at all.
     */
    friend ostream& operator<< <FUN>(ostream& out, const Vector<FUN>& v);
#endif
  private:
    unsigned int sz;
    unsigned int max;
    FUN* array;
};

#include"vector.hpp"
#endif

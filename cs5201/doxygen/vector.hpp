// Constructor
template<class FUN>
Vector<FUN>::Vector()
{
  sz = 4;
  max = 0;
  array = new FUN[4];
}

// Copy Constructor
template<class FUN>
Vector<FUN>::Vector(const Vector<FUN>& v)
{
  sz = v.sz;
  max = v.max;
  array = new FUN[sz];
  for(unsigned int i = 0; i < max; i++)
  {
    array[i] = v.array[i];
  }
}

// Destructor
template<class FUN>
Vector<FUN>::~Vector()
{
  delete [] array;
}

// Add elements to the vector
template<class FUN>
void Vector<FUN>::push_back(FUN v)
{
  // Expand vector if needed
  if(max == sz)
  {
    sz = sz * 2;
    FUN* new_array = new FUN[sz];
    for(unsigned int i = 0; i < max; i++)
    {
      new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;
  }

  array[max] = v;
  max++;
}

// Read elements of the vector
template<class FUN>
FUN& Vector<FUN>::operator[](const unsigned int idx)
{
  if(idx < 0 || idx >= max)
  {
    throw invalid_argument("Index out of range");
  }

  return array[idx];
}

// length getter
template<class FUN>
unsigned int Vector<FUN>::length() const
{
  return max;
}

// size getter
template<class FUN>
unsigned int Vector<FUN>::size() const
{
  return sz;
}

template<class FUN>
ostream& operator<<(ostream& out, const Vector<FUN>^& v)
{
  out << "[";

  // if v.size() == 0 then v.size() - 1 underflows
  if(v.size() > 0)
  {
    for(unsigned int i = 0; i < v.size() - 1; i++)
    {
      out << v[i] << ", ";
    }
    out << v[v.size() - 1];
  }

  out << "]";
  return out;
}

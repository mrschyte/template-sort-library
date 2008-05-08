#ifndef __ARRAYACCESSOR_HPP__
#define __ARRAYACCESSOR_HPP__

#include <cstring>

namespace tsl { namespace util {

  template <class T>
  class ArrayAccessor
  {
    private:
      T* storedArray;
      unsigned int arraySize;
      bool allocatedArray;

    public:
      ArrayAccessor(T* array, unsigned int length)
      {
        storedArray = array;
        arraySize = length;
        allocatedArray = false;
      }

      ArrayAccessor(ArrayAccessor<T>& arrayAccessor)
      {
        storedArray = new T[arrayAccessor.size()];
        std::memcpy(storedArray, arrayAccessor.get(), sizeof(T) * arrayAccessor.size());
        arraySize = arrayAccessor.size();
        allocatedArray = true;
      }

      ~ArrayAccessor()
      {
        if (allocatedArray)
          delete[] storedArray;
      }

      T& at(unsigned int index)
      {
        return storedArray[index];
      }

      T& operator[](unsigned int index)
      {
        return at(index);
      }

      T* get()
      {
        return storedArray;
      }

      unsigned int size()
      {
        return arraySize;
      }
  };

} // util
} // tsl

#endif

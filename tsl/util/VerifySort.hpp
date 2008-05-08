#ifndef __VERIFYSORT_HPP__
#define __VERIFYSORT_HPP__

namespace tsl { namespace util {
  template <class T>
  class VerifySort
  {
    private:
      typedef void (*sort_function)(T& array, unsigned int length);

    public:
      static bool verify(sort_function sort, T& array, T& sorted_array, unsigned int length)
      {
        T temp(array);
        sort(temp, length);

        for (unsigned int i = 0; i < length; i++)
        {
          if (sorted_array[i] != temp[i])
            return false;
        }
        return true;
      }
  };

} // util
} // tsl

#endif

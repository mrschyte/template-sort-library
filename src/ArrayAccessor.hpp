#ifndef __ARRAYACCESSOR_HPP__
#define __ARRAYACCESSOR_HPP__

#include <boost/shared_array.hpp>
#include <cstring>

template <class T>
class ArrayAccessor : public boost::shared_array<T>
{
	private:
		unsigned int arraySize;

	public:
		ArrayAccessor(T* p, unsigned int length) : boost::shared_array<T>(new T[length])
		{
			std::memcpy(this->get(), p, sizeof(T) * length);
			arraySize = length;
		}

		ArrayAccessor(ArrayAccessor<T>& arrayAccessor) : boost::shared_array<T>(new T[arrayAccessor.size()])
		{
			std::memcpy(this->get(), arrayAccessor.get(), sizeof(T) * arrayAccessor.size());
			arraySize = arrayAccessor.size();
		}

		~ArrayAccessor()
		{

		}

		unsigned int size()
		{
			return arraySize;
		}
};

#endif

#ifndef HEAPARRAY_H
#define HEAPARRAY_H

#include <initializer_list>

using namespace std;

namespace util {
	template <class T>
	class HeapArray {
	private:
		T *arr;
		int capacity;

	public:
		HeapArray(int);
		HeapArray(initializer_list<T>);

		static HeapArray& New(int);
		static HeapArray& New(initializer_list<T>);

		~HeapArray();

		T &operator[] (int);
		int Size() const;
	};

}
#endif /* HEAPARRAY_H */
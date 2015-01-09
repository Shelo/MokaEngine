#include "HeapArray.h"
#include "Vertex.h"

namespace util {
	template <class T>
	HeapArray<T>::HeapArray(int capacity) {
		this->capacity = capacity;
		arr = new T[capacity];
	}

	template <class T>
	HeapArray<T>::HeapArray(initializer_list<T> l) {
		capacity = l.size();
		arr = new T[capacity];

		int i = 0;
		for(auto it = l.begin(); it != l.end(); it++) {
			arr[i] = *it; i++;
		}
	}

	template <class T>
	HeapArray<T> &HeapArray<T>::New(int capacity) {
		return *(new HeapArray(capacity));
	}

	template <class T>
	HeapArray<T> &HeapArray<T>::New(initializer_list<T> l) {
		return *(new HeapArray(l));
	}

	template <class T>
	HeapArray<T>::~HeapArray() {
		delete[] arr;
	}

	template <class T>
	T& HeapArray<T>::operator[] (int i) {
		return arr[i % capacity];
	}

	template <class T>
	int HeapArray<T>::Size() const {
		return capacity;
	}

	/* Template known implementations */
	template class HeapArray<int>;
	template class HeapArray<Vertex*>;
}
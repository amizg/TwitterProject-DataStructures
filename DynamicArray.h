#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

template <class T>
class Array {
public:
	Array (int initSize);
	void changeSize(int newSize);               // O(n) steps
	T & operator [] (int index);                // O(1) step
    int length() const { return capacity; }     // O(1) step
	int err() const { return errCode; }

	Array(const Array<T> & rhs) { deepCopy(rhs); }
	Array<T> & operator = (const Array<T> & rhs);
	~Array() { makeEmpty(); }
private:
	T * els;
	int capacity;
	int errCode;
	T dud;
	void deepCopy(const Array<T> & rhs);
	void makeEmpty() { delete[] els; }
};

template <class T>
Array<T>::Array (int initSize) {
    if (initSize <= 0) { errCode = 1; capacity = 1; }
    else { errCode = 0; capacity = initSize; }
    els = new T[capacity];
}

template <class T>
void Array<T>::changeSize(int newSize) {    // n -> 2n -- O(n) steps
    if (newSize <= 0) { errCode = errCode | 4; return; }
	T * temp = new T[newSize];
	int limit = newSize > capacity ? capacity : newSize;
	for (int i = 0; i < limit; i++) {   // limit * O(1)
		temp[i] = els[i];
	}
	delete [] els;
	els = temp;
	capacity = newSize;
}

template <class T>
T & Array<T>::operator [] (int index) {     // O(1) step
    if (index < 0 || index >= capacity) { errCode = errCode | 2; return dud; }
    return (els[index]);
}

template <class T>
Array<T> & Array<T>::operator = (const Array<T> & rhs) {
    if (this == & rhs) return (*this);
    makeEmpty(); deepCopy(rhs); return (*this);
}

template <class T>
void Array<T>::deepCopy(const Array<T> & rhs) {
    capacity = rhs.capacity;
    els = new T[capacity];
    for (int i = 0; i < capacity; i++) {
        els[i] = rhs.els[i];
    }
}

#endif // DYNAMICARRAY_H_INCLUDED

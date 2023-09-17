#ifndef ARRAY_TPP
#define ARRAY_TPP

#ifndef ARRAY_HPP
#error "Array.tpp" should not be included directly.
#endif

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {
    std::cout << "Array() called size:" << _size << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
    std::cout << "Array() called size:" << _size << std::endl;
}

template <typename T>
Array<T>::Array(Array const & src) : _array(NULL), _size(0) {
    *this = src;
    std::cout << "Array(copy) called size:" << _size << std::endl;
}

template <typename T>
Array<T>::~Array() {
    std::cout << "~Array() called size:" << _size << std::endl;
    delete [] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const & rhs) {
    if (this != &rhs) {
        delete [] _array;
        _array = new T[rhs._size];
        _size = rhs._size;
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = rhs._array[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= _size) {
        throw std::exception();
    }
    return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif

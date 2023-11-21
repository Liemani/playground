#ifndef A007_TYPE_HPP
#define A007_TYPE_HPP

#include <iostream>

template <typename T>
class A007_Type {
private:
	T item;
public:
// 	A007_Type(void);
// 	A007_Type(const A007_Type& a007_Type);
// 	~A007_Type(void);
	A007_Type& operator=(const A007_Type& rhs);
	void describe(void);
};

template <typename T>
void A007_Type<T>::describe(void) {
	std::cout << "sizeof(T): " << sizeof(T) << std::endl;
}

template <typename T>
A007_Type<T>& A007_Type<T>::operator=(const A007_Type<T>& rhs) {
	this->item = rhs.item;
	return *this;
}

#endif

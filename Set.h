#pragma once
#include "Bitwise.h"
class MySet: public Bitwise
{
private:

public:
	MySet(size_t n) : Bitwise(n) {}
	MySet(const MySet& s) : Bitwise(s) {}	

	MySet& operator+(MySet& b);
	MySet& operator*(MySet& b);
	MySet& operator-();
	MySet& operator^(MySet& b);// XOR
	MySet& operator -(MySet& b);// Исключение

	void Obedinenie(MySet& b);
	void Perechenie(MySet& b);
	void Otricanie();
	void Iscluchenie(MySet& b);
	void Xor(MySet& b);

};


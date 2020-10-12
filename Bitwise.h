#pragma once

#define S (sizeof(unsigned char)*8)

class Bitwise
{
	protected:

		unsigned char* data;//массив
		size_t size;// размер его


	public:
		Bitwise();
		Bitwise(size_t n);
		Bitwise(const Bitwise& bf);
		~Bitwise();// диструктор
		Bitwise& operator=(const Bitwise& b);

		/*void Obedinenie(Bitwise& b);
		void Perechenie(Bitwise& b);
		void Otricanie();
		void Iscluchenie(Bitwise& b);
		void Xor(Bitwise& b);*/

		int Get(size_t i);// извлечь бит
		void Set(size_t i);// добавить бит
		void print();
		void input();// сами задаем позиции, в которых будут 1-цы
		void Clr(size_t i);// погасить бит

		//Bitwise& operator+(Bitwise& b);
		//Bitwise&  operator*(Bitwise& b);
		//Bitwise& operator-();
		//Bitwise& operator^(Bitwise& b);// XOR
		//Bitwise& operator -(Bitwise& b);// Исключение
};


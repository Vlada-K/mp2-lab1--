#pragma once

#define S (sizeof(unsigned char)*8)

class Bitwise
{
	protected:

		unsigned char* data;//������
		size_t size;// ������ ���


	public:
		Bitwise();
		Bitwise(size_t n);
		Bitwise(const Bitwise& bf);
		~Bitwise();// ����������
		Bitwise& operator=(const Bitwise& b);

		/*void Obedinenie(Bitwise& b);
		void Perechenie(Bitwise& b);
		void Otricanie();
		void Iscluchenie(Bitwise& b);
		void Xor(Bitwise& b);*/

		int Get(size_t i);// ������� ���
		void Set(size_t i);// �������� ���
		void print();
		void input();// ���� ������ �������, � ������� ����� 1-��
		void Clr(size_t i);// �������� ���

		//Bitwise& operator+(Bitwise& b);
		//Bitwise&  operator*(Bitwise& b);
		//Bitwise& operator-();
		//Bitwise& operator^(Bitwise& b);// XOR
		//Bitwise& operator -(Bitwise& b);// ����������
};


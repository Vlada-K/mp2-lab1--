#include "Bitwise.h"
#include <stdlib.h>
#include <iostream>
#include< cstring>
using namespace std;

//#define S (sizeof(unsigned char)*8)

Bitwise::Bitwise(size_t n) // количество битов
{ 
	size = n;
	data = new unsigned char[(n + S - 1) / S];// количесвто элементов массива
	memset(data, 0, (n + S  - 1) / S );//(что берем, чем заполняем, размер заполнения нулями) 
}

Bitwise::Bitwise() // количество битов
{
	size = 0;
	data = 0;// количесвто элементов массива
}

Bitwise::Bitwise(const Bitwise& bf)// констуктор копирования
{
	size = bf.size;
	data = new unsigned char[(size + S  - 1) / S ];
	memcpy(data, bf.data, (size + S - 1) / S);
}

Bitwise& Bitwise::operator=(const Bitwise& bf)// констуктор копирования
{
	delete[] data;
	data = NULL;

	size = bf.size;
	data = new unsigned char[(size + S - 1) / S];
	memcpy(data, bf.data, (size + S - 1) / S);
	return *this;
}

Bitwise:: ~Bitwise()
{
	delete [] data;
	data = NULL;
}


//void Bitwise::Obedinenie(Bitwise& b)
//{	
//	if (size== b.size)
//		for (int i = 0; i < (size + S - 1) / S; i++)
//		{
//			data[i] = data[i] | b.data[i];
//		}
//}
//
//void Bitwise::Perechenie(Bitwise& b)
//{
//	int s = sizeof(unsigned char) * 8;
//	if (size == b.size)
//		for (int i = 0; i < (size + s - 1) / s; i++)
//		{
//			data[i] = data[i] & b.data[i];
//		}
//}
//
//void Bitwise::Otricanie()
//{
//	
//		for (int i = 0; i < (size + S - 1) / S; i++)
//		{
//			data[i] = ~data[i];
//		}
//}
//void Bitwise::Iscluchenie(Bitwise& b)
//{
//	if (size == b.size)
//		for (int i = 0; i < size; i++)
//		{
//			if (b.data[i / S] & (1 << (i % S)))
//				data[i / S] &= ~(1 << (i % S));
//		}
//}
//void Bitwise::Xor(Bitwise& b)
//{
//	if (size == b.size)
//		for (int i = 0; i < size; i++)
//		{
//			//if ((data[i / S] & (1 << (i % S))) && (b.data[i / S] & (1 << (i % S)) == 0))//если  а[i]и b[i] имеют разные значения 0 или 1, тогда ставится 0
//			//	data[i / S] &= ~(1 << (i / S));
//			//
//			//if ((data[i / S] & (1 << (i % S)))==0 && (b.data[i / S] & (1 << (i % S)) ==0))// если а[i]и b[i] имеют одинаковые значения 0 или 1, тогда ставится 1-ца
//			//	data[i / S] |= (1 << (i / S));
//
//			if( Get(i) && !b.Get(i))
//			{
//				Clr(i);
//				continue;
//			}
//			if ( !Get(i) && !b.Get(i))
//			{
//				Set(i);
//				continue;
//			}
//			
//		}
//}

int Bitwise::Get(size_t i)
{
	if (i < 0 || i >= size)
		return 0;
	return  (data[i / S] & (1 << (i % S)));// cмотрим есть ли там бит или нет
}

void Bitwise::Set(size_t i)
{
	if (i < 0 || i >= size)
		return;
	data[i / S] |= (1 << (i % S));// заполняем, выбранное место 1-цей
}

void Bitwise::Clr(size_t i)
{
	if (i < 0 || i >= size)
		return;
	data[i / S] &= ~(1 << (i % S));// заполняем, выбранное место 0
}

void Bitwise::print()
{
	//for (int i = size-1; i >= 0; i--)//правильный варинт чтения двоичной системы
	
	for (int i = 0; i < size; i++)//удобный вариант слева направо
	{
		if (Get(i))
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	cout << endl;
}

void Bitwise::input()
{
	while (true)// бесконечный цикл
	{
		int tmp; //объявили переменную
		cin >> tmp; //ввели ее
		if (tmp < 0 || tmp >= size)// условие для завершения ввода позиций, где будут 1-цы
			break;
		else
			Set(tmp);// добавили бит(поставили туда 1-цу)
	}

}


//Bitwise& Bitwise:: operator+(Bitwise& b)
//{
//	Obedinenie(b);
//	return*this;
//}
//Bitwise& Bitwise::operator*(Bitwise& b)
//{
//	Perechenie(b);
//	return*this;
//}
//Bitwise& Bitwise::operator-()
//{
//	Otricanie();
//	return*this;
//}
//
//Bitwise& Bitwise::operator^(Bitwise& b)
//{
//	Xor(b);
//	return*this;
//}
//
//Bitwise& Bitwise::operator-(Bitwise& b)
//{
//	Iscluchenie(b);
//	return*this;
//}



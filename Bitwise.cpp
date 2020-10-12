#include "Bitwise.h"
#include <stdlib.h>
#include <iostream>
#include< cstring>
using namespace std;

//#define S (sizeof(unsigned char)*8)

Bitwise::Bitwise(size_t n) // ���������� �����
{ 
	size = n;
	data = new unsigned char[(n + S - 1) / S];// ���������� ��������� �������
	memset(data, 0, (n + S  - 1) / S );//(��� �����, ��� ���������, ������ ���������� ������) 
}

Bitwise::Bitwise() // ���������� �����
{
	size = 0;
	data = 0;// ���������� ��������� �������
}

Bitwise::Bitwise(const Bitwise& bf)// ���������� �����������
{
	size = bf.size;
	data = new unsigned char[(size + S  - 1) / S ];
	memcpy(data, bf.data, (size + S - 1) / S);
}

Bitwise& Bitwise::operator=(const Bitwise& bf)// ���������� �����������
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
//			//if ((data[i / S] & (1 << (i % S))) && (b.data[i / S] & (1 << (i % S)) == 0))//����  �[i]� b[i] ����� ������ �������� 0 ��� 1, ����� �������� 0
//			//	data[i / S] &= ~(1 << (i / S));
//			//
//			//if ((data[i / S] & (1 << (i % S)))==0 && (b.data[i / S] & (1 << (i % S)) ==0))// ���� �[i]� b[i] ����� ���������� �������� 0 ��� 1, ����� �������� 1-��
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
	return  (data[i / S] & (1 << (i % S)));// c������ ���� �� ��� ��� ��� ���
}

void Bitwise::Set(size_t i)
{
	if (i < 0 || i >= size)
		return;
	data[i / S] |= (1 << (i % S));// ���������, ��������� ����� 1-���
}

void Bitwise::Clr(size_t i)
{
	if (i < 0 || i >= size)
		return;
	data[i / S] &= ~(1 << (i % S));// ���������, ��������� ����� 0
}

void Bitwise::print()
{
	//for (int i = size-1; i >= 0; i--)//���������� ������ ������ �������� �������
	
	for (int i = 0; i < size; i++)//������� ������� ����� �������
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
	while (true)// ����������� ����
	{
		int tmp; //�������� ����������
		cin >> tmp; //����� ��
		if (tmp < 0 || tmp >= size)// ������� ��� ���������� ����� �������, ��� ����� 1-��
			break;
		else
			Set(tmp);// �������� ���(��������� ���� 1-��)
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



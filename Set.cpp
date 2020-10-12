#include "Set.h"

void MySet::Obedinenie(MySet& b)
{
	if (size == b.size)
		for (int i = 0; i < (size + S - 1) / S; i++)
		{
			data[i] = data[i] | b.data[i];
		}
}

void MySet::Perechenie(MySet& b)
{
	int s = sizeof(unsigned char) * 8;
	if (size == b.size)
		for (int i = 0; i < (size + s - 1) / s; i++)
		{
			data[i] = data[i] & b.data[i];
		}
}

void MySet::Otricanie()
{

	for (int i = 0; i < (size + S - 1) / S; i++)
	{
		data[i] = ~data[i];
	}
}
void MySet::Iscluchenie(MySet& b)
{
	if (size == b.size)
		for (int i = 0; i < size; i++)
		{
			if (b.data[i / S] & (1 << (i % S)))
				data[i / S] &= ~(1 << (i % S));
		}
}
void MySet::Xor(MySet& b)
{
	if (size == b.size)
		for (int i = 0; i < size; i++)
		{
			//if ((data[i / S] & (1 << (i % S))) && (b.data[i / S] & (1 << (i % S)) == 0))//если  а[i]и b[i] имеют разные значения 0 или 1, тогда ставится 0
			//	data[i / S] &= ~(1 << (i / S));
			//
			//if ((data[i / S] & (1 << (i % S)))==0 && (b.data[i / S] & (1 << (i % S)) ==0))// если а[i]и b[i] имеют одинаковые значения 0 или 1, тогда ставится 1-ца
			//	data[i / S] |= (1 << (i / S));

			if (Get(i) && !b.Get(i))
			{
				Clr(i);
				continue;
			}
			if (!Get(i) && !b.Get(i))
			{
				Set(i);
				continue;
			}

		}
}

MySet& MySet:: operator+(MySet& b)
{
	Obedinenie(b);
	return*this;
}
MySet& MySet::operator*(MySet& b)
{
	Perechenie(b);
	return*this;
}
MySet& MySet::operator-()
{
	Otricanie();
	return*this;
}

MySet& MySet::operator^(MySet& b)
{
	Xor(b);
	return*this;
}

MySet& MySet::operator-(MySet& b)
{
	Iscluchenie(b);
	return*this;
}


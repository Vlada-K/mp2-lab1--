﻿// ConsoleApplication27.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//#include "Bitwise.h"
#include "Set.h"
#include <iomanip>
using namespace std;


int main()
{
    
   // Bitwise b1(20);// задали массив из 20 эемнтов
   // b1.Set(4);// задаем номера, в которых будут единицы
   // b1.Set(17);
   // b1.print();//печатаем массив b1
   // Bitwise b3(b1);// передаем (копируем) данные массива b1 в b3

   // Bitwise b2(20);
   // b2.Set(5);
   // b2.Set(17);
   // b2.print();



   //// b1.Obedinenie(b2);
   // b1 + b2;
   // b1.print();
   // 
   // //b3.Perechenie (b2);
   // b3* b2;
   // b3.print();

    MySet b1(20);// задали массив из 20 эемнтов
    
    b1.input();
    //b1.Set(4);// задаем номера, в которых будут единицы
    //b1.Set(17);
    b1.print();//печатаем массив b1

    MySet b2(20);
    b2.input();
    /*b2.Set(5);
    b2.Set(17);*/
    b2.print();

    b1.Obedinenie(b2);
    b1 + b2;
    b1.print();

   
    // Bitwise b4(b1);
   // //b4.Otricanie();
   // -b4;
   // b4.print();

   // Bitwise b5(b1);
   // //b5.Iscluchenie(b2);
   // b5 - b2;
   // b5.print();

   // Bitwise b6(b1);
   // //b6.Xor(b2);
   // b6^ b2;
   // b6.print();


   // MySet s1(20);// задали массив из 20 эемнтов
   // s1.Set(4);// задаем номера, в которых будут единицы
   // s1.Set(17);
   // s1.print();//печатаем массив b1
   // MySet s3(s1);// передаем (копируем) данные массива b1 в b3


    int n, m, k, count;
    cin >> n;
    MySet s(n + 1);
    for (m = 2; m <= n; m++)
    {
        s.Set(m);
    }

    for (m = 2; m * m <= n; m++)
    {
        if (s.Get(m))
        {
            for (k = 2 * m; k <= n; k += m)
            {
                if (s.Get(k))
                {
                    s.Clr(k);
                }
            }
        }
    }
    count = 0; k = 1;
    for (m = 2; m <= n; m++)
    {
        if (s.Get(m))
        {
            count++;
            cout << setw(3) << m << " ";
            if (k++ % 10 == 0) cout << endl;
        }
    }
    cout << endl;
    cout << " In first " << n << " numbers " << count << " primes" << endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
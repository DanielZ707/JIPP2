#include <iostream>
#include "calc.h"
using namespace std;
void add(int x, char *a, char *b)
        {
                if (x == 4)
                {
                    cout<<"simpleCalc [add]"<<endl;
                    int w;
                    w = atoi(a) + atoi(b);
                    cout << "wynik dodawania wynosi: " << w << endl;
                }
                else
                {
                    cout<<"podana została zła ilość argumentów"<<endl;
                    cout<<"prosze uzyc parametru help w celu wyswietlenia dokumentacji"<<endl;
                }
        };
void subtract(int x, char *a, char *b)
        {
                if (x == 4)
                {
                    cout<<"simpleCalc [subtract]"<<endl;
                    int w;
                    w = atoi(a) - atoi(b);
                    cout << "wynik odejmowania wynosi: " << w << endl;
                }
                else
                {
                    cout<<"podana została zła ilość argumentów"<<endl;
                    cout<<"prosze uzyc parametru help w celu wyswietlenia dokumentacji"<<endl;
                }
        };
void volume(int x, char *a, char *b, char *c, char *d)
        {
                if (x == 6) {
                    cout<<"simpleCalc [volume]"<<endl;
                    int w;
                    w = (atoi(a) + atoi(b)) * atoi(c) / 2 * atoi(d);
                    cout << "objetosc graniastoslupa wynosi: " << w << endl;
                }
                else
                {
                    cout<<"podana została zła ilość argumentów"<<endl;
                    cout<<"prosze uzyc parametru help w celu wyswietlenia dokumentacji"<<endl;
                }
        };
void help(int x)
        {
                if (x == 2) {
                    cout<<"simpleCalc [help]"<<endl;
                    cout <<endl<< "Simple calculatur" << endl;
                    cout << "simpleCalc [nazwa działania]" << endl;
                    cout << "Działania:" << endl;
                    cout << "add [a] [b]" << endl;
                    cout << "Dodawanie dwóch liczb ([a] i [b]) całkowitych." << endl;
                    cout << "substract [a] [b]" << endl;
                    cout << "Odejmowanie dwóch liczb ([a] i [b]) całkowitych." << endl;
                    cout << "volume [a] [b] [c] [d]" << endl;
                    cout << "obliczanie objętości graniastosłupa prostego o podstawie trapezu. [a],[b] - podstawy trapezu"
                            "[c] - wysokosc trapezu, [d] - wysokosc graniastoslupa" << endl;
                    cout << "help" << endl;
                    cout << "wyświetlanie dokumentacji" << endl;
                }
                else
                {cout<<"podano zla ilosc argumentow"<<endl;
                }
        };
void blad()
{
    cout<<"podany został zły argument decydujacy o wykonywanym działaniu"<<endl;
    cout<<"Dokumentacja:"<<endl;
    cout << "Simple calculatur" << endl;
    cout<< "simpleCalc [nazwa działania]"<<endl;
    cout << "Działania:" << endl;
    cout << "add [a] [b]" << endl;
    cout << "Dodawanie dwóch liczb ([a] i [b]) całkowitych." << endl;
    cout << "substract [a] [b]" << endl;
    cout << "Odejmowanie dwóch liczb ([a] i [b]) całkowitych." << endl;
    cout << "volume [a] [b] [c] [d]" << endl;
    cout << "obliczanie objętości graniastosłupa prostego o podstawie trapezu. [a],[b] - podstawy trapezu"
            "[c] - wysokosc trapezu, [d] - wysokosc graniastoslupa" << endl;
    cout << "help" << endl;
    cout << "wyświetlanie dokumentacji" << endl;
};

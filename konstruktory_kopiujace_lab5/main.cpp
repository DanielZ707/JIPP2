#include<iostream>
#include<math.h>
using namespace std;

class Pojazd
{
   string  numer_rejestracyjny;
    string  nazwa;
    int  ilosc_miejsc;
    string *tab1;
    string marka_i_typ;
public:
    Pojazd();
    ~Pojazd();
};
Pojazd::Pojazd()
:numer_rejestracyjny("K1AUTO")
, ilosc_miejsc(5)
, marka_i_typ("MERCEDES - BENZYNA")
, nazwa("G - KLASA")

{
    tab1 = new string[ilosc_miejsc];
    for(int i=0;i<ilosc_miejsc;++i)
    {
        tab1[i]="puste";
    }
    cout << "marka i typ \tnazwa \tnumer rejestracyjny \tilość miejsc \t" << endl;
    cout << "----------------------------------" << endl;
cout << marka_i_typ <<"\t"<< nazwa <<"\t"<< numer_rejestracyjny <<"\t"<< ilosc_miejsc << endl;
cout << "informacja o zajętych miejscach:" << endl;
    for(int j=0;j<ilosc_miejsc;++j)
    {
        cout << tab1[j] << endl;
    }
}
Pojazd::~Pojazd() {
   delete [] tab1;
    }

    int main()
{
    Pojazd daniel;
    return 0;
}


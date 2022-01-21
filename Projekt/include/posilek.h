#ifndef JIPP2_POSILEK_H
#define JIPP2_POSILEK_H
#include <iomanip>
#include <ctime>

class Posilek {
    const int numer_posilku;
    string nazwa;
    int ilosc_kalorii;
    string data;
    string typ_posilku;
    bool cel;

public:
    /**
     * konstruktor klasy Posilek
     * @param _numer_posilku pole przechowujący numer posilku
     * @param _nazwa pole przechowujący numer posilku
     * @param _ilosc_kalorii pole przechowujący numer posilku
     * @param _data pole przechowujący datę posiłku
     * @param _typ_posilku pole przechowujący typ posilku
     * @param _cel pole przechowujący dane, czy cel kaloryczny został osiągnięty
     */
    Posilek(int _numer_posilku, string _nazwa = "brak posilku", int _ilosc_kalorii = 0, string _data = "brak danych", string _typ_posilku = "brak danych", bool _cel=false) : numer_posilku(_numer_posilku), nazwa(_nazwa),ilosc_kalorii(_ilosc_kalorii), data(_data),typ_posilku(_typ_posilku), cel(_cel){}
/**
 * konstruktor kopiujący, tworzy nowe obiekty
 * @param posilek referencja do obiektu klasy
 */
    Posilek(const Posilek &posilek) : Posilek(posilek.numer_posilku, posilek.nazwa, posilek.ilosc_kalorii, posilek.data, posilek.typ_posilku, posilek.cel) {}
/**
 * metoda zwracająca numer posiłku
 * @return numer danego posiłku
 */
    int getNumer() const { return numer_posilku; }
    /**
     * metoda zwracająca nazwę posiłku
     * @return nazwa danego posiłku
     */
    string getNazwa() const { return nazwa; }
    /**
     * metoda zwracająca ilość kalorii posiłku
     * @return ilość kalorii w danym posiłku
     */
    int getIlosc() const { return ilosc_kalorii; }
    /**
     * metoda zwracająca datę posiłku
     * @return data spożycia danego posiłku
     */
    string getData() const { return data; }
    /**
     * metoda zwracająca typ posiłku
     * @return typ danego posiłku
     */
    string getTyp() const { return typ_posilku; }
    /**
     * metoda zwracająca, czy cel kaloryczny został osiągnięty, czy nie
     * @return wartość prawdy jeśli cel został osiągnięty lub fałszy kiedy cel nie został osiągnięty
     */
    bool Cel() const { return cel; }

/**
 *metoda powodująca przeciążenie operatora =, modyfikacja istniejącego obiektu
 * @param posilek stały wskaźnik do klasy
 * @return wskaźnik zmodyfikowanego obiektu
 */
    Posilek& operator=(const Posilek& posilek){
        Posilek *tmp = new Posilek(posilek.numer_posilku, posilek.nazwa, posilek.ilosc_kalorii, posilek.data, posilek.typ_posilku, posilek.cel);
        return *tmp;
    }
/**
 * funkcja zaprzyjaźniona, powodująca przeciążenie operatora >>
 * @param in referencja do obiektu klasy istream
 * @param self referencja do obiektu klasy
 * @return wskaźnik do obiektu klasy istream
 */
    friend istream& operator>>(istream& in, Posilek& self){
        auto t = time(nullptr);
        auto tm = *localtime(&t);

        ostringstream oss;
        oss << put_time(&tm, "%Y-%m-%d %H:%M");
        self.data = oss.str();
        cout<<"Podaj nazwę posiłku (Nie używaj polskich znaków!)"<<endl;
        cout<<"(przykładowe nazwy posiłków: zupa pomidorowa, kanapka z almette i z ogórkiem, jablko, lody czekoladowe): ";
        while (!(getline(cin, self.nazwa))) {
            cout << endl << "Ups! Nie została podana prawidłowa nazwa posiłku!" << endl;
            cout << endl<< "Spróbuj ponownie podać nazwę posiłku:"<< endl;
        }
        cout<<"Podaj ilość kalorii: ";
        while (!(cin>>self.ilosc_kalorii)) {
            cout << endl << "Ups! Nie została podana prawidłowa ilość kalorii!" << endl;
            cout << endl << "Spróbuj ponownie podać ilość kalorii:" << endl;
            cin.clear();
            cin.ignore();
        }
        cin.ignore();
        cout<<"Podaj typ posiłku (Nie używaj polskich znaków!)"<<endl;
         cout<<"(przykładowe typy posiłków: sniadanie, drugie sniadanie, obiad, podwieczorek, kolacja, przekaska): ";
        while (!(getline(cin, self.typ_posilku))) {
            cout << endl << "Ups! Nie została podany prawidłowy typ posiłku!" << endl;
            cout << endl<< "Spróbuj ponownie podać typ posiłku:"<< endl;
        }
        cout<<"Czy założony przez Ciebie cel odnośnie ilości kalorii w posiłku został osiągnięty?"<<endl;
        cout<<"\t[t] Cel został osiagnięty"<<endl;
        cout<<"\t[n] Cel nie został osiagnięty"<<endl;

        string str;
        while (!(getline(cin, str))) {
            cout << endl << "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [n] jeżeli cel nie zostal osiagniety lub opcję [t] jeżeli cel zostal osiagniety."<< endl;
        }

        while(str.length()!=1||(str[0]!='n'&&str[0]!='t')) {
            cout << "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [n] jeżeli cel nie zostal osiagniety lub opcję [t] jeżeli cel zostal osiagniety." << endl;
            while (!(getline(cin, str))) {
                cout << endl << "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [n] jeżeli cel nie zostal osiagniety lub opcję [t] jeżeli cel zostal osiagniety."<< endl;
            }
        }
        switch(str[0]) {
            case 't':
                self.cel = true;
                break;
            case 'n':
                self.cel = false;
                break;
        }
        return in;
    }
/**
 *funkcja zaprzyjaźniona, powodująca przeciążenie operatora <<
 * @param out wskaźnik ostream
 * @param self wskaźnik do klasy
 * @return wskaźnik ostream
 */
    friend ostream& operator<<(ostream& out, Posilek& self){
        cout<<"Numer posiłku: "<<self.numer_posilku<<endl;
        cout<<"Nazwa posiłku: "<<self.nazwa<<endl;
        cout<<"Ilość kalorii: "<<self.ilosc_kalorii<<endl;
        cout<<"Data posiłku: "<<self.data<<endl;
        cout<<"Typ posiłku: "<<self.typ_posilku<<endl;
        if(self.cel)
        {
            cout<<"Cel osiagniety"<<endl;
        }
        else
        cout<<"Cel nieosiagniety"<<endl;

        return out;
    }
};
#endif //JIPP2_POSILEK_H

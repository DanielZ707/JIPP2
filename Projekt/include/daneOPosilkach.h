#ifndef JIPP2_DANEOPOSILKACH_H
#define JIPP2_DANEOPOSILKACH_H
#include <list>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>

/**
 * funkcja zaokrąglająca liczbę typu double
 * @param value liczba typu double
 * @return zaokrąglona liczba typu double
 */
double myRound( double value )
{
    return value < 0 ? ceil( value - 0.5 )
                      : floor( value + 0.5 );
}

class Menu{
public:
    /**
     * metoda wirtualna tworząca menu aplikacji
     * @param a funkcja w aplikacji
     */
    virtual void menu(string a) = 0;


};

class Dane: public Menu
{
    int obecnyNumerPosilku;
    list<Posilek> Pos;
    list<Posilek>::iterator it;
/**
 * funkcja wyszukująca posiłek o danym numerze w bazie danych
 * @param i podany numer posiłku
 * @return pozycja danego posilku
 */
    list<Posilek>::iterator szukajPosilku(int i);

/**
 * funkcja zapisująca dane do pliku
 */
    void zapiszDaneDoPliku();
    /**
     * funkcja odczytująca dane z pliku
     */
   void czytajDaneZPliku();

    /**
     * funkcja pokazująca zapisane dane
     */
    void pokazDane();
    /**
     * funkcja dodająca posiłek do bazy danych
     * @param a ilość posiłków do dodania
     */
    void dodajPosilek(int a);
    /**
     * funkcja dodająca posiłek do bazy danych
     * @param a ilość posiłków do dodania
     */
    void dodajPosilek(double b);
    /**
     * funkcja usuwająca posiłek z bazy danych
     * @param a ilość posiłków do usunięcia
     */
    void usunPosilek(int a);
    /**
     * funkcja usuwająca posiłek z bazy danych
     * @param b ilość posiłków do usunięcia
     */
    void usunPosilek(double b);
    /**
     * funkcja sortująca posiłki po numerze
     * @param a referencja do obiektu klasy
     * @param b referencja do obiektu klasy
     * @return
     */
    static bool sortByNumer(const Posilek& a, const Posilek& b);
    /**
     * funkcja sortująca posiłki po nazwie
     * @param a referencja do obiektu klasy
     * @param b referencja do obiektu klasy
     * @return
     */
    static bool sortByNazwa(const Posilek& a, const Posilek& b);
    /**
     *  funkcja sortująca posiłki po dacie
     * @param a referencja do obiektu klasy
     * @param b referencja do obiektu klasy
     * @return
     */
    static bool sortByData(const Posilek& a, const Posilek& b);
    /**
     *  funkcja sortująca posiłki po ilości kalorii
     * @param a referencja do obiektu klasy
     * @param b referencja do obiektu klasy
     * @return
     */
    static bool sortByIloscKalorii(const Posilek& a, const Posilek& b);
    /**
     *  funkcja sortująca posiłki po typie posiłku
     * @param a referencja do obiektu klasy
     * @param b referencja do obiektu klasy
     * @return
     */
    static bool sortByTypPosilku(const Posilek& a, const Posilek& b);
    /**
     * funkcja sortująca posiłki
     */
    void sortPosilki();
/**
 * funkcja wyświetljąca spożycie kalorii pomiędzy posiłkami o danych numerach
 */
    void ileKalorii();

public:
    /**
     * odczytanie danych z pliku
     */
    Dane() { czytajDaneZPliku(); }
    /**
     * zapisanie danych do pliku
     */
    ~Dane() { zapiszDaneDoPliku(); }
    /**
     * funkcja zarządzająca funkcjami aplikacji
     * @param funk podany parametr programu
     */
    void menu(string funk);
};

list<Posilek>::iterator Dane::szukajPosilku(int i){
    if(i<1||i>=obecnyNumerPosilku)
        return Pos.end();

    list<Posilek>::iterator tmp=Pos.begin();
    while(tmp!=Pos.end()&&tmp->getNumer()!=i)
        tmp++;

    return tmp;
}


void Dane::zapiszDaneDoPliku(){
    File* file = new File("dane.csv", "w");
    if(!file->open()) {
        cout << "Błąd otwarcia pliku" << endl;
        exit(1);
    }
    else

    file->writeStringToFile(Pos.size());

    for(it=Pos.begin(); it!=Pos.end(); it++){
        file->writeStringToFile(it->getNumer());
        file->writeStringToFile(it->getNazwa());
        file->writeStringToFile(it->getIlosc());
        file->writeStringToFile(it->getData());
        file->writeStringToFile(it->getTyp());
        if(it->Cel())
            file->writeStringToFile(1);
        else
            file->writeStringToFile(0);
    }
}

void Dane::czytajDaneZPliku(){
    string rozmiar;
    File* file = new File("dane.csv", "r");
    if(!file->open()) {
        cout << "Błąd otwarcia pliku" << endl;
        exit(1);
    }
    else

    file->readStringFromFile(rozmiar);

    for(int i=0; i<atoi(rozmiar.data()); i++){
        string str_numer;
        file->readStringFromFile(str_numer);

        string str_nazwa;
        file->readStringFromFile(str_nazwa);

        string str_ilosc;
        file->readStringFromFile(str_ilosc);

        string str_data;
        file->readStringFromFile(str_data);

        string str_typ;
        file->readStringFromFile(str_typ);

        string str_cel;
        file->readStringFromFile(str_cel);

        int numer=atoi(str_numer.data());
        string nazwa=str_nazwa;
        int ilosc_kalorii=atoi(str_ilosc.data());
        string data=str_data;
        string typ=str_typ;
        bool cel;
        if(atoi(str_cel.data()))
            cel=true;
        else cel=false;

        Pos.push_back(Posilek(numer, nazwa, ilosc_kalorii, data, typ, cel));
        if(numer>obecnyNumerPosilku)
            obecnyNumerPosilku=numer;
    }
    ++obecnyNumerPosilku;
    delete file;
}

void Dane::menu(string funkcja){

    cout<<"=====DANE O POSIŁKACH====="<<endl;

       if(funkcja=="wyjdź")
       {
           cout<<"Do zobaczenia wkrótce!"<<endl;
           return;
       }

        if(funkcja=="dodajPos") {
            string str;

            cout << endl;
            cout << "Chciałbyś podać ilość posiłków do dodania jako typ int czy typ double?" << endl;
            cout << "\t[i] Typ int." << endl;
            cout << "\t[d] Typ double." << endl;

            while (!getline(cin, str)) {
                cout << endl
                     << "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [i] dla typu int lub [d] dla typu double."
                     << endl;
            }

            while (str.length() != 1 || (str[0] != 'i' && str[0] != 'd')) {
                cout << endl
                     << "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [i] dla typu int lub [d] dla typu double."
                     << endl;
                while (!getline(cin, str)) {
                    cout << endl
                         << "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [i] dla typu int lub [d] dla typu double."
                         << endl;
                }
            }
            switch (str[0]) {
                case 'i':
                    cout<<"Wybrany typ to: int!"<<endl;
                    int g;
                    cout<<"Podaj ile posiłków chcesz dodać."<<endl;
                    while (!(cin >> g)||g<=0) {
                        cout << endl << "Ups! Nie została podany prawidłowa ilość posiłków do dodania!" << endl;
                        cout << endl << "Spróbuj ponownie podać ilość posiłków do dodania:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    cin.clear();
                    cin.ignore();
                    dodajPosilek(g);
                    break;
                case 'd':
                    cout<<"Wybrany typ to: double!"<<endl;
                    double t;
                    cout<<"Podaj ile posiłków chcesz dodać."<<endl;
                    while (!(cin >> t)||t<=0) {
                        cout << endl << "Ups! Nie została podany prawidłowa ilość posiłków do dodania!" << endl;
                        cout << endl << "Spróbuj ponownie podać ilość posiłków do dodania:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    cin.clear();
                    cin.ignore();
                    dodajPosilek(t);
                    break;
            }
        }
             if(funkcja=="usuńPos")
             {
                 string str;

                 cout << endl;
                 cout << "Chciałbyś podać ilość posiłków do usunięcia jako typ int czy typ double?" << endl;
                 cout << "\t[i] Typ int." << endl;
                 cout << "\t[d] Typ double." << endl;

                 while (!getline(cin, str)) {
                     cout << endl
                          << "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [i] dla typu int lub [d] dla typu double."
                          << endl;
                 }

                 while (str.length() != 1 || (str[0] != 'i' && str[0] != 'd')) {
                     cout << endl<< "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [i] dla typu int lub [d] dla typu double."<< endl;
                     while (!getline(cin, str)) {
                         cout << endl<< "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [i] dla typu int lub [d] dla typu double."<< endl;
                     }
                 }
                 switch (str[0]) {
                     case 'i':
                         cout<<"Wybrany typ to: int!"<<endl;
                         int g;
                         pokazDane();
                        cout<<"Podaj ile posiłków chcesz usunąć."<<endl;
                         while (!(cin >> g)||g<=0) {
                             cout << endl << "Ups! Nie została podany prawidłowa ilość posiłków do usunięcia!" << endl;
                             cout << endl << "Spróbuj ponownie podać ilość posiłków do usunięcia:" << endl;
                             cin.clear();
                             cin.ignore();
                         }
                         cin.clear();
                         cin.ignore();
                         usunPosilek(g);
                         break;
                     case 'd':
                         cout<<"Wybrany typ to: double!"<<endl;
                         double t;
                         pokazDane();
                         cout<<"Podaj ile posiłków chcesz usunąć."<<endl;
                         while (!(cin >> t)||t<=0) {
                             cout << endl << "Ups! Nie została podany prawidłowa ilość posiłków do usunięcia!" << endl;
                             cout << endl << "Spróbuj ponownie podać ilość posiłków do usunięcia:" << endl;
                             cin.clear();
                             cin.ignore();
                         }
                         cin.clear();
                         cin.ignore();
                         usunPosilek(t);
                         break;
                 }
             }
             if(funkcja=="pokażPos")
             {
                 pokazDane();
             }
            if(funkcja=="sortPos")
             {
                 sortPosilki();
             }
             if(funkcja=="miłeSłowa")
             {
                 Pos.clear();
                 cout<<"Jesteś Super!!! Odpocznij sobie na chwilę i zjedz coś przepysznego :)"<<endl<<"Nie zapominaj oczywiście o powrocie do aplikacji już przy następnym posiłku! :D"<<endl;
                 return;
             }
             if(funkcja=="ileKal")
             {
                 ileKalorii();
             }

             zapiszDaneDoPliku();

     }

     void Dane::pokazDane(){
         if(!Pos.size()){
             cout<<"Brak posiłków w bazie danych."<<endl;
             return;
         }
         cout << endl << "Twoje posiłki:" << endl;
         for(it=Pos.begin(); it!=Pos.end(); it++){
             cout<<*it<<endl;
         }
     }

     void Dane::dodajPosilek(int a) {
         for (int q = 0; q < a; q++) {
             Posilek *tmp = new Posilek(obecnyNumerPosilku++);
             cin >> *tmp;
             Pos.push_back(*tmp);
             delete tmp;
             cout << "Dodano posiłek." << endl;
         }
     }
     void Dane::dodajPosilek(double a) {
         (int) myRound(a);
         cout<<"Podana wartość została zaokrąglona."<<endl;
         for (int q = 0; q < a; q++) {
             Posilek *tmp = new Posilek(obecnyNumerPosilku++);
             cin >> *tmp;
             Pos.push_back(*tmp);
             delete tmp;
             cout << "Dodano posiłek." << endl;
         }
     }
     void Dane::usunPosilek(int a) {
         for (int q = 0; q < a; q++) {
             if(!Pos.size()){
                 cout<<"Brak posiłków w bazie danych."<<endl;
                 return;
             }
             pokazDane();

             int i;

             cout<<"Podaj numer posiłku do usunięcia: ";
             while (!(cin>>i)) {
                 cout << endl << "Ups! Nie została podany prawidłowy numer posiłku do usunięcia!" << endl;
                 pokazDane();
                 cout << endl << "Spróbuj ponownie podać numer posiłku do usunięcia:" << endl;
                 cin.clear();
                 cin.ignore();
             }

             if((it=szukajPosilku(i))==Pos.end()){
                 cout<<"Nie ma posiłku o takim numerze."<<endl;
                 pokazDane();
                 cin.ignore();
                 return;
             }

             Pos.erase(it);
             cout<<"Posiłek usunięty."<<endl;
             pokazDane();
             cin.ignore();
         }
     }
     void Dane::usunPosilek(double a) {
         (int) myRound(a);
         cout<<"Podana wartość została zaokrąglona."<<endl;
         for (int q = 0; q < a; q++) {
             if(!Pos.size()){
                 cout<<"Brak posiłków w bazie danych."<<endl;
                 return;
             }
             pokazDane();

             int i;

             cout<<"Podaj numer posiłku do usunięcia: ";
             while (!(cin>>i)) {
                 cout << endl << "Ups! Nie została podany prawidłowy numer posiłku do usunięcia!" << endl;
                 pokazDane();
                 cout << endl << "Spróbuj ponownie podać numer posiłku do usunięcia:" << endl;
                 cin.clear();
                 cin.ignore();
             }

             if((it=szukajPosilku(i))==Pos.end()){
                 cout<<"Nie ma posiłku o takim numerze."<<endl;
                 pokazDane();
                 cin.ignore();
                 return;
             }

             Pos.erase(it);
             cout<<"Posiłek usunięty."<<endl;
             cin.ignore();
         }
     }
     void Dane::ileKalorii(){
         if(!Pos.size()){
             cout<<"Brak posiłków w bazie danych."<<endl;
             return;
         }
         pokazDane();
         int x,y,z;
         cout<<"Podaj numer posiłku od którego chcesz liczyć kalorie: ";
         while (!(cin>>x)) {
             cout << endl << "Ups! Nie został podany prawidłowy numer posiłku!" << endl;
             pokazDane();
             cout << endl << "Spróbuj ponownie podać numer posiłku:" << endl;
             cin.clear();
             cin.ignore();
         }

         if((it=szukajPosilku(x))==Pos.end()){
             cout<<"Nie ma posiłku o takim numerze."<<endl;
             pokazDane();
             cin.ignore();
             return;
         }

         cout<<"Podaj numer posiłku do którego chcesz liczyć kalorie: ";
         while (!(cin>>z)) {
             cout << endl << "Ups! Nie został podany prawidłowy numer posiłku!" << endl;
             pokazDane();
             cout << endl << "Spróbuj ponownie podać numer posiłku:" << endl;
             cin.clear();
             cin.ignore();
         }

         if((it=szukajPosilku(z))==Pos.end()){
             cout<<"Nie ma posiłku o takim numerze."<<endl;
             pokazDane();
             cin.ignore();
             return;
         }
         list<Posilek>::iterator tmp1=Pos.begin();
         y=0;
         tmp1=szukajPosilku(x);
         while(tmp1!=Pos.end()&&tmp1->getNumer()!=z+1){
             y+=(tmp1->getIlosc());
             tmp1++;
         }
         cout<<"Spożycie posiłków od numeru "<<x<<" do numeru "<<z<<" skutkowało spożyciem "<<y<<" kalorii." <<endl;



     }
     bool Dane::sortByNumer(const Posilek& a, const Posilek& b){
         return a.getNumer()<b.getNumer();
     }

     bool Dane::sortByNazwa(const Posilek& a, const Posilek& b){
         string aString=a.getNazwa();
         string bString=b.getNazwa();
         int i;
         for(i=0; aString[i]==bString[i]; i++);
         return aString[i]<bString[i];
     }
     bool Dane::sortByIloscKalorii(const Posilek& a, const Posilek& b){
         return a.getIlosc()<b.getIlosc();
     }
     bool Dane::sortByData(const Posilek& a, const Posilek& b){
         string aString=a.getData();
         string bString=b.getData();
         int i;
         for(i=0; aString[i]==bString[i]; i++);
         return aString[i]<bString[i];
     }

     bool Dane::sortByTypPosilku(const Posilek& a, const Posilek& b){
         string aString=a.getTyp();
         string bString=b.getTyp();
         int i;
         for(i=0; aString[i]==bString[i]; i++);
         return aString[i]<bString[i];
     }


     void Dane::sortPosilki(){
         if(!Pos.size()){
             cout<<"Brak posiłków w bazie danych."<<endl;
             return;
         }

         cout<<"Posortuj wg:"<<endl;
         cout<<"\t[n] numeru"<<endl;
         cout<<"\t[t] nazwy"<<endl;
         cout<<"\t[a] ilosci kalorii"<<endl;
         cout<<"\t[q] daty"<<endl;
         cout<<"\t[s] typu posilku"<<endl;

         string str;
         while (!(getline(cin, str))) {
             cout << endl << "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [n] jeżeli cel nie zostal osiagniety lub opcję [t] jeżeli cel zostal osiagniety."<< endl;
         }

         while(str.length()!=1||(str[0]!='n'&&str[0]!='t'&&str[0]!='a'&&str[0]!='q'&&str[0]!='s')){
             cout << "Ups! Nie została podana prawidłowa opcja, proszę wybrać ponownie." << endl;
             cout<<"Posortuj wg:"<<endl;
             cout<<"\t[n] numeru"<<endl;
             cout<<"\t[t] nazwy"<<endl;
             cout<<"\t[a] ilosci kalorii"<<endl;
             cout<<"\t[q] daty"<<endl;
             cout<<"\t[s] typu posilku"<<endl;
             while (!(getline(cin, str))) {
                 cout << endl << "Ups! Nie została podana prawidłowa opcja, proszę wybrać ponownie."<< endl;
                 cout<<"Posortuj wg:"<<endl;
                 cout<<"\t[n] numeru"<<endl;
                 cout<<"\t[t] nazwy"<<endl;
                 cout<<"\t[a] ilosci kalorii"<<endl;
                 cout<<"\t[q] daty"<<endl;
                 cout<<"\t[s] typu posilku"<<endl;

             }
         }

         switch(str[0]){
             case 'n':
                 Pos.sort(sortByNumer);
                 break;
             case 't':
                 Pos.sort(sortByNazwa);
                 break;
             case 'a':
                 Pos.sort(sortByIloscKalorii);
                 break;
             case 'q':
                 Pos.sort(sortByData);
                 break;
             case 's':
                 Pos.sort(sortByTypPosilku);
                 break;
         }
         cout<<"Posortowano."<<endl;
         pokazDane();
     }
     #endif //JIPP2_DANEOPOSILKACH_H

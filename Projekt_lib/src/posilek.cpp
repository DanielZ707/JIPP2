#include <list>
#include <algorithm>
#include "lista.h"


class Dane
{
    int obecnyNumerPosilku;
    List<Posilek> Pos;
    List<Posilek>::iterator it;

    List<Posilek>::iterator szukajPosilku(int i);
    void zapiszDaneDoPliku();
    void czytajDaneZPliku();
    void pokazDane();
    void dodajPosilek();
    void usunPosilek();
    void Cel_osiag();
    void Cel_nieOsia();
    static bool sortByNumer(const Posilek& a, const Posilek& b);
    static bool sortByName(const Posilek& a, const Posilek& b);
    static bool sortByData(const Posilek& a, const Posilek& b);
    static bool sortByIloscKalorii(const Posilek& a, const Posilek& b);
    static bool sortByTypPosilku(const Posilek& a, const Posilek& b);
    void sortPosilki();

public:
    Dane() { czytajDaneZPliku(); }
    ~Dane() { zapiszDaneDoPliku(); }
    void menu(string funk);
};

/*Library::Library(): currentBookNumber(1){
    lib.push_back(Book(currentBookNumber++, "Mistrz i Małgorzata", "Lew Tołstoj"));
    lib.push_back(Book(currentBookNumber++, "Hobbit, czyli tam i z powrotem", "J. R. R. Tolkien"));
    lib.push_back(Book(currentBookNumber++, "Gra o Tron", "George R. R. Martin"));
    lib.push_back(Book(currentBookNumber++, "Harry Potter i Insygnia Śmierci", "J. K. Rowling"));
    lib.push_back(Book(currentBookNumber++, "Rok 1984", "George Orwell"));
}*/

List<Posilek>::iterator Dane::szukajPosilku(int i){
    if(i<1||i>=obecnyNumerPosilku)
        return Pos.end();

    List<Posilek>::iterator tmp=Pos.begin();
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
    // string str;

    cout<<"=====DANE O POSILKACH====="<<endl;
    /*  while(1){
          cout<<endl;
          cout<<"Co chciałbyś zrobić?"<<endl;
          cout<<"\t[q] Wyjdź z aplikacji"<<endl;
          cout<<"\t[s] Pokaż moje posilki"<<endl;
          cout<<"\t[a] Dodaj posilek"<<endl;
          cout<<"\t[d] Usuń posilek"<<endl;
          cout<<"\t[v] Posortuj moje posilki"<<endl;
          cout<<"\t[p] Zapomnij na chwile o liczeniu kalorii! :D"<<endl;

          while (!getline(cin, str)) {
              cout << endl << "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [n] jeżeli cel nie zostal osiagniety lub opcję [t] jeżeli cel zostal osiagniety."<< endl;
          }*/

    /* while(str.length()!=1||(str[0]!='s'&&str[0]!='a'&&str[0]!='q'&&str[0]!='d'&&str[0]!='p'&&str[0]!='v')){
         cout << endl << "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [n] jeżeli cel nie zostal osiagniety lub opcję [t] jeżeli cel zostal osiagniety."<< endl;
         while (!getline(cin, str)) {
             cout << endl << "Ups! Nie została podana prawidłowa opcja, proszę wybrać opcję [n] jeżeli cel nie zostal osiagniety lub opcję [t] jeżeli cel zostal osiagniety."<< endl;
         }
     }
     switch(str[0]){
         case 's': pokazDane(); break;
         case 'a': dodajPosilek(); break;
         case 'd': usunPosilek(); break;
         case 'v': sortPosilki(); break;
         case 'p':
             Pos.clear();
             cout<<"Opocznij sobie na chwile i zjedz cos przepysznego :)"<<endl<<"Nie zapominaj oczywiscie o powrocie do aplikacji juz przy nastepnym posilku! :D"<<endl;
             return;
         case 'q':
             cout<<"Do zobaczenia wkrótce!"<<endl;
             return;
             }
             }
             */
    if(funkcja=="wyjdź")
    {
        cout<<"Do zobaczenia wkrótce!"<<endl;
        return;
    }

    if(funkcja=="dodajPos")
    {
        dodajPosilek();
    }
    if(funkcja=="usuńPos")
    {
        usunPosilek();
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
        cout<<"Jesteś Super!!! Odpocznij sobie na chwile i zjedz cos przepysznego :)"<<endl<<"Nie zapominaj oczywiscie o powrocie do aplikacji juz przy nastepnym posilku! :D"<<endl;
        return;
    }

    //zapiszDaneDoPliku();

}

void Dane::pokazDane(){
    if(!Pos.size()){
        cout<<"Brak posilkow w bazie danych."<<endl;
        return;
    }
    cout << endl << "Twoje posiłki:" << endl;
    for(it=Pos.begin(); it!=Pos.end(); it++){
        cout<<*it<<endl;
    }
}

void Dane::dodajPosilek(){
    Posilek *tmp = new Posilek(obecnyNumerPosilku++);
    cin>>*tmp;
    Pos.push_back(*tmp);
    delete tmp;
    cout<<"Dodano posilek."<<endl;
}

void Dane::usunPosilek(){
    if(!Pos.size()){
        cout<<"Brak posilkow w bazie danych."<<endl;
        return;
    }

    int i;

    cout<<"Podaj numer posilku do usunięcia: ";
    while (!(cin>>i)) {
        cout << endl << "Ups! Nie została podany prawidłowy numer posiłku do usunięcia!" << endl;
        cout << endl << "Twoje posiłki:" << endl;
        pokazDane();
        cout << endl << "Spróbuj ponownie podać numer posiłku do usnięcia:" << endl;
        cin.clear();
        cin.ignore();
    }

    if((it=szukajPosilku(i))==Pos.end()){
        cout<<"Nie ma posilku o takim numerze."<<endl;
        cout << endl << "Twoje posiłki:" << endl;
        pokazDane();
        cin.ignore();
        return;
    }

    Pos.erase(it);
    cout<<"Posilek usunięty."<<endl;
    cin.ignore();
}

bool Dane::sortByNumer(const Posilek& a, const Posilek& b){
    return a.getNumer()<b.getNumer();
}

bool Dane::sortByName(const Posilek& a, const Posilek& b){
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
        cout<<"Brak posilkow w bazie danych."<<endl;
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
            //lib.sort(sortByNumber);
            sort(Pos.begin(), Pos.end(), sortByNumer);
            break;
        case 't':
            //lib.sort(sortByTitle);
            sort(Pos.begin(), Pos.end(), sortByName);
            break;
        case 'a':
            //lib.sort(sortByAuthor);
            sort(Pos.begin(), Pos.end(), sortByIloscKalorii);
            break;
        case 'q':
            //lib.sort(sortByAuthor);
            sort(Pos.begin(), Pos.end(), sortByData);
            break;
        case 's':
            //lib.sort(sortByAuthor);
            sort(Pos.begin(), Pos.end(), sortByTypPosilku);
            break;
    }

    cout<<"Posortowano."<<endl;
}//
// Created by HP on 18.01.2022.
//


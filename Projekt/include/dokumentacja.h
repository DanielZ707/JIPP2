#ifndef JIPP2_DOKUMENTACJA_H
#define JIPP2_DOKUMENTACJA_H

using namespace std;

/**
 * funkcja wyświetlająca dokumentację
 */
void dokumentacja()
{
    cout<<"Dokumentacja:"<<endl;
    cout<<endl<<"Program wykonujący różne działania na bazie danych posiłków."<<endl;
    cout<<endl<<"Działanie, które chcesz wykonać musisz podać jako parametr." << endl;
    cout<<endl<<"Następnie musisz postępować zgdonie z poleceniami wyświetlanymi przez program"<<endl;
    cout << "Działania:" << endl;
    cout <<endl<< "dodajPos" << endl;
    cout<<"Dodawanie nowego posiłku do bazy danych."<<endl;
    cout<<"Na początku należy dokonać wyboru ile posiłków chce się dodać. Po odpowiednim wczytaniu danych nowego posiłku, posiłek zostanie dodany do bazy danych."<<endl;
    cout <<endl<< "usuńPos" << endl;
    cout<<"Usuwanie posiłku z bazy danych."<<endl;
    cout<<"Lista posiłków, które są w bazie danych zostaje wyświetlona. Następnie należy wybrać ile posiłków chce się usunąć. Po odpowiednim wprowadzeniu numeru posiłku zostaje on usunięty z bazy danych. "<<endl;
    cout <<endl<< "pokażPos" << endl;
    cout<<"Wyświetlanie bazy danych posiłków."<<endl;
    cout<<"Wyświetlona zostaje baza danych dodanych wcześniej posiłków."<<endl;
    cout <<endl<< "wyjdź" << endl;
    cout<<"Wyjście z aplikacji."<<endl;
    cout<<"Następuje wyjście z aplikacji poprzedzone komunikatem."<<endl;
    cout <<endl<< "miłeSłowa" << endl;
    cout<<"Wyświetlenie miłego komunikatu."<<endl;
    cout<<"Następuje wyświetlenie komunikatu powodującego uśmiech użytkownika, a następnie wyjście z aplikacji bez zapisywania poprzednio wprowadzonych danych, aby użytkownik zapomniał na chwilę o liczeniu kalorii."<<endl;
    cout <<endl<< "sortPos" << endl;
    cout<<"Sortowanie posiłków w bazie danych."<<endl;
    cout<<"W zależności od wybranej opcji, posiłki w bazie danych zostaną posortowane według wybranego parametru."<<endl;
    cout <<endl<< "ileKal" << endl;
    cout<<"Obliczanie ile kalorri zostało spożyte."<<endl;
    cout<<"Po odpowiednim wczytaniu dwóch numerów posiłków, zostaje wyświetlona ilość kalorii spożytych w posiłkach o podanych numerach wraz z posiłkami o numerach znajdującymi się pomiędzy podanymi numerami."<<endl;
    cout <<endl<< "pomoc" << endl;
    cout << "Wyświetlanie dokumentacji" << endl;
};

#endif //JIPP2_DOKUMENTACJA_H

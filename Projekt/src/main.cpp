#include <iostream>
#include <string>

#include "../include/plik.h"
#include "../include/posilek.h"
#include "../include/daneOPosilkach.h"
#include "../include/dokumentacja.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc != 2)
    {
        cout<<"Podana została zła ilość argumentów!"<<endl;
        dokumentacja();
    }
    else {
        string funkcja = argv[1];
        if (funkcja == "pomoc") {
            dokumentacja();
        } else {
            if(funkcja != "ileKal"&& funkcja != "pomoc" && funkcja != "pokażPos" && funkcja != "sortPos" && funkcja != "miłeSłowa" &&funkcja != "wyjdź" && funkcja != "dodajPos" && funkcja != "usuńPos")
            {
                cout << "Podany został zły argument wywołujący funkcję!" << endl;
                dokumentacja();
            }
            else {
                Menu *Pos = new Dane();
                Pos->menu(funkcja);
                delete Pos;
            }
        }
    }
    return 0;
}

#include <iostream>
#include "MacLib.h"

using namespace std;

int main(int argc, char *argv[]) {
    if(argc == 1)
        {
            cout<<"Podana została zła ilość argumentów!"<<endl;
            dokumentacja();
        }
        else {
        string z = argv[1];
        if (z == "help") {
            dokumentacja();
        } else {
            tutaj10:
            cout << "Wybierz czy chcesz wykonywać operacje na macierzach typu int (w tym celu napisz int)," << endl;
            cout << "czy chcesz wykonywać operacje na macierzach typu double (w tym celu napisz double)" << endl;
            string typ_macierzy;
            while (!(cin >> typ_macierzy)) {
                cout << endl << "Ups! Nie został podany prawidłowy typ macierzy!" << endl;
                cout << endl
                     << "Spróbuj ponownie napisać czy chcesz wykonywać operację na macierzach typu int czy double:"
                     << endl;
                cin.clear();
                cin.ignore();
            }
            if (typ_macierzy == "int") {
                if (z == "addMatrix") {
                    int wierszeA, kolumnyA, wierszeB, kolumnyB;
                    cout << "Podaj wymiary macierzy A i B, które chcesz do siebie dodać:" << endl;

                    tutaj:
                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość wierszy macierzy B:" << endl;
                    while (!(cin >> wierszeB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy B:" << endl;
                    while (!(cin >> kolumnyB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    if (wierszeA != wierszeB || kolumnyA != kolumnyB) {
                        cout << endl << "Podano złe wymiary macierzy" << endl;
                        cout << "Dodawanie macierzy jest wykonalne tylko na macierzach o równych wymiarach" << endl;
                        cout << "Spróbuj ponownie:" << endl;
                        goto tutaj;
                    } else {

                        int **MacA = new int *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacA[i] = new int[kolumnyA];
                        }
                        int **MacB = new int *[wierszeB];
                        for (int i = 0; i < wierszeB; ++i) {
                            MacB[i] = new int[kolumnyB];
                        }
                        cout << endl << "wczytaj liczby do macierzy A:" << endl;
                        wczytMac(MacA, wierszeA, kolumnyA);
                        cout << endl << "wczytaj liczby do macierzy B:" << endl;
                        wczytMac(MacB, wierszeB, kolumnyB);
                        cout << endl << "Macierz A:" << endl;
                        wyswietlMac(MacA, wierszeA, kolumnyA);
                        cout << endl << "Macierz B:" << endl;
                        wyswietlMac(MacB, wierszeB, kolumnyB);
                        int **MacWynikowa = new int *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacWynikowa[i] = new int[kolumnyA];
                        }
                        cout << endl << "Macierz wynikowa:" << endl;
                        MacWynikowa = addMatrix(MacA, MacB, wierszeA, kolumnyA);
                        wyswietlMac(MacWynikowa, wierszeA, kolumnyA);
                        for (int w = 0; w < wierszeA; w++) {
                            delete[] MacA[w];
                        }
                        delete[] MacA;
                        for (int p = 0; p < wierszeB; p++) {
                            delete[] MacB[p];
                        }
                        delete[] MacB;
                        for (int o = 0; o < wierszeA; o++) {
                            delete[] MacWynikowa[o];
                        }
                        delete[] MacWynikowa;
                    }
                } else if (z == "subtractMatrix") {
                    int wierszeA, kolumnyA, wierszeB, kolumnyB;
                    cout << "Podaj wymiary macierzy A i macierzy B, ktorą chcesz odjąć od macierzy A:" << endl;

                    tutaj2:
                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość wierszy macierzy B:" << endl;
                    while (!(cin >> wierszeB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy B:" << endl;
                    while (!(cin >> kolumnyB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    if (wierszeA != wierszeB || kolumnyA != kolumnyB) {
                        cout << endl << "Podano złe wymiary macierzy" << endl;
                        cout << "Odejmowanie macierzy jest wykonalne tylko na macierzach o równych wymiarach" << endl;
                        cout << "Spróbuj ponownie:" << endl;
                        goto tutaj2;
                    } else {

                        int **MacA = new int *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacA[i] = new int[kolumnyA];
                        }
                        int **MacB = new int *[wierszeB];
                        for (int i = 0; i < wierszeB; ++i) {
                            MacB[i] = new int[kolumnyB];
                        }
                        cout << endl << "wczytaj liczby do macierzy A:" << endl;
                        wczytMac(MacA, wierszeA, kolumnyA);
                        cout << endl << "wczytaj liczby do macierzy B:" << endl;
                        wczytMac(MacB, wierszeB, kolumnyB);
                        cout << endl << "Macierz A:" << endl;
                        wyswietlMac(MacA, wierszeA, kolumnyA);
                        cout << endl << "Macierz B:" << endl;
                        wyswietlMac(MacB, wierszeB, kolumnyB);
                        int **MacWynikowa = new int *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacWynikowa[i] = new int[kolumnyA];
                        }
                        cout << endl << "Macierz wynikowa:" << endl;
                        MacWynikowa = subtractMatrix(MacA, MacB, wierszeA, kolumnyA);
                        wyswietlMac(MacWynikowa, wierszeA, kolumnyA);
                        for (int w = 0; w < wierszeA; w++) {
                            delete[] MacA[w];
                        }
                        delete[] MacA;
                        for (int p = 0; p < wierszeB; p++) {
                            delete[] MacB[p];
                        }
                        delete[] MacB;
                        for (int o = 0; o < wierszeA; o++) {
                            delete[] MacWynikowa[o];
                        }
                        delete[] MacWynikowa;
                    }
                } else if (z == "multiplyMatrix") {
                    int wierszeA, kolumnyA, wierszeB, kolumnyB;
                    cout << "Podaj wymiary macierzy A i B, które chcesz przez siebie przemnożyć (mnozenie AxB):"
                         << endl;

                    tutaj4:
                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość wierszy macierzy B:" << endl;
                    while (!(cin >> wierszeB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy B:" << endl;
                    while (!(cin >> kolumnyB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    if (kolumnyA != wierszeB) {
                        cout << endl << "Podano złe wymiary macierzy" << endl;
                        cout
                                << "Mnożenie macierzy (AxB) jest wykonalne tylko w przypadku gdy liczba kolumn macierzy A jest równa liczbie wierszy macierzy B"
                                << endl;
                        cout << "Spróbuj ponownie:" << endl;
                        goto tutaj4;
                    } else {

                        int **MacA = new int *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacA[i] = new int[kolumnyA];
                        }
                        int **MacB = new int *[wierszeB];
                        for (int i = 0; i < wierszeB; ++i) {
                            MacB[i] = new int[kolumnyB];
                        }
                        cout << endl << "wczytaj liczby do macierzy A:" << endl;
                        wczytMac(MacA, wierszeA, kolumnyA);
                        cout << endl << "wczytaj liczby do macierzy B:" << endl;
                        wczytMac(MacB, wierszeB, kolumnyB);
                        cout << endl << "Macierz A:" << endl;
                        wyswietlMac(MacA, wierszeA, kolumnyA);
                        cout << endl << "Macierz B:" << endl;
                        wyswietlMac(MacB, wierszeB, kolumnyB);
                        int **MacWynikowa = new int *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacWynikowa[i] = new int[kolumnyB];
                        }
                        cout << endl << "Macierz wynikowa:" << endl;
                        MacWynikowa = multiplyMatrix(MacA, MacB, wierszeA, kolumnyA, kolumnyB);
                        wyswietlMac(MacWynikowa, wierszeA, kolumnyB);
                        for (int w = 0; w < wierszeA; w++) {
                            delete[] MacA[w];
                        }
                        delete[] MacA;
                        for (int p = 0; p < wierszeB; p++) {
                            delete[] MacB[p];
                        }
                        delete[] MacB;
                        for (int o = 0; o < wierszeA; o++) {
                            delete[] MacWynikowa[o];
                        }
                        delete[] MacWynikowa;
                    }
                } else if (z == "multiplyByScalar") {
                    int wierszeA, kolumnyA, skalar;
                    cout << "Podaj wymiary macierzy A i skalar, przez który chcesz przemnożyć macierz A" << endl;

                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    cout << "Podaj skalar przez który chcesz przemnożyć macierz A:" << endl;
                    while (!(cin >> skalar)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    int **MacA = new int *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacA[i] = new int[kolumnyA];
                    }

                    cout << endl << "wczytaj liczby do macierzy A:" << endl;
                    wczytMac(MacA, wierszeA, kolumnyA);
                    cout << "podany skalar: " << skalar << endl;
                    int **MacWynikowa = new int *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacWynikowa[i] = new int[kolumnyA];
                    }
                    cout << endl << "Macierz wynikowa:" << endl;
                    MacWynikowa = multiplyByScalar(MacA, wierszeA, kolumnyA, skalar);
                    wyswietlMac(MacWynikowa, wierszeA, kolumnyA);
                    for (int w = 0; w < wierszeA; w++) {
                        delete[] MacA[w];
                    }
                    delete[] MacA;
                    for (int p = 0; p < wierszeA; p++) {
                        delete[] MacWynikowa[p];
                    }
                    delete[] MacWynikowa;
                } else if (z == "transpozeMatrix") {
                    int wierszeA, kolumnyA;
                    cout << "Podaj wymiary macierzy A, ktorą chcesz transponować" << endl;

                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    int **MacA = new int *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacA[i] = new int[kolumnyA];
                    }

                    cout << endl << "wczytaj liczby do macierzy A:" << endl;
                    wczytMac(MacA, wierszeA, kolumnyA);

                    int **MacWynikowa = new int *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacWynikowa[i] = new int[kolumnyA];
                    }
                    cout << "Macierz wynikowa:" << endl;
                    MacWynikowa = transpozeMatrix(MacA, wierszeA, kolumnyA);
                    wyswietlMac(MacWynikowa, kolumnyA, wierszeA);
                    for (int w = 0; w < wierszeA; w++) {
                        delete[] MacA[w];
                    }
                    delete[] MacA;
                    for (int p = 0; p < wierszeA; p++) {
                        delete[] MacWynikowa[p];
                    }
                    delete[] MacWynikowa;
                } else if (z == "powerMatrix") {
                    if (argc != 3) {
                        cout << "Podana została zła ilość argumentów!" << endl;
                        dokumentacja();
                    } else {
                        unsigned potega = atoi(argv[2]);
                        int wierszeA, kolumnyA;
                        cout << "Podaj wymiary macierzy A, którą chcesz podnieść do potęgi" << endl;
                        tutaj6:
                        cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                        while (!(cin >> wierszeA)) {
                            cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                            cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                            cin.clear();
                            cin.ignore();
                        }

                        cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                        while (!(cin >> kolumnyA)) {
                            cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                            cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                            cin.clear();
                            cin.ignore();
                        }

                        if (wierszeA != kolumnyA) {
                            cout << endl << "Podano złe wymiary macierzy" << endl;
                            cout << "Potęgowanie macierzy jest wykonalne tylko na macierzy kwadratowej" << endl;
                            cout << "Spróbuj ponownie:" << endl;
                            goto tutaj6;
                        } else {

                            int **MacA = new int *[wierszeA];
                            for (int i = 0; i < wierszeA; ++i) {
                                MacA[i] = new int[kolumnyA];
                            }

                            cout << endl << "wczytaj liczby do macierzy A:" << endl;
                            wczytMac(MacA, wierszeA, kolumnyA);

                            int **MacWynikowa = new int *[wierszeA];
                            for (int i = 0; i < wierszeA; ++i) {
                                MacWynikowa[i] = new int[kolumnyA];
                            }
                            cout << "Macierz wynikowa:" << endl;
                            MacWynikowa = powerMatrix(MacA, wierszeA, kolumnyA, potega);
                            wyswietlMac(MacWynikowa, wierszeA, kolumnyA);
                            for (int w = 0; w < wierszeA; w++) {
                                delete[] MacA[w];
                            }
                            delete[] MacA;
                            for (int p = 0; p < wierszeA; p++) {
                                delete[] MacWynikowa[p];
                            }
                            delete[] MacWynikowa;
                        }
                    }
                } else if (z == "determinantMatrix") {
                    int wierszeA, kolumnyA, wyznacznik;
                    cout << "Podaj wymiary macierzy A, której wyznacznik chcesz obliczyć" << endl;
                    tutaj8:
                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (wierszeA != kolumnyA) {
                        cout << endl << "Podano złe wymiary macierzy" << endl;
                        cout << "Wyznacznik macierzy da się obliczyć tylko dla macierzy kwadratowej" << endl;
                        cout << "Spróbuj ponownie:" << endl;
                        goto tutaj8;
                    } else {
                        int **MacA = new int *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacA[i] = new int[kolumnyA];
                        }

                        cout << endl << "wczytaj liczby do macierzy A:" << endl;
                        wczytMac(MacA, wierszeA, kolumnyA);

                        wyznacznik = determinantMatrix(MacA, wierszeA, kolumnyA);
                        cout << endl << "Wyznacznik podanej macierzy wynosi: " << wyznacznik << endl;
                        for (int w = 0; w < wierszeA; w++) {
                            delete[] MacA[w];
                        }
                        delete[] MacA;
                    }
                } else if (z == "matrixIsDiagonal") {
                    int wierszeA, kolumnyA;
                    cout
                            << "Podaj wymiary macierzy A, dla której chcesz sprawdzić własność, czy macierz jest diagonalna"
                            << endl;

                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (wierszeA != kolumnyA) {
                        cout << endl << "Macierz o danych wymiarach nie jest macierzą diagonalną." << endl;
                        cout << "Macierz diagonalna musi być macierzą kwadratową" << endl;
                    } else {

                        int **MacA = new int *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacA[i] = new int[kolumnyA];
                        }

                        cout << endl << "wczytaj liczby do macierzy A:" << endl;
                        wczytMac(MacA, wierszeA, kolumnyA);
                        bool diagonalnaAlboNie;
                        diagonalnaAlboNie = matrixIsDiagonal(MacA, wierszeA, kolumnyA);
                        if (diagonalnaAlboNie) {
                            cout << "podana macierz jest diagonalna" << endl;
                        } else
                            cout << "podana macierz nie jest diagonalna" << endl;
                        for (int w = 0; w < wierszeA; w++) {
                            delete[] MacA[w];
                        }
                        delete[] MacA;
                    }
                } else if (z == "swap") {
                    int wierszeA, kolumnyA;
                    cout << "Podaj wymiary macierzy A, w której chcesz zamienić poszczególne wartości" << endl;

                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    int **MacA = new int *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacA[i] = new int[kolumnyA];
                    }

                    cout << endl << "wczytaj liczby do macierzy A:" << endl;
                    wczytMac(MacA, wierszeA, kolumnyA);
                    int wiersz1liczba, kolumna1liczba, wiersz2liczba, kolumna2liczba;
                    tutaj11:
                    cout << "Podaj numer wiersza pierwszej liczby, którą chcesz zamienić z drugą" << endl;
                    while (!(cin >> wiersz1liczba)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (wiersz1liczba < 1 || wiersz1liczba > wierszeA) {
                        cout << endl << "Została podana liczba, która nie jest numerem wiersza macierzy A" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        goto tutaj11;
                    }
                    tutaj12:
                    cout << "Podaj numer kolumny pierwszej liczby, którą chcesz zamienić z drugą" << endl;
                    while (!(cin >> kolumna1liczba)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (kolumna1liczba < 1 || kolumna1liczba > kolumnyA) {
                        cout << endl << "Została podana liczba, która nie jest numerem kolumny macierzy A" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        goto tutaj12;
                    }
                    tutaj13:
                    cout << "Podaj numer wiersza drugiej liczby, którą chcesz zamienić z pierwszą" << endl;
                    while (!(cin >> wiersz2liczba)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (wiersz2liczba < 1 || wiersz2liczba > wierszeA) {
                        cout << endl << "Została podana liczba, która nie jest numerem wiersza macierzy A" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        goto tutaj13;
                    }
                    tutaj14:
                    cout << "Podaj numer kolumny drugiej liczby, którą chcesz zamienić z pierwszą" << endl;
                    while (!(cin >> kolumna2liczba)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (kolumna2liczba < 1 || kolumna2liczba > kolumnyA) {
                        cout << endl << "Została podana liczba, która nie jest numerem kolumny macierzy A" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        goto tutaj14;
                    }
                    swap(MacA[wiersz1liczba - 1][kolumna1liczba - 1], MacA[wiersz2liczba - 1][kolumna2liczba - 1]);
                    cout << "wczytana macierz po zamianie liczb:" << endl;
                    wyswietlMac(MacA, wierszeA, kolumnyA);
                    for (int w = 0; w < wierszeA; w++) {
                        delete[] MacA[w];
                    }
                    delete[] MacA;
                } else if (z == "sortRowsInMatrix") {
                    int wierszeA, kolumnyA;
                    cout << "Podaj wymiary macierzy A, w której chcesz posortować wiersze" << endl;

                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    int **MacA = new int *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacA[i] = new int[kolumnyA];
                    }

                    cout << endl << "wczytaj liczby do macierzy A:" << endl;
                    wczytMac(MacA, wierszeA, kolumnyA);
                    sortRowsInMatrix(MacA, wierszeA, kolumnyA);
                    cout << "wczytana macierz po posortowaniu wierszy:" << endl;
                    wyswietlMac(MacA, wierszeA, kolumnyA);
                    for (int w = 0; w < wierszeA; w++) {
                        delete[] MacA[w];
                    }
                    delete[] MacA;
                } else {
                    cout << "Podany został zły argument decydujący o wykonywanym działaniu na macierzach!" << endl;
                    cout << endl;
                    dokumentacja();
                }
            } else if (typ_macierzy == "double") {
                if (z == "addMatrix") {
                    int wierszeA, kolumnyA, wierszeB, kolumnyB;
                    cout << "Podaj wymiary macierzy A i B, które chcesz do siebie dodać:" << endl;

                    tutaj1:
                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość wierszy macierzy B:" << endl;
                    while (!(cin >> wierszeB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy B:" << endl;
                    while (!(cin >> kolumnyB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    if (wierszeA != wierszeB || kolumnyA != kolumnyB) {
                        cout << endl << "Podano złe wymiary macierzy" << endl;
                        cout << "Dodawanie macierzy jest wykonalne tylko na macierzach o równych wymiarach" << endl;
                        cout << "Spróbuj ponownie:" << endl;
                        goto tutaj1;
                    } else {

                        double **tab1 = new double *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            tab1[i] = new double[kolumnyA];
                        }
                        double **tab2 = new double *[wierszeB];
                        for (int i = 0; i < wierszeB; ++i) {
                            tab2[i] = new double[kolumnyB];
                        }
                        cout << endl << "wczytaj liczby do macierzy A:" << endl;
                        wczytMac(tab1, wierszeA, kolumnyA);
                        cout << endl << "wczytaj liczby do macierzy B:" << endl;
                        wczytMac(tab2, wierszeB, kolumnyB);
                        cout << endl << "Macierz A:" << endl;
                        wyswietlMac(tab1, wierszeA, kolumnyA);
                        cout << endl << "Macierz B:" << endl;
                        wyswietlMac(tab2, wierszeB, kolumnyB);
                        double **tab3 = new double *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            tab3[i] = new double[kolumnyA];
                        }
                        cout << endl << "Macierz wynikowa:" << endl;
                        tab3 = addMatrix(tab1, tab2, wierszeA, kolumnyA);
                        wyswietlMac(tab3, wierszeA, kolumnyA);
                        for (int w = 0; w < wierszeA; w++) {
                            delete[] tab1[w];
                        }
                        delete[] tab1;
                        for (int p = 0; p < wierszeB; p++) {
                            delete[] tab2[p];
                        }
                        delete[] tab2;
                        for (int o = 0; o < wierszeA; o++) {
                            delete[] tab3[o];
                        }
                        delete[] tab3;
                    }
                } else if (z == "subtractMatrix") {
                    int wierszeA, kolumnyA, wierszeB, kolumnyB;
                    cout << "Podaj wymiary macierzy A i macierzy B, ktorą chcesz odjąć od macierzy A:" << endl;

                    tutaj3:
                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość wierszy macierzy B:" << endl;
                    while (!(cin >> wierszeB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy B:" << endl;
                    while (!(cin >> kolumnyB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    if (wierszeA != wierszeB || kolumnyA != kolumnyB) {
                        cout << endl << "Podano złe wymiary macierzy" << endl;
                        cout << "Odejmowanie macierzy jest wykonalne tylko na macierzach o równych wymiarach" << endl;
                        cout << "Spróbuj ponownie:" << endl;
                        goto tutaj3;
                    } else {

                        double **MacA = new double *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacA[i] = new double[kolumnyA];
                        }
                        double **MacB = new double *[wierszeB];
                        for (int i = 0; i < wierszeB; ++i) {
                            MacB[i] = new double[kolumnyB];
                        }
                        cout << endl << "wczytaj liczby do macierzy A:" << endl;
                        wczytMac(MacA, wierszeA, kolumnyA);
                        cout << endl << "wczytaj liczby do macierzy B:" << endl;
                        wczytMac(MacB, wierszeB, kolumnyB);
                        cout << endl << "Macierz A:" << endl;
                        wyswietlMac(MacA, wierszeA, kolumnyA);
                        cout << endl << "Macierz B:" << endl;
                        wyswietlMac(MacB, wierszeB, kolumnyB);
                        double **MacWynikowa = new double *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacWynikowa[i] = new double[kolumnyA];
                        }
                        cout << endl << "Macierz wynikowa:" << endl;
                        MacWynikowa = subtractMatrix(MacA, MacB, wierszeA, kolumnyA);
                        wyswietlMac(MacWynikowa, wierszeA, kolumnyA);
                        for (int w = 0; w < wierszeA; w++) {
                            delete[] MacA[w];
                        }
                        delete[] MacA;
                        for (int p = 0; p < wierszeB; p++) {
                            delete[] MacB[p];
                        }
                        delete[] MacB;
                        for (int o = 0; o < wierszeA; o++) {
                            delete[] MacWynikowa[o];
                        }
                        delete[] MacWynikowa;
                    }
                } else if (z == "multiplyMatrix") {
                    int wierszeA, kolumnyA, wierszeB, kolumnyB;
                    cout << "Podaj wymiary macierzy A i B, które chcesz przez siebie przemnożyć (mnozenie AxB):"
                         << endl;

                    tutaj5:
                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość wierszy macierzy B:" << endl;
                    while (!(cin >> wierszeB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy B:" << endl;
                    while (!(cin >> kolumnyB)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    if (kolumnyA != wierszeB) {
                        cout << endl << "Podano złe wymiary macierzy" << endl;
                        cout
                                << "Mnożenie macierzy (AxB) jest wykonalne tylko w przypadku gdy liczba kolumn macierzy A jest równa liczbie wierszy macierzy B"
                                << endl;
                        cout << "Spróbuj ponownie:" << endl;
                        goto tutaj5;
                    } else {

                        double **MacA = new double *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacA[i] = new double[kolumnyA];
                        }
                        double **MacB = new double *[wierszeB];
                        for (int i = 0; i < wierszeB; ++i) {
                            MacB[i] = new double[kolumnyB];
                        }
                        cout << endl << "wczytaj liczby do macierzy A:" << endl;
                        wczytMac(MacA, wierszeA, kolumnyA);
                        cout << endl << "wczytaj liczby do macierzy B:" << endl;
                        wczytMac(MacB, wierszeB, kolumnyB);
                        cout << endl << "Macierz A:" << endl;
                        wyswietlMac(MacA, wierszeA, kolumnyA);
                        cout << endl << "Macierz B:" << endl;
                        wyswietlMac(MacB, wierszeB, kolumnyB);
                        double **MacWynikowa = new double *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacWynikowa[i] = new double[kolumnyB];
                        }
                        cout << endl << "Macierz wynikowa:" << endl;
                        MacWynikowa = multiplyMatrix(MacA, MacB, wierszeA, kolumnyA, kolumnyB);
                        wyswietlMac(MacWynikowa, wierszeA, kolumnyB);
                        for (int w = 0; w < wierszeA; w++) {
                            delete[] MacA[w];
                        }
                        delete[] MacA;
                        for (int p = 0; p < wierszeB; p++) {
                            delete[] MacB[p];
                        }
                        delete[] MacB;
                        for (int o = 0; o < wierszeA; o++) {
                            delete[] MacWynikowa[o];
                        }
                        delete[] MacWynikowa;
                    }
                } else if (z == "multiplyByScalar") {
                    int wierszeA, kolumnyA;
                    double skalar;
                    cout << "Podaj wymiary macierzy A i skalar, przez który chcesz przemnożyć macierz A" << endl;

                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    cout << "Podaj skalar przez który chcesz przemnożyć macierz A:" << endl;
                    while (!(cin >> skalar)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    double **MacA = new double *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacA[i] = new double[kolumnyA];
                    }

                    cout << endl << "wczytaj liczby do macierzy A:" << endl;
                    wczytMac(MacA, wierszeA, kolumnyA);
                    cout << "podany skalar: " << skalar << endl;
                    double **MacWynikowa = new double *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacWynikowa[i] = new double[kolumnyA];
                    }
                    cout << endl << "Macierz wynikowa:" << endl;
                    MacWynikowa = multiplyByScalar(MacA, wierszeA, kolumnyA, skalar);
                    wyswietlMac(MacWynikowa, wierszeA, kolumnyA);
                    for (int w = 0; w < wierszeA; w++) {
                        delete[] MacA[w];
                    }
                    delete[] MacA;
                    for (int p = 0; p < wierszeA; p++) {
                        delete[] MacWynikowa[p];
                    }
                    delete[] MacWynikowa;
                } else if (z == "transpozeMatrix") {
                    int wierszeA, kolumnyA;
                    cout << "Podaj wymiary macierzy A, ktorą chcesz transponować" << endl;

                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    double **MacA = new double *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacA[i] = new double[kolumnyA];
                    }

                    cout << endl << "wczytaj liczby do macierzy A:" << endl;
                    wczytMac(MacA, wierszeA, kolumnyA);

                    double **MacWynikowa = new double *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacWynikowa[i] = new double[kolumnyA];
                    }
                    cout << "Macierz wynikowa:" << endl;
                    MacWynikowa = transpozeMatrix(MacA, wierszeA, kolumnyA);
                    wyswietlMac(MacWynikowa, kolumnyA, wierszeA);
                    for (int w = 0; w < wierszeA; w++) {
                        delete[] MacA[w];
                    }
                    delete[] MacA;
                    for (int p = 0; p < wierszeA; p++) {
                        delete[] MacWynikowa[p];
                    }
                    delete[] MacWynikowa;
                } else if (z == "powerMatrix") {
                    if (argc != 3) {
                        cout << "Podana została zła ilość argumentów!" << endl;
                        dokumentacja();
                    } else {
                        unsigned potega = atoi(argv[2]);
                        int wierszeA, kolumnyA;
                        cout << "Podaj wymiary macierzy A, którą chcesz podnieść do potęgi" << endl;
                        tutaj7:
                        cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                        while (!(cin >> wierszeA)) {
                            cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                            cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                            cin.clear();
                            cin.ignore();
                        }

                        cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                        while (!(cin >> kolumnyA)) {
                            cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                            cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                            cin.clear();
                            cin.ignore();
                        }
                        if (wierszeA != kolumnyA) {
                            cout << endl << "Podano złe wymiary macierzy" << endl;
                            cout << "Potęgowanie macierzy jest wykonalne tylko na macierzy kwadratowej" << endl;
                            cout << "Spróbuj ponownie:" << endl;
                            goto tutaj7;
                        } else {
                            double **MacA = new double *[wierszeA];
                            for (int i = 0; i < wierszeA; ++i) {
                                MacA[i] = new double[kolumnyA];
                            }

                            cout << endl << "wczytaj liczby do macierzy A:" << endl;
                            wczytMac(MacA, wierszeA, kolumnyA);

                            double **MacWynikowa = new double *[wierszeA];
                            for (int i = 0; i < wierszeA; ++i) {
                                MacWynikowa[i] = new double[kolumnyA];
                            }
                            cout << "Macierz wynikowa:" << endl;
                            MacWynikowa = powerMatrix(MacA, wierszeA, kolumnyA, potega);
                            wyswietlMac(MacWynikowa, wierszeA, kolumnyA);
                            for (int w = 0; w < wierszeA; w++) {
                                delete[] MacA[w];
                            }
                            delete[] MacA;
                            for (int p = 0; p < wierszeA; p++) {
                                delete[] MacWynikowa[p];
                            }
                            delete[] MacWynikowa;
                        }
                    }
                } else if (z == "determinantMatrix") {
                    int wierszeA, kolumnyA;
                    double wyznacznik;
                    cout << "Podaj wymiary macierzy A, której wyznacznik chcesz obliczyć" << endl;
                    tutaj9:
                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (wierszeA != kolumnyA) {
                        cout << endl << "Podano złe wymiary macierzy" << endl;
                        cout << "Wyznacznik macierzy da się obliczyć tylko dla macierzy kwadratowej" << endl;
                        cout << "Spróbuj ponownie:" << endl;
                        goto tutaj9;
                    } else {
                        double **MacA = new double *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacA[i] = new double[kolumnyA];
                        }

                        cout << endl << "wczytaj liczby do macierzy A:" << endl;
                        wczytMac(MacA, wierszeA, kolumnyA);

                        wyznacznik = determinantMatrix(MacA, wierszeA, kolumnyA);
                        cout << endl << "Wyznacznik podanej macierzy wynosi: " << wyznacznik << endl;
                        for (int w = 0; w < wierszeA; w++) {
                            delete[] MacA[w];
                        }
                        delete[] MacA;
                    }
                } else if (z == "matrixIsDiagonal") {
                    int wierszeA, kolumnyA;
                    cout
                            << "Podaj wymiary macierzy A, dla której chcesz sprawdzić własność, czy macierz jest diagonalna"
                            << endl;

                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (wierszeA != kolumnyA) {
                        cout << endl << "Macierz o danych wymiarach nie jest macierzą diagonalną." << endl;
                        cout << "Macierz diagonalna musi być macierzą kwadratową" << endl;
                    } else {
                        double **MacA = new double *[wierszeA];
                        for (int i = 0; i < wierszeA; ++i) {
                            MacA[i] = new double[kolumnyA];
                        }

                        cout << endl << "wczytaj liczby do macierzy A:" << endl;
                        wczytMac(MacA, wierszeA, kolumnyA);
                        bool diagonalnaAlboNie;
                        diagonalnaAlboNie = matrixIsDiagonal(MacA, wierszeA, kolumnyA);
                        if (diagonalnaAlboNie) {
                            cout << "podana macierz jest diagonalna" << endl;
                        } else
                            cout << "podana macierz nie jest diagonalna" << endl;
                        for (int w = 0; w < wierszeA; w++) {
                            delete[] MacA[w];
                        }
                        delete[] MacA;
                    }
                } else if (z == "swap") {
                    int wierszeA, kolumnyA;
                    cout << "Podaj wymiary macierzy A, w której chcesz zamienić poszczególne wartości" << endl;

                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    double **MacA = new double *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacA[i] = new double[kolumnyA];
                    }

                    cout << endl << "wczytaj liczby do macierzy A:" << endl;
                    wczytMac(MacA, wierszeA, kolumnyA);
                    int wiersz1liczba, kolumna1liczba, wiersz2liczba, kolumna2liczba;
                    tutaj15:
                    cout << "Podaj numer wiersza pierwszej liczby, którą chcesz zamienić z drugą" << endl;
                    while (!(cin >> wiersz1liczba)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (wiersz1liczba < 1 || wiersz1liczba > wierszeA) {
                        cout << endl << "Została podana liczba, która nie jest numerem wiersza macierzy A" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        goto tutaj15;
                    }
                    tutaj16:
                    cout << "Podaj numer kolumny pierwszej liczby, którą chcesz zamienić z drugą" << endl;
                    while (!(cin >> kolumna1liczba)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (kolumna1liczba < 1 || kolumna1liczba > kolumnyA) {
                        cout << endl << "Została podana liczba, która nie jest numerem kolumny macierzy A" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        goto tutaj16;
                    }
                    tutaj17:
                    cout << "Podaj numer wiersza drugiej liczby, którą chcesz zamienić z pierwszą" << endl;
                    while (!(cin >> wiersz2liczba)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (wiersz2liczba < 1 || wiersz2liczba > wierszeA) {
                        cout << endl << "Została podana liczba, która nie jest numerem wiersza macierzy A" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        goto tutaj17;
                    }
                    tutaj18:
                    cout << "Podaj numer kolumny drugiej liczby, którą chcesz zamienić z pierwszą" << endl;
                    while (!(cin >> kolumna2liczba)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    if (kolumna2liczba < 1 || kolumna2liczba > kolumnyA) {
                        cout << endl << "Została podana liczba, która nie jest numerem kolumny macierzy A" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        goto tutaj18;
                    }
                    swap(MacA[wiersz1liczba - 1][kolumna1liczba - 1], MacA[wiersz2liczba - 1][kolumna2liczba - 1]);
                    cout << "wczytana macierz po zamianie liczb:" << endl;
                    wyswietlMac(MacA, wierszeA, kolumnyA);
                    for (int w = 0; w < wierszeA; w++) {
                        delete[] MacA[w];
                    }
                    delete[] MacA;
                } else if (z == "sortRowsInMatrix") {
                    int wierszeA, kolumnyA;
                    cout << "Podaj wymiary macierzy A, w której chcesz posortować wiersze" << endl;

                    cout << endl << "Podaj ilość wierszy macierzy A:" << endl;
                    while (!(cin >> wierszeA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    cout << endl << "Podaj ilość kolumn macierzy A:" << endl;
                    while (!(cin >> kolumnyA)) {
                        cout << endl << "Ups! Nie została podana prawidłowa liczba!" << endl;
                        cout << endl << "Spróbuj ponownie podać liczbę:" << endl;
                        cin.clear();
                        cin.ignore();
                    }

                    double **MacA = new double *[wierszeA];
                    for (int i = 0; i < wierszeA; ++i) {
                        MacA[i] = new double[kolumnyA];
                    }

                    cout << endl << "wczytaj liczby do macierzy A:" << endl;
                    wczytMac(MacA, wierszeA, kolumnyA);
                    sortRowsInMatrix(MacA, wierszeA, kolumnyA);
                    cout << "wczytana macierz po posortowaniu wierszy:" << endl;
                    wyswietlMac(MacA, wierszeA, kolumnyA);
                    for (int w = 0; w < wierszeA; w++) {
                        delete[] MacA[w];
                    }
                    delete[] MacA;
                } else {
                    cout << "Podany został zły argument decydujący o wykonywanym działaniu na macierzach!" << endl;
                    cout << endl;
                    dokumentacja();
                }
            } else {
                cout << endl << "Ups! Nie został podany prawidłowy typ macierzy!" << endl;
                cout << endl
                     << "Spróbuj ponownie napisać czy chcesz wykonywać operację na macierzach typu int czy double:"
                     << endl;
                goto tutaj10;
            }
        }
    }
    return 0;
}
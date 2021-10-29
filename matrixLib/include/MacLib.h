#ifndef JIPP2_MACLIB_H
#define JIPP2_MACLIB_H
#include <iostream>

using namespace std;
/**
 * funkcja wyświetlająca dokumentację
 */
void dokumentacja();
/**
 * funkcja wyświetlająca podaną macierz (typ macierzy - int)
 * @param A wskaźnik - macierz, która ma zostać wyświetlona
 * @param e ilość wierszy macierzy, która ma zostać wyświetlona
 * @param d ilość kolumn macierzy, która ma zostać wyświetlona
 */
void wyswietlMac(int **A, int e, int d);
/**
 * funkcja wczytująca liczby podane przez użytkownika do macierzy (typ macierzy - int)
 * @param A wskaźnik - macierz do której użytkownik wczytuje liczby
 * @param wA ilość wierszy macierzy,do której użytkownik wczytuje liczby
 * @param kA ilość kolumn macierzy,do której użytkownik wczytuje liczby
 */
void wczytMac(int **A, int wA, int kA);
/**
 * funkcja wyświetlająca podaną macierz (typ macierzy - double)
 * @param A wskaźnik - macierz, która ma zostać wyświetlona
 * @param e ilość wierszy macierzy, która ma zostać wyświetlona
 * @param d ilość kolumn macierzy, która ma zostać wyświetlona
 */
void wyswietlMac(double **A, int e, int d);
/**
 * funkcja wczytująca liczby podane przez użytkownika do macierzy (typ macierzy - double)
 * @param A wskaźnik - macierz do której użytkownik wczytuje liczby
 * @param wA ilość wierszy macierzy,do której użytkownik wczytuje liczby
 * @param kA ilość kolumn macierzy,do której użytkownik wczytuje liczby
 */
void wczytMac(double **A, int wA, int kA);
/**
 * funkcja dodająca do siebie dwie macierze podane przez użytkownika (typ macierzy - int)
 * @param A wskaźnik - podana przez użytkownika macierz A, do której użytkownik chce dodać macierz B
 * @param B wskaźnik - podana przez użytkownika macierz B, którą użytkownik chce dodać do macierzy A
 * @param e ilość wierszy macierzy A i B
 * @param d ilość kolumn macierzy A i B
 * @return macierz wynikowa - wynik dodawania macierzy A i B
 */
int **addMatrix(int **A,int  **B, int e, int d);
/**
 * funkcja odejmująca od siebie dwie macierze podane przez użytkownika (typ macierzy - int)
 * @param A wskaźnik - podana przez użytkownika macierz A, od której użytkownik chce odjąć macierz B
 * @param B wskaźnik - podana przez użytkownika macierz B, którą użytkownik chce odjąć od macierzy A
 * @param e ilość wierszy macierzy A i B
 * @param d ilość kolumn macierzy A i B
 * @return macierz wynikowa - wynik odejmowania macierzy A i B
 */
int **subtractMatrix(int **A,int  **B, int e, int d);
/**
 * funkcja mnożąca pierwszą macierz podaną przez użytkownika, przez drugą macierz podaną przez użytkownika (typ macierzy - int)
 * @param A wskaźnik - podana przez użytkownika macierz A, którą użytkownik chce pomnożyć przez macierz B
 * @param B wskaźnik - podana przez użytkownika macierz B, przez którą użytkownik chce pomnożyć macierz A
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @param f ilość kolumn macierzy B
 * @return macierz wynikowa - wynik pomnożenia macierzy A przez macierz B
 */
int **multiplyMatrix(int **A,int  **B, int e, int d, int f);
/**
 * funkcja mnożąca macierz podaną przez użytkownika, przez skalar podany przez uzytkownika (typ macierzy - int)
 * @param A wskaźnik - podana przez użytkownika macierz A, którą użytkownik chce pomnożyć przez skalar
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @param f skalar - liczba podana przez użytkownika, przez którą użytkownik chce pomnożyć macierz A (typ skalara - int)
 * @return macierz wynikowa - wynik pomnożenia macierzy A przez skalar
 */
int **multiplyByScalar(int **A, int e, int d, int f);
/**
 * funkcja transponująca macierz podaną przez użytkownika (typ macierzy - int)
 * @param A wskaźnik - podana przez użytkownika macierz A, którą użytkownik chce transponować
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @return macierz wynikowa - transponowana macierz A
 */
int **transpozeMatrix(int **A, int e, int d);
/**
 * funkcja podnosząca macierz podaną przez użytkownika do potęgi podanej przez użytkownika (typ macierzy - int)
 * @param A wskaźnik - podana przez użytkownika macierz A, którą użytkownik chce podnieść do potęgi
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @param b podana przez użytkownika liczba - potęga, do której użytkownik chce podnieść macierz A (podany przez użytkownika w postaci parametru - typ unsigned)
 * @return macierz wynikowa - macierz A podniesiona do potęgi podanej przez użytkownika
 */
int **powerMatrix(int **A, int e, int d, unsigned b);
/**
 * funkcja sprawdzająca, czy macierz podana przez użytkownika jest macierzą diagonalną (typ macierzy - int)
 * @param A wskaźnik - podana przez użytkownika macierz A, dla której użytkownik chce sprawdzić własność, czy podana macierz jest macierzą diagonalną
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @return wartość prawdy lub fałszu w zależności, czy macierz A jest macierzą diagonalną, czy nie jest macierzą diagonalną
 */
bool matrixIsDiagonal(int **A, int e, int d);
/**
 * funkcja obliczająca wyznacznik dla macierzy podanej przez użytkownika (typ macierzy - int)
 * @param A wskaźnik - podana przez użytkownika macierz A, dla której użytkownik chce obliczyć jej wyznacznik
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @return wartość wyznacznika macierzy A (typ wyznacznika - int)
 */
int determinantMatrix(int **A, int e, int d);
/**
 * funkcja zamieniająca miejscem wybrane przez użytkownika dwie wartości w macierzy podanej przez użytkownika (typ macierzy - int)
 * @param a pierwsza wartość w podanej przez użytkownika macierzy A, przekazana przez referencję, którą użytkownik chce zamienić z drugą wartością
 * @param b druga wartość w podanej przez użytkownika macierzy A, przekazana przez referencję, którą użytkownik chce zamienić z pierwszą wartością
 */
void swap(int &a,int &b);
/**
 * funkcja sortująca tablicę podaną przez użytkownika (typ tablicy - int)
 * @param A wskaźnik - podana przez użytkownika tablica A, którą użytkownik chce posortować rosnąco (sortowanie bąbelkowe)
 * @param e rozmiar tablicy do posortowania
 */
void sortRow(int *A,int e);
/**
 * funkcja sortująca macierz podaną przez użytkownika (typ macierzy - int)
 * @param A wskaźnik - podana przez użytkownika macierz A, w której użytkownik chce posortować rosnąco każdy wiersz (sortowanie bąbelkowe)
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 */
void sortRowsInMatrix(int **A, int e, int d);
/**
 * funkcja dodająca do siebie dwie macierze podane przez użytkownika (typ macierzy - double)
 * @param A wskaźnik - podana przez użytkownika macierz A, do której użytkownik chce dodać macierz B
 * @param B wskaźnik - podana przez użytkownika macierz B, którą użytkownik chce dodać do macierzy A
 * @param e ilość wierszy macierzy A i B
 * @param d ilość kolumn macierzy A i B
 * @return macierz wynikowa - wynik dodawania macierzy A i B
 */
double **addMatrix(double **A,double  **B, int e, int d);
/**
 * funkcja odejmująca od siebie dwie macierze podane przez użytkownika (typ macierzy - double)
 * @param A wskaźnik - podana przez użytkownika macierz A, od której użytkownik chce odjąć macierz B
 * @param B wskaźnik - podana przez użytkownika macierz B, którą użytkownik chce odjąć od macierzy A
 * @param e ilość wierszy macierzy A i B
 * @param d ilość kolumn macierzy A i B
 * @return macierz wynikowa - wynik odejmowania macierzy A i B
 */
double **subtractMatrix(double **A,double  **B, int e, int d);
/**
 * funkcja mnożąca pierwszą macierz podaną przez użytkownika, przez drugą macierz podaną przez użytkownika (typ macierzy - double)
 * @param A wskaźnik - podana przez użytkownika macierz A, którą użytkownik chce pomnożyć przez macierz B
 * @param B wskaźnik - podana przez użytkownika macierz B, przez którą użytkownik chce pomnożyć macierz A
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @param f ilość kolumn macierzy B
 * @return macierz wynikowa - wynik pomnożenia macierzy A przez macierz B
 */
double **multiplyMatrix(double **A,double  **B, int e, int d, int f);
/**
 * funkcja mnożąca macierz podaną przez użytkownika, przez skalar podany przez uzytkownika (typ macierzy - double)
 * @param A wskaźnik - podana przez użytkownika macierz A, którą użytkownik chce pomnożyć przez skalar
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @param f skalar - liczba podana przez użytkownika, przez którą użytkownik chce pomnożyć macierz A (typ skalara - double)
 * @return macierz wynikowa - wynik pomnożenia macierzy A przez skalar
 */
double **multiplyByScalar(double **A, int e, int d, double f);
/**
 * funkcja transponująca macierz podaną przez użytkownika (typ macierzy - double)
 * @param A wskaźnik - podana przez użytkownika macierz A, którą użytkownik chce transponować
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @return macierz wynikowa - transponowana macierz A
 */
double **transpozeMatrix(double **A, int e, int d);
/**
 * funkcja podnosząca macierz podaną przez użytkownika do potęgi podanej przez użytkownika (typ macierzy - double)
 * @param A wskaźnik - podana przez użytkownika macierz A, którą użytkownik chce podnieść do potęgi
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @param b podana przez użytkownika liczba - potęga, do której użytkownik chce podnieść macierz A (podany przez użytkownika w postaci parametru - typ unsigned)
 * @return macierz wynikowa - macierz A podniesiona do potęgi podanej przez użytkownika
 */
double **powerMatrix(double **A, int e, int d, unsigned b);
/**
 * funkcja sprawdzająca, czy macierz podana przez użytkownika jest macierzą diagonalną (typ macierzy - double)
 * @param A wskaźnik - podana przez użytkownika macierz A, dla której użytkownik chce sprawdzić własność, czy podana macierz jest macierzą diagonalną
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @return wartość prawdy lub fałszu w zależności, czy macierz A jest macierzą diagonalną, czy nie jest macierzą diagonalną
 */
bool matrixIsDiagonal(double **A, int e, int d);
/**
 * funkcja obliczająca wyznacznik dla macierzy podanej przez użytkownika (typ macierzy - double)
 * @param A wskaźnik - podana przez użytkownika macierz A, dla której użytkownik chce obliczyć jej wyznacznik
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 * @return wartość wyznacznika macierzy A (typ wyznacznika - double)
 */
double determinantMatrix(double **A, int e, int d);
/**
 * funkcja zamieniająca miejscem wybrane przez użytkownika dwie wartości w macierzy podanej przez użytkownika (typ macierzy - double)
 * @param a pierwsza wartość w podanej przez użytkownika macierzy A, przekazana przez referencję, którą użytkownik chce zamienić z drugą wartością
 * @param b druga wartość w podanej przez użytkownika macierzy A, przekazana przez referencję, którą użytkownik chce zamienić z pierwszą wartością
 */
void swap(double &a,double &b);
/**
 * funkcja sortująca tablicę podaną przez użytkownika (typ tablicy - double)
 * @param A wskaźnik - podana przez użytkownika tablica A, którą użytkownik chce posortować rosnąco (sortowanie bąbelkowe)
 * @param e rozmiar tablicy do posortowania
 */
void sortRow(double *A,int e);
/**
 * funkcja sortująca macierz podaną przez użytkownika (typ macierzy - double)
 * @param A wskaźnik - podana przez użytkownika macierz A, w której użytkownik chce posortować rosnąco każdy wiersz (sortowanie bąbelkowe)
 * @param e ilość wierszy macierzy A
 * @param d ilość kolumn macierzy A
 */
void sortRowsInMatrix(double **A, int e, int d);
#endif

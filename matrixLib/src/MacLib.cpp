#include <iostream>
#include "Maclib.h"

using namespace std;
void wyswietlMac(int **A, int e, int d){
    for (int k = 0; k < e; ++k, cout << endl) {
        for (int m = 0; m < d; ++m) {
            cout << A[k][m] << " ";
        }
    }
};

void wczytMac(int **A, int wA, int kA) {
    for (int i = 0; i < wA; ++i) {
        cout<< endl<<"podaj elementy " << i + 1 << " wiersza macierzy" << endl;
        for (int j = 0; j < kA; ++j) {
            cout <<endl<< "podaj liczbe:" << endl;
                while (!(cin >> A[i][j])) {
                    cout <<endl<< "Ups! Nie została podana prawidłowa liczba!" << endl;
                    cout<<endl<< "Spróbuj ponownie podać liczbę:" <<endl;
                    cin.clear();
                    cin.ignore();
                }
            cout <<endl<< "wczytana liczba: " << A[i][j] << endl;
        }
        cout << endl<<"Wczytany " << i+1 << " wiersz macierzy:" << endl;
        for (int m = 0; m < kA; ++m) {
            cout << A[i][m] << " ";
        }
        cout<<endl;

    }
    cout <<endl<<"Wczytana macierz:" << endl;
    for (int k = 0; k < wA; ++k, cout << endl) {
        for (int m = 0; m < kA; ++m) {
            cout << A[k][m] << " ";
        }
    }
};
void wyswietlMac(double **A, int e, int d){
    for (int k = 0; k < e; ++k, cout << endl) {
        for (int m = 0; m < d; ++m) {
            cout << A[k][m] << " ";
        }
    }
};

void wczytMac(double **A, int wA, int kA) {
    for (int i = 0; i < wA; ++i) {
        cout<< endl<<"podaj elementy " << i + 1 << " wiersza macierzy" << endl;
        for (int j = 0; j < kA; ++j) {
            cout <<endl<< "podaj liczbe:" << endl;
            while (!(cin >> A[i][j])) {
                cout <<endl<< "Ups! Nie została podana prawidłowa liczba!" << endl;
                cout<<endl<< "Spróbuj ponownie podać liczbę:" <<endl;
                cin.clear();
                cin.ignore();
            }
            cout <<endl<< "wczytana liczba: " << A[i][j] << endl;
        }
        cout << endl<<"Wczytany " << i+1 << " wiersz macierzy:" << endl;
        for (int m = 0; m < kA; ++m) {
            cout << A[i][m] << " ";
        }
        cout<<endl;

    }
    cout <<endl<<"Wczytana macierz:" << endl;
    for (int k = 0; k < wA; ++k, cout << endl) {
        for (int m = 0; m < kA; ++m) {
            cout << A[k][m] << " ";
        }
    }
};
int **addMatrix(int **A,int  **B, int e, int d)
{
    int **C = new int *[e];
    for ( int i = 0; i < e; ++i ) {
        C[i] = new int[d];
    }
for(int i=0; i<e; i++)
{
    for(int j=0; j<d; j++)
    {
        C[i][j]=A[i][j]+B[i][j];
    }
}
return C;
};
int **subtractMatrix(int **A,int  **B, int e, int d) {
    int **C = new int *[e];
    for (int i = 0; i < e; ++i) {
        C[i] = new int[d];
    }
    for (int i = 0; i < e; i++) {
        for (int j = 0; j < d; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
};
int **multiplyMatrix(int **A,int  **B, int e, int d, int f) {
    int **C = new int *[e];
    for (int i = 0; i < e; ++i) {
        C[i] = new int[d];
    }
    for (int k = 0; k < e; k++)
        for (int l = 0; l < f; l++) {
            int s = 0;
            for (int m = 0; m < d; m++) s += A[k][m] * B[m][l];
            C[k][l] = s;
        }
    return C;
};

    int **multiplyByScalar(int **A, int e, int d, int f) {
        int **C = new int *[e];
        for (int i = 0; i < e; ++i) {
            C[i] = new int[d];
        }
        for (int k = 0; k < e; k++) {
            for (int l = 0; l < d; l++) {
                C[k][l] = A[k][l] * f;
            }
        }
        return C;
    };
        int **transpozeMatrix(int **A, int e, int d) {
            int **C = new int *[d];
            for (int i = 0; i < d; ++i) {
                C[i] = new int[e];
            }
            for(int k = 0; k < e; k++ ) {
                for (int l = 0; l < d; l++) {
                    C[l][k] = A[k][l];
                }
            }
            return C;
};
int **powerMatrix(int **A, int e, int d, unsigned b) {
    int **B = new int *[e];
    for (int f = 0; f < e; ++f) {
        B[f] = new int[d];
    }
    int **C = new int *[e];
    for (int j = 0; j < e; ++j) {
        C[j] = new int[d];
    }


        if( !b ) {
            int t, u;

            for (t = 0; t < e; t++) {
                for (u = 0; u < d; u++) A[t][u] = 0;
                A[t][t] = 1;
            }
        }
        else if( b > 1 )
        {

            int h, g;

            for( h = 0; h < e; h++ ) {
                for (g = 0; g < d; g++) {
                    B[h][g] = A[h][g];
                }
            }
            for(int q = 2; q <= b; q++ )
            {
                int x, y, r, s;

                for( x = 0; x < e; x++ )
                    for( y = 0; y < d; y++ )
                    {
                        s = 0;
                        for( r = 0; r < e; r++ ) s += B [ x ][ r ] * A [ r ][ y ];
                        C [ x ][ y ] = s;
                    }
                int l, m;

                for( l = 0; l < e; l++ )
                    for( m = 0; m < d; m++ ) A[ l ][ m ] = C [ l ][ m ];
            }


            for(int i = 0; i < e; i++ )
            {
                delete [ ] B [ d ];
                delete [ ] C [ d ];
            }
            delete [ ] B;
            delete [ ] C;
        }
    return A;
};
bool matrixIsDiagonal(int **A, int e, int d) {
    bool ok=true;
    for(int i=0;i<e;i++) {
        for (int j = 0; j < d; j++) {
            if (j != i && A[i][j] != 0)
                ok = false;
        }
    }
    return ok;
};
int det (int **A, int *B, int e, int d){
        int    *w, p, i, j, t, y;

        if( e == 1 )
            return A [ d ][ B [ 0 ] ];
        else
        {
            w = new int [ e - 1 ];
            t = 0;
            y = 1;
            for( i = 0; i < e; i++ )
            {
                p = 0;
                for( j = 0; j < e - 1; j++ )
                {
                    if( p == i ) p++;
                    w [ j ] = B [ p++ ];
                }
                t += y * A [ d ][ B [ i ] ] * det ( A, w,e - 1, d  + 1);
                y = -y;
            }
            delete [ ] w;
            return t;
        }
};
int determinantMatrix(int **A, int e, int d) {
    int *B = new int [e];

    for(int l = 0; l < e; l++ ) {
        B[l] = l;
    }
    int q;
    q = det(A, B, e, 0);
    return q;
};
void swap(int &a,int &b)
{
  int c;
  c=a;
  a=b;
  b=c;
};
void sortRow(int *A,int e)
{
        for(int i=0;i<e;i++)
            for(int j=1;j<e-i;j++)
                if(A[j-1]>A[j])
                    swap(A[j-1], A[j]);

};
void sortRowsInMatrix(int **A, int e, int d)
{
    for(int i=0;i<e;i++) {
        sortRow(A[i], d);
    }
};
double **addMatrix(double **A,double  **B, int e, int d)
{
    double **C = new double *[e];
    for ( int i = 0; i < e; ++i ) {
        C[i] = new double[d];
    }
    for(int i=0; i<e; i++)
    {
        for(int j=0; j<d; j++)
        {
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    return C;
};
double **subtractMatrix(double **A,double  **B, int e, int d) {
    double **C = new double *[e];
    for (int i = 0; i < e; ++i) {
        C[i] = new double[d];
    }
    for (int i = 0; i < e; i++) {
        for (int j = 0; j < d; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
};
double **multiplyMatrix(double **A,double  **B, int e, int d, int f) {
    double **C = new double *[e];
    for (int i = 0; i < e; ++i) {
        C[i] = new double[d];
    }
    for (int k = 0; k < e; k++)
        for (int l = 0; l < f; l++) {
            double s = 0;
            for (int m = 0; m < d; m++) s += A[k][m] * B[m][l];
            C[k][l] = s;
        }

    return C;
};

double **multiplyByScalar(double **A, int e, int d, double f) {
    double **C = new double *[e];
    for (int i = 0; i < e; ++i) {
        C[i] = new double[d];
    }
    for (int k = 0; k < e; k++) {
        for (int l = 0; l < d; l++) {
            C[k][l] = A[k][l] * f;
        }
    }
    return C;
};
double **transpozeMatrix(double **A, int e, int d) {
    double **C = new double *[d];
    for (int i = 0; i < d; ++i) {
        C[i] = new double[e];
    }
    for(int k = 0; k < e; k++ ) {
        for (int l = 0; l < d; l++) {
            C[l][k] = A[k][l];
        }
    }
    return C;
};
double **powerMatrix(double **A, int e, int d, unsigned b) {
    double **B = new double *[e];
    for (int f = 0; f < e; ++f) {
        B[f] = new double[d];
    }
    double **C = new double *[e];
    for (int j = 0; j < e; ++j) {
        C[j] = new double[d];
    }

    if( !b ) {
        int t, u;

        for (t = 0; t < e; t++) {
            for (u = 0; u < d; u++) A[t][u] = 0;
            A[t][t] = 1;
        }
    }
    else if( b > 1 )
    {

        int h, g;

        for( h = 0; h < e; h++ ) {
            for (g = 0; g < d; g++) {
                B[h][g] = A[h][g];
            }
        }
        for(int q = 2; q <= b; q++ )
        {
            int x, y, r;
            double s;

            for( x = 0; x < e; x++ )
                for( y = 0; y < d; y++ )
                {
                    s = 0;
                    for( r = 0; r < e; r++ ) s += B [ x ][ r ] * A [ r ][ y ];
                    C [ x ][ y ] = s;
                }
            int l, m;

            for( l = 0; l < e; l++ )
                for( m = 0; m < d; m++ ) A[ l ][ m ] = C [ l ][ m ];
        }


        for(int i = 0; i < e; i++ )
        {
            delete [ ] B [ d ];
            delete [ ] C [ d ];
        }
        delete [ ] B;
        delete [ ] C;
    }
    return A;
};
bool matrixIsDiagonal(double **A, int e, int d) {
    bool ok=true;
    for(int i=0;i<e;i++) {
        for (int j = 0; j < d; j++) {
            if (j != i && A[i][j] != 0)
                ok = false;
        }
    }
    return ok;
};
double det(double ** A,int *B, int e, int d)
{
    int    *w, p, i, j;
    double t, y;

    if( e == 1 )
        return A [ d ][ B [ 0 ] ];
    else
    {
        w = new int [ e - 1 ];
        t = 0;
        y = 1;
        for( i = 0; i < e; i++ )
        {
            p = 0;
            for( j = 0; j < e - 1; j++ )
            {
                if( p == i ) p++;
                w [ j ] = B [ p++ ];
            }
            t += y * A [ d ][ B [ i ] ] * det ( A, w,e - 1, d  + 1);
            y = -y;
        }
        delete [ ] w;
        return t;
    }
};
double determinantMatrix(double **A, int e, int d) {
    int *B = new int [e];

    for(int l = 0; l < e; l++ ) {
        B[l] = l;
    }
        double q;
    q = det(A, B, e, 0);
    return q;
};
void swap(double &a,double &b)
{
    double c;
    c=a;
    a=b;
    b=c;
};
void sortRow(double *A,int e)
{
    for(int i=0;i<e;i++)
        for(int j=1;j<e-i;j++)
            if(A[j-1]>A[j])
                swap(A[j-1], A[j]);

};
void sortRowsInMatrix(double **A, int e, int d)
{
    for(int i=0;i<e;i++) {
        sortRow(A[i], d);
    }
};
void dokumentacja()
{
    cout<<"Dokumentacja:"<<endl;
    cout<<endl<<"Program wykonujący różne działania na macierzach."<<endl;
    cout<<endl<<"Działanie, które chcesz wykonać musisz podać jako parametr." << endl;
    cout<<endl<<"Następnie musisz zdecydować, czy chcesz wykonywać daną operację na macierzach typu int (wpisz int), czy typu double (wpisz double)"<<endl;
    cout<<endl<<"W kolejnym kroku musisz podać wymiary (podając liczby z klawiatury) jednej lub dwóch macierzy (w zależności od wykonywanego działania),"<<endl;
    cout<<"a następnie wczytać dane do jednej lub dwóch macierzy (odpowiednio podając liczby z klawiatury dla wybranego typu macierzy), dane wczytywane są wierszami."<<endl;
    cout << "Działania:" << endl;
    cout <<endl<< "addMatrix" << endl;
    cout<<"Dodawanie dwóch macierzy A i B. Macierze są typu wybranego przez użytkownika."<<endl;
    cout<<"Po odpowiednim wczytaniu danych do obydwu macierzy zostanie wykonane dodawanie macierzy, a następnie zostanie wyświetlona macierz wynikowa."<<endl;
    cout <<endl<< "subtractMatrix" << endl;
    cout<<"Odejmowanie dwóch macierzy A i B. Macierze są typu wybranego przez użytkownika."<<endl;
    cout<<"Po odpowiednim wczytaniu danych do obydwu macierzy zostanie wykonane odejmowanie macierzy, a następnie zostanie wyświetlona macierz wynikowa."<<endl;
    cout <<endl<< "multiplyMatrix" << endl;
    cout<<"Pomnożenie macierzy A przez macierz B. Macierze są typu wybranego przez użytkownika."<<endl;
    cout<<"Po odpowiednim wczytaniu danych do obydwu macierzy zostanie wykonane pomnożenie macierzy A przez macierz B, a następnie zostanie wyświetlona macierz wynikowa."<<endl;
    cout <<endl<< "multiplyByScalar" << endl;
    cout<<"Pomnożenie macierzy A przez skalar. Macierz i skalar są typu wybranego przez użytkownika."<<endl;
    cout<<"Po odpowiednim wczytaniu danych do macierzy i odpowiednim podaniu wartości skalara (użytkownik podaje liczbę z klawiatury) przez,"<<endl;
    cout<<"który zostanie pomnożona macierz A, wykonane zostanie mnożenie, a następnie zostanie wyświetlona macierz wynikowa."<<endl;
    cout <<endl<< "transpozeMatrix" << endl;
    cout<<"Transponowanie macierzy A. Macierz jest typu wybranego przez użytkownika."<<endl;
    cout<<"Po odpowiednim wczytaniu danych do macierzy zostanie wykonane transponowanie macierzy, a następnie zostanie wyświetlona macierz transponowana."<<endl;
    cout <<endl<< "powerMatrix [potęga]" << endl;
    cout<<"Potęgowanie macierzy A. Macierz jest typu wybranego przez użytkownika."<<endl;
    cout<<"Potęgę, do której ma zostać podniesiona macierz A użytkownik podaje w postaci drugiego parametru (np. powerMatrix 3)."<<endl;
    cout<<"Po odpowiednim wczytaniu danych do macierzy i odpowiednim podaniu wartości potęgi (użytkownik podaje liczbę jako drugi parametr),"<<endl;
    cout<<"wykonane zostanie potęgowanie macierzy A, a następnie zostanie wyświetlona macierz wynikowa."<<endl;
    cout <<endl<< "determinantMatrix" << endl;
    cout<<"Obliczanie wyznacznika macierzy A. Macierz jest typu wybranego przez użytkownika."<<endl;
    cout<<"Po odpowiednim wczytaniu danych do macierzy, wykonane zostaną obliczenia, a następnie zostanie wyświetlony wyznacznik macierzy A."<<endl;
    cout <<endl<< "matrixIsDiagonal" << endl;
    cout<<"Sprawdzenie, czy macierz A jest macierzą diagonalną. Macierz jest typu wybranego przez użytkownika."<<endl;
    cout<<"Po odpowiednim wczytaniu danych do macierzy, wykonany zostanie mechanizm sprawdzający daną własność, a następnie zostanie wyświetlony komunikat"<<endl;
    cout<<"albo informujący, że macierz A jest macierzą diagonalną albo informujący, że macierz A nie jest macierzą diagonalną."<<endl;
    cout <<endl<< "swap" << endl;
    cout<<"Zamiana miejscami dwóch wartości w macierzy A. Macierz jest typu wybranego przez użytkownika."<<endl;
    cout<<"Po odpowiednim wczytaniu danych do macierzy, użytkownik podaje numer wiersza i numer kolumny pierwszej wartości, a następnie numer wiersza i numer kolumny drugiej wartości"<<endl;
    cout<<"(numery wierszy i numery kolumn są podawane z klawiatury przez użytkownika), kolejno wykonana zostanie zamiana miejscami pierwszej i drugiej wartości."<<endl;
    cout<<"Na koniec zostanie wyświetlona macierz A, w której dane wartości zamieniły się miejscami."<<endl;
    cout <<endl<< "sortRowsInMatrix" << endl;
    cout<<"Sortowanie rosnące każdego wiersza macierzy A. Macierz jest typu wybranego przez użytkownika."<<endl;
    cout<<"Po odpowiednim wczytaniu danych do macierzy, wykonane zostanie sortowanie rosnące (sortowanie metodą bąbelkową) każdego wiersza macierzy,"<<endl;
    cout<<"a następnie zostanie wyświetlona posortowana macierz A."<<endl;
    cout <<endl<< "help" << endl;
    cout << "Wyświetlanie dokumentacji" << endl;
};


#include<iostream>
#include<math.h>
using namespace std;
/*
class Prostopadloscian
{
public:
    double bok_a;
    double bok_b;
    double h;
    double pole_podstawy()
    {return bok_a*bok_b;}
    double pole_boczne_1()
    {return h*bok_b;}
    double pole_boczne_2()
    {return bok_a*h;}
    double pole_calkowite()
    {return 2*pole_boczne_1()+2*pole_boczne_2()+2*pole_podstawy();}
};
class Kula
{
public:
    double r;
    double objetosc()
    {return pow(r,3)*M_PI*(4.0/3.0);}
};
class FunkcjaKwadratowa
{
private:
    double a = 5;
    double b = 3;
    double c = 4;
public:
    void wyswietlanie()
    {cout<<"f(x) = "<<a<<"x^2 + "<<b<<"x + "<<c<<endl;}
    double geta() {
        return a;
    }
    double getb() {
        return b;
    }
    double getc() {
        return c;
    }
    void seta(double a) {
        this->a = a;
    }
    void setb(double b) {
        this->b = b;
    }
    void setc(double c) {
        this->c = c;
    }
};


struct samochod{
    string marka;
    string model;
    int rok_produkcji;
    string kolor;
};

int takaSamaMarka(samochod tab1[],int w)
{
    int x = 1;
    for (int i = 1; i < w; i++)
    {
        if(tab1[i-1].marka==tab1[i].marka)
            x++;
    }
return x;
};
int najnizszyRok(samochod tab1[],int w)
{

        int x = 0;
        for (int i = 1; i < w; i++) {
            if (tab1[x].rok_produkcji > tab1[i].rok_produkcji)
                x = i;
        }
    return x+1;
};
 */
class Punkt
{
public:
    double x;
    double y;
    double x1;
    double y1;
    Punkt();
    double odleglosc(double x, double y, double x1, double y1)
    {
double m;
m = sqrt(pow(x1-x,2)+pow(y1-y,2));
return m;
    }
    void setx(double x) {
        this->x = x;
    }
    void sety(double y) {
        this->y = y;
    }
    void setx1(double x1) {
        this->x1 = x1;
    }
    void sety1(double y1) {
        this->y1 = y1;
    }
};
Punkt::Punkt() {
    cout<<"konstruktor działa!"<<endl;
}
int main()
{
    /*
    int liczba_osob = 6;

    samochod pojazd[] = {{"Opel","Astra",2012,"czerwony"},
                         {"Mercedes","A - klasa",2018,"srebrny"},
                         {"Ford","Focus",2001,"żółty"},
                         {"Toyota","Yaris",2021,"niebieski"},
                         {"Toyota","Corolla",2014,"zielony"},
                         {"Toyota","Rav4",2002,"czarny"}};


    cout << "marka\tmodel \trok produkcji \tkolor" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < liczba_osob; i++)
    {
        cout << pojazd[i].marka << "\t" << pojazd[i].model << "\t" << pojazd[i].rok_produkcji <<    	  "\t" << pojazd[i].kolor << endl;
    }
    cout <<"liczba samochodów o takiej samej marce = " << takaSamaMarka(pojazd,6)<<endl;
    cout <<"indeks samochodu o najnizszym roku produkcji = " << najnizszyRok(pojazd,6)<<endl;

    Prostopadloscian figura;
    Kula okrag;
cout<<"podaj długości boków podstawy prostopadłościanu:"<<endl;
cin>> figura.bok_a>>figura.bok_b;
    cout<<"podaj wysokość prostopadłościanu:"<<endl;
    cin>> figura.h;
    cout<<"pole całkowite prostopadłościanu wynosi = " << figura.pole_calkowite() <<endl;

    cout<<"podaj promień kuli:"<<endl;
    cin>> okrag.r;
    cout<<"objetość kuli wynosi = " << okrag.objetosc() <<endl;
    kwadratowa.geta();
    kwadratowa.getb();
    kwadratowa.getc();

    int a, b, c;
    cout<<"podaj współczynniki funkcji kwadratowej"<<endl;
    cin>> a >> b >> c;

    FunkcjaKwadratowa kwadratowa;
    kwadratowa.seta(a);
    kwadratowa.setb(b);
    kwadratowa.setc(c);
    cout<<"funkcja kwadratowa o podanych współczynnikach:" << endl;
    kwadratowa.wyswietlanie();
     */
    int x, y, x1, y1;
    cout<<"podaj współrzędne dwóch punktów"<<endl;
    cin>> x >> y >> x1 >> y1;
    Punkt punkcik;
    punkcik.setx(x);
    punkcik.sety(y);
    punkcik.setx1(x1);
    punkcik.sety1(y1);
    cout<<"odległość podanych puntków wynosi = "<< punkcik.odleglosc(x,y,x1,y1) << endl;
    return 0;
}
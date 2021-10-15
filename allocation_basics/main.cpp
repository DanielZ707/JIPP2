#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{

  /*  int i;
 for(i=1;i<=5;++i)
 {
     cout<<"JIPP2"<<endl;
 } */
 /* int tablica[4][3][5];
  tablica[1][1][1] = 15;
  cout<<tablica[1][1][1];
 */
 /*int rozmiar;
 cin>>rozmiar;
 int *tablica = new int[rozmiar];
 tablica[rozmiar-1]=3;
 cout<<tablica[rozmiar-1]<<endl;
 delete [] tablica;
*/
  /*  for(int i = 0; i < argc ; ++i) {
        cout << argv[i] <<endl;
    }
*/
  if(argc!=3)
  {
      cout<<"podana została zła ilość argumentów!"<<endl;
  }
  else if(argv[0]="help") {
      cout << "Simple calculatur" << endl;
      cout<< "simpleCalc [nazwa działania]"<<endl;
      cout << "Działania:" << endl;
      cout << "add [a] [b]" << endl;
      cout << "Dodawanie dwóch liczb ([a] i [b]) całkowitych." << endl;
      cout << "substract [a] [b]" << endl;
      cout << "Odejmowanie dwóch liczb ([a] i [b]) całkowitych." << endl;
      cout << "volume [a] [b]" << endl;
      cout << "obliczanie objętości graniastosłupa prostego o podstawie trapezu" << endl;
      cout << "help [a] [b]" << endl;
      cout << "wyświetlanie dokumentacji" << endl;
  }
    else if(argv[0]="add")
  {
        int w;
        w=argv[1] + argv[2];

  }
  else if(argv[0]="substract")
  {
      int w;
      w=argv[1] + argv[2];

  }
  else if(argv[0]="volume")
  {
      int w;
      w=argv[1] + argv[2];

  }
    return 0;
}


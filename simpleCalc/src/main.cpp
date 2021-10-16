#include <iostream>
#include "calc.h"
using namespace std;
int main(int argc, char *argv[])
{
    string a = argv[1];
if(a == "help") {
    help(argc);
}
if(a=="add") {
    add(argc, argv[2], argv[3]);
}
if(a=="subtract") {
    subtract(argc, argv[2], argv[3]);
}
if(a=="volume") {
    volume(argc, argv[2], argv[3], argv[4], argv[5]);
}
if(a!="add"&&a!="subtract"&&a!="volume"&&a!="help")
{
    blad();

}
    return 0;
}
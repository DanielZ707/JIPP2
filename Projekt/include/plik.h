#ifndef JIPP2_PLIK_H
#define JIPP2_PLIK_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class File
{
    FILE *file;
    string name;
    string accessType;
/**
 * funkcja zapisująca znak do pliku
 * @param c
 */
    void write(char c){
        putc(c, file);
    }
/**
 * funkcja odczytująca znak z pliku
 * @param c
 */
    void read(char& c){
        c=getc(file);
    }

public:
    /**
     * konstruktor klasy File
     * @param _name nazwa pliku
     * @param _accessType tryb dostępu do pliku
     */
    File(string _name, string _accessType): name(_name), accessType(_accessType){
    }
/**
 * destruktor zamykający plik
 */
    ~File(){
        if(fclose(file)==EOF){
            perror("ERROR: fclose");
            exit(EXIT_FAILURE);
        }
    }
/**
 * funkcja otwierająca plik
 * @return wartość czy plik został poprawnie otwarty
 */
    bool open(){
        if((file=fopen(name.data(), accessType.data()))==NULL)
            return false;
        else return true;
    }
/**
 * funkcja odczytująca tekst z pliku do separatora "|"
 * @param str
 */
    void readStringFromFile(string& str){
        char c;
        do{
            read(c);
            if(c=='|')
                break;
            str+=c;
        }while(c!=EOF);
    }
/**
 * funkcja zamieniająca typ odczytanej wartości na string
 * @tparam T typ oczytanej wartości
 * @param value odczytana wartość
 * @return odczytana wartość typu string
 */
    template<typename T>
    string to_string(T value){
        ostringstream oss;
        oss << value;
        return oss.str();
    }
/**
 * funkcja odczytująca tekst z pliku do separatora "|"
 * @tparam T typ odczytanej wartości
 * @param var odczytana wartość
 */
    template <typename T>
    void writeStringToFile(const T& var){
        string str=to_string(var);

        for(int i=0; i<str.length(); i++)
            write(str[i]);
        write('|');
    }
};

#endif

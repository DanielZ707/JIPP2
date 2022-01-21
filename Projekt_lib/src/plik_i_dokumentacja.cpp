#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class File
{
    FILE *file;
    std::string name;
    std::string accessType;

    void write(char c){
        putc(c, file);
    }

    void read(char& c){
        c=getc(file);
    }

public:
    File(string _name, string _accessType): name(_name), accessType(_accessType){
    }

    ~File(){
        if(fclose(file)==EOF){
            perror("ERROR: fclose");
            exit(EXIT_FAILURE);
        }
    }

    bool open(){
        if((file=fopen(name.data(), accessType.data()))==NULL)
            return false;
        else return true;
    }

    void readStringFromFile(string& str){
        char c;
        do{
            read(c);
            if(c=='|')
                break;
            str+=c;
        }while(c!=EOF);
    }

    template<typename T>
    std::string to_string(T value){
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }

    template <typename T>
    void writeStringToFile(const T& var){
        string str=to_string(var);

        for(int i=0; i<str.length(); i++)
            write(str[i]);
        write('|');
    }
};
//
// Created by HP on 18.01.2022.
//


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

template <typename T>
T myfunc(FILE * input_file){
    char myBuffer;
    if (input_file==nullptr) perror ("Error opening file");
    myBuffer = getc (input_file);

}

int main() {
    char type_data;

    FILE * pFile;
    pFile=fopen ("/home/alphae/Cours/C++/TP2/example_2.txt","r");
    if (pFile==nullptr) perror ("Error opening file");
    else{
        type_data = getc (pFile);
        std::cout << type_data << std::endl;

        switch (getc (pFile)){
            case 'i':
                myfunc<int>(pFile);
                break;
            case 'u':
                myfunc<unsigned int>(pFile);
                break;
            case 'f':
                myfunc<float>(pFile);
                break;
            case 'd':
                myfunc<double>(pFile);
                break;
            case 'c':
                myfunc<char>(pFile);
                break;
            case 's':
                myfunc<std::string>(pFile);
                break;
        }


    }
    fclose (pFile);
    return 0;
}
/*
    std::ifstream file ("/home/alphae/Cours/C++/TP2/example_1.txt");
    if (file.is_open()){
        std::cout << "file opened" << std::endl ;

        file.read(type_data,1);
        //getline(file,type_data);
        switch (type_data)
            case 'i':
                myfunc<int>(file);
                break;
            case 'u':
                myfunc<unsigned int>(file);
                break;
            case 'f':
                myfunc<float>(file);
                break;
            case 'd':
                myfunc<double>(file);
                break;
            case 'c':
                myfunc<char>(file);
                break;
            case 's':
                myfunc<std::string>(file);
                break;
        
        file.close();
    }
    else std::cout << "Unable to open file" << std::endl;
    return 0;
}*/


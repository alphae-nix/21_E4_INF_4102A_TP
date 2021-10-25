#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <iterator>




char variable_type(std::ifstream& data) {
    auto s = std::string{};
    std::getline(data, s);
    return s[0];
}


template<typename tab>
void write_file(tab& storage){
    auto iterator_min = storage.begin();
    auto iterator_max = storage.end();

    std::ofstream myFile("resultat.txt");
    for (auto i = iterator_min; i != iterator_max; i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    myFile.close();
}

template<typename it>
void swap(it* it_1, it* it_2){
    it temp = *it_1;
    *it_1 = *it_2;
    *it_2 = temp;
}


template<typename tab>
void sort_file(tab& storage){
    auto it_min = storage.begin();
    auto it_max = storage.end();
    for(auto i = it_min; i != it_max ; i++ ){
        it_min = i;
        std::cout << *it_min << std::endl;
        for(auto j = i; j != it_max; j++)
            if (*j < *it_min)
                it_min = j;
        swap(&*it_min,&*i);

    }
}

template <typename T,typename tab>
void read_file(std::ifstream &input_file) {
    tab storage;
    T value;
    while (input_file >> value) {
        storage.push_back(value);
    }
    sort_file<tab>(storage);
    write_file<tab>(storage);

}





int main() {

    std::ifstream file ("/home/alphae/Cours/C++/TP/TP3/example_2.txt");
    if (file.is_open()){
        std::cout << "file opened" << std::endl ;

        //Premier Switch permettant la vérification du type à stocker
        switch (variable_type(file)){
            case 'i':
                switch (variable_type(file)){ //Deuxième switch
                    case 'v':
                        read_file<int, std::vector<int> >(file);
                        break;
                    case 'l':
                        read_file<int, std::list<int>>(file);
                        break;
                    case 'd':
                        read_file<int, std::deque<int>>(file);
                        break;
                }
                break;

            case 'f':
                switch (variable_type(file)){
                    case 'v':
                        read_file<float, std::vector<float> >(file);
                        break;
                    case 'l':
                        read_file<float, std::list<float>>(file);
                        break;
                    case 'd':
                        read_file<float, std::deque<float>>(file);
                        break;
                }
                break;

            case 's':
                switch (variable_type(file)){
                    case 'v':
                        read_file<std::string, std::vector<std::string> >(file);
                        break;
                    case 'l':
                        read_file<std::string, std::list<std::string>>(file);
                        break;
                    case 'd':
                        read_file<std::string, std::deque<std::string>>(file);
                        break;
                }
                break;
        }

        file.close();
    }
    else std::cout << "Unable to open file" << std::endl;
    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

//Fonction permettant la lecture d'une ligne dans un fichier passé en paramètre
char variable_type(std::ifstream& data) {
    std::string s;
    std::getline(data, s);
    return s[0];
}


template<typename tab>
void write_file(tab& storage){
    auto iterator_min = storage.begin();
    auto iterator_max = storage.end();

    std::ofstream myFile("resultat.txt");
    //affichage de notre contenu
    for (auto i = iterator_min; i != iterator_max; i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    myFile.close();
}


template<typename tab>
void sort_file(tab& storage){
    auto it_min = storage.begin(); //création des 2 itérateurs
    auto it_max = storage.end();

    for(auto i = it_min; i != it_max ; i++ ){
        it_min = i;
        for(auto j = i; j != it_max; j++) //au fur et à mesure on diminue le tableau à trier
            if (*j < *it_min)
                it_min = j;
        //switch value
        auto temp = *it_min;
        *it_min = *i;
        *i = temp;

    }
}
//fonction nous permettant de stocker dans le container adéquat nos valeurs (adéquates)
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

    std::ifstream file ("/home/alphae/Cours/C++/TP/TP3/example_1.txt");
    if (file.is_open()){
        std::cout << "file opened" << std::endl ;

        //Premier Switch permettant la vérification du type à stocker
        switch (variable_type(file)){
            case 'i':
                switch (variable_type(file)){ //Deuxième switch permettant la vérification du type de notre container
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


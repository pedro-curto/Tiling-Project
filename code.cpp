/*******************************************************************************
**                       Analise e Sintese de Algoritmos                      **
**                                 Projeto 1                                  **
********************************************************************************
**                                 Autores:                                   **
**                            Pedro Sousa - 102664                            **
**                            Pedro Curto - 103091                            **
*******************************************************************************/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>

std::unordered_map<std::string, long long unsigned> values;


long long unsigned solution_func(std::vector<int> path) {

    std::string key(path.begin(), path.end());

    if (values.count(key)) {
        return values.at(key);
    }

    int max_size = (int)(path.size());

    int i = -1;
    int max = 0;
    for (int k = 0; k < max_size; k++){
        if(path[k] > max){
            max = path[k];
            i = k;
        }
    }

    if (i == -1) {
        return 1;
    }

    int j = path[i];

    if (j == 1){
        return 1;
    }

    long long unsigned sum = 0;
    std::vector<int> path2;

    int height = 1;
    for (int k = 1; (i + k) < max_size; k++){
        if ((path[i] > path[i+k]) || height > j){
            break;
        }
        height++;
    }

    int n;
    if (height > j)
        n = j;
    else
        n = height;

    for(int k = n;k >= 1; k--){  //k é tamanho do quadrado nxn max
        path2 = path;
        for(int y = i; y < i+k ;y++){ // y é iteracao de 1 ate k
            path2[y] -= k;
        }
        sum += solution_func(path2);
    }

    values[key] = sum;

    return sum;
}

int main() { 
    int n;
    int lines;
    int columns;
    bool ones = false;
    
    std::cin >> lines;
    std::cin >> columns;

    std::vector<int> path;

    for (int i = 0; i < lines; i++){
        std::cin >> n;
        if (n == 1) ones = true;
        else if (n != 0)    
            path.push_back(n);
    }


    if (lines == 0 || columns == 0){
        std::cout << 0 << std::endl;
        return 0;
    }


    if(path.size() == 0){
        if (ones)
            std::cout << 1 << std::endl;
        else 
            std::cout << 0 << std::endl;
        return 0;
    }

    int max_size = path[path.size()-1];
    int c_size = path.size();

    if(max_size < c_size){
        std::vector<int> path2(max_size);

        for(int i = 0; i< c_size;i++)
            for (int j =0; j < path[i]; j++)
                path2[max_size-1-j] += 1;

        std::cout << solution_func(path2) << std::endl;
    }
    else    
        std::cout << solution_func(path) << std::endl;

    return 0;
}   

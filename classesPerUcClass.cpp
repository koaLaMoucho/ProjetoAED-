//
// Created by danie on 15/10/2022.
//
#include <algorithm>
#include <vector>
#include <iostream>
#include "classesPerUcClass.h"

///Todas as UCs que têm alunos inscritos. Complexidade O(n).
///@param arr - Vetor que armazena todas as Ucs e as suas respetivas turmas.
///@return - Não tem return, apenas couts que dão print as Ucs armazenadas em v.
void classesPerUcClass::todasUcs(const vector<classesPerUcClass>& arr){
    string sep = ":";
    vector<string> v;
    for (const auto& x: arr){
        if (!(find(v.begin(), v.end(), x.UcCode) != v.end())){
            v.push_back(x.UcCode);
        }
    }
    cout << "The UCs that has at least one student assigned to it are: ";
    for (auto x: v){
        cout << sep << " " << x;
        sep = ",";
    }
    cout << endl;
}

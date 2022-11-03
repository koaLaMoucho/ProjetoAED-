//
// Created by danie on 15/10/2022.
//

#include "classesClass.h"

///Função para comparar horas. Complexidade O(1).
///@param a - atributos da classe classesClass.
///@param b - atributos da classe classesClass.
///@return - verdadeiro se a hora de começo da aula dos atributos de a (a.StartHour) for anterior a dos atributos de b (b.StartHour), falso se a hora de a.StartHour for igual ao superior à hora de b.StartHour.
bool classesClass::intcomp(classesClass a, classesClass b){
    return a.StartHour < b.StartHour;
}

#include <string>
#include <queue>
#include "classesClass.h"
using namespace std;
#ifndef UNTITLED_STUDENTSCLASSESCLASS_H
#define UNTITLED_STUDENTSCLASSESCLASS_H


class studentsClassesClass {
public:
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;

    static int ocupacaoTurma(const string cadeira, string turma, const vector<studentsClassesClass>& arr);
    static void ocupacaoUc(const vector<studentsClassesClass>& arr, string cadeira);
    static void estudantesTurma(const vector<studentsClassesClass>& arr, string turma);
    static void todosEstudantes(const vector<studentsClassesClass>& arr);
    static void estudantesUC(const vector<studentsClassesClass>& arr, string cadeira);
    static void turmasUC(const vector<studentsClassesClass>& arr, string uc);
    static bool diferencaDeAlunosTurma(const string cadeira, const vector<studentsClassesClass>& arr);
    static void adicionarEstudante(const string nome, const string cadeira, const string turma, vector<studentsClassesClass>& arr);
    static void removerEstudante(const string nome, const string cadeira, vector<studentsClassesClass>& arr);
    static void alteraçaoVariasTurmas( vector<studentsClassesClass> &arr);
    static void turmaAluno(const vector<studentsClassesClass> &arr, string nome);
    static void estudantesEmUcsAno(const vector<studentsClassesClass> &arr, int ano);
    static set<string> UcsAluno(const vector<studentsClassesClass> &arr, string nome);
    static void printUcsAluno(const vector<studentsClassesClass> &arr, string nome);
    static void estudantesNUcsAlfabeto(vector<studentsClassesClass> &arr, int n);
    static void horarioEstudante(const vector<studentsClassesClass> &arr1, const vector<classesClass> &arr2, string nomeEstudante);
    static bool verificaSobreposicao(const vector<studentsClassesClass> &arr1, const vector<classesClass> &arr2, string nomeEstudante);
    static void ocupacaoTurmaCout(const string cadeira, string turma, const vector<studentsClassesClass> &arr);
    static void pedidoAlteracaoHorario(const string nome, const string cadeira, const string novaTurma, vector<studentsClassesClass> &arr, vector<classesClass> &arr2);
    static void verificarFinalDoDia(vector<studentsClassesClass> &arr, vector<classesClass> &arr2);
    static void ocupacaoUcsAno(const vector<studentsClassesClass> &arr, int ano);

};


#endif //UNTITLED_STUDENTSCLASSESCLASS_H

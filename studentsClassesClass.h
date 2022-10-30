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

    static bool strcomp0(string a, string b);
    static bool strcomp1(string a, string b);
    static int ocupacaoTurma(const string cadeira, string turma, const vector<studentsClassesClass>& arr);
    static void ocupacaoUcsAno(const vector<studentsClassesClass>& arr, int ano);
    static void ocupacaoUc(const vector<studentsClassesClass>& arr, string cadeira);
    static void estudantesTurma(const vector<studentsClassesClass>& arr, string turma);
    static void estudantesEmUcsAno(const vector<studentsClassesClass>& arr, int ano);
    static void todosEstudantes(const vector<studentsClassesClass>& arr);
    static void estudantesUC(const vector<studentsClassesClass>& arr, string cadeira);
    static void turmasUC(const vector<studentsClassesClass>& arr, string uc);
    static void pedidoAlteracaoHorario(const string nome, const string cadeira, const string novaTurma, vector<studentsClassesClass> &arr, vector<classesClass> &arr2);
    static bool diferencaDeAlunosTurma(const string cadeira, const vector<studentsClassesClass>& arr);
    static void adicionarEstudante(const string nome, const string cadeira, const string turma, vector<studentsClassesClass>& arr);
    static void removerEstudante(const string nome, const string cadeira, vector<studentsClassesClass>& arr);
    static void alteraçaoVariasTurmas( vector<studentsClassesClass> &arr);
    static void verificarFinalDoDia(vector<studentsClassesClass> &arr, vector<classesClass> &arr2);

    static void turmaAluno(const vector<studentsClassesClass> &arr, string nome);
    static void horarioEstudante(const vector<studentsClassesClass>& arr1, const vector<classesClass>& arr2, string nomeEstudante);
    static bool verificaSobreposicao(const vector<studentsClassesClass>& arr1, const vector<classesClass>& arr2, string nomeEstudante);

};


#endif //UNTITLED_STUDENTSCLASSESCLASS_H

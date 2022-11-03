#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <set>
#include "studentsClassesClass.h"
#include "classesClass.h"

using namespace std;

///funcao para comparar strings
bool studentsClassesClass::strcomp0(string a, string b){
    return a<b;
}
///funcao para comparar ints
bool studentsClassesClass::strcomp1(string a, string b) {
    return a > b;
}

///Horário de determinado estudante

void studentsClassesClass::horarioEstudante(const vector<studentsClassesClass>& arr1, const vector<classesClass>& arr2, string nomeEstudante) {
    string turmaAtual;
    string cadeiraAtual;
    vector<classesClass> v1;
    vector<classesClass> v2;
    vector<classesClass> v3;
    vector<classesClass> v4;
    vector<classesClass> v5;
    for (auto x: arr1) {
        if (x.StudentName.compare(nomeEstudante) == 0) {
            turmaAtual = x.ClassCode;
            cadeiraAtual = x.UcCode;
            for (auto y: arr2) {
                int n1 = y.ClassCode.compare(turmaAtual);
                int n2 = y.UcCode.compare(cadeiraAtual);
                if (n1 == 0 && n2 == 0) {
                    if (y.Weekday.compare("Monday") == 0) {
                        v1.push_back(y);
                        sort(v1.begin(), v1.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Tuesday") == 0) {
                        v2.push_back(y);
                        sort(v2.begin(), v2.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Wednesday") == 0) {
                        v3.push_back(y);
                        sort(v3.begin(), v3.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Thursday") == 0) {
                        v4.push_back(y);
                        sort(v4.begin(), v4.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Friday") == 0) {
                        v5.push_back(y);
                        sort(v5.begin(), v5.end(), classesClass::intcomp);
                    }

                }

            }
        }

    }
    if (v1.size() + v2.size() + v3.size()+v4.size()+v5.size()==0) cout << "There is no student with the name " << nomeEstudante << "." << endl;

    for (const auto &n: v1) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v2) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v3) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v4) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v5) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
}

///Verifica a sobreposição de horário de determinado estudante

bool studentsClassesClass::verificaSobreposicao(const vector<studentsClassesClass>& arr1, const vector<classesClass>& arr2, string nomeEstudante){
    vector<classesClass> v1;
    vector<classesClass> v2;
    vector<classesClass> v3;
    vector<classesClass> v4;
    vector<classesClass> v5;
    string turmaAtual;
    string cadeiraAtual;

    for (auto x: arr1) {
        if (x.StudentName.compare(nomeEstudante) == 0) {
            turmaAtual = x.ClassCode;
            cadeiraAtual = x.UcCode;
            for (auto y: arr2) {
                int n1 = y.ClassCode.compare(turmaAtual);
                int n2 = y.UcCode.compare(cadeiraAtual);
                if (n1 == 0 && n2 == 0) {
                    if (y.Weekday.compare("Monday") == 0) {
                        v1.push_back(y);
                        sort(v1.begin(), v1.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Tuesday") == 0) {
                        v2.push_back(y);
                        sort(v2.begin(), v2.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Wednesday") == 0) {
                        v3.push_back(y);
                        sort(v3.begin(), v3.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Thursday") == 0) {
                        v4.push_back(y);
                        sort(v4.begin(), v4.end(), classesClass::intcomp);
                    }
                    if (y.Weekday.compare("Friday") == 0) {
                        v5.push_back(y);
                        sort(v5.begin(), v5.end(), classesClass::intcomp);
                    }

                }

            }
        }

    }

    int i = 0;
    while(i+1 != v1.size()){
        if ( v1[i].Type == "TP" &&  v1[i+1].Type == "TP" && (v1[i].StartHour + v1[i].Duration) > v1[i+1].StartHour ) return false; // tem sobreposição
        else return true; //não tem sobreposição
    }
    i = 0;
    while(i+1 != v2.size()){
        if ( v2[i].Type == "TP" &&  v2[i+1].Type == "TP" && (v2[i].StartHour + v2[i].Duration) > v2[i+1].StartHour ) return false;
        else return true;
    }
    i = 0;
    while(i+1 != v3.size()){
        if ( v3[i].Type == "TP" &&  v3[i+1].Type == "TP" && (v3[i].StartHour + v3[i].Duration) > v3[i+1].StartHour ) return false;
        else return true;
    }
    i = 0;
    while(i+1 != v4.size()){
        if ( v4[i].Type == "TP" &&  v4[i+1].Type == "TP" && (v4[i].StartHour + v4[i].Duration) > v4[i+1].StartHour ) return false;
        else return true;
    }
    i = 0;
    while(i+1 != v5.size()){
        if ( v5[i].Type == "TP" &&  v5[i+1].Type == "TP" && (v5[i].StartHour + v5[i].Duration) > v5[i+1].StartHour ) return false;
        else return true;
    }
    return false; //se não entrar em algum while verificar.
}

void studentsClassesClass::ocupacaoTurmaCout(const string cadeira, string turma, const vector<studentsClassesClass>& arr){
    int acc=0;
    for (const auto& x:arr){
        int i = x.UcCode.compare(cadeira);
        int j = x.ClassCode.compare(turma);
        if (i==0 && j==0){
            acc++;
        }
    }

    cout << "Number of people in class " << turma << " for UC " << cadeira << ": " << acc << endl;
}

///Numero de estudantes numa turma x (Ocuupação da turma)
int studentsClassesClass::ocupacaoTurma(const string cadeira, string turma, const vector<studentsClassesClass>& arr){
    int acc=0;
    for (const auto& x:arr){
        int i = x.UcCode.compare(cadeira);
        int j = x.ClassCode.compare(turma);
        if (i==0 && j==0){
            acc++;
        }
    }

    //cout << "Number of people in class " << turma << " for UC " << cadeira << ": " << acc << endl;

    return acc;
}

void studentsClassesClass::removerEstudante(const string nome, const string cadeira, vector<studentsClassesClass>& arr){
    int i=0;
    string turma;
    int flag = 0;
    for (const auto& x: arr){
        if (x.StudentName == nome && x.UcCode == cadeira){
            turma = x.ClassCode;
            arr[i].ClassCode = "NoClass";
            i++;
            flag = 1;
        }
        i++;
    }
    if (flag == 0) {
        cout << nome << "is not in that UC so He / She can't change classes." << endl;
        return;
    }
    cout << nome << " no longer has a class in " <<  cadeira <<  endl;

}

void studentsClassesClass::adicionarEstudante(const string nome, const string cadeira, const string turma, vector<studentsClassesClass>& arr){
    int i=0;
    for (const auto& x: arr){
        if (x.StudentName == nome && x.ClassCode == "NoClass" && x.UcCode == cadeira){
            arr[i].ClassCode = turma;
        }
        i++;
    }
    cout << nome << " has been added to new class " << turma << " for UC " << cadeira << endl;
}

bool studentsClassesClass::diferencaDeAlunosTurma(const string cadeira, const vector<studentsClassesClass>& arr){
    vector<string> v;
    int maior = INT_MIN;
    int menor = INT_MAX;

    for (const auto& x: arr){
        if (x.UcCode.compare(cadeira) == 0 && !(find(v.begin(), v.end(), x.ClassCode) != v.end()) ){
            v.push_back(x.ClassCode);
        }
    }
    sort(v.begin(), v.end(), strcomp0);
    for (const auto& y: v) {
        if (ocupacaoTurma(cadeira, y, arr) > maior) maior = ocupacaoTurma(cadeira, y, arr);
        if (ocupacaoTurma(cadeira, y, arr) < menor) menor = ocupacaoTurma(cadeira, y, arr);
    }
    if ( maior - menor < 50) return true;
    return false;
}

void studentsClassesClass::pedidoAlteracaoHorario(const std::string nome, const std::string cadeira,const std::string novaTurma,vector<studentsClassesClass> &arr, vector<classesClass> &arr2) {
    int Cap = 50;
    int n_alunosTurma = ocupacaoTurma(cadeira, novaTurma, arr);


    if (!verificaSobreposicao(arr,arr2,nome)){
        cout << "You couldn't change your schedule because you would have 2 TP's at the same time.";
        return;
    }

    if (diferencaDeAlunosTurma(cadeira, arr) == 0 && n_alunosTurma >= Cap) {
        cout << "You couldn't change classes because diferencaDeAlunosTurma was too great and n_alunosTurma >= Cap.";
        return;
    }
    if (n_alunosTurma >= Cap) {
        cout << "You couldn't change classes because n_alunosTurma >= Cap.";
        return;
    }
    if (diferencaDeAlunosTurma(cadeira, arr) == 0){
        cout << "You couldn't change classes because diferencaDeAlunosTurma was too great.";
        return;
    }



    for (const auto& x : arr){
        if (x.StudentName == nome && x.UcCode == cadeira && verificaSobreposicao(arr,arr2,nome)) {
            removerEstudante(nome,cadeira,arr);
            adicionarEstudante(nome,cadeira,novaTurma,arr);
            return;
        }
    }
    cout << nome << "is not in that UC so He / She can't change classes or that student doesn't exist." << endl;

}

queue<studentsClassesClass> fila;

void studentsClassesClass::alteraçaoVariasTurmas(vector<studentsClassesClass> &arr){
    studentsClassesClass x;
    bool flag = 1;
    cout << "What is the name of the student? || FORMAT: Mafalda" << endl;
    cin >> x.StudentName;
    while(flag) {
        cout << "What is the UC? || FORMAT: L.EIC001" << endl;
        cin >> x.UcCode;
        cout << "What is the new class? || FORMAT:1LEIC01" << endl;
        cin >> x.ClassCode;
        cout << "Your order has been added to the queue ";
        cout << "Do you want to submit any other class change request for this student? Write '1' for 'Yes' or '0' for 'No'. " << endl;
        cin >> flag;
        fila.push(x);
    }
}
void studentsClassesClass:: verificarFinalDoDia(vector<studentsClassesClass> &arr, vector<classesClass> &arr2) {
    if (fila.empty()) cout << "There were schedule change requests today." << endl;
    else {
        while (!fila.empty()) {
            pedidoAlteracaoHorario(fila.front().StudentName, fila.front().UcCode, fila.front().ClassCode, arr, arr2);
            fila.pop();
        }
    }
}

void studentsClassesClass::ocupacaoUcsAno(const vector<studentsClassesClass>& arr, int ano){
    vector<string> v;
    char anoc = '9';
    if (ano==1) anoc = '1';
    if (ano==2) anoc = '2';
    if (ano==3) anoc = '3';
    for (const auto& x: arr){
        if(x.ClassCode.at(0) == anoc && !(find(v.begin(), v.end(), x.StudentName) != v.end())){
            v.push_back(x.StudentName);
        }}
    int acc=0;
    for (auto x: v) acc++;
    cout << "Number of people attending UCs belonging to year " << ano << ": " << acc << endl;
}
///Número de estudantes numa UC x (Ocupação UC)

void studentsClassesClass::ocupacaoUc(const vector<studentsClassesClass>& arr, string cadeira){
    int sum = 0;
    for (const auto& x: arr){
        int i = x.UcCode.compare(cadeira);
        if (i == 0){
            sum++;
        }
    }
    cout << "Number of students in UC " << cadeira << ": " << sum << endl;
}

///Estudantes em determinada turma x

void studentsClassesClass::estudantesTurma(const vector<studentsClassesClass>& arr, string turma){
    string sep = ":";
    set<string> names;
    for (const auto& x: arr){
        if (x.ClassCode.compare(turma) == 0 ){
            names.insert(x.StudentName);
        }
    }
    if (names.empty()){
        cout << "That class doesn't exist, try again" << endl;
    }
    else{
        cout << "The students that belong to class " << turma << " in at least one UC are";

        for (const auto& n: names){
            cout << sep << " " << n;
            sep = ",";
        }
        cout << "." << endl;}
}
void studentsClassesClass::estudantesEmUcsAno(const vector<studentsClassesClass>& arr, int ano){
    string sep = ":";
    set<string> setUC;
    char anoc = '9';
    if (ano==1) anoc = '1';
    if (ano==2) anoc = '2';
    if (ano==3) anoc = '3';
    for (const auto& x: arr){
        if(x.ClassCode.at(0) == anoc ){
            setUC.insert(x.StudentName);
        }
    }
    if (setUC.empty()){
        cout << "No one attending UCs of that year in our database" << endl;
    }
    else{
        cout << "The students attending UCs belonging to year " << ano << " are";
        for (auto x : setUC){
            cout << sep << " " << x;
            sep = ",";

        }
        cout << "." << endl;
        setUC.clear();
    }


}

void studentsClassesClass::todosEstudantes(const vector<studentsClassesClass>& arr){
    string sep = ":";
    set<string> v;
    for (const auto& x: arr){

            v.insert(x.StudentName);

    }
    cout << "All the students that are assigned to at least one UC are: ";
    for (auto x: v){
        cout << sep << " " << x;
        sep = ",";
    }
    cout << endl;
}

///Estudantes em determinada UC x
void studentsClassesClass::estudantesUC(const vector<studentsClassesClass>& arr, string cadeira){
    string sep = ":";
    set<string> v;
    for (const auto& x: arr){
        if (x.UcCode.compare(cadeira) == 0){
            v.insert(x.StudentName);
        }
    }
    if (v.empty()){
        cout << "That UC doesn't exist or doesn't have any students." << endl;
    }
    else{
        cout << "The students that are attending UC " << cadeira << " are: ";


        for (const auto& n: v){
            cout << sep << " " << n;
            sep = ",";
        }

        cout << "." << endl;
        v.clear();
    }
}

///turmas de um estudante; complexidade n
void studentsClassesClass::turmaAluno(const vector<studentsClassesClass>& arr, string nome){
    string sep = ":";
    set<string> v;
    for (const auto& x: arr){
        if (x.StudentName == nome){
            v.insert(x.ClassCode);
        }
    }
    cout << "The UCs assigned to student " << nome << " are: ";
    for (auto x: v){
        cout << sep << " " << x;
        sep = ",";
    }
    cout << endl;
}

///turmas de cada UC
void studentsClassesClass::turmasUC(const vector<studentsClassesClass>& arr, string uc){
    string sep = ":";
    int sum = 0;
    vector<string> v;
    for (const auto& x: arr){
        if (x.UcCode.compare(uc) == 0 && !(find(v.begin(), v.end(), x.ClassCode) != v.end()) ){
            v.push_back(x.ClassCode);
            sum++;
        }
    }
    sort(v.begin(), v.end(), strcomp0);
    if (sum == 0){
        cout << "There is no Uc with that code." << endl;
    }
    else{
        cout << "The classes belonging to UC " << uc << " are";
        for (const auto& n: v){
            cout << sep << " " << n;
            sep = ",";
        }
        cout << ". " << sum << " classes in total." << endl;
    }
}



///Ucs de um estudante; complexidade
set<string> studentsClassesClass::UcsAluno(const vector<studentsClassesClass>& arr, string nome){
    string sep = ":";
    set<string> v;
    for (const auto& x: arr){
        if (x.StudentName == nome){
            v.insert(x.UcCode);
        }
    }
    return v;
}
///complexidade n
void studentsClassesClass::printUcsAluno(const vector<studentsClassesClass>& arr, string nome){
    string sep = ":";

    if (studentsClassesClass::UcsAluno(arr, nome).size() == 0){
        cout << "That student doesn't exist or he isn't assigned to any UCs" << endl;
        return;
    }
    cout << "The UCs that the student " << nome <<  " is assigned to are " ;
    for (auto x: studentsClassesClass::UcsAluno(arr, nome)){
        cout << sep << " " << x;
        sep = ",";
    }
    cout << endl;
}
///complexidade n
void studentsClassesClass::estudantesNUcsAlfabeto(vector<studentsClassesClass> &arr, int n){
    string sep = ":";
    set<string> v;
    for (const auto& x: arr){
        if (studentsClassesClass::UcsAluno(arr, x.StudentName).size() > n){
            v.insert(x.StudentName);
        }
    }

    if (v.size() == 0){
        cout << "There aren't any student with more than " << n << " UCs" << endl;
        return;
    }

    cout << "The students that have at least more than " << n << " Ucs are ";
    for (auto x: v){
        cout << sep << " " << x;
        sep = ",";
    }
    cout << endl;
}











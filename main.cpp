#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <cstring>
#include <set>
#include "studentsClassesClass.h"
#include "classesPerUcClass.h"
#include "classesClass.h"

using namespace std;

///Função que dá print out para um ou mais ficheiros. Complexidade O(n).
///@param classesArr - vetor que contém o código da turma e da respetiva Uc, como também a hora de começo das aulas, a sua duração e o tipo de aula.
///@param studentsClassesArr - vetor que contém o código e o nome dos estudantes e as Ucs e respetivas turmas em que estão inscritos.
///@param classesPerUcArr - vetor que contém as Ucs e as turmas associadas.
void DarOutput(vector<classesClass>& classesArr, vector<studentsClassesClass>& studentsClassesArr, vector<classesPerUcClass> classesPerUcArr) {
    ofstream output1("new_classes.csv");
    if (output1.is_open()){
        output1 << "ClassCode" << "," << "UcCode" << "," << "Weekday" << "," << "StartHour" << "," << "Duration" << "," << "Type" << endl;
        for (auto x:classesArr){
            output1 << x.ClassCode << "," << x.UcCode << "," << x.Weekday << "," << x.StartHour << "," << x.Duration << "," << x.Type << endl;
        }
    }
    output1.close();

    ofstream output2("new_students_classes.csv");
    if (output2.is_open()){
        output2 << "StudentCode" << "," << "StudentName" << "," << "UcCode" << "," << "ClassCode" << endl;
        for (auto x:studentsClassesArr){
            output2 << x.StudentCode << "," << x.StudentName << "," << x.UcCode << "," << x.ClassCode << endl;
        }
    }
    output2.close();

    ofstream output3("new_classes_per_uc.csv");
    if (output3.is_open()){
        output3 << "UcCode" << "," << "ClassCode" << endl;
        for (auto x:classesPerUcArr){
            output3 << x.UcCode << "," << x.ClassCode << endl;
        }
    }
    output3.close();
}


///Local que contém o menu. Passa os dados dos ficheiros para vetores.
int main() {
    classesClass classesClass1;
    classesPerUcClass classesPerUcClass1;
    studentsClassesClass studentsClassesClass1;

    ifstream myFile;
    string CurrentLine;   // string usada para ler os ficheiros

    //Passar ficheiro Classes para vetor ArrClasses

    vector<classesClass> ArrClasses;
    classesClass classe;

    myFile.open("../classes.csv");
    getline(myFile, CurrentLine);
    string tempClassString; // string criada para poder copiar ints como classes.StartHour e classe.Duration para uma string

    while (getline(myFile, CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, classe.ClassCode, ',');
        getline(inputString, classe.UcCode, ',');
        getline(inputString, classe.Weekday, ',');

        getline(inputString, tempClassString, ',');
        classe.StartHour = atoi(tempClassString.c_str());

        tempClassString = "";
        getline(inputString, tempClassString, ',');
        classe.Duration = atoi(tempClassString.c_str());

        getline(inputString, classe.Type, ',');
        if (classe.Type.back() == '\r') classe.Type.pop_back();
        ArrClasses.push_back(classe);

        CurrentLine = "";
    }
    myFile.close();
    CurrentLine = "";

    //Passar ficheiro ClassesPerUc para vetor ArrClassesPerUc
    vector<classesPerUcClass> ArrClassesPerUc;
    classesPerUcClass classPerUc;

    myFile.open("../classes_per_uc.csv");
    getline(myFile, CurrentLine);
    while (getline(myFile, CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, classPerUc.UcCode, ',');
        getline(inputString, classPerUc.ClassCode, ',');
        if (classe.ClassCode.back() == '\r') classe.ClassCode.pop_back();
        ArrClassesPerUc.push_back(classPerUc);
        CurrentLine = "";
    }
    myFile.close();
    CurrentLine = "";

    //Passar ficheiro StudentsClasses para vetor ArrStudentsClasses

    vector<studentsClassesClass> ArrStudentsClasses;
    studentsClassesClass studentClasses;

    myFile.open("../students_classes.csv");
    getline(myFile, CurrentLine);

    while (getline(myFile, CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, studentClasses.StudentCode, ',');
        getline(inputString, studentClasses.StudentName, ',');
        getline(inputString, studentClasses.UcCode, ',');
        getline(inputString, studentClasses.ClassCode, ',');
        if (classe.ClassCode.back() == '\r') classe.ClassCode.pop_back();
        ArrStudentsClasses.push_back(studentClasses);
        CurrentLine = "";
    }


    string stringResposta;
    int intResposta;
    while (stringResposta != "q"){
        cout << "========================= What action do you wish to do? =========================" << endl;
        cout << "Actions related to students (Students in UCs, Classes,...) - [PRESS 1]" << endl;
        cout << "Actions related to UCs (Occupation of UC,Classes Per UC, All UCs,...) - [PRESS 2]" << endl;
        cout << "Actions related to Classes (Occupation of Class,...) - [PRESS 3]" << endl;
        cout << "Request to add classes to schedule or leave classes - [PRESS 4]" << endl;
        cout << "If the day has come to an end - [PRESS f]" << endl;
        cout << "If you want to exit the menu - [PRESS q]" << endl;
        cout << "==================================================================================" << endl;
        cin >> stringResposta;
        if(stringResposta=="q"){
            DarOutput(ArrClasses,ArrStudentsClasses,ArrClassesPerUc);
            break;
        }
        if (stringResposta == "f") studentsClassesClass::verificarFinalDoDia(ArrStudentsClasses, ArrClasses);
        else if (stringResposta == "1"){
            while (stringResposta != "e"){
                intResposta=0;
                cout << "================= What action do you wish to do? =================" << endl;
                cout << "If you want to see which students are in a certain class [PRESS 1]" << endl;
                cout << "If you want to see all students [PRESS 2]" << endl;
                cout << "If you want to see all students belonging to a year [PRESS 3]" << endl;
                cout << "If you want to see all students from an UC [PRESS 4]" << endl;
                cout << "If you want to see the schedule of a student [PRESS 5]" << endl;
                cout << "If you want to see the classes a student attends [PRESS 6]" << endl;
                cout << "If you want to see the Ucs a student has [PRESS 7]" << endl;
                cout << "If you want to see the students with more than n Ucs [PRESS 8]" << endl;
                cout << "If the day has come to an end - [PRESS f]" << endl;
                cout << "If you want to go back - [PRESS e]" << endl;
                cout << "==================================================================" << endl;
                cin >> stringResposta;
                if (stringResposta == "e") break;
                else if (stringResposta == "f") studentsClassesClass::verificarFinalDoDia(ArrStudentsClasses,ArrClasses);
                else if (stringResposta == "1"){
                    cout << "==============================================" << endl;
                    cout << "Which class do you want see? || FORMAT:1LEIC01" << endl;
                    cout << "==============================================" << endl;
                    cin >> stringResposta;
                    studentsClassesClass::estudantesTurma(ArrStudentsClasses, stringResposta);
                }
                else if (stringResposta == "2"){
                    studentsClassesClass::todosEstudantes(ArrStudentsClasses);
                }
                else if (stringResposta == "3"){
                    cout << "====================================== =" << endl;
                    cout << "Which year do you want see? || FORMAT: 1" << endl;
                    cout << "========================================" << endl;
                    cin >> intResposta;
                    studentsClassesClass::estudantesEmUcsAno(ArrStudentsClasses, intResposta);
                }
                else if (stringResposta == "4"){
                    cout << "============================================" << endl;
                    cout << "Which UC do you want see? || FORMAT:L.EIC001" << endl;
                    cout << "============================================" << endl;
                    cin >> stringResposta;
                    studentsClassesClass::estudantesUC(ArrStudentsClasses, stringResposta);
                }
                else if (stringResposta == "5"){
                    cout << "==========================================================" << endl;
                    cout << "Which students schedule you want to see? || FORMAT:Mafalda" << endl;
                    cout << "==========================================================" << endl;
                    cin >> stringResposta;
                    studentsClassesClass::horarioEstudante(ArrStudentsClasses, ArrClasses, stringResposta);
                }
                else if (stringResposta == "6"){
                    cout << "===================================================" << endl;
                    cout << "Whose classes do you want to see? || FORMAT:Mafalda" << endl;
                    cout << "===================================================" << endl;
                    cin >> stringResposta;
                    studentsClassesClass::turmaAluno(ArrStudentsClasses, stringResposta);
                }
                else if (stringResposta == "7"){
                    cout << "===============================================" << endl;
                    cout << "Whose Ucs do you want to see? || FORMAT:Mafalda" << endl;
                    cout << "===============================================" << endl;
                    cin >> stringResposta;
                    studentsClassesClass::printUcsAluno(ArrStudentsClasses, stringResposta);
                }
                else if (stringResposta == "8"){
                    cout << "==================================================" << endl;
                    cout << "What value of n do you want to input? || FORMAT: 1" << endl;
                    cout << "==================================================" << endl;
                    cin >> intResposta;
                    studentsClassesClass::estudantesNUcsAlfabeto(ArrStudentsClasses, intResposta);
                }
            }
        }
        else if (stringResposta == "2"){
            while (stringResposta != "e"){
                cout << "===================== What action do you wish to do? =====================" << endl;
                cout << "If you want to see the number of students are in UCs from a certain year [PRESS 1]" << endl;
                cout << "If you want to see all UCs [PRESS 2]" << endl;
                cout << "If you want to see all students belonging to an UC [PRESS 3]" << endl;
                cout << "If the day has come to an end - [PRESS f]" << endl;
                cout << "If you want to go back - [PRESS e]" << endl;
                cout << "==========================================================================" << endl;
                cin >> stringResposta;
                if (stringResposta == "e") break;
                if (stringResposta == "f") studentsClassesClass::verificarFinalDoDia(ArrStudentsClasses, ArrClasses);
                if (stringResposta == "1"){
                    cout << "================================================" << endl;
                    cout << "From which year do you want to see? || FORMAT: 1" << endl;
                    cout << "================================================" << endl;
                    cin >> intResposta;
                    studentsClassesClass::ocupacaoUcsAno(ArrStudentsClasses, intResposta);
                }
                if (stringResposta == "2"){
                    classesPerUcClass::todasUcs(ArrClassesPerUc);
                }
                if (stringResposta == "3"){
                    cout << "====================================================" << endl;
                    cout << "From which UC do you want to see? || FORMAT:L.EIC001" << endl;
                    cout << "====================================================" << endl;
                    cin >> stringResposta;
                    studentsClassesClass::ocupacaoUc(ArrStudentsClasses, stringResposta);
                }
            }
        }
        else if (stringResposta == "3"){
            while (stringResposta != "e"){
                cout << "================= What action do you wish to do? =================" << endl;
                cout << "See which classes are in an UC [PRESS 1]" << endl;
                cout << "See how many people are in a class [PRESS 2]" << endl;
                cout << "If you want to go back - [PRESS e]" << endl;
                cout << "==================================================================" << endl;
                cin >> stringResposta;
                if (stringResposta=="1"){
                    cout << "Which UC do you want to choose? || FORMAT:L.EIC001" << endl;
                    cin >> stringResposta;
                    studentsClassesClass::turmasUC(ArrStudentsClasses, stringResposta);
                }
                string stringResposta2;
                if (stringResposta == "2"){
                    cout << "Which UC do you want to choose? || FORMAT:L.EIC001" << endl;
                    cin >> stringResposta;
                    cout << "Which class do you want to choose? || FORMAT:1LEIC01" << endl;
                    cin >> stringResposta2;

                    studentsClassesClass::ocupacaoTurmaCout(stringResposta, stringResposta2, ArrStudentsClasses);
                }

            }}
        else if (stringResposta == "4") {
            while (stringResposta != "e") {
                cout << "================= What action do you wish to do? =================" << endl;
                cout << "If you want to remove a student from a class [PRESS 1]" << endl;
                cout << "If you want to add a student to a class [PRESS 2]" << endl;
                cout << "If you want to go back - [PRESS e]" << endl;
                cout << "==================================================================" << endl;
                cin >> stringResposta;
                string stringResposta2;
                if (stringResposta == "1") {
                    cout << "What is the name of the student || FORMAT:Mafalda" << endl;
                    cin >> stringResposta2;
                    cout << "Which UC do you want to choose? || FORMAT:L.EIC001" << endl;
                    cin >> stringResposta;
                    studentsClassesClass::removerEstudante(stringResposta2, stringResposta, ArrStudentsClasses);
                }

                if (stringResposta == "2") {
                    studentsClassesClass::alteraçaoVariasTurmas(ArrStudentsClasses);
                }

            }
        }
    }
}


//studentsClassesClass1.turmasUC(ArrStudentsClasses,"L.EIC012");
//studentsClassesClass1.estudantesTurma(ArrStudentsClasses, "1LEIC05");
//studentsClassesClass1.ocupacaoTurma("L.EIC002","1LEIC14",ArrStudentsClasses);
//studentsClassesClass1.ocupacaoUc(ArrStudentsClasses, "L.EIC021");
//horarioEstudante(ArrStudentsClasses,ArrClasses, "Rodrigo");
//studentsClassesClass::estudantesEmUcsAno(ArrStudentsClasses, '1');
//studentsClassesClass1.ocupacaoUcsAno(ArrStudentsClasses,'1');
//classesPerUcClass1.todasUcs(ArrClassesPerUc);
//studentsClassesClass1.todosEstudantes(ArrStudentsClasses);
//studentsClassesClass::pedidoAlteracaoHorario("Iara", "L.EIC002", "1LEIC08", ArrStudentsClasses);
//removerEstudante("Jose Jesualdo", "L.EIC023", "3LEIC08", ArrStudentsClasses);
//studentsClassesClass::alteraçaoVariasTurmas(ArrStudentsClasses);

#include <fstream>
#include <iostream>
#include <cstring>
#include "auxiliares.h"
#include "login.h"

using namespace std;

int main(){
    int categoriaLogin = 0;
    int login_value = 0;
    int opcao;
    int periodo;
    registroAluno registroAluno;
    registroProfessor registroProfessor;
    alunoMaterias alunoMaterias;
    turmas turmas;

    do{
        menu({"Registro", "Login", "Info", "Sair"}, true);


        
        opcao = escolha();
        switch(opcao){
            case 1:
                registre();
                break;
            case 2:
                login_value = login(registroAluno.nome,registroAluno.matricula, opcao, registroProfessor.id, registroAluno.periodo);
                if (!login_value){

                }
                else{
                    opcao=4;
                }
                break;
            case 3:
                clear();
                menu({"By: Beto, Betina, Elisa, Thiago"});
                break;
        }
    }while(opcao!=4);

   
        
        if(login_value == 1){
        
            menu({"Notas", "Horarios", "Salas", "Contato", "Escolher Matérias"}, true);
            cout << "Matricula: " << registroAluno.matricula << " ";
            switch(escolha()){
                case 5:
                char materiaVerifica[100];
                char turmaVerifica;
                    ifstream arqTurmas("arquivoTurmas.txt");
                    while(arqTurmas >> turmas.materia >> turmas.turma >> turmas.dia >> turmas.hora1 >> turmas.dia2 >> turmas.hora2 >> 
                    turmas.professor >> turmas.monitor >> turmas.periodo){
                                ifstream arqmaterias("alunoMaterias.txt");
                                while(arqmaterias >> alunoMaterias.matricula >> alunoMaterias.nome >> alunoMaterias.materia >> alunoMaterias.turma){
                                    if(turmas.periodo == registroAluno.periodo && turmas.materia != alunoMaterias.materia){
                                        cout << turmas.materia << " " << turmas.turma << " " << turmas.professor << endl;
                                    }
                                }
                                arqmaterias.close();
                            }
                           
                            
                            cout << "Digite a materia" << endl;
                            cin.getline(materiaVerifica,100);
                            cout << "Digite a turma" << endl;
                            cin >> turmaVerifica;

                            ofstream arqmateriassalva("alunoMaterias.txt");
                                arqmateriassalva << registroAluno.matricula << " " << registroAluno.nome << " " << materiaVerifica << " " << turmaVerifica;
                            arqmateriassalva.close();
                        }
                     
                    }
                    
            
            
          
        
        }else if(login_value == 2){

            menu({"Registrar materias novas", "Atualizar notas", "Horarios de aula", "Contato"}, true);
            cout << "ID: " << registroProfessor.id << endl;
            switch(escolha()){
                case 1:
					turmas turmas;
					int verifica;
					menu({"Escreva a materia"});
					cin.getline(turmas.materia,100);
					menu({"Escreva a turma"}); 
					cin >> turmas.turma;
					cin.ignore();
					menu({"Escreva o dia"}); 
					cin.getline(turmas.dia,100);
					menu({"Escreva o horario"}); 
					cin.getline(turmas.hora1,100);
					menu({"adicionar outro dia de aula?"}); 
					menu({"Sim", "Não"}, true, false); 
					cin >> verifica;
					if(verifica == 1){
						menu({"Escreva o dia"});
						cin.ignore();
						cin.getline(turmas.dia2,100);
						menu({"Escreva o horario"});
						cin.getline(turmas.hora2,6);
					}
					else{
						strcpy(turmas.dia2,"0");
						strcpy(turmas.hora2,"0");
					}
					menu({"Escreva a matricula do monitor"});
					cin >> turmas.monitor;
                    menu({"Escreva o período da matéria"});
                    cin >> turmas.periodo;
					ofstream arq;
					arq.open("arquivoTurmas.txt", ios::app);
					arq << turmas.materia << " " << turmas.turma << " " << turmas.dia << " " << turmas.hora1 << " " <<
					turmas.dia2 << " " << turmas.hora2 << " " << registroProfessor.id << " " << turmas.monitor << " " << turmas.periodo << " ";
					arq.close();
					break;

                case 2:

                    char materiaVerifica[100];
                    char turmaVerifica;
                    int matriculaVerifica;
                    int NP1Verifica, NP2Verifica;
                    int provaVerifica;
                    notas notas;

                    ifstream arqMateriasProfessor("arqTurmas.txt");
                    while(arqMateriasProfessor >> turmas.turma >> turmas.materia >> turmas.dia >> turmas.hora1 >> turmas.dia2 >> turmas.hora2 >> 
                    turmas.professor >> turmas.monitor >> turmas.periodo){
                        if(turmas.professor == registroProfessor.id){
                            cout << turmas.materia << " " << turmas.professor << " " <<< endl;
                        }
                    }
                            cout << "Digite a materia" << endl;
                            cin.getline(materiaVerifica,100);
                            cout << "Digite a turma" << endl;
                            cin >> turmaVerifica;

                    ifstream alunosMaterias("alunosMaterias.txt");
                    while(alunosMaterias >> alunosMaterias.matricula >> alunosMaterias.nomeAluno >> alunosMaterias.materia
                     >> alunosMaterias.turma){
                        if(strcmp(materiaVerifica, alunosMaterias.materia) == 0 && alunosMaterias.turma = turmaVerifica){
                            cout << alunosMaterias.matricula << " " << alunosMaterias.nomeAluno << endl;
                          } 
                        }
                    cout << "Digite a matricula do aluno que deseja adicionar nota da prova" << endl;
                    cin >> matriculaVerifica;

                        do{
                        cout << "Digite a nota da NP1";
                        cin >> NP1Verifica;
                        if(NP1Verifica > 100 || NP1Verifica < 0){
                            cout << "Nota inválida!"
                        }
                        }while(NP1Verifica > 100 || NP1Verifica < 0);

                        do{
                        cout << "Digite a nota da NP2";
                        cin >> NP2Verifica;
                        if(NP1Verifica > 100 || NP1Verifica < 0){
                            cout << "Nota inválida!"
                        }
                   
                    }while(NP2Verifica > 100 || NP2Verifica < 0);

                    }
                    ofstream alunosNotas("alunoNotas.txt");
                    alunosNotas << matriculaVerifica << " " << materiaVerifica << " " << turmaVerifica << " "
                    << NP1Verifica << " " << NP2Verifica << " ";
                        arq.close();
                        }
                     }
                    
                    
                    break;
			
            
        }else if(login_value == 3){
            menu({"Notas", "Horarios", "Salas", "Contato", "Atualizar notas", "Escolher matérias", "Atualizar notas"}, true);
            cout << "Matricula: " << registroAluno.matricula << endl;
            switch(escolha()){
                
            }
           }
}

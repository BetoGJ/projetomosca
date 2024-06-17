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
    registroAluno registroAluno;
    registroProfessor registroProfessor;

    do{
        menu({"Registro", "Login", "Info", "Sair"}, true);


        
        opcao = escolha();
        switch(opcao){
            case 1:
                registre();
                break;
            case 2:
                login_value = login(registroAluno.matricula, categoriaLogin, registroProfessor.id);
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

    if(login!=0){
        if(categoriaLogin==1){
            menu({"Notas, Horarios, Salas, Contato"}, true);
            cout << "Matricula: " << registroAluno.matricula;
            escolha();
        }

        else if(categoriaLogin==2){
            menu({"Registrar materias novas", "Atualizar notas", "Horarios de aula", "Contato"}, true);
            cout << "ID: " << registroProfessor.id;
            switch(escolha()){
                case 1:
					turmas turmas;
					int verifica;
					cin.ignore();
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
					menu({"Sim", "Não"}, true); 
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
					ofstream arq;
					arq.open("arquivoTurmas.txt", ios::app);
					arq << turmas.materia << " " << turmas.turma << " " << turmas.dia << " " << turmas.hora1 << " " <<
					turmas.dia2 << " " << turmas.hora2 << " " << registroProfessor.id << " " << turmas.monitor << " ";
					arq.close();
					break;
			}
                
        }
        else if(categoriaLogin==3){
            menu({"Notas, Horarios, Salas, Contato, Atualizar notas"}, true);
            cout << "Matricula: " << registroAluno.matricula;
            escolha();
        }

    }
}
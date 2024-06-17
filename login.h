#ifndef login_h
#define login_h

#include "auxiliares.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


struct registroAluno {
    string nome;
    string senha;
    int matricula;
    int periodo;
    int numero_de_materias;
};

struct registroProfessor {
    string nome;
    int id;
    string senha;
};

struct turmas{
		char turma;
		char materia[100];
		char hora1[100];
		char hora2[100];
		char dia[100];
		char dia2[100];
		int professor;
		int monitor;
        int periodo;
	};
struct notas{
    int alunoMat;
    char materia[100];
    char turma;
    int NP1;
    int NP2;
};
struct alunoMaterias{
    int matricula;
    char nome[100];
    char materia[100];
    char turma;
};
void registre() {
   
	menu({"Aluno", "Professor"}, false);
    int categoria = escolha();
    while (categoria < 1 || categoria > 2) {
        menu({"Insira sua categoria novamente"});
        categoria = escolha();
    }
    if (categoria == 1) {
        registroAluno aluno;
        menu({"Digite seu nome"});
        getline(cin, aluno.nome);
        menu({"Digite sua senha"});
        getline(cin, aluno.senha);
        menu({"Digite sua matricula"});
        cin >> aluno.matricula;
        menu({"Digite seu periodo"});
        cin >> aluno.periodo;
        ofstream arq("arquivoAlunos.txt", ios::app);
        arq << aluno.nome << " " << aluno.senha << " " << aluno.matricula << " " << aluno.periodo << " ";
        arq.close();
    } else if (categoria == 2) {
        registroProfessor professor;
        menu({"Digite seu nome"});
        getline(cin, professor.nome);
        menu({"Digite sua senha"});
        getline(cin, professor.senha);
        menu({"Digite seu id"});
        cin >> professor.id;
        ofstream arq("arquivoProfessores.txt", ios::app);
        arq << professor.nome << " " << professor.senha << " " << professor.id << " ";
        arq.close();
    }
}

int login(string &nomeAluno, int &matricula, int &categoria, int &id, int &periodo) {
    string senha;
    string senha2;
    int matricula2;
    int id2;
    string nome;
    bool loginSucesso = false;
    bool alunoMonitor = false;
    turmas turmas;

    menu({"Digite sua categoria"});
    menu({"Aluno", "Professor"}, 1);
    categoria = escolha();

    if (categoria == 1) {
        menu({"Digite sua matrícula: "});
        cin >> matricula;
        menu({"Digite sua senha"});
        cin >> senha;

        ifstream arq("arquivoAlunos.txt");
        while (arq >> nome >> senha2 >> matricula2 >> periodo) {
            if (matricula == matricula2 && senha == senha2) {
                loginSucesso = true;
                nomeAluno = nome;    
                break;
            }
        }
      
        ifstream arqTurmas("arquivoTurmas.txt");
        while (arqTurmas >> turmas.materia >> turmas.turma >> turmas.dia >> turmas.hora1 >> turmas.dia2 >> turmas.hora2
         >> turmas.professor >> turmas.monitor >> turmas.periodo) {

            if (matricula == turmas.monitor) {
                categoria = 3;
                break;
            }
             
        }
        arq.close();


        if (loginSucesso) {

            // Login bem-sucedido, pode adicionar outras ações aqui se necessário
        } else {
            int pause;
            cout << "Senha ou matricula errados!" << endl;
            return 0;
        }
    }
    else if(categoria == 2){
		menu({"Digite seu id"});
		cin >> id;
        cin.ignore();
 		menu({"Digite sua senha"});;
 		getline(cin, senha);
 		
 		ifstream arq("arquivoProfessores.txt");
		while (arq >> nome >> senha2 >> id2) {
            if (id == id2 && senha.compare(senha2) == 0) {		
                loginSucesso = true;
            }
		
		}
        arq.close();
    }
		
		if(loginSucesso){
			return categoria;
		}
        else{
			cout << "Senha ou matricula errados!" << endl;
			return 0;
		}
    }
#endif

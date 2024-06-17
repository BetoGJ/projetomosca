#ifndef login_h
#define login_h

#include "auxiliares.h"
#include <iostream>
#include <fstream>
#include <string>

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
		char Professor[100];
		int monitor;
	};

void registre() {
    menu({"Digite sua categoria"});
	menu({"Aluno", "Professor"}, true);
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
        cin.ignore();
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

int login(int &matricula, int &categoria, int &id) {
    string senha;
    string senha2;
    int matricula2;
    int id2;
    string nome;
    categoria = 0;
    int periodo;
    bool loginSucesso = false;
    bool alunoMonitor = false;
    turmas turmas;

    menu({"Digite sua categoria"});
    menu({"Aluno", "Professor"}, 1);
    categoria = escolha();

    if (categoria == 1) {
        menu({"Digite sua matrícula: "});
        cin >> matricula;
        cin.ignore();
        menu({"Digite sua senha"});
        cin >> senha;

        ifstream arq("arquivoAlunos.txt");
        while (arq >> nome >> senha2 >> matricula2 >> periodo) {
            if (matricula == matricula2 && senha == senha2) {
                loginSucesso = true;
                categoria = 3;
                break;
            }
        }
        arq.close();

        ifstream ("arquivoTurmas.txt");
        while (arq >> turmas.materia >> turmas.turma >> turmas.dia >> turmas.hora1 >> turmas.dia2 >> turmas.hora2
         >> turmas.Professor >> turmas.monitor) {
            if (matricula == turmas.monitor) {
                loginSucesso = true;
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
            cin >> pause;
            return 0;
        }
    }

    // Adicione o tratamento para categoria == 2 (professor) se necessário

    return 0; // Faltou retornar algo no caso geral
}

#endif
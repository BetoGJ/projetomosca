#include <fstream>
#include <iostream>
#include <cstring>
#include "teste.cpp"

void clear(){
	printf("\033c");
}


using namespace std;

	struct registroAluno{
		char nome[100];
		char senha[100];
		int matricula;
		int periodo;
		int numero_de_materias;
	};
	struct registroProfessor{
		char nome[100];
		int id;
		char senha[100];
	};
	struct notas{
		char turma[100];
		int alunoMat;
		int NP1;
		int NP2;
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
	
	void registrar(){

		int i = 0;
		int categoria;

		registroAluno registroAluno;
		registroProfessor registroProfessor;
		clear();
		abluble();
		cout << "------- Digite sua categoria -------" << endl;
 		cout << "------- 1 - Aluno            -------" << endl;
 		cout << "------- 2 - Professor        -------" << endl;
		cin >> categoria;
		cin.ignore();
		clear();
		while(categoria < 1 || categoria > 2){
				clear();
				cout << "------- Insira sua categoria novamente -------" << endl;
				cin >> categoria;
				cin.ignore();
			 }
		clear();
		if(categoria == 1){
			cout << "------- Digite seu nome -------" << endl;
 			cin.getline(registroAluno.nome,100);
 			cout << "------- Digite sua senha -------" << endl;
 			cin.getline(registroAluno.senha,100);
 			cout << "------- Digite sua matricula -------" << endl;
 			cin >> registroAluno.matricula;
			cout << "------- Digite seu periodo -------" << endl;
			cin >> registroAluno.periodo;
		}

		
		else if(categoria == 2){
			cout << "------- Digite seu nome -------" << endl;
 			cin.getline(registroProfessor.nome,100);
 			cout << "------- Digite sua senha -------" << endl;
 			cin.getline(registroProfessor.senha,100);
 			cout << "------- Digite seu id -------" << endl;
 			cin >> registroProfessor.id;
		}
 		
		if(categoria == 1){
 			ofstream arq;
			arq.open("arquivoAlunos.txt", ios::app);
			arq << registroAluno.nome << " " << registroAluno.senha << " " << registroAluno.matricula << " " << " " << registroAluno.periodo << " ";
			arq.close();
		}
		else if(categoria == 2){
			ofstream arq;
			arq.open("arquivoProfessores.txt", ios::app);
			arq << registroProfessor.nome << " " << registroProfessor.senha << " " << registroProfessor.id << " ";
			arq.close();
		}
	};
	
	int loginVerifica(int &matricula, int &categoria, int &id){
		

		char senha[100];
	 	char senha2[100];
	 	int matricula2;
		int id2;
	 	char nome[100];
	    categoria = 0;
		int periodo;
	    bool loginSucesso = false;
	 	clear();
		cout << "------- Digite sua categoria -------" << endl;
 		cout << "------- 1 - Aluno            -------" << endl;
 		cout << "------- 2 - Professor        -------" << endl;
		cin >> categoria;

		if(categoria == 1){
		cout << "------- Digite sua matricula -------" << endl;
		cin >> matricula;
		cin.ignore();
 		cout << "------- Digite sua senha -------" << endl;
 		cin.getline(senha,100);
 		
 		ifstream arq("arquivoAlunos.txt");
				 while (arq >> nome >> senha2 >> matricula2 >> periodo) {
            if (matricula == matricula2 && strcmp(senha, senha2) == 0) {		
	 	 		loginSucesso = true;
			}
		
				 }
				 	 arq.close();
			if(loginSucesso){
				
			}else{
				cout << "Senha ou matricula errados!" << endl;
				return 0;
			}
		}
		if(categoria == 2){
		cout << "------- Digite seu id -------" << endl;
		cin >> id;
		cin.ignore();
 		cout << "------- Digite sua senha -------" << endl;
 		cin.getline(senha,100);
 		
 		ifstream arq("arquivoProfessores.txt");
				 while (arq >> nome >> senha2 >> id2) {
            if (id == id && strcmp(senha, senha2) == 0) {		
	 	 		loginSucesso = true;
			}
		
				 }
				 	 arq.close();
			if(loginSucesso){
				return categoria;
			}else{
				cout << "Senha ou matricula errados!" << endl;
				return 0;
			}
		}
		  
	}

int main(){
	
	int categoriaLogin = 0;
	int login = 0;
	int escolha;
	registroAluno registroAluno;
	registroProfessor registroProfessor;
	
	do{
		clear();
	   	cout << "-------------------------------------" << endl;
	   	cout << "--------       Menu      ------------" << endl;
		cout << "-------- 1 - Registro    ------------" << endl;
		cout << "-------- 2 - Login       ------------" << endl;
		cout << "-------- 3 - Info        ------------" << endl;
		cout << "-------- 4 - Sair        ------------" << endl;
	
 	   	  	cin >> escolha;
	   	 	cin.ignore();
	
 	switch(escolha){
		case 1:
			registrar();
			break;
		
		case 2:
			login = loginVerifica(registroAluno.matricula, categoriaLogin, registroProfessor.id);
			
			if(login == 0){
				
			}
			else{
				escolha = 4;
			}
			break;
		
		case 3:
			clear();
			cout << "By : Beto, Betina, Elisa, Thiago" << endl;
			cout << "----- Mosca corrige com carinho to escrevendo isso num domingo a tarde S2 -----" << endl;
			break;
	}
	}while(escolha != 4);
	
	if(login != 0){
		if(categoriaLogin == 1){
			clear();
			cout << "------" << registroAluno.matricula << "----- Menu do Aluno --------------" << endl;
			cout << "-------------- 1 - Notas --------------" << endl;
			cout << "-------------- 2 - Horarios --------------" << endl;
			cout << "-------------- 3 - Salas --------------" << endl;
			cout << "-------------- 4 - Contato --------------" << endl; 
			cin >> escolha;
		}
		else if(categoriaLogin == 2){
			clear();
			cout << "------" << registroProfessor.id << "----- Menu do Professor --------------" << endl;
			cout << "-------------- 1 - Registrar materias novas --------------" << endl;
			cout << "-------------- 2 - Atualizar notas --------------" << endl;
			cout << "-------------- 3 - Horarios de aula --------------" << endl;
			cout << "-------------- 4 - Contato --------------" << endl; 
			cin >> escolha;
			switch(escolha){
				case 1:
					turmas turmas;
					int verifica;
					cin.ignore();
					cout << "-------------- Escreva a materia --------------" << endl;
					cin.getline(turmas.materia,100);
					cout << "-------------- Escreva a turma --------------" << endl;
					cin >> turmas.turma;
					cin.ignore();
					cout << "-------------- Escreva o dia --------------" << endl;
					cin.getline(turmas.dia,100);
					cout << "-------------- Escreva o horario --------------" << endl;
					cin.getline(turmas.hora1,100);
					cout << "-------------- Deseja adicionar outro dia de aula? --------------" << endl;
					cout << "-------------- 1 - Sim 2 - Não --------------" << endl;
					cin >> verifica;
					if(verifica == 1){
						cout << "-------------- Escreva o dia --------------" << endl;
						cin.ignore();
						cin.getline(turmas.dia2,100);
						cout << "-------------- Escreva o horario --------------" << endl;
						cin.getline(turmas.hora2,6);
					}
					else{
						strcpy(turmas.dia2,"0");
						strcpy(turmas.hora2,"0");
					}
					cout << "-------------- Escreva a matricula do monitor --------------" << endl;
					cin >> turmas.monitor;
					ofstream arq;
					arq.open("arquivoTurmas.txt", ios::app);
					arq << turmas.materia << " " << turmas.turma << " " << turmas.dia << " " << turmas.hora1 << " " <<
					turmas.dia2 << " " << turmas.hora2 << " " << registroProfessor.id << " " << turmas.monitor << " ";
					arq.close();
					break;
			}

	}


}
}

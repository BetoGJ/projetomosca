#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

	struct registro{
		char nome[100];
		char senha[100];
		int matricula;
		int categoria;
		char materia[100];
	};
	
	void registrar(){

		registro registro;
		
		cout << "------- Digite seu nome -------" << endl;
 		cin.getline(registro.nome,100);
 		cout << "------- Digite sua senha -------" << endl;
 		cin.getline(registro.senha,100);
 		cout << "------- Digite sua matricula -------" << endl;
 		cin >> registro.matricula;
 		cout << "------- Digite sua categoria -------" << endl;
 		cout << "------- 1 - Aluno            -------" << endl;
 		cout << "------- 2 - Professor        -------" << endl;
 		cout << "------- 3 - Aluno-Monitor    -------" << endl;
 		cin >> registro.categoria;
 		if(registro.categoria == 2 || registro.categoria == 3){
			 cin.ignore();
		 }
			 while(registro.categoria < 1 || registro.categoria > 3){
				 cout << "------- Insira sua categoria novamente -------" << endl;
				 cin >> registro.categoria;
				 cin.ignore();
			 }
		 
 		if(registro.categoria == 2 || registro.categoria == 3){
			 cout << "------- Insira sua materia -------" << endl;
			 cin.getline(registro.materia,100);
		 }
		 else{
			 strcpy(registro.materia, "0");
		 }
 		
 		ofstream arq;
		 arq.open("arquivo.txt", ios::app);
		 arq << registro.nome << " " << registro.senha << " " << registro.matricula << " "
         << registro.categoria << " " << registro.materia << " ";
		 arq.close();

	};
	
	int loginVerifica(char materia[], int &matricula, int &categoria){
		

		char senha[100];
	 	char senha2[100];
	 	int matricula2;
	 	char nome[100];
	    categoria = 0;
	    char materiaArquivo[100];
	    bool loginSucesso = false;
	 	
		cout << "------- Digite sua matricula -------" << endl;
		cin >> matricula;
		cin.ignore();
 		cout << "------- Digite sua senha -------" << endl;
 		cin.getline(senha,100);
 		
 		ifstream arq("arquivo.txt");
				 while (arq >> nome >> senha2 >> matricula2 >> categoria >> materiaArquivo) {
            if (matricula == matricula2 && strcmp(senha, senha2) == 0) {		
				strcpy(materia, materiaArquivo);	
	 	 		loginSucesso = true;
			}
		
				 }
				 	 arq.close();
			if(loginSucesso == true){
				return categoria;
			}else{
				cout << "Senha ou matricula errados!" << endl;
				return 0;
			}

		  
	}
int main(){
	
	int login = 0;
	int escolha;
	char materia[100];
	registro registro;
	strcpy(registro.materia, "Placeholder");
	
	do{
	
	   	cout << "-------------------------------------" << endl;
	   	cout << "--------       Menu      ------------" << endl;
		cout << "-------- 1 - Registro    ------------" << endl;
		cout << "-------- 2 - Login       ------------" << endl;
		cout << "-------- 3 - Info        ------------" << endl;
		cout << "-------- 4 - Sair        ------------" << endl;
	
 	   	  	cin >> escolha;
	   	 	cin.ignore();
	
 	
 	if(escolha == 1){
 		registrar();
	 }
	 
	 if(escolha == 2){
	 	login = loginVerifica(registro.materia, registro.matricula, registro.categoria);
	 	
		 if(login == 0){
			 
		 }
		 else{
			 escolha = 4;
		 }

	 }
	 if(escolha == 3){
		 cout << "By : Beto, Betina, Elisa, Thiago" << endl;
		 cout << "----- Mosca corrige com carinho to escrevendo isso num domingo a tarde S2 -----" << endl;
	 }
	 
	}while(escolha != 4);
	
	if(login != 0){
		
	}
}
#include <iostream>
#include "Proj_dc.h"

using namespace std;

void menu()
{
	cout<<"Escolha uma das opções abaixo: "<<endl;
	cout<<"1 - Insere início"<<endl;
	cout<<"2 - Insere fim"<<endl;
	cout<<"3 - Remove inicio"<<endl;
	cout<<"4 - Remove fim"<<endl;
	cout<<"5 - Remove valor"<<endl;
	cout<<"6 - Imprime normal"<<endl;
	cout<<"7 - Imprime reverso"<<endl;
	cout<<"Escolha qualquer outro para encerrar o programa"<<endl;
	cout<<"Opção: ";
}

int numb()
{
	int n;
	cout<<"Digite o número que deseja usar: ";
	cin>>n;
	cout<<endl;
	return n;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	Lista* l;
	int op, num;
	
	l = inicializa();
	
	do
	{
		menu();
		cin >> op;
		cout << endl;	
		switch(op)
		{
			case 1:
				num = numb();
				l = insere_inicio(l, num);
				break;
			
			case 2:
				num = numb();
				l = insere_fim(l, num);
				break;
			
			case 3:
				l = remove_inicio(l);
				break;
			
			case 4:
				l = remove_fim(l);
				break;
			
			case 5:
				num = numb();
				l = remove_valor(l, num);
				break;
			
			case 6:
				imprime(l);
				break;
			
			case 7:
				imprime_reverso(l);
				break;
		}
		
	}while(op>=1 && op<=7);
	
	cout<< "Fim do programa\n";
	system("pause");
	return 0;
}

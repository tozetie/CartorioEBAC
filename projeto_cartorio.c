#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string

int registro()
{
	setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	char arquivo[40]; //In�cio das vari�veis 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //Alterar o arquivo
	fprintf(file,nome); //Salva o valor da vari�vel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //Alterar o arquivo
	fprintf(file,sobrenome); //Salva o valor da vari�vel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //Alterar o arquivo
	fprintf(file,cargo); //Salva o valor da vari�vel
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, CPF n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("Cart�rio da EBAC\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); 
	
	if(comparacao == 0)
	{
		system("cls");	
		for(laco=1;laco=1;)
		{
		system("cls");
	
			setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
			printf("Cart�rio da EBAC\n\n"); //In�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n");
			printf("Digite o n�mero correspondente a op��o desejada: ");//Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
			system("cls");
	
			switch(opcao)
			{
				case 1:
				registro();
				break;
			
				case 2:
				consulta();
				break;
		
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema.\n");
				return 0;
				break;
		
				default:
				printf("Esta op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
			}
		}
	}
	else
		printf("Senha incorreta!\n");
}

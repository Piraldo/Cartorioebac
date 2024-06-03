#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das string

int registro()// Função responsável por cadastrar os usuários no sistema
{
	char arquivo[40];
	char cpf[40];//colchetes é string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do user
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//Responsável por copiar os valores das strings
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo tambem kkkk
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a")//atualiza a informação
	;fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ")
	;scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a")//atualiza a informação
	;fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a")//atualiza a informação
	;fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ")
	;scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
	
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo não localizado.\n");
	}
	
	while(fgets(conteudo,200,file)!= NULL)
	{
		printf("\nEstas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não se encontra no sistema.\n");
		system("pause");
		
	}

}
int main()//função principal
{
	int opcao=0;
	int laco=1;//variável de loop que volta para o menu
	
	for(laco=1;laco=1;)//enquanto o valor for 1 ele volta pro menu sempre
	{
		
		system("cls");
	
	
	
		setlocale(LC_ALL,"Portuguese");//local definido como pt pra ter acentos e pa
	
		printf("###Cartório do Guigui###\n\n");//barra N é pra pular linha
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nome\n");//barra T é pra dar espaço na linha
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Deletar nome\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção:");//fim do menu
	
		scanf("%d",&opcao);//armazenar escolha do usuario
	
		system("cls");//limpar a tela
		
		switch(opcao)//função de condição com vários fatores
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
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
			
			default:
			printf("comando inválido.\n");
			system("pause");
			break;	
				
		}//switch case começa com ':' e termina com 'break;'
	
		
	
	
	}
}

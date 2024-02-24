#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidas das string

int registro() //Funcao responsavel por cadastrar os usuarios no sistema
	{
	//Inicio da criacao das variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criacao de variaveis/string

	printf("Digite o CPF a ser cadastrado: "); //Coletando informacao do usuario
	scanf("%s",cpf); //%s Refere-se a string

	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Criando o arquivo e o "w" significa escrever
	fprintf(file,cpf); // Salvo o valor da variavel
	fclose(file); // Fechar o arquivo

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);

	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	printf("\n");
	printf("CPF registrado com sucesso!\n\n");
	system("pause"); 
	}
	
int consultar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];
    char *token; //String para o funcionamente do TOKEN

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("Arquivo não localizado!\n");
        system("pause");
    }

    while (fgets(conteudo, 200, file) != NULL) //Le o arquivo e armazena
	{
        printf("\n");
		printf("Usuário encontrado com sucesso!\n\n");
		
		printf("\nEssas são as informações do usuário:\n");

        token = strtok(conteudo, ","); //Variavel responsavel por dividir as string em linhas
        printf("CPF: %s\n", token);

        token = strtok(NULL, ",");
        printf("Nome: %s\n", token);

        token = strtok(NULL, ",");
        printf("Sobrenome: %s\n", token);

        token = strtok(NULL, ",");
        printf("Cargo: %s\n", token);
    }

    fclose(file);
    system("pause");
}


int deletar()
{
    char cpf[40];
    char confirmacao[5]; //Variável para armazenar a confirmação do usuário

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    printf("Tem certeza que deseja deletar o usuário? (Digite 'Sim' para confirmar): ");
    scanf("%s", confirmacao);

    if (strcmp(confirmacao, "Sim") == 0 || strcmp(confirmacao, "sim") == 0) //Verifica se a confirmação foi bem sucedida
	
	{ 
        remove(cpf);

        FILE *file;
        file = fopen(cpf, "r");

        if (file == NULL) 
		{
            printf("O usuário não se encontra no sistema!\n");
            system("pause");
        } 
		else 
		{
            fclose(file);
            printf("Usuário deletado com sucesso!\n");
            system("pause");
        }
    } else {
        printf("Operação cancelada.\n");
        system("pause");
    }
}	
	

int main ()
{  
		int opcao=0; //Definindo variáveis
		int x=1;
	
		for(x=1;x=1;)
	{
		
			system ("cls");
	
	  		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	  		printf("### Cartório do Guarujá###\n\n"); //Inicio do menu
	  		printf("Escolha a opção desejada do menu:\n\n");
   	   		printf("\t1 - Registrar nomes\n");
	   		printf("\t2 - Consultar nomes\n");
	  		printf("\t3 - Deletar nomes\n\n"); 
	  		printf("Opção: "); //Fim do menu
	
	  		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	  		system("cls"); //Responsavel por limpar a tela
	   
	  	 switch(opcao) //Inicio da selecao
	   		{
	   	case 1:
	   	registro(); //Chamada de funcoes
	   	break; //Interrompe funcao
	   		
	   	case 2:
	   	consultar();//Chamada de funcoes
		break; //Interrompe funcao
		
		case 3:
		deletar();//Chamada de funcoes
		break;//Interrompe funcao
		
		
		default:
		printf("Essa opção não está disponivel!\n");
		system ("pause");
		break;//Interrompe funcao
			} //Fim da selecao
	   
	   
	}
	
}
	   
	   
	

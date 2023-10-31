#include <stdio.h> //biblioteca de comunicação com usúario
#include <stdlib.h> //biblioteca de alocação em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()
{
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s",cpf);
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo,"w"); //Cria o aquivo
    fprintf(file,cpf); //Salvo o valor da variavel
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado");
    scanf("%s",cargo);
    
    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}

int consulta()
{
    setlocale(LC_ALL,"PORTUGUESE"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF as ser consultado! ");
    scanf("%s" ,cpf);
    
    FILE  *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("Não foi possivel abrir o arquivo, não localizado. \n");
    	
	}

     while(fgets(conteudo, 200, file) !=NULL)
    {
     	printf("\n Essas são as informações do usuário: ");
     	printf("%s", conteudo);	 
		printf("\n\n");	  
	}
	
	system("pause");
	
}
     
int deletar()
{
	printf("Você escolheu deletar nomes!");
 	system("pause");
}

int main()
    {
    int opcao=0; //Definindo variáveis
    int laco=1;

    for(laco=1;laco=1;)
    {
    	
    	system("cls");
	
 	    setlocale(LC_ALL,"PORTUGUESE"); //Definindo a linguagem
 	
	    printf("###Cartório da EBAC### \n\n"); //Inicio do menu
    	printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Resgistrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");   
		printf("\t4 - Sair do sistema\n\n");
    	printf("opcao:");//Fim do menu

    	scanf("%d", &opcao); // Armazenando a escolha do usuário
 	
    	system("cls");
    	
    	
    	switch(opcao)
    	{
    	    case 1:  //inicio da seleção
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
			printf("Essa opção não está disponivel!");
  	        system("pause");
			break;  
			//Fim da seleção	
		}
	}

}
	
	

    

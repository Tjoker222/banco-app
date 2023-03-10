#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*PRINCIPAIS BUGS: NO BUGS.*/

typedef char string[100];
typedef char String[500];

//Criação das estruras com cliente

typedef struct 
{
	
	string nome;
	char CPF[12];
	String Enderec;
	char telefone[9];
	int numero_de_contas;
	
	
}tclientes;

//Criação das estruras com conta

typedef struct 
{
	
	int numero_agencia;
	int numero_conta;
	float saldo;
	char cliente[12];
	
}tcontas;

//função que representa o menu do programa

int menu(String opcoes[], int n0p)
{
	int i;
	int op=-1;
	while(op<=0||op>n0p)
	{
		
		printf("MENU\n");
		
		for(i=0;i<n0p;i++)
		{
			
			printf("%i. %s\n", i+1, opcoes[i]);	
				
		}
		
		string str;
		gets(str);
		op = atoi(str);
				
	}
	
	return op;
	
}


//Função do cadastro do cliente

void cadastro_cliente(int i,tclientes *x, int *tamanho_cliente)
{
	
	system("cls");
	
	int j, val;
	
	printf("Nome completo: ");
	gets(x[i].nome);

	while(strlen(x[i].nome) < 2)
	{	
		printf("Digite um nome válido:\n");
		gets(x[i].nome);
			
	}
		
	printf("\n");
	printf("CPF: ");
	gets(x[i].CPF);
	fflush(stdin);
	
	while(strlen(x[i].CPF) != 11)
	{	
		printf("Digite um CPF válido:\n");
		gets(x[i].CPF);
		fflush(stdin);
			 
	}
	
	
	if(i>0)
	{
		for(j=0;j<i;j++)
		{
			
			val = strcmp(x[i].CPF, x[j].CPF);
			
		}
		
		if(val==0)
		{
			printf("Cliente já cadastrada!\n");
			
			free(&x[i].nome);
			
			free(&x[i].CPF);
			
			getchar();
			fflush(stdin);
			return;
		}
		else
		{
			
			printf("\n");
			printf("Endereço (Rua, Casa, Quadra): ");
			gets(x[i].Enderec);
			
			while(strlen(x[i].Enderec) <=5 )
			{
				printf("Coloque um endereço valido!\n");
				gets(x[i].Enderec);
			}
				
			
			printf("\n");
			printf("Telefone: ");
			gets(x[i].telefone);
			
			while(strlen(x[i].telefone) != 9)
			{
				printf("Coloque um numero de telefone valido!\n");
				gets(x[i].telefone);
			}
			
			printf("\n");
			printf("Cliente Cadastrado com sucesso!");
			getchar();
			fflush(stdin);
			*tamanho_cliente = *tamanho_cliente + 1;
			return;
			
		}
	}
	if(i==0)
	{
		printf("\n");
		printf("Endereço (Rua, Casa, Quadra): ");
		gets(x[0].Enderec);
		fflush(stdin);
		
		while(strlen(x[0].Enderec) <=5 )
			{
				printf("Coloque um endereço valido!\n");
				gets(x[0].Enderec);
			}
			
		printf("\n");
		printf("Telefone: ");
		gets(x[0].telefone);
		
		while(strlen(x[0].telefone) != 9)
			{
				printf("Coloque um numero de telefone valido!\n");
				gets(x[0].telefone);
			}
			
		printf("Cliente Cadastrado com sucesso!");
		printf("\n");
		getchar();
		fflush(stdin);
		*tamanho_cliente = *tamanho_cliente + 1;
		
		return;	
	}
	
}

//Função remover conta de um cliente

void RemoverConta(int i, tcontas *x, tclientes *y, int *tamanho_conta)
{
	system("cls");
	
	int j;
	
	printf("Numero da agencia: ");
	scanf("%d", &x[i].numero_agencia);
	printf("\n");
	printf("Numero da conta: ");
	scanf("%d", &x[i].numero_conta);
	fflush(stdin);
	

	
	if(i>0)
	{	
		for(j=0;j<i;j++)
		{
			
			if(x[i].numero_agencia == x[j].numero_agencia && x[i].numero_conta == x[j].numero_conta)
			{
	   			int k = 0;
	   			int p;
	   			
	   			for(p=0;p<i;p++)
				{
					
					if(x[i].numero_agencia == x[p].numero_agencia)
					{
						free(&x[i].numero_agencia);
				
						free(&x[i].numero_conta);
						
						free(&x[i].saldo);
						
						free(&x[i].cliente);
						
						y[p].numero_de_contas = y[p].numero_de_contas - 1;
						
						continue;
					}
					else
					{
						x[k].numero_agencia = x[p].numero_agencia;
						x[k].numero_conta = x[p].numero_conta;
						x[k].saldo = x[p].saldo;
						strcpy(x[k].cliente, x[p].cliente);
						
						k++;
						
					}
					   	
				   	
				}
				
			
				*tamanho_conta = *tamanho_conta - 1;
								
				printf("Conta removida com sucesso! \n");
				fflush(stdin);
				getchar();
				return;
				
			}
			
		}
		
	}
	
	printf("Conta inválida!");
	getchar();
	return;
	

		
	
}

//Função do cadastro da conta

void cadastro_conta(int i, tcontas *x, tclientes *y, int *tamanho_conta)
{
	
	system("cls");
	
	int j, k, val;
	
	printf("Numero da agencia: ");
	scanf("%d", &x[i].numero_agencia);
	
	while(x[i].numero_agencia > 999)
	{
		printf("Coloque um numero de agencia valido!\n");
		scanf("%d", &x[i].numero_agencia);
	}
	
	
	printf("\n");
	printf("Numero da conta: ");
	scanf("%d", &x[i].numero_conta);
	
	while(x[i].numero_conta > 999999999)
	{
		printf("Coloque um numero de conta valido!\n");
		scanf("%d", &x[i].numero_conta);
	}
	
	printf("\n");
	
	fflush(stdin);
	
	if(i>0)
	{
		
		for(j=0;j<i;j++)
		{
			
			if(x[i].numero_agencia == x[j].numero_agencia && x[i].numero_conta == x[j].numero_conta)
			{
				
				printf("Conta já cadastrada! \n");
				fflush(stdin);
				getchar();
				return;
				
			}
			
		}
		
	}
	
	
	printf("\n");
	printf("Cliente (CPF): ");
	gets(x[i].cliente);
	
	while(strlen(x[i].cliente) != 11)
	{	
		printf("Digite um cliente válido:\n");
		gets(x[i].cliente);
			 
	}
	
	printf("\n");
	
	
	for(j=0;j<=i;j++)
	{
		
		val = strcmp(x[i].cliente, y[j].CPF);
		printf("%s \n",x[i].cliente );
		printf("%s \n",y[j].CPF );
		k = j;
		
		if(val==0)
		{
			printf("Conta criada com sucesso!\n");
			printf("Saldo: %f\n", x[i].saldo);
			*tamanho_conta = *tamanho_conta + 1;
			y[k].numero_de_contas = y[k].numero_de_contas + 1;
			printf("%d",y[k].numero_de_contas);
			getchar();
			break;
			return;
		}
		

		
	}
	if(val!=0)
	{
		printf("Conta invalida!\n");
		free(&x[i].cliente);
		
		free(&x[i].numero_agencia);
				
		free(&x[i].numero_conta);
			
		getchar();
		return;
	}

	
}

//FUNÇÃO MOSTRAR SALDO

void mostrar_saldo(int i, tcontas *x)
{
	
	system("cls");
	
	int c,a, j, aux, val;
	
	if(i>0)
	{
		printf("Numero da agencia: ");
		scanf("%d", &a);
		
		while(a > 999)
		{
			printf("Coloque um numero de agencia valido!\n");
			scanf("%d", &a);
		}
		
		
		printf("\n");
		printf("Numero da conta: ");
		scanf("%d", &c);
		
		while(c > 999999999)
		{
			printf("Coloque um numero de conta valido!\n");
			scanf("%d", &c);
		}
		
		printf("\n");
		
		fflush(stdin);
		
		
		for(j=0;j<i;j++)
		{
		
			if(c==x[j].numero_conta && a==x[j].numero_agencia)
			{
				
				aux = j;
				val = 0;
				break;
				
			}
		}
		
		if(val!=0)
		{
			printf("Conta inexistente!");
			fflush(stdin);
			getchar();
			return;
		}
	
	}
	else
	{
		printf("Não há contas cadastradas");
		fflush(stdin);
		getchar();
		return;
	}
	
	
	printf("O saldo da conta %d: %.3f\n", c, x[aux].saldo);
	printf("%d\n", aux);
	fflush(stdin);
	getchar();
	return;
	
}

//FUNÇÃO DEPOSITO

void deposito(int i, tcontas *x)
{
	
	system("cls");
	
	int c,a, j, aux, val;
	float dep;
	
	if(i>0)
	{
		printf("Numero da agencia: ");
		scanf("%d", &a);
		
		while(a > 999)
		{
			printf("Coloque um numero de agencia valido!\n");
			scanf("%d", &a);
		}
		
		
		printf("\n");
		printf("Numero da conta: ");
		scanf("%d", &c);
		
		while(c > 999999999)
		{
			printf("Coloque um numero de conta valido!\n");
			scanf("%d", &c);
		}
		
		printf("\n");
		
		fflush(stdin);
		
		
		for(j=0;j<i;j++)
		{
		
			if(c==x[j].numero_conta && a==x[j].numero_agencia)
			{
				
				aux = j;
				val = 0;
				break;
				
			}
		}
		
		if(val!=0)
		{
			printf("Conta inexistente!");
			fflush(stdin);
			getchar();
			return;
		}
		
		printf("Digite o valor que será depositado:\n");
		scanf("%f", &dep);
		
		x[aux].saldo = x[aux].saldo + dep;
		
		printf("Valor depositado: %.3f\n", dep);
		printf("Novo saldo da conta %d: %.3f", c, x[aux].saldo);
		fflush(stdin);
		getchar();
		return;
	
	}
	else
	{
		printf("Não há contas cadastradas");
		fflush(stdin);
		getchar();
		return;
	}
	
	
	
}

//FUNÇÃO SAQUE

void saque(int i, tcontas *x)
{
	
	system("cls");
	
	int c,a, j, aux, val;
	float sac;
	
	if(i>0)
	{
		printf("Numero da agencia: ");
		scanf("%d", &a);
		
		while(a > 999)
		{
			printf("Coloque um numero de agencia valido!\n");
			scanf("%d", &a);
		}
		
		
		printf("\n");
		printf("Numero da conta: ");
		scanf("%d", &c);
		
		while(c > 999999999)
		{
			printf("Coloque um numero de conta valido!\n");
			scanf("%d", &c);
		}
		
		printf("\n");
		
		fflush(stdin);
		
		
		for(j=0;j<i;j++)
		{
		
			if(c==x[j].numero_conta && a==x[j].numero_agencia)
			{
				
				aux = j;
				val = 0;
				break;
				
			}
		}
		
		if(val!=0)
		{
			printf("Conta inexistente!");
			fflush(stdin);
			getchar();
			return;
		}
		
		printf("Digite o valor que será sacado:\n");
		scanf("%f", &sac);
		
		if(sac > x[aux].saldo)
		{
			printf("Saldo insuficiente\n");
			fflush(stdin);
			getchar();
			return;
		}
		
		x[aux].saldo = x[aux].saldo - sac;
		
		printf("Valor sacado: %.3f\n", sac);
		printf("Novo saldo da conta %d: %.3f", c, x[aux].saldo);
		fflush(stdin);
		getchar();
		return;
	
	}
	else
	{
		printf("Não há contas cadastradas");
		fflush(stdin);
		getchar();
		return;
	}	
	
	
	
}

//FUNÇÃO TRASNFERÊNCIA

void transferencia(int i, tcontas *x)
{
	
	system("cls");
	
	int c1,a1, j, aux1, val, c2, a2, aux2;
	float trans;
	
	if(i>0)
	{
		printf("CONTA DE ORIGEM:\n");
		
		printf("Numero da agencia: ");
		scanf("%d", &a1);
		
		while(a1 > 999)
		{
			printf("Coloque um numero de agencia valido!\n");
			scanf("%d", &a1);
		}
		
		
		printf("\n");
		printf("Numero da conta: ");
		scanf("%d", &c1);
		
		while(c1 > 999999999)
		{
			printf("Coloque um numero de conta valido!\n");
			scanf("%d", &c1);
		}
		
		printf("\n");
		
		fflush(stdin);
		
		
		for(j=0;j<i;j++)
		{
		
			if(c1==x[j].numero_conta && a1==x[j].numero_agencia)
			{
				
				aux1 = j;
				val = 0;
				break;
				
			}
		}
		
		if(val!=0)
		{
			printf("Conta inexistente!");
			fflush(stdin);
			getchar();
			return;
		}
		
		printf("CONTA DE DESTINO:\n");
		
		printf("Numero da agencia: ");
		scanf("%d", &a2);
		
		while(a2 > 999)
		{
			printf("Coloque um numero de agencia valido!\n");
			scanf("%d", &a2);
		}
		
		
		printf("\n");
		printf("Numero da conta: ");
		scanf("%d", &c2);
		
		while(c2 > 999999999)
		{
			printf("Coloque um numero de conta valido!\n");
			scanf("%d", &c2);
		}
		
		printf("\n");
		
		fflush(stdin);
		
		
		for(j=0;j<i;j++)
		{
		
			if(c2==x[j].numero_conta && a2==x[j].numero_agencia)
			{
				
				aux2 = j;
				val = 0;
				break;
				
			}
		}
		
		if(val!=0)
		{
			printf("Conta inexistente!");
			fflush(stdin);
			getchar();
			return;
		}
		
		if(c1==c2 && a1==a2)
		{
			printf("As contas de origem e destino são as mesmas\n");
			fflush(stdin);
			getchar();
			return;
		}
		
		printf("Qual o valor que será transferido?");
		scanf("%f", &trans);
		
		if(trans > x[aux1].saldo)
		{
			printf("Saldo da conta de origem é insuficiente\n");
			fflush(stdin);
			getchar();
			return;
		}
		
		x[aux1].saldo = x[aux1].saldo - trans;
		x[aux2].saldo = x[aux2].saldo + trans;
		
		printf("\n");
		printf("Novo saldo da conta de origem: %.3f\n", x[aux1].saldo);
		printf("Novo saldo da conta de destino: %.3f\n", x[aux2].saldo);
		fflush(stdin);
		getchar();
		return;
	
	}
	else
	{
		printf("Não há contas cadastradas");
		fflush(stdin);
		getchar();
		return;
	}	
	
}

//FUÇÃO INFORMAÇÃO DAS CONTAS DE UM CLIENTE

void i_contas(int i, int l, tclientes *x, tcontas *y)
{
	system("cls");
	
	char cpf[12];
	int j, val, aux, count, val2;
	
	
	if(l>0)
	{
		printf("Digite o CPF do cliente: \n");
		
		gets(cpf);
		
		while(strlen(cpf) != 11)
		{	
			printf("Digite um CPF válido:\n");
			gets(cpf);
			fflush(stdin);
				 
		}
		
		for(j=0;j<i;j++)
		{
				
			val = strcmp(cpf, x[j].CPF);
			
			if(val==0)
			{
				aux = j;
				break;
			}
				
		}
		
		if(val!=0)
		{
				printf("CPF inexistente!");
				fflush(stdin);
				getchar();
				return;		
		}
		
		count = 1;
		
		for(j=0;j<l;j++)
		{
			val2 = strcmp(x[aux].CPF, y[j].cliente);
			
			if(val2==0)
			{
				printf("\n");
				printf("CONTA %d:\n", count++);
				printf("Numero da conta: %d\n", y[j].numero_conta);
				printf("Numero da agencia: %d\n", y[j].numero_agencia);
				printf("Saldo: %f\n", y[j].saldo);
				printf("\n");
			}
				
			
		}	
		
		fflush(stdin);
		getchar();
		return;		
	
	}
	else
	{
		printf("Não há contas cadastradas");
		fflush(stdin);
		getchar();
		return;		
	}
	
	
	
	
}

//FUNÇÃO INFORMAR DADOS DE UM CLIENTE USANDO UM VALOR DIGITADO

void dados_por_valor(int i, int l, tclientes *x, tcontas *y)
{
	
	system("cls");
	
	FILE *arquivo;

	float sal;
	int choice, j, k, count=1, val, z, t = 0, v = 0;
	
	printf("Qual o valor de saldo a ser pesquisado?");
	scanf("%f", &sal);
	printf("\n");
	
	while(sal<=0)
	{
		printf("Digite um valor válido");
		scanf("%f", &sal);
		printf("\n");
	}
	
	printf("Escolha uma das opções: \n");
	printf("(1) Contas com o saldo menor que o valor digitado\n");
	printf("(0) Contas com o saldo igual que o valor digitado\n");
	printf("(-1) Contas com o saldo maior que o valor digitado\n");
	fflush(stdin);
	scanf("%d", &choice);
	
	
	if(choice==0 || choice==1 || choice==(-1))
	{
		v = 1;
	}
	
	while(v != 1)
	{
		printf("Digite uma opção válida: \n");
		fflush(stdin);
		scanf("%d", &choice);
		if(choice==0 || choice==1 || choice==(-1))
		{
			v = 1;
		}
	
	}

	printf("Deseja salvar essas informações em arquivos? Sim(1) Não(0) \n");
	fflush(stdin);
	scanf("%d", &z);
	
	if(z==0 || z==1 )
	{
		v = 1;
	}
	
	while(v != 1)
	{
		printf("Digite uma escolha válida:\n");
		fflush(stdin);
		scanf("%d", &z);
		if(z==0 || z==1 )
		{
			v = 1;
		}
		
	}
	

	
	if(choice == 1)
	{
		for(j=0;j<i;j++)
		{
			for(k=0;k<l;k++)
			{
					val = strcmp(y[j].cliente,x[k].CPF);
					
					if(val==0 && y[j].saldo < sal)
					{
						printf("---Conta %d---\n", count++);
						printf("Nome: %s\n", x[k].nome);
				   	   	printf("CPF: %s\n", y[j].cliente);
				   	   	printf("Numero da conta: %d\n", y[j].numero_conta);
				   	   	printf("Numero da agência: %d\n", y[j].numero_agencia);
				   	   	printf("Saldo: %.2f\n", y[j].saldo);
				   	   	
				   	   	t++;
				   	   	
				   	   	if(z == 1)
						{
							
							arquivo = fopen("Dados clientes por saldo.txt", "a");
							
							fprintf(arquivo, "----------------------------------");
							fprintf(arquivo, "Saldo menor que o valor informado\n");
							fprintf(arquivo, "---Conta %d---\n", count++);
							fprintf(arquivo, "Nome: %s\n", x[k].nome);
					   	   	fprintf(arquivo, "CPF: %s\n", y[j].cliente);
					   	   	fprintf(arquivo, "Numero da conta: %d\n", y[j].numero_conta);
					   	   	fprintf(arquivo, "Numero da agência: %d\n", y[j].numero_agencia);
					   	   	fprintf(arquivo, "Saldo: %.2f\n", y[j].saldo);
							fprintf(arquivo, "----------------------------------");	
								  	
							fclose(arquivo);
								  
						}
				
					}
					
			}
		
		}
		
		if(t==0)
		{
			printf("Não há contas cadastradas!\n");
			fflush(stdin);
			getchar();
			return;
			
		}		
		
		fflush(stdin);
		getchar();
		return;		
	}
	
	if(choice==0)
	{
		
		for(j=0;j<i;j++)
		{
			for(k=0;k<l;k++)
			{
					val = strcmp(y[j].cliente,x[k].CPF);
					
					if(val==0 && y[j].saldo == sal)
					{
						printf("---Conta %d---\n", count++);
						printf("Nome: %s\n", x[k].nome);
				   	   	printf("CPF: %s\n", y[j].cliente);
				   	   	printf("Numero da conta: %d\n", y[j].numero_conta);
				   	   	printf("Numero da agência: %d\n", y[j].numero_agencia);
				   	   	printf("Saldo: %.2f\n", y[j].saldo);
				   	   	
	   	   				t++;
				   	   	
			   	   		if(z == 1)
						{
							arquivo = fopen("Dados clientes por saldo.txt", "a");
							
							fprintf(arquivo, "----------------------------------");
							fprintf(arquivo, "Saldo igual ao valor informado\n");
							fprintf(arquivo, "---Conta %d---\n", count++);
							fprintf(arquivo, "Nome: %s\n", x[k].nome);
					   	   	fprintf(arquivo, "CPF: %s\n", y[j].cliente);
					   	   	fprintf(arquivo, "Numero da conta: %d\n", y[j].numero_conta);
					   	   	fprintf(arquivo, "Numero da agência: %d\n", y[j].numero_agencia);
					   	   	fprintf(arquivo, "Saldo: %.2f\n", y[j].saldo);
					   	   	fprintf(arquivo, "----------------------------------");
							  	
							fclose(arquivo);	  	
						}
				
					}
					
			}
		
		}
		
		if(t==0)
		{
			printf("Não há contas cadastradas!\n");
			fflush(stdin);
			getchar();
			return;
			
		}		
		fflush(stdin);
		getchar();
		return;		
		
	}
	
	if(choice==(-1))
	{
		
		for(j=0;j<i;j++)
		{
			for(k=0;k<l;k++)
			{
					val = strcmp(y[j].cliente,x[k].CPF);
					
					if(val==0 && y[j].saldo > sal)
					{
						printf("---Conta %d---\n", count++);
						printf("Nome: %s\n", x[k].nome);
				   	   	printf("CPF: %s\n", y[j].cliente);
				   	   	printf("Numero da conta: %d\n", y[j].numero_conta);
				   	   	printf("Numero da agência: %d\n", y[j].numero_agencia);
				   	   	printf("Saldo: %.2f\n", y[j].saldo);
				   	   	
	   	   				t++;
				   	   	
			   	   		if(z == 1)
						{
							arquivo = fopen("Dados clientes por saldo.txt", "a");
							
							fprintf(arquivo, "----------------------------------");
							fprintf(arquivo, "Saldo maior que o valor informado\n");
							fprintf(arquivo, "---Conta %d---\n", count++);
							fprintf(arquivo, "Nome: %s\n", x[k].nome);
					   	   	fprintf(arquivo, "CPF: %s\n", y[j].cliente);
					   	   	fprintf(arquivo, "Numero da conta: %d\n", y[j].numero_conta);
					   	   	fprintf(arquivo, "Numero da agência: %d\n", y[j].numero_agencia);
					   	   	fprintf(arquivo, "Saldo: %.2f\n", y[j].saldo);
					   	   	fprintf(arquivo, "----------------------------------");
							  	
							fclose(arquivo);							  	
						}				   	   	
				
					}
					
			}
		
		}
		
		if(t==0)
		{
			printf("Não há contas cadastradas!\n");
			fflush(stdin);
			getchar();
			return;
			
		}		
		
		fflush(stdin);
		getchar();
		return;
		
	}
}

//FUNÇÃO LISTAR DADOS CADASTRAIS DO CLIENTE

void lista_clientes(int i, tclientes *x)
{

	system("cls");
	
	FILE *arquivo;
	
	int z, v, j, count = 0, t = 0;
	
	printf("Deseja salvar essas informações em arquivos? Sim(1) Não(0) \n");
	fflush(stdin);
	scanf("%d", &z);
	
	if(z==0 || z==1 )
	{
		v = 1;
	}
	
	while(v != 1)
	{
		printf("Digite uma escolha válida:\n");
		fflush(stdin);
		scanf("%d", &z);
		if(z==0 || z==1 )
		{
			v = 1;
		}
		
	}
		
		
	for(j=0;j<i;j++)
	{
			
		printf("---Cliente %d---\n", count++);
		printf("Nome: %s\n", x[j].nome);
		printf("CPF: %s\n", x[j].CPF);
		printf("Endereço: %s\n", x[j].Enderec);
		printf("Telefone: %s\n", x[j].telefone);
		t++;
		if(z==1)
		{
					
			arquivo = fopen("Dados cadastrais dos clientes.txt", "a");
			
			fprintf(arquivo, "Dados cadastrais do cliente\n");
			fprintf(arquivo, "---Cliente %d---\n", count++);
			fprintf(arquivo, "Nome: %s\n", x[j].nome);
			fprintf(arquivo, "CPF: %s\n", x[j].CPF);
			fprintf(arquivo, "Endereço: %s\n", x[j].Enderec);
			fprintf(arquivo, "Telefone: %s\n", x[j].telefone);
			fprintf(arquivo, "-----------------\n");	
			
			fclose(arquivo);	
			
		}	
			
	}
	if(t==0)
	{
		printf("Não há clientes cadastrados!\n");
			fflush(stdin);
			getchar();
			return;		
	}
	
			fflush(stdin);
			getchar();
			return;	
}

//FUNÇÕES LISTAR DADOS ACERCA DE TODAS AS CONTAS

void lista_contas(int i, int l, tclientes *x, tcontas *y)
{

	
	system("cls");
	
	FILE *arquivo;
	
	int z, v,val, j,k, count = 1, t = 0;
	
	printf("Deseja salvar essas informações em arquivos? Sim(1) Não(0) \n");
	fflush(stdin);
	scanf("%d", &z);
	
	if(z==0 || z==1 )
	{
		v = 1;
	}
	
	while(v != 1)
	{
		printf("Digite uma escolha válida:\n");
		fflush(stdin);
		scanf("%d", &z);
		if(z==0 || z==1 )
		{
			v = 1;
		}
		
	}
		
		
		for(j=0;j<i;j++)
		{
			for(k=0;k<l;k++)
			{
					val = strcmp(y[j].cliente,x[k].CPF);
					
					if(val==0)
					{
						printf("---Conta %d---\n", count++);
						printf("Nome: %s\n", x[k].nome);
				   	   	printf("CPF: %s\n", y[j].cliente);
				   	   	printf("Numero da conta: %d\n", y[j].numero_conta);
				   	   	printf("Numero da agência: %d\n", y[j].numero_agencia);
				   	   	
				   	   	t++;
				   	   	
				   	   	if(z == 1)
						{
							
							arquivo = fopen("Dados cadastrais das contas.txt", "a");
							
							fprintf(arquivo, "----------------------------------");
							fprintf(arquivo, "---Conta %d---\n", count++);
							fprintf(arquivo, "Nome: %s\n", x[k].nome);
					   	   	fprintf(arquivo, "CPF: %s\n", y[j].cliente);
					   	   	fprintf(arquivo, "Numero da conta: %d\n", y[j].numero_conta);
					   	   	fprintf(arquivo, "Numero da agência: %d\n", y[j].numero_agencia);
							fprintf(arquivo, "----------------------------------");	
								  	
							fclose(arquivo);
								  
						}
				
					}
					
			}
		}
		
	if(t==0)
	{
		printf("Não há contas cadastrados!\n");
			fflush(stdin);
			getchar();
			return;		
	}
	
			fflush(stdin);
			getchar();
			return;		
	
	
}

//FUNÇÃO LISTAR TODAS AS INFORMAÇÕES SOBRE TODOS OS CLIENTES

void listar_todos_clientes(int i, int l, tclientes *x, tcontas *y)
{
	
	system("cls");
	
	FILE *arquivo;
	
	int z, v, j, k, count1 = 0, count2, t = 0;
	
	printf("Deseja salvar essas informações em arquivos? Sim(1) Não(0) \n");
	fflush(stdin);
	scanf("%d", &z);
	
	if(z==0 || z==1 )
	{
		v = 1;
	}
	
	while(v != 1)
	{
		printf("Digite uma escolha válida:\n");
		fflush(stdin);
		scanf("%d", &z);
		if(z==0 || z==1 )
		{
			v = 1;
		}
		
	}
		
	for(j=0;j<i;j++)
	{
		
		printf("---Cliente %d---\n", count1++);
		printf("Nome: %s\n", x[j].nome);
		printf("CPF: %s\n", x[j].CPF);
		printf("Endereço: %s\n", x[j].Enderec);
		printf("Telefone: %s\n", x[j].telefone);
		t++;
		
		if(x[j].numero_de_contas != 0)
		{
			
			count2 = 1;
			
			printf("O cliente %d possui %d contas!\n",count1, x[j].numero_de_contas);
			
			for(k=0;k<i;k++)
			{
				printf("------CONTA %d\n------", count2++);
	   	   		printf("Numero da conta: %d\n", y[k].numero_conta);
  				printf("Numero da agência: %d\n", y[k].numero_agencia);
				printf("Saldo: %f\n", y[k].saldo);
				
				if(z==1)
				{
							
					arquivo = fopen("Dados gerais clientes e contas.txt", "a");
					
					fprintf(arquivo, "Dados gerais do cliente\n");
					fprintf(arquivo, "---Cliente %d---\n", count1++);
					fprintf(arquivo, "Nome: %s\n", x[j].nome);
					fprintf(arquivo, "CPF: %s\n", x[j].CPF);
					fprintf(arquivo, "Endereço: %s\n", x[j].Enderec);
					fprintf(arquivo, "Telefone: %s\n", x[j].telefone);
					fprintf(arquivo, "Numero de contas: %d\n", x[j].numero_de_contas);
					fprintf(arquivo, "-----------------\n");	
					fprintf(arquivo, "CONTA %d: \n", count2);
		   	   		fprintf(arquivo, "Numero da conta: %d\n", y[j].numero_conta);
		   	   		fprintf(arquivo, "Numero da agência: %d\n", y[j].numero_agencia);
   	   				fprintf(arquivo, "Saldo: %f\n", y[j].saldo);
					fprintf(arquivo, "-----------------\n");	
					
					fclose(arquivo);	
					
				}
				
			}
			
			
		}
		else
		{
			printf("O cliente %d não possui contas cadastradas\n", count1);
			
				if(z==1)
				{
							
					arquivo = fopen("Dados gerais clientes e contas.txt", "a");
					
					fprintf(arquivo, "Dados gerais do cliente\n");
					fprintf(arquivo, "---Cliente %d---\n", count1++);
					fprintf(arquivo, "Nome: %s\n", x[j].nome);
					fprintf(arquivo, "CPF: %s\n", x[j].CPF);
					fprintf(arquivo, "Endereço: %s\n", x[j].Enderec);
					fprintf(arquivo, "Telefone: %s\n", x[j].telefone);
					fprintf(arquivo, "O cliente %d não possui contas cadastradas\n", count1);
					fprintf(arquivo, "-----------------\n");		
					
					fclose(arquivo);	
					
				}
		}
		
		
	}
	
	if(t==0)
	{
		printf("Não há clientes cadastrados!\n");
		fflush(stdin);
		getchar();
		return;		
	}
	
	fflush(stdin);
	getchar();
	return;		
		
	
	
}

int main()
{
	
	system("title CAIXA");
	system("color 1F");
	
	setlocale(LC_ALL, "Portuguese");
	
	//Determinando o tamanho do vetor e declarando os ponteiros para estruturas
	int tamanho_vetor_clients = 1;
	int tamanho_vetor_contas = 1;
	tclientes *clientes;
	tcontas *contas;
	
	//Os ponteiros começam como vetores de tamanho 1
	clientes = (tclientes *)malloc(sizeof(tclientes));
	
	contas = (tcontas *)malloc(sizeof(tcontas));
		
	String opcoes[] = {"Cadastrar Cliente", "Cadastrar conta", "Remover conta", "Mostrar saldo", "Deposito", "Saque", "Transferencia", "Contas de um cliente", "Dados do cliente com saldo superior, inferior ou igual a um valor", "Listar dados cadastrais de todos os clientes","Listar as informações de todas contas", "Listar as informações de todos os clientes", "Sair"};
	

	
	while(1>0)
	{

		int op = menu(opcoes, 13);
			
		
		if(op!=13)
		{
			/*Redimensioando os ponterios toda vez que o usuario não encerra as operações, dando novos tamanhos aos vetores (aumentando)*/
			clientes = realloc(clientes, tamanho_vetor_clients * sizeof(tclientes));
			contas = realloc(contas, tamanho_vetor_contas * sizeof(tcontas));
			contas[tamanho_vetor_contas-1].saldo = 0;
			clientes[tamanho_vetor_clients-1].numero_de_contas = 0;
			
			if(op==1)
			{
				cadastro_cliente(tamanho_vetor_clients-1, clientes,&tamanho_vetor_clients);
				system("cls");
			}
			if(op==2)
			{
				cadastro_conta(tamanho_vetor_contas-1,contas,clientes,&tamanho_vetor_contas);
				system("cls");
			}
			if(op==3)
			{
				RemoverConta(tamanho_vetor_contas-1,contas,clientes,&tamanho_vetor_contas);
				system("cls");
			}
			if(op==4)
			{
				mostrar_saldo(tamanho_vetor_contas-1, contas);
				system("cls");
			}
			if(op==5)
			{
				deposito(tamanho_vetor_contas-1,contas);
				system("cls");
			}
			if(op==6)
			{
				saque(tamanho_vetor_contas-1,contas);
				system("cls");
			}
			if(op==7)
			{
				transferencia(tamanho_vetor_contas-1,contas);
				system("cls");
			}
			if(op==8)
			{
				i_contas(tamanho_vetor_clients-1,tamanho_vetor_contas-1,clientes, contas);
				system("cls");
			}
			if(op==9)
			{
				dados_por_valor(tamanho_vetor_clients-1,tamanho_vetor_contas-1,clientes, contas);
				system("cls");
			}
			if(op==10)
			{
				lista_clientes(tamanho_vetor_clients-1, clientes);
				system("cls");
			}
			if(op==11)
			{
				lista_contas(tamanho_vetor_clients-1,tamanho_vetor_contas-1,clientes, contas);
				system("cls");
			}
			if(op==12)
			{
				listar_todos_clientes(tamanho_vetor_clients-1,tamanho_vetor_contas-1,clientes, contas);
				system("cls");
			}
			

			
		}
		else
		{
			printf("PROGRAMA ENCERRADO");
			break;
				
		}
		
	}
	
	return 0;
}
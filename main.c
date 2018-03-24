#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct contacorrente {
	int cc;
	char nome[50], mail[50];
};
struct endereco {
	char rua[50], bairro[50], cidade[50], estado[3];
	int num;
};
int main(int argc, char *argv[]) {
	int i, j = 0, l = 0, dig, dig1, certa = 0;
	struct contacorrente cc[100];
	struct endereco dados[100];
	while (l == 0)
	{
		clear();
		printf("1-Cadastrar Conta Corrente.\n");
		printf("2-Listar Conta Corrente.\n");
		printf("3-Excluir Conta Corrente\n");
		printf("------------------------------------------------------\n");
		printf("Insira o numero correspondente a acao desejada\n");
		scanf("%d", &dig);
		switch (dig)
		{
		case 1:
			//cadastrarConta();
			clear();
			printf("Insira o numero da nova conta: ");
			scanf("%d", &dig1);
			for (i = 0; i<j; i++)
			{
				if (dig1 == cc[i].cc)
				{
					certa++;
				}
			}
			if (certa == 0)
			{
				j++;
				cc[j - 1].cc = dig1;
				printf("%d\n", cc[j - 1].cc);
				printf("Informe o nome do correntista: ");
				fflush(stdin);
				gets(cc[j - 1].nome);
				fflush(stdin);
				printf("%s\n", cc[j - 1].nome);
				printf("Insira a rua onde mora(Separados.por.pontos): ");
				gets(dados[j - 1].rua);
				fflush(stdin);
				printf("Insira o numero da rua: ");
				scanf("%d", &dados[j - 1].num);
				fflush(stdin);
				printf("Insira o bairro onde mora: ");
				gets(dados[j - 1].bairro);
				fflush(stdin);
				printf("Insira a cidade onde mora: ");
				gets(dados[j - 1].cidade);
				fflush(stdin);
				printf("Insira o estado onde mora: ");
				gets(dados[j - 1].estado);
				fflush(stdin);
				printf("Insira o email para contato: ");
				gets(cc[j - 1].mail);
				fflush(stdin);
			}
			else
			{
				printf("Conta ja exixtente.\n");
				sleep(2000);
				certa = 0;
			}
			break;
		case 2:
			clear();
			for (i = 0; i<j; i++)
			{
				printf("CC:%d \n", cc[i].cc);
				printf("Nome:%s \n", cc[i].nome);
				printf("Email:%s \n", cc[i].mail);
				printf("Rua:%s ,Num:%d \n", dados[i].rua, dados[i].num);
				printf("Bairro:%s Cidade:%s Estado:%s \n", dados[i].bairro, dados[i].cidade, dados[i].estado);
				printf("------------------------------------------------------------------- \n");
			}
			getch();
			break;
		case 3:
			clear();
			printf("Insira o codigo da conta que voce deseja excluir: ");
			scanf("%d", &dig1);
			certa = 0;
			for (i = 0; i<j; i++)
			{
				if (dig1 == cc[i].cc)
				{
					certa = 1;
					l = i;
				}
			}
			if (certa == 1)
			{
				for (i = l; i<j - 1; i++)
				{
					cc[i].cc = cc[i + 1].cc;
					strcpy(cc[i].mail , cc[i + 1].mail);
					strcpy(cc[i].nome , cc[i + 1].nome);
					strcpy(dados[i].bairro , dados[i + 1].bairro);
					strcpy(dados[i].cidade , dados[i + 1].cidade);
					strcpy(dados[i].estado , dados[i + 1].estado);
					dados[i].num = dados[i + 1].num;
					strcpy(dados[i].rua , dados[i + 1].rua);
				}
				j = j - 1;
			}
			else
			{
				printf("Conta nao encontrada.\n");
				sleep(2000);
				certa = 0;
			}
			break;
		default:
			printf("Valor Invalido!\n");
		}

	}
	return 0;
}
void clear()
{
	system("cls");
}

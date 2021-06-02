#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int QtCar;
int Tsenha;
int Aux;

void SenhaNumerica (){
	int NumRand[QtCar];
        printf("Sua senha é: \n");
        for(int i = 0; i < QtCar; i++){
            NumRand[i] = rand() % 10;
            printf("%d", NumRand[i]);
        }
}
void SenhaAlfaNumerica (){
    char Alfnum[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char SenAlf[QtCar];
    printf("Sua senha é: \n");
    for(int i = 0; i < QtCar; i++){
    	SenAlf[i] = Alfnum[rand() % 62];
    	printf("%c", SenAlf[i]);
	}
}
void SenhaForte (){
	char AlfaNum[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char Especial[] = "@!#$%^&*()/\\";
    char SenhaForte[QtCar];
    printf("Sua senha é: \n");
    for (int i=0; i < QtCar; i++){
    	SenhaForte[i*2] = AlfaNum[rand() % 75];
    	SenhaForte[i*2+1] = Especial[rand() % 12];
    }
    int RandomA;
    int RandomB;
    int Aux2;
    for (RandomA = QtCar - 1; RandomA > 0; RandomA--){
    	RandomB = rand () % (RandomA + 1);
    	Aux2 = SenhaForte[RandomB];
        SenhaForte[RandomB] = SenhaForte[RandomA];
        SenhaForte[RandomA] = Aux2;
	}
	for (int i = 0; i < QtCar; i++){
		printf("%c", SenhaForte[i]);
	}
}



int main(){
	srand (time(0));
	setlocale(LC_ALL, "Portuguese");
    printf("Gerador de Senha\n");
    printf("Quantos caracteres?\n");
    scanf("%d",&QtCar);
    if(QtCar < 3 || QtCar > 30){
        printf("Quantidade de caracteres não permitida \n");
        return main();
    }
    else printf("Qual tipo de senha?\n 1. Numérica\n 2. Alfanumérica\n 3. Senha Forte\n");
    scanf("%d",&Tsenha);
    switch (Tsenha){
        case 1:
        SenhaNumerica();
        break;
        case 2:
        SenhaAlfaNumerica();
        break;
        case 3:
        SenhaForte();
        break;
        }
    printf("\nDeseja criar uma nova senha? \n 1. Sim \n 2. Não \n");
    scanf("%d", &Aux);
    if(Aux == 1){
        return main();
    }
}

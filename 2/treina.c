#include<stdio.h> //FILE
#include<stdlib.h> //rand

typedef struct{
	float peso;
	char especie;
} fruta;

main(){
	fruta amostra[50];
	srand(time(0));

	//busca os valores no arquivo e armazena em um array 'amostra'
	FILE *fp=fopen("entradas.txt","r");
	for(int x=0;x<50;x++){
		//fread(&amostra[x],sizeof(fruta),1,fp);
		fscanf(fp,"%f %c\n",&amostra[x].peso,&amostra[x].especie); //busca no arquivo
		//printf("%2d) %f %c\n",x,amostra[x].peso,amostra[x].especie); //exibe na tela
	}
	fclose(fp);

	//inicializa o weight com um valor aleatorio
	float weight=((float)rand()/(float)(RAND_MAX))/1.0; //valor entre 0 e 1

	for(int x=0;x<10000;x++){
		int alguma=rand()%50; //escolhe uma amostra qualquer da amostra

		//printf("%d) [%c] %f\n",alguma,amostra[alguma].especie,amostra[alguma].peso);

		//calibra o weight
		if(amostra[alguma].especie=='m'){ //maca
			if(amostra[alguma].peso>weight)		weight=weight+(weight*0.01);
			else if(amostra[alguma].peso<weight)weight=weight-(weight*0.01);
		}else{ //qualquer fruta
			if(amostra[alguma].peso<weight)		weight=weight-(weight*0.01);
			else if(amostra[alguma].peso>weight)weight=weight+(weight*0.01);
		}

		//printf("weight: %f\n",weight);
	}
	printf("O valor que diferencia (weight): %f\n",weight);
}

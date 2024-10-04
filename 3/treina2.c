#include<stdio.h> //FILE
#include<stdlib.h> //rand

typedef struct{
	float peso;
	float volume;
	float cor;
	float posicao;
	float textura;
	float consistencia;
	float temperatura;
	float idade;
	char especie;
} fruta;

main(){
	float finalWeight;
	float weight[8];
	fruta amostra[30];
	srand(time(0));

	//busca os valores no arquivo e armazena em um array 'amostra'
	FILE *fp=fopen("entradas.txt","r");
	for(int x=0;x<30;x++)
		fread(&amostra[x],sizeof(fruta),1,fp);
	fclose(fp);

	//inicializa os weight com um valor aleatorio
	for(int t=0;t<8;t++)weight[t]=((float)rand()/(float)(RAND_MAX))/1.0;
	finalWeight=((float)rand()/(float)(RAND_MAX))/1.0;

	for(int x=0;x<1000;x++){
		int alguma=rand()%30; //escolhe uma amostra qualquer

		//calibra os weight peso
		int t=0;
		if(amostra[alguma].especie=='m'){
			if(amostra[alguma].peso>weight[t])		weight[t]=weight[t]+(weight[t]*0.01);
			else if(amostra[alguma].peso<weight[t])	weight[t]=weight[t]-(weight[t]*0.01);
		}else{
			if(amostra[alguma].peso<weight[t])		weight[t]=weight[t]-(weight[t]*0.01);
			else if(amostra[alguma].peso>weight[t])	weight[t]=weight[t]+(weight[t]*0.01);
		}

		//calibra os weight volume
		t=1;
		if(amostra[alguma].especie=='m'){
			if(amostra[alguma].volume>weight[t])		weight[t]=weight[t]+(weight[t]*0.01);
			else if(amostra[alguma].volume<weight[t])	weight[t]=weight[t]-(weight[t]*0.01);
		}else{
			if(amostra[alguma].volume<weight[t])		weight[t]=weight[t]-(weight[t]*0.01);
			else if(amostra[alguma].volume>weight[t])	weight[t]=weight[t]+(weight[t]*0.01);
		}

		//calibra os weight cor
		t=2;
		if(amostra[alguma].especie=='m'){
			if(amostra[alguma].cor>weight[t])			weight[t]=weight[t]+(weight[t]*0.01);
			else if(amostra[alguma].cor<weight[t])		weight[t]=weight[t]-(weight[t]*0.01);
		}else{
			if(amostra[alguma].cor<weight[t])			weight[t]=weight[t]-(weight[t]*0.01);
			else if(amostra[alguma].cor>weight[t])		weight[t]=weight[t]+(weight[t]*0.01);
		}

		//calibra os weight posicao
		t=3;
		if(amostra[alguma].especie=='m'){
			if(amostra[alguma].posicao>weight[t])		weight[t]=weight[t]+(weight[t]*0.01);
			else if(amostra[alguma].posicao<weight[t])	weight[t]=weight[t]-(weight[t]*0.01);
		}else{
			if(amostra[alguma].posicao<weight[t])		weight[t]=weight[t]-(weight[t]*0.01);
			else if(amostra[alguma].posicao>weight[t])	weight[t]=weight[t]+(weight[t]*0.01);
		}

		//calibra os weight textura
		t=4;
		if(amostra[alguma].especie=='m'){
			if(amostra[alguma].textura>weight[t])		weight[t]=weight[t]+(weight[t]*0.01);
			else if(amostra[alguma].textura<weight[t])	weight[t]=weight[t]-(weight[t]*0.01);
		}else{
			if(amostra[alguma].textura<weight[t])		weight[t]=weight[t]-(weight[t]*0.01);
			else if(amostra[alguma].textura>weight[t])	weight[t]=weight[t]+(weight[t]*0.01);
		}

		//calibra os weight consistencia
		t=5;
		if(amostra[alguma].especie=='m'){
			if(amostra[alguma].consistencia>weight[t])		weight[t]=weight[t]+(weight[t]*0.01);
			else if(amostra[alguma].consistencia<weight[t])	weight[t]=weight[t]-(weight[t]*0.01);
		}else{
			if(amostra[alguma].consistencia<weight[t])		weight[t]=weight[t]-(weight[t]*0.01);
			else if(amostra[alguma].consistencia>weight[t])	weight[t]=weight[t]+(weight[t]*0.01);
		}

		//calibra os weight temperatura
		t=6;
		if(amostra[alguma].especie=='m'){
			if(amostra[alguma].temperatura>weight[t])		weight[t]=weight[t]+(weight[t]*0.01);
			else if(amostra[alguma].temperatura<weight[t])	weight[t]=weight[t]-(weight[t]*0.01);
		}else{
			if(amostra[alguma].temperatura<weight[t])		weight[t]=weight[t]-(weight[t]*0.01);
			else if(amostra[alguma].temperatura>weight[t])	weight[t]=weight[t]+(weight[t]*0.01);
		}

		//calibra os weight idade
		t=7;
		if(amostra[alguma].especie=='m'){
			if(amostra[alguma].idade>weight[t])		weight[t]=weight[t]+(weight[t]*0.01);
			else if(amostra[alguma].idade<weight[t])weight[t]=weight[t]-(weight[t]*0.01);
		}else{
			if(amostra[alguma].idade<weight[t])		weight[t]=weight[t]-(weight[t]*0.01);
			else if(amostra[alguma].idade>weight[t])weight[t]=weight[t]+(weight[t]*0.01);
		}

		printf("w [ %f %f %f %f %f %f %f %f ]\n",weight[0],weight[1],weight[2],weight[3],weight[4],weight[5],weight[6],weight[7]);
	}
	printf("\nOs valores que diferenciam = %f %f %f %f %f %f %f %f\n",weight[0],weight[1],weight[2],weight[3],weight[4],weight[5],weight[6],weight[7]);
}

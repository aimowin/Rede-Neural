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

		//calibra os weight
		float caracteristica[8]={amostra[alguma].peso,amostra[alguma].volume,amostra[alguma].cor,amostra[alguma].posicao,amostra[alguma].textura,amostra[alguma].consistencia,amostra[alguma].temperatura,amostra[alguma].idade};
		for(int t=0;t<8;t++){
			if(amostra[alguma].especie=='m'){
				if(caracteristica[t]>weight[t])		weight[t]=weight[t]+(weight[t]*0.01);
				else if(caracteristica[t]<weight[t])weight[t]=weight[t]-(weight[t]*0.01);
			}else{
				if(caracteristica[t]<weight[t])		weight[t]=weight[t]-(weight[t]*0.01);
				else if(caracteristica[t]>weight[t])weight[t]=weight[t]+(weight[t]*0.01);
			}
		}

		float referencia=(weight[0]+weight[1]+weight[2]+weight[3]+weight[4]+weight[5]+weight[6]+weight[7])/8;

		if(amostra[alguma].especie=='m'){
			if(referencia>finalWeight)		finalWeight=finalWeight+(finalWeight*0.01);
			else if(referencia<finalWeight)	finalWeight=finalWeight-(finalWeight*0.01);
		}else{
			if(referencia<finalWeight)		finalWeight=finalWeight-(finalWeight*0.01);
			else if(referencia>finalWeight)	finalWeight=finalWeight+(finalWeight*0.01);
		}

		printf("w = [ %f %f %f %f %f %f %f %f ] finalWeight = %f\n",weight[0],weight[1],weight[2],weight[3],weight[4],weight[5],weight[6],weight[7],finalWeight);
	}
	printf("\nOs valores que diferenciam = %f %f %f %f %f %f %f %f\n",weight[0],weight[1],weight[2],weight[3],weight[4],weight[5],weight[6],weight[7]);

	fp=fopen("weight.txt","w");
	fwrite(&finalWeight,sizeof(float),1,fp); //grava no arquivo
	fclose(fp);

	printf("\nO valor final %f foi inserido no weight.txt\n",finalWeight);
}

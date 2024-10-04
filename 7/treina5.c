#include<stdio.h> //FILE
#include<stdlib.h> //rand

main(){
	int qtdpedacos=60; //quantidade de pedacos de cada imagem
	int imagens=200; //quantidade de imagens
	float learningRate=0.01;
	float finalWeight;
	float weight[qtdpedacos];
	short int amostra[imagens][qtdpedacos];
	srand(time(0));

	char filename[200][24]; //variavel que guarda o nome das 200 imagens
	for(int x=0;x<200;x++){
		char numero[4];
		strcpy(filename[x],"imagens/amostra");
		sprintf(numero,"%d",x);
		strcat(filename[x],numero);
		strcat(filename[x],".bmp");
	}

	//extrai uns valores nos arquivos imagem e armazena em um array 'amostra'
	for(int c=0;c<imagens;c++){
		FILE *fp=fopen(filename[c],"r");
		for(int x=0;x<qtdpedacos;x++)fread(&amostra[c][x],sizeof(short),1,fp);
		fclose(fp);
	}

	//inicializa os weight com um valor aleatorio
	for(int t=0;t<qtdpedacos;t++)weight[t]=((float)rand()/(float)(RAND_MAX))/1.0;
	finalWeight=((float)rand()/(float)(RAND_MAX))/1.0;

	for(int x=0;x<10000;x++){
		int alguma=rand()%imagens; //escolhe uma amostra qualquer

		for(int t=0;t<qtdpedacos;t++){
			if(alguma>imagens/2){
				if(amostra[alguma][t]>weight[t])		weight[t]=weight[t]+(weight[t]*learningRate);
				else if(amostra[alguma][t]<weight[t])	weight[t]=weight[t]-(weight[t]*learningRate);
			}else{
				if(amostra[alguma][t]<weight[t])		weight[t]=weight[t]-(weight[t]*learningRate);
				else if(amostra[alguma][t]>weight[t])	weight[t]=weight[t]+(weight[t]*learningRate);
			}
		}

		float referencia=0;
		for(int t=0;t<qtdpedacos;t++)referencia+=(amostra[alguma][t]*weight[t])/qtdpedacos;

		if(alguma>imagens/2){
			if(referencia>finalWeight)		finalWeight=finalWeight+(finalWeight*learningRate);
			else if(referencia<finalWeight)	finalWeight=finalWeight-(finalWeight*learningRate);
		}else{
			if(referencia<finalWeight)		finalWeight=finalWeight-(finalWeight*learningRate);
			else if(referencia>finalWeight)	finalWeight=finalWeight+(finalWeight*learningRate);
		}

		printf("weight = %f\n",finalWeight);
	}

	FILE *fp=fopen("weights.txt","w");
	for(int t=0;t<qtdpedacos;t++)fwrite(&weight[t],sizeof(float),1,fp); //grava no arquivo
	fwrite(&finalWeight,sizeof(float),1,fp); //grava no arquivo
	fclose(fp);

	printf("\nO valor final %f foi inserido no weights.txt\n",finalWeight);
}

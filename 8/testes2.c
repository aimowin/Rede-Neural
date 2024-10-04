#include<stdio.h> //FILE
#include<stdlib.h> //rand

main(){
	int qtdpedacos=60; //quantidade de pedacos de cada imagem
	int imagens=200; //quantidade de imagens
	float margem=0.01;
	float finalWeight;
	float weight[qtdpedacos];
	short int amostra[imagens][qtdpedacos];
	int quadradocerto=0,quadradoerrado=0,circulocerto=0,circuloerrado=0;
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

	//inicializa os weight com valores buscado do arquivo
	FILE *fp=fopen("weights.txt","r");
	for(int t=0;t<qtdpedacos;t++)fread(&weight[t],sizeof(float),1,fp); //valor dos weights da primeira camada
	fread(&finalWeight,sizeof(float),1,fp); //valor final
	fclose(fp);

	for(int x=0;x<1000;x++){
		int alguma=rand()%imagens; //escolhe uma amostra qualquer

		float referencia=0;
		for(int t=0;t<qtdpedacos;t++)referencia+=(amostra[alguma][t]*weight[t])/qtdpedacos;

		if(alguma<imagens/2)
			if(referencia>finalWeight-(finalWeight*margem)&&referencia<finalWeight+(finalWeight*margem))quadradocerto++;else quadradoerrado++;
		else
			if(referencia>finalWeight-(finalWeight*margem)&&referencia<finalWeight+(finalWeight*margem))circuloerrado++;else circulocerto++;
	}
	printf("\n%d tentativas:\n\nEsperado quadrado dado quadrado: %d\nEsperado quadrado dado circulo: %d\nEsperado circulo dado circulo: %d\nEsperado circulo dado quadrado: %d\n",(quadradocerto+quadradoerrado+circulocerto+circuloerrado),quadradocerto,quadradoerrado,circuloerrado,circulocerto);
}

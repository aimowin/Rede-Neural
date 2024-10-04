#include<stdio.h> //FILE
#include<stdlib.h> //rand

main(){
	int qtdpedacos=60; //quantidade de pedacos de cada imagem
	int imagens=200; //quantidade de imagens
	float learningRate=0.01;
	float finalWeight;
	float weight[qtdpedacos];
	int amostra[imagens][qtdpedacos];
	int quadradocerto=0,quadradoerrado=0,circulocerto=0,circuloerrado=0;
	srand(time(0));

	char filename[200][24]; //variavel que guarda o nome das 200 imagens
	for(int x=0;x<200;x++){
		char numero[4];
		strcpy(filename[x],"imagens/amostra");
		itoa(x,numero,10);
		strcat(filename[x],numero);
		strcat(filename[x],".bmp");
	}

	//extrai uns valores nos arquivos imagem e armazena em um array 'amostra'
	for(int c=0;c<imagens;c++){
		FILE *fp=fopen(filename[c],"r");
		for(int x=0;x<qtdpedacos;x++)fread(&amostra[c][x],sizeof(int),1,fp);
		fclose(fp);
	}

	//inicializa os weight com valores buscado do arquivo
	FILE *fp=fopen("weight.txt","r");
	fscanf(fp,"%f",&finalWeight); //valor final
	fclose(fp);

	for(int x=0;x<1000;x++){
		int alguma=rand()%imagens; //escolhe uma amostra qualquer

		float referencia=0;
		for(int t=0;t<qtdpedacos;t++)referencia+=(amostra[alguma][t]*weight[t])/qtdpedacos;

		if(alguma<imagens/2)
			if(referencia>finalWeight-.5&&referencia<finalWeight+.5)quadradocerto++;else quadradoerrado++;
		else
			if(referencia>finalWeight-.5&&referencia<finalWeight+.5)circulocerto++;else circuloerrado++;
	}
	printf("\n%d tentativas:\n\nEsperado quadrado dado quadrado: %d\nEsperado quadrado dado circulo: %d\nEsperado circulo dado circulo: %d\nEsperado circulo dado quadrado: %d\n",(quadradocerto+quadradoerrado+circulocerto+circuloerrado),quadradocerto,quadradoerrado,circuloerrado,circulocerto);
}

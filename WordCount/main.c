#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void wc(char *filename){
	FILE *fp;
	char buffer[1000];
	char a;
	int parameter;
	int bufferlen;
	int b = 0;
	int n; // �ϸ��ַ��Ƿ��ǿո�(1��ʾ��  0��ʾ����)
	int charCount=0;
	int wordCount=0;
	int i;
	if((fp=fopen(filename,"rb"))==NULL){
		printf("�ļ����ܴ�\n");
		exit(0);
	}
	while(fgets(buffer,1000,fp)!=NULL){
		bufferlen=strlen(buffer);
		for(i=0;i<bufferlen;i++){
			a=buffer[i];
			if(a==' ' || a=='\t'){
				if(b==0){
					wordCount++;
				}
				b=1;
			}
			else if(a!='\n'&&a!='\r'){
				charCount++;
				b=0;
			}
		}
		if(b==0)
			wordCount++;	
	}
	fclose(fp);
   

	for(parameter=1;parameter<3;parameter++){
		 printf("��ѡ��Ҫ�鿴����Ϣ��\n1:�ַ���\n2:������\n����������˳���");
		 scanf("%d",&parameter);
		 switch (parameter)
	{
		case 1:{
		         n=charCount;
		         printf("�ַ�����%d\n",n);
			     break;
		}
		case 2:{
		         n=wordCount;
		         printf("��������%d\n",n);
			     break;
		}
		default:{
			break;
		}
	}

	
	}
	
	
 
	
}
int main(){
	char filename[]="\\Users\\10438\\Desktop\\input_file_name.txt";
	wc(filename);
}  


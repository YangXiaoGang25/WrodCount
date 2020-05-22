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
	int n; // 上个字符是否是空格(1表示是  0表示不是)
	int charCount=0;
	int wordCount=0;
	int i;
	if((fp=fopen(filename,"rb"))==NULL){
		printf("文件不能打开\n");
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
		 printf("请选择要查看的信息：\n1:字符数\n2:单词数\n其他任意键退出！");
		 scanf("%d",&parameter);
		 switch (parameter)
	{
		case 1:{
		         n=charCount;
		         printf("字符数：%d\n",n);
			     break;
		}
		case 2:{
		         n=wordCount;
		         printf("单词数：%d\n",n);
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


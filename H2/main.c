#include <stdio.h>
#include <stdlib.h>
#include "bmp.h" 


FILE* readBmp(FILE* fpSrcBmpFile);
void getBmpHeader(FILE*, PBITMAPFILEHEADER, PBITMAPINFOHEADER, PRGBQUAD);
void ChangeHistHeader(PBITMAPFILEHEADER, PBITMAPINFOHEADER);
void setHistHeader(FILE*, PBITMAPFILEHEADER, PBITMAPINFOHEADER, PRGBQUAD);
int main(int argc, char *argv[]) {
	// 原图像文件
	FILE* fpSrcBmpFile = readBmp(fpSrcBmpFile);
	//  = (FILE*)malloc(sizeof(FILE));
	PBITMAPFILEHEADER fileHeader = (PBITMAPFILEHEADER)malloc(sizeof(BITMAPFILEHEADER));
	PBITMAPINFOHEADER infoHeader = (PBITMAPINFOHEADER)malloc(sizeof(BITMAPINFOHEADER));
	PRGBQUAD quadHeader = (PRGBQUAD)malloc(sizeof(RGBQUAD)*256);
	if (!fileHeader || !infoHeader || !quadHeader){
		printf("allocate memory error!");
		exit(0);
	}
	getBmpHeader(fpSrcBmpFile, fileHeader, infoHeader, quadHeader);
	ChangeHistHeader(fileHeader, infoHeader);
	FILE* fpHistBmpFile = fopen("hist.bmp", "wb");
	if (!fpHistBmpFile){
		printf("Error: Open the hist file!\n");
		exit(-1);
	}
	setHistHeader(fpHistBmpFile, fileHeader, infoHeader, quadHeader);
	
	fclose(fpSrcBmpFile);
	fclose(fpHistBmpFile);
	free(fileHeader);
	free(infoHeader);
	free(quadHeader);
	return 0;
}

FILE* readBmp(FILE* fpSrcBmpFile) {
	char SrcBmpfile[256];
	printf("Input the path of SrcBmpfile:\n");
    scanf("%s", SrcBmpfile);
    if((fpSrcBmpFile=fopen(SrcBmpfile,"rb"))==NULL) 
    {
        printf("Error:Open the file of SrcBmpfile failed!\n");//输入源位图文件
        exit(-1);
    }
	return fpSrcBmpFile;
	// printf("read dim.bmp successfully!"); 测试成功！
}

void getBmpHeader(FILE* fpSrcBmpFile, PBITMAPFILEHEADER fileHeader, PBITMAPINFOHEADER infoHeader, PRGBQUAD quadHeader){
	rewind(fpSrcBmpFile);
	fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, fpSrcBmpFile);
	fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, fpSrcBmpFile);
	fread(quadHeader, sizeof(RGBQUAD), 256, fpSrcBmpFile);
	// printf("read headers successfully!"); 测试成功！
}

void ChangeHistHeader(PBITMAPFILEHEADER fileHeader, PBITMAPINFOHEADER infoHeader){
	infoHeader->biWidth = 256;
	infoHeader->biHeight = 256;
	infoHeader->biSizeImage = 256*256;
	fileHeader->bfSize = fileHeader->bfOffBits+infoHeader->biSizeImage;
	// printf("change hist headers successfully!"); 测试成功！
}
void setHistHeader(FILE* fpHistBmpFile, PBITMAPFILEHEADER fileHeader, PBITMAPINFOHEADER infoHeader, PRGBQUAD quadHeader){
	fwrite(fileHeader, sizeof(BITMAPFILEHEADER), 1, fpHistBmpFile);
	fwrite(infoHeader, sizeof(BITMAPINFOHEADER), 1, fpHistBmpFile);
	fwrite(quadHeader, sizeof(RGBQUAD), 256, fpHistBmpFile);
	// printf("write hist headers successfully!"); 测试成功！
}
/* C���Զ���ͼ�� λͼ�ļ��ṹ���� */
#ifndef BMP_H_INCLUDED
#define BMP_H_INCLUDED

typedef unsigned short WORD;//2*8=16
typedef unsigned long DWORD;//4*8=32
typedef long LONG;//4*8=32
typedef unsigned char BYTE;//1*8=8

// #pragma pack(1) ָʾ����������1�ֽڵĶ��뷽ʽ���洢�ṹ���Ա
#pragma pack(1) 
// ����λͼ�ļ�ͷ�ṹ�� 14���ֽ� 
typedef struct tagBITMAPFILEHEADER
{
	WORD bfType; 
	DWORD bfSize; // ����ͼƬ��С 
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffBits; // ͷ���ܴ�С
}BITMAPFILEHEADER, *PBITMAPFILEHEADER;
// #pragma pop()�������ڻָ�Ĭ�ϵĶ��뷽ʽ 
# pragma pop() 

// λͼ��Ϣͷ�ṹ�� 40���ֽ� 
typedef struct tagBITMAPINFOHEADER
{
	DWORD biSize; // �̶�ֵ40
	LONG biWidth; // ͼƬ��������
	LONG biHeight; // ͼƬ��������
	WORD biPlanes; 
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage; // ͼƬ���ݴ�С
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed; // �Ƿ�ʹ�õ�ɫ�壬��ɫ����ɫ��Ŀ
	DWORD biClrImportant;
 }BITMAPINFOHEADER, *PBITMAPINFOHEADER;

 // ��ɫ�����ݽṹ 4���ֽ� 
typedef struct tagRGBQUAD
{
	BYTE rgbBlue;
	BYTE rgbGreen;
	BYTE rgbRed;
	BYTE rgbReserved;
 }RGBQUAD, *PRGBQUAD;
 
//  typedef struct BMPFILEPTR
// {//����bmp�ļ�ָ������
//     PBITMAPFILEHEADER bmpFileHeader;//bmp�ļ�ͷָ��
//     PBITMAPINFOHEADER bmpInfoHeader;//bmp��Ϣͷָ��
//     PRGBQUAD  bmpColorTable;//��ɫ��ָ��
// }BMPFILEPTR;

#endif
 



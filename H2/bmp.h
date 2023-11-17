/* C语言读入图像 位图文件结构声明 */
#ifndef BMP_H_INCLUDED
#define BMP_H_INCLUDED

typedef unsigned short WORD;//2*8=16
typedef unsigned long DWORD;//4*8=32
typedef long LONG;//4*8=32
typedef unsigned char BYTE;//1*8=8

// #pragma pack(1) 指示编译器按照1字节的对齐方式来存储结构体成员
#pragma pack(1) 
// 定义位图文件头结构体 14个字节 
typedef struct tagBITMAPFILEHEADER
{
	WORD bfType; 
	DWORD bfSize; // 整个图片大小 
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffBits; // 头部总大小
}BITMAPFILEHEADER, *PBITMAPFILEHEADER;
// #pragma pop()函数用于恢复默认的对齐方式 
# pragma pop() 

// 位图信息头结构体 40个字节 
typedef struct tagBITMAPINFOHEADER
{
	DWORD biSize; // 固定值40
	LONG biWidth; // 图片宽像素数
	LONG biHeight; // 图片高像素数
	WORD biPlanes; 
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage; // 图片内容大小
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed; // 是否使用调色板，调色板颜色数目
	DWORD biClrImportant;
 }BITMAPINFOHEADER, *PBITMAPINFOHEADER;

 // 调色板数据结构 4个字节 
typedef struct tagRGBQUAD
{
	BYTE rgbBlue;
	BYTE rgbGreen;
	BYTE rgbRed;
	BYTE rgbReserved;
 }RGBQUAD, *PRGBQUAD;
 
//  typedef struct BMPFILEPTR
// {//定义bmp文件指针类型
//     PBITMAPFILEHEADER bmpFileHeader;//bmp文件头指针
//     PBITMAPINFOHEADER bmpInfoHeader;//bmp信息头指针
//     PRGBQUAD  bmpColorTable;//颜色表指针
// }BMPFILEPTR;

#endif
 



/*
 Класс одного пикселя
 */
#ifndef C_PIXEL_H
#define C_PIXEL_H
//========================================================================
 //---------------------------- ПОДКЛЮЧАЕМЫЕ ФАЙЛЫ ------------------------
 //========================================================================

 //========================================================================
 //-------------------------------- КОНСТАНТЫ -----------------------------
 //========================================================================

 //========================================================================
 //--------------------------- ОБЪЯВЛЕНИЕ КЛАССОВ -------------------------
 //========================================================================
class cPixel{
 //------------------------------------------------------------------------
 // Атрибуты
 //------------------------------------------------------------------------
 
public:
 unsigned char ColorX;
 static unsigned char R;
 static unsigned char G;
 static unsigned char B;

 //------------------------------------------------------------------------
 // Конструкторы
 //------------------------------------------------------------------------
  cPixel();
  cPixel(unsigned char r, unsigned char g, unsigned char b);
 //------------------------------------------------------------------------
 // Методы
 //------------------------------------------------------------------------
 void code(unsigned char r, unsigned char g, unsigned char b);
 void decode();
 
};//End of class cPixel

 //========================================================================
 //--------------------------- РЕАЛИЗАЦИЯ МЕТОДОВ -------------------------
 //========================================================================

//
// Конструкторы
//
cPixel::cPixel()
{
	R = 0;
	G = 0;
	B = 150;
}

cPixel::cPixel(unsigned char r, unsigned char g, unsigned char b)
{
  code(r, g, b);
}

void cPixel::code(unsigned char r, unsigned char g, unsigned char b)
{
  ColorX = 0;
  ColorX |= r & 0xC0;
  ColorX |= (g & 0xE0) >> 2;
  ColorX |= (b & 0xE0) >> 5;
}

void cPixel::decode()
{
  cPixel::R = ColorX & 0xC0;
  cPixel::G = (ColorX & 0x38) << 2;
  cPixel::B = (ColorX & 0x07) << 5;
}

//===========================СТАТИЧЕСКИЕ ПЕРЕМЕННЫЕ==========================

unsigned char cPixel::R = 0x80;
unsigned char cPixel::G = 0x80;
unsigned char cPixel::B = 0x80;


#endif

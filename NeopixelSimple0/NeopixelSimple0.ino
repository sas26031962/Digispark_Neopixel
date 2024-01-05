#include <Adafruit_NeoPixel.h>

// Вывод контроллера Arduino к которому подключён NeoPixels
#define PIN            0

// Количество NeoPixels, подключённых к контроллеу Arduino
//#define NUMPIXELS      16
#define NUMPIXELS      8

// Объект управления NeoPixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // Задержка переключения между операциями
int R = 100;
int G = 150;
int B = 0;
//----------------------------------------------------------------
// Программа начальной установки
//----------------------------------------------------------------
void setup() 
{
  pixels.begin(); // Инициализация объекта NeoPixel
}

//----------------------------------------------------------------
// Главный цикл программы
//----------------------------------------------------------------
void loop() 
{
  // Последовательное включение элементов объекта
  for(int i=0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(R,G,B)); 
    pixels.show(); 
    delay(delayval); 
  }
}//End of void loop() 

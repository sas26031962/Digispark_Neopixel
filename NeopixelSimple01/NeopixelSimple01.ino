#include <Adafruit_NeoPixel.h>

// Вывод контроллера Arduino к которому подключён NeoPixels
#define PIN            0

// Количество NeoPixels, подключённых к контроллеу Arduino
#define NUMPIXELS      62
//#define NUMPIXELS      8

#define START_DELAY 1000

// Объект управления NeoPixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//int delayval = 500; // Задержка переключения между операциями
int delayval = 100; // Задержка переключения между операциями
int R = 0;
int G = 0;
int B = 150;

//----------------------------------------------------------------
// Программа начальной установки
//----------------------------------------------------------------
void setup() 
{
  pixels.begin(); // Инициализация объекта NeoPixel
  
  pixels.setPixelColor(0, pixels.Color(R,G,B));
  pixels.show(); 
  delay(START_DELAY);
}

//----------------------------------------------------------------
// Главный цикл программы
//----------------------------------------------------------------
void loop() 
{
  // Последовательное включение элементов объекта
  for(int i = 1; i < NUMPIXELS; i++)
  {
    if(i % 2) R = 150; else R = 0;
    if(i % 3) G = 150; else G = 0;
    if(i % 5) B = 150; else B = 0;
    
    pixels.setPixelColor(i - 1, pixels.Color(0,0,0)); 
    pixels.setPixelColor(i, pixels.Color(R,G,B)); 
    pixels.show(); 
    delay(delayval); 
  }
    pixels.setPixelColor(NUMPIXELS - 1, pixels.Color(0,0,0)); 
    pixels.show(); 
  
}//End of void loop() 

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
//int delayval = 100; // Задержка переключения между операциями
//int delayval = 50; // Задержка переключения между операциями
//int delayval = 30; // Задержка переключения между операциями
int delayval = 20; // Задержка переключения между операциями

int R = 0;
int G = 0;
int B = 150;

int X = 1;
int PreX = 0;
bool Direction = true;
bool IsRefraction = false;

//----------------------------------------------------------------
// Программа начальной установки
//----------------------------------------------------------------
void setup() 
{
  pixels.begin(); // Инициализация объекта NeoPixel
  
  pixels.setPixelColor(PreX, pixels.Color(R,G,B));
  pixels.show(); 
  delay(START_DELAY);
}

//----------------------------------------------------------------
// Главный цикл программы
//----------------------------------------------------------------
void loop() 
{
  setColor(X); 
  draw(X);
  move();
  delay(delayval); 
//  // Последовательное прямое включение элементов объекта
//  Direction = true;
//  for(int i = X; i < NUMPIXELS; i++)
//  {
//    setColor(i);
//    draw(i);
//    
//    int x = delayval / 2;
//    x = x + random(x);
//    delay(x); 
//  }
//
//  // Последовательное обратное включение элементов объекта 
//  Direction = false;
//  for(int i =  NUMPIXELS - 2; i > 0; i--)
//  {
//
//    setColor(i);
//    draw(i);
//    
//    int x = delayval / 2;
//    x = x + random(x);
//    delay(x); 
//  }
//    pixels.setPixelColor(0, pixels.Color(0,0,0)); 
//    pixels.show(); 
//  
}//End of void loop() 

void setColor(int x)
{
  if(x % 2) R = 150; else R = 0;
  if(x % 3) G = 150; else G = 0;
  if(x % 5) B = 150; else B = 0;
}

void draw(int x)
{
  if(Direction)
  {
    if(IsRefraction)
    {
      IsRefraction = false;  
    }
    else
    {
      pixels.setPixelColor(x - 1, pixels.Color(0,0,0));
    } 
    pixels.setPixelColor(x, pixels.Color(R,G,B)); 
  }
  else
  {
    if(IsRefraction)
    {
      IsRefraction = false;  
    }
    else
    {
      pixels.setPixelColor(x + 1, pixels.Color(0,0,0));
    } 
    pixels.setPixelColor(x, pixels.Color(R,G,B)); 
  }
    pixels.show(); 
}

void move()
{
  if(Direction)
  {
    X++;
    if(X == NUMPIXELS - 1)
    {
      Direction = !Direction;
      IsRefraction = true;
    }
  }
  else
  {
    X--;
    if(X == 0)
    {
      Direction = !Direction;
      IsRefraction = true;
    }
  }
}//End of void move()

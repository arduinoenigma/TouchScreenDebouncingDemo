#include <TFTv2.h>
#include <SPI.h>
#include <SeeedTouchScreen.h>

byte releasecount = 0;
byte state = 0;
bool pressed = false;

//init TouchScreen port pins
TouchScreen ts = TouchScreen(XP, YP, XM, YM);

void setup() {
  Serial.begin(9600);
  Tft.TFTinit();  //init TFT library
}

void loop() {

  Point p = ts.getPoint();
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);

  if (p.z > 1000)
  {
    Serial.print("Phantom touch at ");
    Serial.print(p.x);
    Serial.print(" ");
    Serial.println(p.y);
    Tft.fillCircle(p.x, p.y, 4, RED);
  }

  // if no max detection phantom touches are detected
  if ((p.z > __PRESURE) && (p.z < 1000))
  {
    pressed = true;
  }
  else
  {
    pressed = false;
  }

  switch (state)
  {
    case 0:
      {
        if (pressed)
        {
          // do entry tasks here
          Tft.fillCircle(p.x, p.y, 6, GREEN);

          Serial.print("initial screen touch at ");
          Serial.print(p.x);
          Serial.print(" ");
          Serial.println(p.y);

          releasecount = 0;
          state = 1;
        }
        break;
      }

    case 1:
      {
        if (!pressed)
        {
          Serial.println("no touch detected");
          releasecount++;
        }
        else
        {
          // send x and y to task needing press and hold
          Tft.fillCircle(p.x, p.y, 2, BLUE);

          Serial.print("screen touch at ");
          Serial.print(p.x);
          Serial.print(" ");
          Serial.println(p.y);

          releasecount = 0;
        }

        // adjust this threshold, or use timer
        if (releasecount > 10)
        {
          // do cleanup tasks here
          Tft.fillRectangle(0, 0, 240, 320, BLACK);
                    
          Serial.println("release registered");
          state = 0;
        }
        break;
      }
  }
}

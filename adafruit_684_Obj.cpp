#include "adafruit_684_Obj.h"

static const int16_t OLED_WIDTH = 96;    ///< The width of the display
static const int16_t OLED_HEIGHT = 64;   ///< The height of the display

float		percBlack = 0;  
colorObj	gColor; 


colorObj* sDim(colorObj* inColor) {

	//return inColor;							// Debug. Keeps display on.
	if (percBlack<=0) return inColor;
	if (percBlack>=100) return &black;
	gColor.setColor(inColor);
	gColor.blend(&black,percBlack);
	return &gColor;
}
	
  
adafruit_684_Obj::adafruit_684_Obj(byte inCS,byte inRST)
  :displayObj(true,true,false,true,false) {

  theOLED = NULL;
  cs = inCS;
  rst = inRST;
}

adafruit_684_Obj::~adafruit_684_Obj(void) {

    if (theOLED) { 
      delete theOLED;
      theOLED = NULL;
    }
  }

  
bool adafruit_684_Obj::dispObjBegin(void) { 

  theOLED = new Adafruit_SSD1331(&SPI,cs, LC_DC, rst);
  if (theOLED!=NULL) {
    theOLED->begin();
    return true;
  }
  return false;
}


int adafruit_684_Obj::width(void)																							{ return theOLED->width(); }
int adafruit_684_Obj::height(void)																							{ return theOLED->height(); }
void adafruit_684_Obj::setRotation(byte inRotation)																	{ theOLED->setRotation(inRotation); }
void adafruit_684_Obj::setTextColor(colorObj* inColor)																{ theOLED->setTextColor(sDim(inColor)->getColor16()); }
void adafruit_684_Obj::setTextColor(colorObj* tColor,colorObj* bColor)											{ theOLED->setTextColor(sDim(tColor)->getColor16(),sDim(bColor)->getColor16()); }
void adafruit_684_Obj::setTextSize(byte inSize)																			{ theOLED->setTextSize(inSize); }
void adafruit_684_Obj::setTextWrap(boolean wrap)																		{ theOLED->setTextWrap(wrap); }
void adafruit_684_Obj::setFont(const GFXfont* font)																	{ theOLED->setFont(font); }
void adafruit_684_Obj::setCursor(int x,int y)																			{ theOLED->setCursor(gX(x),gY(y)); }
void adafruit_684_Obj::drawText(char* inText)																			{ theOLED->print(inText); }
void adafruit_684_Obj::fillScreen(colorObj* inColor)																	{ theOLED->fillScreen(sDim(inColor)->getColor16()); }
void adafruit_684_Obj::fillRect(int x,int y,int width,int height,colorObj* inColor)							{ theOLED->fillRect(gX(x),gY(y), width, height,sDim(inColor)->getColor16()); }
void adafruit_684_Obj::drawRect(int x,int y,int width,int height,colorObj* inColor)							{ theOLED->drawRect(gX(x),gY(y), width, height,sDim(inColor)->getColor16()); }
void adafruit_684_Obj::fillRect(rect* inRect,colorObj* inColor)													{ theOLED->fillRect(gX(inRect->x),gY(inRect->y), inRect->width, inRect->height,sDim(inColor)->getColor16()); }
void adafruit_684_Obj::drawRect(rect* inRect,colorObj* inColor)													{ theOLED->drawRect(gX(inRect->x),gY(inRect->y), inRect->width, inRect->height,sDim(inColor)->getColor16()); }
void adafruit_684_Obj::fillRoundRect(int x,int y,int width,int height,int radius,colorObj* inColor)	{ theOLED->fillRoundRect(gX(x),gY(y),width,height,radius,sDim(inColor)->getColor16()); }
void adafruit_684_Obj::drawRoundRect(int x,int y,int width,int height,int radius,colorObj* inColor)	{ theOLED->drawRoundRect(gX(x),gY(y),width,height,radius,sDim(inColor)->getColor16()); }
void adafruit_684_Obj::drawCircle(int x,int y,int diam, colorObj* inColor)										{ drawRoundRect(gX(x),gY(y),diam,diam,diam/2,inColor); }
void adafruit_684_Obj::fillCircle(int x,int y,int diam, colorObj* inColor)										{ fillRoundRect(gX(x),gY(y),diam,diam,diam/2,inColor); }
void adafruit_684_Obj::drawVLine(int x,int y,int height,colorObj* inColor)										{ theOLED->drawFastVLine(gX(x),gY(y),height,sDim(inColor)->getColor16()); }
void adafruit_684_Obj::drawHLine(int x,int y,int width,colorObj* inColor)										{ theOLED->drawFastHLine(gX(x),gY(y),width,sDim(inColor)->getColor16()); }
void adafruit_684_Obj::drawLine(int x,int y,int x2,int y2,colorObj* inColor)									{ theOLED->drawLine(gX(x),gY(y),gX(x2),gY(y2),sDim(inColor)->getColor16()); }
void adafruit_684_Obj::drawPixel(int x,int y,colorObj* inColor)													{ theOLED->drawPixel(gX(x),gY(y),sDim(inColor)->getColor16()); }







 

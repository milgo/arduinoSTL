#ifndef _GUI_H
#define _GUI_H

#include "messages.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define MAIN_MENU_OPTS 4
#define COMM_MENU_OPTS 6
#define MAX_STRING_SIZE 10

#define BUTTON_DOWN 0
#define BUTTON_LEFT 2
#define BUTTON_RIGHT 1
#define BUTTON_UP 3
#define BUTTON_ENTER 4
#define IS_PRESSED(BUTTONS, BUTTON) (((BUTTONS) & (1<<(BUTTON))) == (1<<(BUTTON)))

extern void setupGUI();
extern int showMenu(const char * const *menu, int from, int to);
extern long int enterValue(int msg, long int curVal, bool isSigned, int len, int maxDigit);
extern void printA(const char *const* arr, int id);
extern unsigned char getButtons();
extern void printMessageAndWaitForButton(int msg);
extern void displaySetTextNormal();
extern void displaySetTextInvert();
extern void displayClear();
extern void displayDisplay();
extern void displaySetCursor(uint8_t x, uint8_t y);
extern void displayPrint(const char* msg);
extern void displayPrint(long i);

#endif //_GUI_H

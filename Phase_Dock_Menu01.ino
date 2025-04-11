#include <GEM_u8g2.h>

// Include sprites of animation frames
// (moved to separate file to save space)
#include "frames.h"

// Create an instance of the U8g2 library.
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int brightness = 50;
bool enableFeature = true;

GEMItem itemBrightness("Brightness:", brightness);
GEMItem itemEnableFeature("Enable Feature:", enableFeature);
GEMItem itemAboutLink("About", menuPageAbout);

// Create mennu page object of class GEMPage. Menu page holds menu items (GEMItem) and represents menu level.
GEMPage menuPageMain("Main Menu");
GEMPage menuPageSettings("Settings");
GEMPage menuPageAbout("About");

// Create menu object of class GEM_u8g2. Supply its constructor with reference to u8g2 object we created earlier
GEM_u8g2 menu(u8g2, GEM_POINTER_ROW, GEM_ITEMS_COUNT_AUTO);

void setup() {
    // Serial communication setup
  Serial.begin(115200);

  // U8g2 library init. Pass pin numbers the buttons are connected to.
  // The push-buttons should be wired with pullup resistors (so the LOW means that the button is pressed)
  u8g2.begin(/*Select/OK=*/ 32, /*Right/Next=*/ 14, /*Left/Prev=*/ 33, /*Up=*/ 26, /*Down=*/ 27, /*Home/Cancel=*/ 25);

  menu.init();
  setupMenu();
}

void setupMenu() {
  // Add menu items to menu page
  menuPageMain.addMenuItem(itemBrightness);
  menuPageMain.addMenuItem(itemEnableFeature);
  menuPageMain.addMenuItem(itemAboutLink);

  // Add menu page to menu and set it as current
  menu.setMenuPageCurrent(menuPageMain);
}

void loop() {
  // If menu is ready to accept button press...
  if (menu.readyForKey()) {
    // ...detect key press using U8g2 library
    // and pass pressed button to menu
    menu.registerKeyPress(u8g2.getMenuEvent());
  }
}

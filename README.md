# GEM-OLED-Menu
## **OLED Hierarchical Menu System with GEM Library**

This project implements a customizable hierarchical menu system for embedded systems using an OLED display. It uses the **GEM (Good Enough Menu)** library for efficient menu navigation and the **U8g2** library for dynamic screen rendering.

---

## **Features**
- **Multi-level hierarchical menus** with parent/child relationships.
- **Variable editing** for `int`, `bool`, `float`, and `char` types.
- **Dynamic screen rendering** using U8g2 graphics library.
- **Low memory footprint**, making it ideal for resource-constrained microcontrollers.

---

## **Why Choose GEM?**

### 1. **Object-Oriented Design**
GEM leverages C++ classes (`GEMPage`, `GEMItem`, `GEM_u8g2`) to encapsulate:
- Menu item state management.
- Display rendering logic.
- Navigation stack handling.

This makes it easy to build complex menus without worrying about low-level implementation details.

### 2. **Ease of Use**
The library simplifies menu creation with intuitive syntax:  
>GEMPage mainMenu("Settings");  
>GEMItem brightnessItem("Brightness", brightnessVal);  
>mainMenu.addMenuItem(brightnessItem);  
>menu.init(mainMenu);  


### 3. **Display Compatibility**
- Supports **128x64** and **128x32** OLED displays.
- Works with both **I2C** and **SPI** interfaces.
- Automatically adapts to different screen dimensions.

---

## **Button Configuration**

The GEM library supports flexible button setups, ranging from **3 to 6 buttons**, depending on your hardware configuration. Below is how we mapped our buttons but this is flexible

| Action      | GEM Constant      | Pin we used   |
|-------------|-------------------|---------------|
| Select      | `PIN_SELECT`      | 32            |
| Right       | `PIN_RIGHT`       | 14            |
| Left        | `PIN_LEFT`        | 33            |
| Up          | `PIN_UP`          | 26            |
| Down        | `PIN_DOWN`        | 27            |
| Escape      | `PIN_HOME`        | 25            |

---

## **Installation**

1. Install the required libraries via the Arduino IDE Library Manager:
   - [GEM Library](https://github.com/Spirik/GEM) (v1.5+)
   - [U8g2](https://github.com/olikraus/u8g2) (v2.32+)

2. Connect your OLED display and buttons according to your hardware schematic.

3. Wire the buttons to your microcontroller, ensuring they match the configuration in your code.

---

## **Example Usage**

Below is a simple example of setting up a hierarchical menu system:  

```
#include <GEM_u8g2.h>

// Initialize U8g2 and GEM objects  
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  
GEM_u8g2 menu(u8g2, GEM_POINTER_ROW, GEM_ITEMS_COUNT_AUTO);  //menu object of class GEM_u8g2 

// Define variables  
int number = 50;

// Create Pages
GEMPage mainMenu("Main Menu");  
GEMPage settingsPage("Settings");

// Create items to display on pages
GEMItem welcomeMessage("Welcome");
GEMItem settingsLink("--> Settings", settingsPage);
GEMItem settingItemInt("Number", number);

void setup() {
   Serial.begin(115200); // Serial communication setup
   u8g2.begin(/*Select/OK=*/ 7, /*Right/Next=*/ 4, /*Left/Prev=*/ 3, /*Up=*/ 5, /*Down=*/ 2, /*Home/Cancel=*/ 6);

   menu.init();
   setupMenu();
   menu.drawMenu();
}

void setupMenu() {
  mainMenu
    .addMenuItem(welcomeMessage)
    .addMenuItem(settingsLink); // this links the menu and settings page together
  settingsPage
    .setParentMenuPage(mainMenu) // sets the parent page of the settings page to the main menu page
    .addMenuItem(settingItemInt); // an editable number displayed on the settings page

  // Add menu page to menu and set it as current
  menu.setMenuPageCurrent(mainMenu);
}

void loop() {
  // If menu is ready to accept button press...
  if (menu.readyForKey()) {
    // ...detect key press using U8g2 library
    // and pass pressed button to menu
    menu.registerKeyPress(u8g2.getMenuEvent());
  }
}

```
---

## **Credits**
- [GEM Library](https://github.com/Spirik/GEM): Core menu logic.
- [U8g2 Library](https://github.com/olikraus/u8g2): OLED rendering engine.

---

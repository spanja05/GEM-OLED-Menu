# GEM-OLED-Menu
## **OLED Hierarchical Menu System with GEM Library**

This project implements a customizable hierarchical menu system for embedded systems using an OLED display. It uses the **GEM (Good Enough Menu)** library for efficient menu navigation and the **U8g2** library for dynamic screen rendering.

---

## **Features**
- **Multi-level hierarchical menus** with parent/child relationships.
- **Variable editing** for `int`, `bool`, `float`, and `char` types.
- **Rotary encoder/button navigation** with flexible configurations.
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
| Select      | `GEM_KEY_SELECT`  | 32            |
| Right       | `GEM_KEY_RIGHT`   | 14            |
| Left        | `GEM_KEY_LEFT`    | 33            |
| Up          | `GEM_KEY_UP`      | 26            |
| Down        | `GEM_KEY_DOWN`    | 27            |
| Escape      | `GEM_KEY_CANCEL`  | 25            |

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

>#include <U8g2lib.h>  
>#include <GEM.h>  
>
>// Initialize U8g2 and GEM objects  
>U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);  
>GEM_u8g2 menu(u8g2);  
>
>// Define variables  
>int brightness = 50;  
>bool enableFeature = true;  
>
>// Create menu pages and items  
>void setup() {  
>>u8g2.begin();  
>>
>>GEMPage mainMenu("Main Menu");  
>>GEMPage settingsPage("Settings");
>>
>>//Connecting and Populating Menu  
>>mainMenu.addMenuItem(GEMItem("Settings", settingsPage)); // add settings page to mainMenu  
>>settingsPage.addMenuItem(GEMItem("Brightness:", brightness)); // add brightness item to settingsPage  
>>settingsPage.addMenuItem(GEMItem("Enable Feature:", enableFeature)); // add checkbox item to settingsPage  
>>
>>menu.init(mainMenu); // Initialize menu system
>
>}  
>
>void loop() {  
>>menu.handleInput(); // Handle button presses or rotary encoder input
>
>}  

---

## **Adding and Linking Pages / Menus**

Basic Concept  
You create a new GEMPage, then add it as a child to a GEMItem, which is added to the parent page. For example:  

>// Creating the page objects  
>GEMPage mainMenu("Main Menu");  
>GEMPage settingsPage("Settings");  
>GEMPage displayPage("Display");  
>
>// Linking pages together  
>mainMenu.addMenuItem(GEMItem("Settings", settingsPage));  
>settingsPage.addMenuItem(GEMItem("Display", displayPage));  


This creates a structure like:  
Main Menu  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── Settings  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── Display  

---

## **Credits**
- [GEM Library](https://github.com/Spirik/GEM): Core menu logic.
- [U8g2 Library](https://github.com/olikraus/u8g2): OLED rendering engine.

---

#include <GEM_u8g2.h>

// Create an instance of the U8g2 library.
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

bool controlFeature = false;
int xCoord = 0;
int yCoord = 0;
int zCoord = 0;
bool selectFeature = false;

// Create page objects of class GEMPage. Menu page holds menu items (GEMItem) and represents menu level.
GEMPage homePage("Home");
GEMPage menuPageMain("Main Menu");
GEMPage teleoperation("Teleoperation"); //Teleoperation submenu
GEMPage reactiveControl("Reactive Control");
GEMPage fsm("Finite State Machine");
GEMPage scriptedControl("Scripted Control");
GEMPage smartDecisions("Sensor + Logic");
GEMPage subsumptionArch("Subsumption Architecture");
GEMPage swarmBehavior("Swarm Behavior");
GEMPage directControl("Direct Control");
GEMPage assistedControl("Assisted Control");

GEMItem phaseDock("Phase Dock");
GEMItem mainMenuLink("--> Main Menu", menuPageMain);
GEMItem teleoperationLink("Teleoperation", teleoperation); // Create menu item linked to teleoperation page
GEMItem reactiveControlLink("Reactive Control", reactiveControl);
GEMItem fsmLink("Finite State Machine", fsm);
GEMItem scriptedControlLink("Scripted Control", scriptedControl);
GEMItem smartDecisionsLink("Sensor + Logic", smartDecisions);
GEMItem subsumptionArchLink("Subsumption Architecture", subsumptionArch);
GEMItem swarmBehaviorLink("Swarm Behavior", swarmBehavior);
GEMItem directControlLink("Direct Control", directControl);
GEMItem assistedControlTeleopLink("Assisted Control", assistedControl);
GEMItem assistedControlReactiveLink("Assisted Control", assistedControl);

GEMItem xPositionTeleop("x coordinate: ", xCoord);
GEMItem yPositionTeleop("y coordinate: ", yCoord);
GEMItem zPositionTeleop("z coordinate: ", zCoord);

GEMItem xPositionReactive("x coordinate: ", xCoord);
GEMItem yPositionReactive("y coordinate: ", yCoord);
GEMItem zPositionReactive("z coordinate: ", zCoord);

GEMItem controlOption("Manual: ", controlFeature);
GEMItem selectOption("Select: ", selectFeature);

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
  menu.drawMenu();
}

void setupMenu() {
  homePage
    .addMenuItem(phaseDock)
    .addMenuItem(mainMenuLink);
  menuPageMain
    .setParentMenuPage(homePage)
    .addMenuItem(teleoperationLink)
    .addMenuItem(reactiveControlLink)
    .addMenuItem(fsmLink)
    .addMenuItem(scriptedControlLink)
    .addMenuItem(smartDecisionsLink)
    .addMenuItem(subsumptionArchLink)
    .addMenuItem(swarmBehaviorLink);

  teleoperation
    .setParentMenuPage(menuPageMain)
    .addMenuItem(xPositionTeleop)
    .addMenuItem(yPositionTeleop)
    .addMenuItem(zPositionTeleop)
    .addMenuItem(directControlLink)
    .addMenuItem(assistedControlTeleopLink);

  reactiveControl
    .setParentMenuPage(menuPageMain)
    .addMenuItem(xPositionReactive)
    .addMenuItem(yPositionReactive)
    .addMenuItem(zPositionReactive)
    .addMenuItem(assistedControlReactiveLink);

  fsm
    .setParentMenuPage(menuPageMain);

  scriptedControl
    .setParentMenuPage(menuPageMain);

  smartDecisions
    .setParentMenuPage(menuPageMain)
    .addMenuItem(xPositionTeleop); // this will NOT display on the page since it is already tied to the Teleoperations page

  subsumptionArch
    .setParentMenuPage(menuPageMain);

  swarmBehavior
    .setParentMenuPage(menuPageMain);

  directControl
    .setParentMenuPage(teleoperation)
    .addMenuItem(controlOption);

  assistedControl
    .setParentMenuPage(menuPageMain)
    .addMenuItem(selectOption);

  // Add menu page to menu and set it as current
  menu.setMenuPageCurrent(homePage);
}

void loop() {
  // If menu is ready to accept button press...
  if (menu.readyForKey()) {
    // ...detect key press using U8g2 library
    // and pass pressed button to menu
    menu.registerKeyPress(u8g2.getMenuEvent());
  }
}

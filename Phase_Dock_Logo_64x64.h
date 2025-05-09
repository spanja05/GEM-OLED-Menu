/*
  Party Hard menu example using GEM library.

  Sprites of the animation frames used in the example.
  
  Additional info (including the breadboard view) available on GitHub:
  https://github.com/Spirik/GEM
  
  This example code is in the public domain.

  PHASE DOCK (Consult Your Community):-

  Included below are two frames of the Phase Dock logo shrunk to 64 x 64 pixels.
  Image was converted using https://javl.github.io/image2cpp/ and enabling the 'Swap bits in byte' option.
  Worked on by Micah Carson, Simone Panja, Colin Walls, and Darryl Thomas


*/

#define partyFrame1_width  64
#define partyFrame1_height 64
static const unsigned char partyFrame1_bits [] U8X8_PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xcd, 0x33, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xcc, 0x33, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xc4, 0x33, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xcc, 0x33, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xdc, 0x3b, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xbf, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xfd, 0xff, 0xff, 
	0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xcf, 0xfb, 0xfc, 0xff, 0xf7, 0xff, 
	0xff, 0x07, 0xcc, 0x33, 0x38, 0x20, 0xe0, 0xff, 0xff, 0x47, 0xc8, 0x33, 0x30, 0x37, 0xfa, 0xff, 
	0xff, 0xe7, 0xc9, 0x33, 0x33, 0x3f, 0xff, 0xff, 0xff, 0xe7, 0x08, 0x30, 0x33, 0x38, 0xf0, 0xff, 
	0xff, 0x47, 0x08, 0x10, 0x63, 0x30, 0xf0, 0xff, 0xff, 0x07, 0xcc, 0x11, 0xe0, 0x23, 0xff, 0xff, 
	0xff, 0xc7, 0xcf, 0x13, 0xa2, 0x23, 0xfe, 0xff, 0xff, 0xe7, 0xcf, 0x93, 0x07, 0x30, 0xe0, 0xff, 
	0xff, 0xe7, 0xcf, 0xdb, 0x67, 0x78, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x81, 0x03, 0x39, 0xff, 0xff, 
	0xff, 0xff, 0x80, 0x01, 0x03, 0x19, 0xff, 0xff, 0xff, 0x7f, 0x9c, 0x38, 0xf1, 0x89, 0xff, 0xff, 
	0xff, 0xff, 0x9c, 0x3c, 0xf9, 0xc1, 0xff, 0xff, 0xff, 0xff, 0x9c, 0x3c, 0xf9, 0xc1, 0xff, 0xff, 
	0xff, 0xff, 0x9c, 0x3c, 0xf9, 0xc9, 0xff, 0xff, 0xff, 0xff, 0x9c, 0x38, 0xf1, 0x99, 0xff, 0xff, 
	0xff, 0xff, 0x80, 0x01, 0x03, 0x19, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x81, 0x03, 0x39, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

#define partyFrame2_width  64
#define partyFrame2_height 64
static const unsigned char partyFrame2_bits [] U8X8_PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xcd, 0x33, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xcc, 0x33, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xc4, 0x33, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xcc, 0x33, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xc4, 0x23, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xdc, 0x3b, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xbf, 0xfc, 0xff, 0xff, 
	0xff, 0xff, 0x3f, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xfd, 0xff, 0xff, 
	0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xcf, 0xfb, 0xfc, 0xff, 0xf7, 0xff, 
	0xff, 0x07, 0xcc, 0x33, 0x38, 0x20, 0xe0, 0xff, 0xff, 0x47, 0xc8, 0x33, 0x30, 0x37, 0xfa, 0xff, 
	0xff, 0xe7, 0xc9, 0x33, 0x33, 0x3f, 0xff, 0xff, 0xff, 0xe7, 0x08, 0x30, 0x33, 0x38, 0xf0, 0xff, 
	0xff, 0x47, 0x08, 0x10, 0x63, 0x30, 0xf0, 0xff, 0xff, 0x07, 0xcc, 0x11, 0xe0, 0x23, 0xff, 0xff, 
	0xff, 0xc7, 0xcf, 0x13, 0xa2, 0x23, 0xfe, 0xff, 0xff, 0xe7, 0xcf, 0x93, 0x07, 0x30, 0xe0, 0xff, 
	0xff, 0xe7, 0xcf, 0xdb, 0x67, 0x78, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x81, 0x03, 0x39, 0xff, 0xff, 
	0xff, 0xff, 0x80, 0x01, 0x03, 0x19, 0xff, 0xff, 0xff, 0x7f, 0x9c, 0x38, 0xf1, 0x89, 0xff, 0xff, 
	0xff, 0xff, 0x9c, 0x3c, 0xf9, 0xc1, 0xff, 0xff, 0xff, 0xff, 0x9c, 0x3c, 0xf9, 0xc1, 0xff, 0xff, 
	0xff, 0xff, 0x9c, 0x3c, 0xf9, 0xc9, 0xff, 0xff, 0xff, 0xff, 0x9c, 0x38, 0xf1, 0x99, 0xff, 0xff, 
	0xff, 0xff, 0x80, 0x01, 0x03, 0x19, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x81, 0x03, 0x39, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// Splash is the custom type used internally in GEM library for convenient way of storing XBM graphics of Splash screen
const Splash partyFrame1 = {partyFrame1_width, partyFrame1_height, partyFrame1_bits};
const Splash partyFrame2 = {partyFrame2_width, partyFrame2_height, partyFrame2_bits};


const Splash frames[] = {partyFrame1, partyFrame2};

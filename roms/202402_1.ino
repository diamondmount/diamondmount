int hwYpos;
 int hwXpos;

  #include <stdint.h>
  #include <LCD.h>
  #include <SPI.h>
  #include <XPT2046.h>
  #include <Touch.h>
  #include <EEPROM.h>


void SMS() {
  Tft.lcd_clear_screen(YELLOW);
    Tft.lcd_display_string(0, 0, (const uint8_t *)"<", FONT_1608, BLACK);
  	  Tft.lcd_display_string(0, 20, (const uint8_t *)"Soon", FONT_1608, BLACK);
  	  hwXpos = EEPROM.read(250) * 2;
     hwYpos = EEPROM.read(251) * 2;
    Tp.tp_draw_board();
    if(hwYpos > 0 && hwYpos < 20 && hwXpos > 0 && hwXpos < 20){
     home();
   EEPROM.write(250, 0);
   EEPROM.write(251, 0);
    }
}

void info() {
  Tft.lcd_clear_screen(BLACK);
    Tft.lcd_display_string(0, 0, (const uint8_t *)"<", FONT_1608, WHITE);
  	  Tft.lcd_display_string(0, 60, (const uint8_t *)"XCENT", FONT_1608, WHITE);
  	  Tft.lcd_display_string(0, 80, (const uint8_t *)"http://diamondmount.github.io/main/", FONT_1206, BLUE);
  	  Tft.lcd_display_string(0, 100, (const uint8_t *)"XCENT OS Version: 202402.1", FONT_1206, WHITE);
  	  hwXpos = EEPROM.read(250) * 2;
     hwYpos = EEPROM.read(251) * 2;
    Tp.tp_draw_board();
    if(hwYpos > 0 && hwYpos < 20 && hwXpos > 0 && hwXpos < 20){
     home();
   EEPROM.write(250, 0);
   EEPROM.write(251, 0);
    }
}

void shutdown() {
   void(* resetFunc) (void) = 0;
   resetFunc();
}

void home() {
  Tft.lcd_clear_screen(WHITE);
   Tft.lcd_draw_rect(1, 280, 40, 60, BLUE);
  	 Tft.lcd_draw_rect(61, 280, 40, 60, CYAN);
  	 Tft.lcd_draw_rect(121, 280, 40, 60, YELLOW);
  	 Tft.lcd_draw_rect(200, 280, 40, 60, BLACK);
  	// Dock_menu
    hwXpos = EEPROM.read(250) * 2;
     hwYpos = EEPROM.read(251) * 2;
    Tp.tp_draw_board();
    if(hwYpos > 280 && hwYpos < 320 && hwXpos > 0 && hwXpos < 60){
     Phone();
   EEPROM.write(250, 0);
   EEPROM.write(251, 0);
    }
    hwXpos = EEPROM.read(250) * 2;
     hwYpos = EEPROM.read(251) * 2;
    Tp.tp_draw_board();
    if(hwYpos > 280 && hwYpos < 320 && hwXpos > 41 && hwXpos < 80){
     info();
   EEPROM.write(250, 0);
   EEPROM.write(251, 0);
    }
    hwXpos = EEPROM.read(250) * 2;
     hwYpos = EEPROM.read(251) * 2;
    Tp.tp_draw_board();
    if(hwYpos > 280 && hwYpos < 320 && hwXpos > 81 && hwXpos < 120){
     SMS();
   EEPROM.write(250, 0);
   EEPROM.write(251, 0);
    }
    hwXpos = EEPROM.read(250) * 2;
     hwYpos = EEPROM.read(251) * 2;
    Tp.tp_draw_board();
    if(hwYpos > 280 && hwYpos < 320 && hwXpos > 121 && hwXpos < 240){
     shutdown();
   EEPROM.write(250, 0);
   EEPROM.write(251, 0);
    }
}

void Phone() {
  Tft.lcd_clear_screen(GBLUE);
    Tft.lcd_display_string(0, 0, (const uint8_t *)"<", FONT_1608, WHITE);
  	  Tft.lcd_display_string(0, 20, (const uint8_t *)"Soon", FONT_1608, WHITE);
  	  hwXpos = EEPROM.read(250) * 2;
     hwYpos = EEPROM.read(251) * 2;
    Tp.tp_draw_board();
    if(hwYpos > 0 && hwYpos < 20 && hwXpos > 0 && hwXpos < 20){
     home();
   EEPROM.write(250, 0);
   EEPROM.write(251, 0);
    }
}


void setup() {
  Tp.tp_init();
 Tp.tp_adjust();
 Tp.tp_dialog();
  Tft.lcd_clear_screen(BLACK);

     SPI.setDataMode(SPI_MODE3);
 SPI.setBitOrder(MSBFIRST);
 SPI.setClockDivider(SPI_CLOCK_DIV4);
  SPI.begin();
  Tft.lcd_init();
 Tft.lcd_clear_screen(BLACK);


}

void loop() {
  // Loader
      Tft.lcd_display_string(0, 0, (const uint8_t *)"Unlocked. Current version: 202402.1", FONT_1206, WHITE);
    	  Tft.lcd_display_string(106, 100, (const uint8_t *)"XCENT", FONT_1608, WHITE);
    	  Tft.lcd_display_string(0, 280, (const uint8_t *)"No Jailbreak Detected.", FONT_1206, WHITE);
    	  Tft.lcd_display_string(0, 300, (const uint8_t *)"Powered by Diamond Mount", FONT_1206, BLUE);
    	delay(3000);
    home();

}
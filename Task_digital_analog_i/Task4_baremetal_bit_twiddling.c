#include "sam.h"
#include <Arduino.h>

#define LED_PORT 1        // PORTB on SAMD21
#define LED_PIN  10       // PB10 (D10 on the MKR board)
#define LED_MASK (1u << LED_PIN)

void setup() {
  // enable clock for the PORT module
  PM->APBBMASK.reg |= PM_APBBMASK_PORT;

  // make PB10 a plain GPIO (no peripheral mux / input / pull)
  PORT->Group[LED_PORT].PINCFG[LED_PIN].bit.PMUXEN = 0;
  PORT->Group[LED_PORT].PINCFG[LED_PIN].bit.INEN   = 0;
  PORT->Group[LED_PORT].PINCFG[LED_PIN].bit.PULLEN = 0;

  // PB10 becomes an output, start LOW (LED off)
  PORT->Group[LED_PORT].DIRSET.reg = LED_MASK;
  PORT->Group[LED_PORT].OUTCLR.reg = LED_MASK;
}

void loop() {
  PORT->Group[LED_PORT].OUTTGL.reg = LED_MASK;  // toggle pin
  delay(1000);
}

#ifndef DRV8837C_H
#define DRV8837C_H

/**
 * DRV8837C datasheet:https://www.ti.com/lit/ds/symlink/drv8837c.pdf?HQS=dis-dk-null-digikeymode-dsf-pf-null-wwe&ts=1617351582787
 */

#define FORWARD 1
#define REVERSE 0

class DRV8837C {
  public:
    /**
     * Constructor
     * 
     * @param pin_nSleep - pin number corresponding to DRV8837C's nSleep input
     * @param pin_in1 - pin number corresponding to DRV8837C's IN1 input
     * @param pin_in2 - pin number corresponding to DRV8837C's IN2 input
     * @param invertDirection - reverses pin_in1 and pin_in2 assignment to adjust forward/reverse direction
     */
    DRV8837C(uint8_t pin_nSleep, uint8_t pin_in1, uint8_t pin_in2, bool invertDirection = false);

    /**
     * Toggles DRV8837C's nSleep pin state HIGH/ON
     */
    void enable();

    /**
     * Toggles DRV8837C's nSleep pin state LOW/OFF
     */
    void disable();

    /**
     * Gets the DRV8837C's nSleep pin state
     */
    bool getEnableState();

    /**
     * Sets the DRV8837C driver to drive in a given direction at a specified magnitude
     * 
     * @param magnitude - magnitude of driving speed
     * @param direction - direction of driving
     */
    void drive(uint8_t magnitude, bool direction = FORWARD);

    /**
     * Sets the DRV8837C to coast (LOW output to IN1 and IN2)
     */
    void off();

    /**
     * Sets the DRV8837C to brake (HIGH output to IN1 and IN2)
     * Warning: Not recommended to brake for very long
     */
    void brake();

  private:
    /**
     * DRV8837C nSleep pin number
     */
    uint8_t _pin_nSleep;

    /**
     * DRV8837C IN1 pin number
     */
    uint8_t _pin_in1;

    /**
     * DRV8837C IN2 pin number
     */
    uint8_t _pin_in2;
  
    /**
     * Current state of DRV8837C's nSleep pin state
     */
    bool _enabled = false;

    /**
     * Initializes DRV8837C
     */
    void initialize();

    /**
     * drive DRV8837C's nSleep pin
     * 
     * @param enabled - Set 
     */
    void setEnableState(bool enabled);
};

#endif

const int STEPPER_STEP_COUNT = 8;
const int STEPPER_PIN_COUNT  = 4;

class Engine {
  private:
    const int[STEPPER_STEP_COUNT][STEPPER_PIN_COUNT] ROTOR_STATE_TABLE = {
      {0, 0, 0, 1},
      {0, 0, 1, 1},
      {0, 0, 1, 0},
      {0, 1, 1, 0},
      {0, 1, 0, 0},
      {1, 1, 0, 0},
      {1, 0, 0, 0}
      {1, 0, 0, 1}
    };

    int[STEPPER_PIN_COUNT] stepperPins;

    int rotorState = 0;

    /**
     * Lets the stepper do a step
     * direction = 1:   rotate right
     * direction = -1:  rotate left
     */
    void doStep(int direction) {
      rotorState = (rotorState + direction) % STEPPER_STEP_COUNT;
      
      for (int i = 0; i < STEPPER_PIN_COUNT; i++) {
        digitalWrite(stepperPin[i], ROTOR_STATE_TABLE[rotorState][i])
      }
    }

  public:
    /**
     * Saves the pins used by the stepper ({IN1, IN2, IN3, IN4})
     * and sets them as output
     */
    Engine(int[STEPPER_PIN_COUNT] pins) {
      for (int i = 0; i < STEPPER_PIN_COUNT; i++) {
        stepperPins[i] = pins[i];
        pinMode(stepperPins[i], OUTPUT);
      }
    }

    /**
     * Lets the stepper rotate left
     */
    void rotateLeft() {
      doStep(-1);
    }

    /**
     * Lets the stepper rotate right
     */
    void rotateRight() {
      doStep(1);
    }
}


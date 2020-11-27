#include <Task.h>
#include <TaskScheduler.h>

// Timed task to blink a LED.
class Blinker : public TimedTask
{
  public:
    // Create a new blinker for the specified pin and rate.
    Blinker(uint8_t _pin, uint64_t _rate);
    virtual void run(uint64_t now);
  private:
    // LED pin.
    uint8_t pin;      
    // Blink rate.
    uint32_t rate;    
    // Current state of the LED.
    bool on;          
};

Blinker::Blinker(uint8_t _pin, uint64_t _rate)
  : TimedTask(millis()),
  pin(_pin),
  rate(_rate),
  on(false)
{
  // Set pin for output.
  pinMode(pin, OUTPUT);     
}

void Blinker::run(uint64_t now)
{
  // If the LED is on, turn it off and remember the state.
  if (on) {
    digitalWrite(pin, LOW);
    on = false;
    // If the LED is off, turn it on and remember the state.
  } else {
    digitalWrite(pin, HIGH);
    on = true;
  }
  // Run again in the required number of milliseconds.
  incRunTime(rate);
}

TaskScheduler *scheduler;
Task *tasks[1];

// the setup function runs once when you press reset or power the board
void setup() {
  tasks[0] = new Blinker(13,1000);
  scheduler = new TaskScheduler(tasks, NUM_TASKS(tasks));
}

// the loop function runs over and over again forever
void loop() {
  scheduler->run(millis()); 
}

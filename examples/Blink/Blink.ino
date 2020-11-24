#include <Debugger.h>
#include <Task.h>
#include <TaskScheduler.h>

TaskScheduler *scheduler;

Task *tasks[1];

class BlinkTask: public TimedTask {
  public:

    BlinkTask(uint64_t now, uint64_t rate)
      : TimedTask(now),
      rate(rate) {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);

    // Start led off;
    state = false;
    digitalWrite(LED_BUILTIN, LOW);
  };

  private:
    uint64_t rate;
    bool state;

    void run(uint64_t now) override {
      state = !state;
      digitalWrite(LED_BUILTIN, state);

      // Run again in the specified time.
      incRunTime(rate);
    }

};


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  tasks[0] = new BlinkTask(0,100);
  scheduler = new TaskScheduler(tasks, NUM_TASKS(tasks));
}

// the loop function runs over and over again forever
void loop() {
  scheduler->run(millis()); 
}

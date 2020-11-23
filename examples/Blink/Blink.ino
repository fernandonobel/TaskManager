#include <Debugger.h>
#include <Task.h>
#include <TaskScheduler.h>

#include "BlinkTask.h"

TaskScheduler *scheduler;

Task *tasks[1];


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  tasks[0] = new BlinkTask(0,1000,NULL);
  scheduler = new TaskScheduler(tasks, NUM_TASKS(tasks));
}

// the loop function runs over and over again forever
void loop() {
  scheduler->run(millis()); 
}

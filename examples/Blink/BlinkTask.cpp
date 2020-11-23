#include "BlinkTask.h"

/**
   @brief: Constructor of BlinkTask.

   @param: uint64_t _now           Time in 100ns of first execution of the task.
         : uint64_t _rate          Time interval in 100ns of execution of the task.
         : Debugger *_ptrDebugger  Pointer to debugger.

*/
BlinkTask::BlinkTask(uint64_t _now, uint64_t _rate, Debugger *_ptrDebugger)
  : TimedTask(_now),
    rate(_rate),
    ptrDebugger(_ptrDebugger)
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // Start led off;
  state = false;
  digitalWrite(LED_BUILTIN, LOW);
}

/**
   @brief: Destructor of BlinkTask.

*/
BlinkTask::~BlinkTask() {}

/**
   @brief: Toggle the led.

   @param: uint64_t now Current time in 100 nanoseconds.

   @return: void
*/
void BlinkTask::run(uint64_t now) {
  state = !state;
  digitalWrite(LED_BUILTIN, state);
  
  if (ptrDebugger)  ptrDebugger->debugWrite("BlinkTask: Toggle the led output.");

  // Run again in the specified time.
  incRunTime(rate);
}

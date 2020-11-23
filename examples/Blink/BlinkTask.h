#ifndef BLINKTASK_H
#define BLINKTASK_H

#include <inttypes.h>

#include "Task.h"
#include "Debugger.h"

/**
   @brief This class controls the green led of the turbidostat.

   In normal operation the led will be ON and it will blink if there is a problem.

*/
class BlinkTask: public TimedTask {
  public:
    BlinkTask(uint64_t now, uint64_t rate, Debugger *_ptrDebugger = NULL);
    ~BlinkTask();

  private:
    uint64_t rate;
    Debugger *ptrDebugger;

    bool state;

    void run(uint64_t now) override;

};

#endif /* end of include guard: BLINKTASK_H */

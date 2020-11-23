/*
 * Copyright (C) 2020 Fernando Nóbel Santos Navarro 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @file Task.h
 *
 * @brief Description of classes Task, TriggeredTask and TimedTask.
 * 
 * @author Fernando Nóbel Santos Navarro
 * Contact: fersann1@upv.es
 *
 */

#ifndef TASK_H
#define TASK_H

#include <inttypes.h>

// Maximum time into the future - approximately 50 days.
#define MAX_TIME UINT32_MAX

/**
 * @brief Abstract task class.
 *
 */
class Task {
  public:
    virtual bool canRun(uint64_t now) = 0; // Can the task currently run?
    virtual void run(uint64_t now) = 0;    // Run the task.

};

/**
 * @brief A task triggered by an external event.
 *
 */
class TriggeredTask : public Task {
  public:
    bool        canRun(uint64_t now) override;
    inline void setRunnable() { runFlag = true; }
    inline void resetRunnable() { runFlag = false; }

  protected:
    bool runFlag; // True if the task is currently runnable.
};

/**
 * @brief A task that is run on a periodic basis.
 *
 */
class TimedTask : public Task {
  public:
    inline          TimedTask(uint64_t when) { runTime = when; }
    bool            canRun(uint64_t now) override;
    inline void     setRunTime(uint64_t when) { runTime = when; }
    inline void     incRunTime(uint64_t inc) { runTime += inc; }
    inline uint64_t getRunTime() {return runTime; }

  protected:
    uint64_t runTime;   // The system clock tick when the task can next run.
};  

#endif /* end of include guard: TASK_H */

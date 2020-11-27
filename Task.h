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
    /**
     * @brief: Can the task currently run?
     * This method must be overriden to implement a task.
     *
     * @param: uint64_t now Current time in units defined in the TaskScheduler.
     *
     * @return: bool True if the task has to be runned.
     */
    virtual bool canRun(uint64_t now) = 0; // Can the task currently run?

    /**
     * @brief: Run the task.
     * This method must be overriden to implement a task.
     *
     * @param: uint64_t now Current time in units defined in the TaskScheduler.
     *
     * @return: void.
     */
    virtual void run(uint64_t now) = 0;    // Run the task.
};

/**
 * @brief A task triggered by an external event.
 *
 */
class TriggeredTask : public Task {
  public:
    /**
     * @brief: Can the task currently run?
     * The task can run when the runFlag is true.
     *
     * @param: uint64_t now Current time in units defined in the TaskScheduler.
     *
     * @return: bool True if the task has to be runned.
     */
    inline bool canRun(uint64_t now) override { return runFlag; };

    /**
     * @brief: Mark the task as runnable.
     *
     * @return: bool True if the task has to be runned.
     */
    inline void setRunnable() { runFlag = true; } 

    /**
     * @brief: Mark the task as non-runnable.
     *
     * @return: bool True if the task has to be runned.
     */
    inline void resetRunnable() { runFlag = false; }

  protected:
    // True if the task is currently runnable.
    bool runFlag; 
};

/**
 * @brief A task that runs at a certain time.
 *
 */
class TimedTask : public Task {
  public:
    /**
     * @brief: Constuctor of TimedTask.
     *
     * @param: uint64_t when The time when the task can run.
     */
    inline TimedTask(uint64_t when) { runTime = when; }

    /**
     * @brief: Can the task currently run?
     * The task can run when current time is >= runTime.
     *
     * @param: uint64_t now Current time in units defined in the TaskScheduler.
     *
     * @return: bool True if the task has to be runned.
     */
    inline bool canRun(uint64_t now) override { return now >= runTime; };

    /**
     * @brief: Set the time when the task can run.
     *
     * @param: uint64_t when The time when the task can run.
     */
    inline void setRunTime(uint64_t when) { runTime = when; }

    /**
     * @brief: Increment the time when the task can run.
     *
     * @param: uint64_t inc The time increment we want to add.
     */
    inline void incRunTime(uint64_t inc) { runTime += inc; }

    /**
     * @brief: Get the time when the task can run.
     *
     * @param: uint64_t The time when the task can run.
     */
    inline uint64_t getRunTime() {return runTime; }

  protected:
    // The system clock tick when the task can next run.
    uint64_t runTime; 
};  

#endif /* end of include guard: TASK_H */

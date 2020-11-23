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
 * @file TaskScheduler.h
 *
 * @brief Description of class TaskScheduler.
 * 
 * @author Fernando Nóbel Santos Navarro
 * Contact: fersann1@upv.es
 *
 */

#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H

#include "Task.h"

// Calculate the number of tasks in the array, given the size.
#define NUM_TASKS(T) (sizeof(T) / sizeof(Task))

/**
 * @brief The task scheduler will execute the tasks when needed.
 *
 * @details A task has priotity form another is it is added first to the **tasks.
 * This way, first added tasks will have the most priotity.
 *
 */
class TaskScheduler {
  public:
    TaskScheduler(Task **task, uint8_t numTasks);
    void run(uint64_t now);

  private:
    Task **tasks;   // Array of task pointers.
    int numTasks;   // Number of tasks in the array.

};

#endif /* end of include guard: TASKSCHEDULER_H */

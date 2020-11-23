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

#include "TaskScheduler.h"

/**
 * @brief: Constructor of TaskScheduler.
 *
 * @param: Task **_tasks Array of pointers of tasks to execute.
 *       : uint8_t _numTasks Number of tasks in the array.
 *
 */
TaskScheduler::TaskScheduler(Task **_tasks, uint8_t _numTasks) :
  tasks(_tasks),
  numTasks(_numTasks) {
  }


/**
 * @brief: Check if any task needs to be executed and execute it.
 *
 * @param: uint64_t now Current time in 100 nanoseconds.
 *
 * @return: void 
 */
void TaskScheduler::run(uint64_t now) {
  Task **tpp = tasks;
  for (int t = 0; t < numTasks; t++) {
    Task *tp = *tpp;
    if (tp->canRun(now)) {
      tp->run(now);
      break;
    }
    tpp++;
  }
}

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

#include "Task.h"

/**
 * @brief: The task can run when the flag is set.
 *
 * @param: uint64_t now  Current time in 100 nanoseconds.
 *
 * @return: bool 
 */
bool TriggeredTask::canRun(uint64_t now) {
  return runFlag;
}

/**
 * @brief: The task can run when current time is >= runTime.
 *
 * @param: uint64_t now  Current time in 100 nanoseconds.
 *
 * @return: bool 
 */
bool TimedTask::canRun(uint64_t now) {
  return now >= runTime;
}

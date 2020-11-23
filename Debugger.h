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
 * @file Debugger.h
 *
 * @brief Description of class Debugger.
 * 
 * @author Fernando Nóbel Santos Navarro
 * Contact: fersann1@upv.es
 *
 */

#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <Arduino.h>
#include "Task.h"

/**
 * @brief Task used for debugging.
 *
 */
class Debugger : public Task {
  public:
    Debugger();
    void debugWrite(String debugMsg);
    virtual void run(uint64_t now)    override;
    virtual bool canRun(uint64_t now) override;
};

#endif /* end of include guard: DEBUGGER_H */

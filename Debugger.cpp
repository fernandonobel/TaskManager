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

#include "Debugger.h" 

/**
 * @brief: Constructor of Debugger.
 *
 */
Debugger::Debugger()
  : Task()
{
  Serial.begin(9600);
}

/**
 * @brief: The Debugger is executed when there is serial data.
 *
 * @param: uint64_t now Current time in 100 nanoseconds.
 *
 * @return: bool 
 */
bool Debugger::canRun(uint64_t now)
{
  return Serial.available() > 0;
}

/**
 * @brief: The Debugger echoes the data recived form serial.
 *
 * @param: uint64_t now Current time in 100 nanoseconds.
 *
 * @return: void 
 */
void Debugger::run(uint64_t now)
{
  uint16_t byteCount = 0;

  Serial.println("-----------------");
  Serial.println("Input Received...");
  Serial.println("-----------------");
  while (Serial.available() > 0) {
    int byte = Serial.read();
    Serial.print("'") ;
    Serial.print(char(byte));
    Serial.print("' = ");
    Serial.print(byte, DEC);
    Serial.println(" ");
    if (byte == '\r') {
      Serial.print('\n', DEC);
    }

    byteCount++;
  }

  Serial.println("-----------------");
  Serial.print("Bytes Received: "); Serial.println(String(byteCount));
  Serial.println("-----------------");

}

/**
 * @brief: Provies basic debug info for other tasks.
 *
 * @param: String debugMsg Debug message to send.
 *
 * @return: void 
 */
void Debugger::debugWrite(String debugMsg)
{
  Serial.println(debugMsg);
}

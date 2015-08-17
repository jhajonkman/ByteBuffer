/*
Arduino Buffered Serial
A library that helps establish buffered serial communication with a 
host application.
Copyright (C) 2010 Sigurður Örn Aðalgeirsson (siggi@media.mit.edu)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
 
#ifndef ByteBuffer_h
#define ByteBuffer_h

#include "Arduino.h"

#include "Time.h"
#include <print.h>

class ByteBuffer
{
public:
	ByteBuffer();

	// This method initializes the datastore of the buffer to a certain sizem the buffer should NOT be used before this call is made
	void init(uint16_t buf_size);

	// This method resets the buffer into an original state (with no data)	
	void clear();

	// This releases resources for this buffer, after this has been called the buffer should NOT be used
	void deAllocate();

	// Returns how much space is left in the buffer for more data
	uint16_t getFreeSize();

	// Returns how much space is used in the buffer
	uint16_t getSize();

	// Returns the maximum capacity of the buffer
	uint16_t getCapacity();

	// This method returns the byte that is located at index in the buffer but doesn't modify the buffer like the get methods (doesn't remove the retured byte from the buffer)
	byte peek(uint16_t index);

	//
	// Put methods, either a regular put in back or put in front
	// 
	int putInFront(byte in);
	int put(byte in);

	int putU16InFront(uint16_t in);
	int putU16(uint16_t in);

	int putIntInFront(int in);
	int putInt(int in);

	int putLongInFront(long in);
	int putLong(long in);

	int putTimeInFront(time_t in);
	int putTime(time_t in);

	int putFloatInFront(float in);
	int putFloat(float in);

    //
	// Get methods, either a regular get from front or from back
	//  
	byte get();
	byte getFromBack();

	uint16_t getU16();
	uint16_t getU16FromBack();

	int getInt();
	int getIntFromBack();

	long getLong();	
	long getLongFromBack();	

	time_t getTime();	
	time_t getTimeFromBack();	

	float getFloat();	
	float getFloatFromBack();
    
    byte* getByteBuffer();

private:
	byte* data;

	uint16_t capacity;
	uint16_t position;
	uint16_t length;
};

#endif


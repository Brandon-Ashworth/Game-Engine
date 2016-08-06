#pragma once

#include "Sound.h"

/**
 * @brief The controller for the sound engine
 * @details The user takes sound data structures and sends them here to be processed
 * @author  Umar Badat
 */
class SoundEngine
{
public:
	/**
	 * @brief Constructors that don't do anythiing
	 * 
	 */
	SoundEngine(void);
	/**
	 * @brief destructors that don't do anything (they don't need to)
	 * 
	 */
	~SoundEngine(void);

	/**
	 * @brief the sound object sent in is played once
	 * @details The user sends in the sound object and it is played once 
	 * 
	 * @param sound the object containing the sound
	 */
	void playOnce(Sound &sound);

	/**
	 * @brief loop the sound 
	 * @details The sound object sent here will play and loop till a pause or stop command is called
	 * 
	 * @param sound the object containing a sound, see Sound class for more details
	 */
	void playWithLoop(Sound &sound);

	/**
	 * @brief sets volume
	 * @details sets the volume of the object you sent in
	 * 
	 * @param sound sound object to volume adjust
	 * @param volume the volume number to change it to, it can range from 0 to 100 (float) and wil be set to 0 or 100 if found outside the range
	 */
	void setVolume(Sound &sound, float volume);

	/**
	 * @brief get volume
	 * @details Gets the volume of the sound object you sent in
	 * 
	 * @param sound Sound object to find the volume of
	 * @return float representing the volume of the sound object
	 */
	float getVolume(Sound &sound);

private:

};


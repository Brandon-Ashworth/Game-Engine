#pragma once

#include <SFML\Audio.hpp>
#include <string>


/**
 * @brief Sound facade
 * @details This is the layer between SFML and our interface (equivalant class)
 * @return Used for all the main sound processing
 * @author Umar Badat
 */
class SFML_Sound
{
public:
	enum Sound {
		S_LOOP = 0,
		S_NOTLOOP
	};

	/**
	 * @brief The sound constructor
	 * 
	 */
	SFML_Sound(void);
	~SFML_Sound(void);

	/**
	 * @brief loads sound into ram
	 * @details This function loads the sound into ram so it can be manipulated
	 * 
	 * @param location The location of the sound file
	 * @return true if the program loaded the sound file
	 */
	bool load(std::string location);

	//play the currently selcted sound, maybe call setLoop()
	/**
	 * @brief Plays the sound
	 * @details Plays the sound only once
	 */
	void play();
	//play and set the loop
	/**
	 * @brief Loops the sound
	 * @details Plays the sound until the user pauses or stops it
	 * 
	 * @param loop true if you want it to loop
	 */
	void play(bool loop);
	//pause the currently loaded sound
	/**
	 * @brief Puause the music
	 * @details Pauses the sound currently playing
	 */
	void pause();
	//stop the currently loaded sound
	/**
	 * @brief stops th esound
	 * @details Stops the sound currently being player
	 */
	void stop();
	//set volume
	/**
	 * @brief Sets Volume
	 * @details Sets The volume of the sound can't be above 100 or below 0
	 * 
	 * @param float the new volume value
	 */
	void setVolume(float volume);
	//get volume
	/**
	 * @brief Get volume
	 * @details Get the volume of the sound
	 * @return float, returns a float representing the current volume
	 */
	float getVolume();
	//get loop
	/**
	 * @brief Get the loop
	 * @details retrives the value of if the sound is looping or now
	 * @return bool, return true if the function is looping
	 */
	bool getLoop();
	//set loop, this function should not need or rather should be ignored and only through play should things be done
	void setLoop(bool loop);

private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	

};


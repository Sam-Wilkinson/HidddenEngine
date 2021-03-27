#pragma once
class SoundSystem
{
public:
	SoundSystem() = default;
	virtual ~SoundSystem() = default;


	SoundSystem(const SoundSystem& other) = default; // copy constructor
	SoundSystem(SoundSystem && other) noexcept = default; // move constructor
	SoundSystem& operator=(const SoundSystem & other) = default; // copy assignment
	SoundSystem& operator=(SoundSystem && other) noexcept = default; // move assignment

	virtual void play(const unsigned int id, const float volume) = 0;
	virtual void pause(const unsigned int id) = 0;
	virtual void stop(const unsigned int id) = 0;

protected:

private:


};


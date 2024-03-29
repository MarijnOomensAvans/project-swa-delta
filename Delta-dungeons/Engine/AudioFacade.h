#pragma once
#include "IAudioFacade.h"
#include "AudioWrapper.h"
#include <memory>

class AudioFacade : public IAudioFacade
{
public:
	AudioFacade();
	~AudioFacade() {};
	void playAudio(const std::string& path, bool loop) const override;
	void playEffect(const std::string& path) const override;

private:
	std::unique_ptr<AudioWrapper> wrapper;
};
#pragma once
#include <SFML/Audio.hpp>
#include <stdexcept>
#include <string>
#include "SourceManager.h"

class SoundManager {
public:
    SoundManager() {}

    void Play() {
        sound.play();
    }

    void Stop() {
        sound.stop();
    }

    void SetSound(const std::string& soundPath,SourceManager& soundManager) {
        buffer = soundManager.GetSound(soundPath);
        sound.setBuffer(buffer);
    }

    void SetVolume(float volume) {
        if (volume < 0.0f || volume > 100.0f) {
            throw std::invalid_argument("Volume must be between 0 and 100.");
        }
        sound.setVolume(volume);
    }

    void SetLoop(bool loop) {
        sound.setLoop(loop);
    }

private:
    sf::SoundBuffer buffer; // Almacena los datos del sonido
    sf::Sound sound;        // Reproduce el sonido
};

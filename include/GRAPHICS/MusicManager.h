#pragma once
#include <SFML/Audio.hpp>

class MusicManager
{
public:
    MusicManager() {}

    void Play()
    {
        music.play();
    }

    void Stop()
    {
        music.stop();
    }

    void ChangeMusic(const std::string &newMusicPath)
    {
        music.stop(); // Detener la música actual
        if (!music.openFromFile(newMusicPath))
        {
            throw std::runtime_error("Failed to load new music: " + newMusicPath);
        }
        music.setLoop(true); // Opcional, depende de tu necesidad
        music.play();        // Iniciar la nueva música
    }

private:
    sf::Music music;
};

#pragma once
#include <string>
#include <map>
#include <SFML/Audio.hpp>

class AudioManager {

    public:
        static void playSound(std::string name, bool loop);
        static void stopSound(std::string name);
        static bool soundIsPlaying(std::string name);
        static void loadDemoSound();

    private:
        inline static std::map<std::string, sf::Sound> sounds;
        inline static std::map<std::string, sf::SoundBuffer> buffers;

};

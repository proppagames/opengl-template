#include "AudioManager.h"
#include <iostream>

void AudioManager::playSound(std::string name, bool loop) {
    if (buffers.count(name) == 0) {
        std::cerr << "WARNING: attempted to play sound which doesn't exist: " << name << std::endl;
    }

    sounds.emplace(name, buffers.at(name));
    sounds.at(name).setLooping(loop);
    sounds.at(name).play();
    printf("played sound\n");

}
void AudioManager::stopSound(std::string name) {

}
bool AudioManager::soundIsPlaying(std::string name) {
    return false;
}

void AudioManager::loadDemoSound() {
    std::string path = "assets/audio/ping.wav";
    sf::SoundBuffer buffer;
    bool loaded = buffer.loadFromFile(path);
    if (not loaded) {
        std::cerr << "WARNING: failed to load audio from path: " << path << std::endl;
    } 
    buffers["demo"] = buffer;
}
#include "App.h"
#include "AudioManager.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Graphic.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <filesystem>

App::App(unsigned int scrWidth, unsigned int scrHeight) {
    screenDimensions = glm::ivec2(scrWidth, scrHeight);
}

void App::initialize() {
    this->createDemoObject(); 
    this->setupShaders();
    this->renderer = new Renderer(ResourceManager::getShader("sprite"));

    AudioManager::loadDemoSound();
    AudioManager::playSound("demo", false);

}

void App::createDemoObject() {
    ResourceManager::loadTexture("assets/textures/proppasmile.png", true, "demo");
    glm::vec2 demoGraphicSize(500.0f);
    glm::vec2 demoGraphicPos = glm::vec2(screenDimensions.x/2.0f, screenDimensions.y/2.0f) - glm::vec2(demoGraphicSize/2.0f);
    demoGraphic = new Graphic(demoGraphicPos, demoGraphicSize, 0.0f, ResourceManager::getTexture("demo"));
}

void App::setupShaders() {
    std::cout << "Current path: " << std::filesystem::current_path() << std::endl;
    ResourceManager::loadShader("shaders/default.vert", "shaders/default.frag", nullptr, "sprite");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(screenDimensions.x), static_cast<float>(screenDimensions.y), 0.0f, -1.0f, 1.0f);
    ResourceManager::getShader("sprite")->use().setInteger("image", 0);
    ResourceManager::getShader("sprite")->use().setMatrix4("projection", projection);
}

void App::update(float dt) {

}

void App::render() {
    this->demoGraphic->draw(*this->renderer);
}

App::~App() {
    delete this->renderer;
    delete this->demoGraphic;
}
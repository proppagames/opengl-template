#pragma once
#include <glm/glm.hpp>

class Canvas;
class Graphic;
class Renderer;

class App {
    public:
        App(unsigned int scrWidth, unsigned int scrHeight);
        ~App();

        void initialize();
        void update(float dt);
        void render();

    private:
        void setupShaders();

        void createDemoObject();

        glm::ivec2 screenDimensions;
        Graphic* demoGraphic;
        Renderer* renderer;

};

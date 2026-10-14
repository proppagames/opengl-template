#include "Graphic.h"
#include "Texture.h"
#include "Renderer.h"

#include <iostream>

Graphic::Graphic() 
    : position(0.0f, 0.0f), size(1.0f, 1.0f), rotation(0.0f), color(1.0f)
{ }

Graphic::Graphic(glm::vec2 position, glm::vec2 size, float rotation, Texture* texture)
    : position(position), size(size), rotation(rotation), texture(texture), color(glm::vec4(1.0f)) 
{ }

void Graphic::update(float dt) {

}

void Graphic::draw(Renderer &renderer) {   
    renderer.draw(this->position, this->size, this->rotation, this->texture, this->color);
}



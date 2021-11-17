#ifndef FROMBOOK_BLOCK_H
#define FROMBOOK_BLOCK_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Object.h"

class Block : public Object {
public:
    explicit Block(unsigned int _id = 0);

    void setPos(float x, float y) override;

    sf::Sprite getSprite() override;

    ~Block() = default;

private:

    unsigned int id;
    sf::Sprite mBlock;
    sf::Texture texBlock;
};


#endif //FROMBOOK_BLOCK_H

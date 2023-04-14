//
// Created by Paolo Octoman on 1/16/23.
//

#ifndef WHATEVER_SANDCASTLE_H
#define WHATEVER_SANDCASTLE_H

#include <SFML/Graphics.hpp>

class SandCastle : public sf::Transformable, public sf::Drawable{
private:
     sf::Texture castleTexture;
     sf::Sprite castleSprite;
    sf::Texture smashedTexture;
    sf::Sprite smashedSprite;
    bool standing = false;
public:
    bool isStanding() const;

    SandCastle();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void setStatus(int value);

    void move(sf::Vector2f newPos);
    void move(float x, float y);
    sf::FloatRect getGlobalBounds();



};


#endif //WHATEVER_SANDCASTLE_H

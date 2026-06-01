#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!", Style::Fullscreen);

    window.setFramerateLimit(120);

    Texture textureBackground;
    textureBackground.loadFromFile("assets/graphics/background.png");

    Sprite spriteBackgound;
    spriteBackgound.setTexture(textureBackground);
    spriteBackgound.setPosition(0, 0);

    Texture textureTree;
    textureTree.loadFromFile("assets/graphics/tree.png");

    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    Texture textureBee;
    textureBee.loadFromFile("assets/graphics/bee.png");

    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);

    bool beeActive = false;
    float beeSpeed = 0.0f;

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }




        window.clear();

        window.draw(spriteBackgound);
        window.draw(spriteTree);
        window.draw(spriteBee);

        window.display();
    }

    return 0;
}

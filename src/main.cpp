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

    Texture textureCloud;
    textureCloud.loadFromFile("assets/graphics/cloud.png");

    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;
    
    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }




        window.clear();

        window.draw(spriteBackgound);
       
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        window.draw(spriteTree);
        
        window.draw(spriteBee);

        window.display();
    }

    return 0;
}

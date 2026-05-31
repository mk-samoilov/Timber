#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!", Style::Fullscreen);

    Texture textureBackground;

    textureBackground.loadFromFile("assets/graphics/background.png");

    Sprite spriteBackgound;

    spriteBackgound.setTexture(textureBackground);

    spriteBackgound.setPosition(0, 0);

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }




        window.clear();

        window.draw(spriteBackgound);

        window.display();
    }

    return 0;
}

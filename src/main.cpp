#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Cloud {
public:
    Sprite spriteCloud;
    int cloudID;

    Cloud(Texture& textureCloud, int cloudID)
        : cloudID(cloudID)
    {
        spriteCloud.setTexture(textureCloud);

        spawn();
    }

    void update(Time& dt) {
        spriteCloud.setPosition(
            spriteCloud.getPosition().x - (speed * dt.asSeconds()),
            spriteCloud.getPosition().y
        ); 

        if (spriteCloud.getPosition().x < -310) {
            respawn();
        }
    }
private:
    int speed = 0;

    int gen_width() {
        return (rand() % 1920 + cloudID * 37) % 1920;
    }

    int gen_height() {
        return 12 + ((rand() % 200 + cloudID * 37) % 200);
    }

    int gen_speed() {
        return 10 + ((rand() % 85 + cloudID * 37) % 85);
    }

    void spawn() {
        speed = gen_speed();
        spriteCloud.setPosition(gen_width(), gen_height());
    }

    void respawn() {
        speed = gen_speed();
        spriteCloud.setPosition(2000, gen_height());
    }
};

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!", Style::Fullscreen);

    window.setFramerateLimit(120);

    srand((int)time(0));

    Clock clock;

    bool paused = true;

    int score = 0;

    Text startMessageText;
    Text scoreText;
    
    Font font;
    font.loadFromFile("assets/fonts/HighlandGothicFLF.ttf");

    startMessageText.setFont(font);
    scoreText.setFont(font);

    startMessageText.setString("Press Enter for start!");
    scoreText.setString("Score: 0");

    startMessageText.setCharacterSize(75);
    scoreText.setCharacterSize(80);

    startMessageText.setFillColor(Color::White);
    scoreText.setFillColor(Color::White);

    FloatRect textRect = startMessageText.getLocalBounds();

    startMessageText.setOrigin(
        textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0
    );

    startMessageText.setPosition(
        1920 / 2.0f,
        1080 / 2.0
    );

    scoreText.setPosition(20, 20);

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

    int cloudsCount = 3;

    vector<Cloud> clouds;
    clouds.reserve(cloudsCount);
    for (int i = 0; i < cloudsCount; i++) {
        clouds.emplace_back(textureCloud, i + 1);
    }

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape) || Keyboard::isKeyPressed(Keyboard::Q))
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            paused = false;
        }

        if (paused) {
            window.draw(spriteBackgound);
            window.draw(startMessageText);
            window.display();
            continue;
        }

        Time dt = clock.restart();

        if (!beeActive)
        {
            beeSpeed = (rand() % 200) + 200;

            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);

            beeActive = true;
        }
        else {
            spriteBee.setPosition(
                spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                spriteBee.getPosition().y
            );

            if (spriteBee.getPosition().x < -100)
            {
                beeActive = false;
            }
        }

        window.clear();

        window.draw(spriteBackgound);

        for (auto& cloud : clouds) {
            cloud.update(dt);

            window.draw(cloud.spriteCloud);
        }

        window.draw(spriteTree);
        
        window.draw(spriteBee);

        stringstream ss;
        ss << "Score: " << score;
        scoreText.setString(ss.str());
        window.draw(scoreText);

        window.display();
    }

    return 0;
};

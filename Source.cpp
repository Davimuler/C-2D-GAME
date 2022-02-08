#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "windows.h"
using namespace std;
using namespace sf;
class Being
{
public:
    float ScaleVar;
    float x, y, w, h, dx, dy, speed = 0, aTime;
    int dir;
    string File;
    Texture texture;
    Sprite sprite;
    Being()
    {

    }
    ~Being()
    {

    }
};
class Player :public Being
{
public:
    float Hero_Frame = 0; int JumpSpot = 150; int hp;
    int GroundSpot = 490;
    bool Hero_Left = 0, Hero_Right = 1, Hero_On_Ground = 1, IsJump = 0, Hero_Right_turn = 1, Hero_Left_turn = 0;
    Player()
    {
        hp = 1000;
        File = "Sem_Full.png";
        texture.loadFromFile(File);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(14780, 198, 325, 925));
        ScaleVar = 0.45;
        sprite.setScale(ScaleVar, ScaleVar);
        setDefaultPosition();
    }
    void plusY(int q)
    {
        this->y+= q;
        JumpSpot += q;
        GroundSpot += q;
    }
    void setDefaultValues()
    {
        setDeafaultY();
        setDefaultJumpSpot();
        setDefaultGroundSpot();
    }
    void setDeafaultY()
    {
        y = 490;
    }
    void setDefaultJumpSpot()
    {
        JumpSpot = 150;
    }
    void setDefaultGroundSpot()
    {
        GroundSpot = 490;
    }
    float getHp()
    {
        return hp / 1000;
    }
    void minusHp(int q)
    {
        hp -= q;
    }
    void setDefaultPosition()
    {
        x = 810;
        y = 490;
        sprite.setPosition(x, y);
    }
    void Go(float stime, View& sViev)
    {
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (!((Keyboard::isKeyPressed(Keyboard::Up)) or IsJump or !Hero_On_Ground))
            sprite.setPosition(sprite.getPosition().x, y + 20);
            sprite.setRotation(-10);
            Hero_Left = true;
            Hero_Right = false;
            if (!((Keyboard::isKeyPressed(Keyboard::Up)) or IsJump))
            {
                if (Hero_Frame < 2 && Hero_Frame >= 1)
                {
                    sprite.setTextureRect(IntRect(13377 + 630, 250, -630, 1115));
                }
                else if (Hero_Frame < 3 && Hero_Frame >= 2)
                {
                    sprite.setTextureRect(IntRect(12186 + 630, 250, -630, 1117));
                }
                else if (Hero_Frame < 4 && Hero_Frame >= 3)
                {
                    sprite.setTextureRect(IntRect(11055 + 630, 207, -630, 1120));
                }
                else if (Hero_Frame < 5 && Hero_Frame >= 4)
                {
                    sprite.setTextureRect(IntRect(9977 + 630, 211, -630, 1117));
                }
                else if (Hero_Frame < 6 && Hero_Frame >= 5)
                {
                    sprite.setTextureRect(IntRect(8721 + 630, 191, -630, 1123));
                }
                else if (Hero_Frame < 7 && Hero_Frame >= 6)
                {
                    sprite.setTextureRect(IntRect(7465 + 630, 212, -630, 1124));
                }
                else if (Hero_Frame < 8 && Hero_Frame >= 7)
                {
                    sprite.setTextureRect(IntRect(6209 + 630, 220, -630, 1102));
                }
                else if (Hero_Frame < 9 && Hero_Frame >= 8)
                {
                    sprite.setTextureRect(IntRect(5004 + 630, 201, -630, 1115));
                }
                else if (Hero_Frame < 10 && Hero_Frame >= 9)
                {
                    sprite.setTextureRect(IntRect(3945 + 630, 181, -630, 1119));
                }
                else if (Hero_Frame < 11 && Hero_Frame >= 10)
                {
                    sprite.setTextureRect(IntRect(2828 + 630, 181, -630, 1123));
                }
                else if (Hero_Frame < 12 && Hero_Frame >= 11)
                {
                    sprite.setTextureRect(IntRect(1509 + 630, 181, -630, 1117));
                }
                else if (Hero_Frame < 13 && Hero_Frame >= 12)
                {
                    sprite.setTextureRect(IntRect(241 + 630, 191, -630, 1053));
                }
                else if (Hero_Frame > 13)
                {
                    Hero_Frame -= 12;
                }
            }
            if (sprite.getPosition().x > 0)
            {
                sprite.move(-1.5 * stime, 0);
            }
            Hero_Frame += 0.02 * stime;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (!((Keyboard::isKeyPressed(Keyboard::Up)) or IsJump or !Hero_On_Ground))
            sprite.setPosition(sprite.getPosition().x, y - 20);
            sprite.setRotation(10);
            Hero_Left = false;
            Hero_Right = true;
            if (!((Keyboard::isKeyPressed(Keyboard::Up)) or IsJump))
            {
                if (Hero_Frame < 2 && Hero_Frame >= 1)
                {
                    sprite.setTextureRect(IntRect(13377, 250, 630, 1115));
                }
                else if (Hero_Frame < 3 && Hero_Frame >= 2)
                {
                    sprite.setTextureRect(IntRect(12186, 250, 630, 1117));
                }
                else if (Hero_Frame < 4 && Hero_Frame >= 3)
                {
                    sprite.setTextureRect(IntRect(11055, 207, 630, 1120));
                }
                else if (Hero_Frame < 5 && Hero_Frame >= 4)
                {
                    sprite.setTextureRect(IntRect(9977, 211, 630, 1117));
                }
                else if (Hero_Frame < 6 && Hero_Frame >= 5)
                {
                    sprite.setTextureRect(IntRect(8721, 191, 630, 1123));
                }
                else if (Hero_Frame < 7 && Hero_Frame >= 6)
                {
                        sprite.setTextureRect(IntRect(7465, 212, 630, 1124));
                }
                else if (Hero_Frame < 8 && Hero_Frame >= 7)
                {
                    sprite.setTextureRect(IntRect(6209, 220, 630, 1102));
                }
                else if (Hero_Frame < 9 && Hero_Frame >= 8)
                {
                    sprite.setTextureRect(IntRect(5004, 201, 630, 1115));
                }
                else if (Hero_Frame < 10 && Hero_Frame >= 9)
                {
                    sprite.setTextureRect(IntRect(3945, 181, 630, 1119));
                }
                else if (Hero_Frame < 11 && Hero_Frame >= 10)
                {
                    sprite.setTextureRect(IntRect(2828, 181, 630, 1123));
                }
                else if (Hero_Frame < 12 && Hero_Frame >= 11)
                {
                    sprite.setTextureRect(IntRect(1509, 181, 630, 1117));
                }
                else if (Hero_Frame < 13 && Hero_Frame >= 12)
                {
                    sprite.setTextureRect(IntRect(241, 191, 630, 1053));
                }
                else if (Hero_Frame > 13)
                {
                    Hero_Frame -= 12;
                }
            }
            Hero_Frame += 0.02 * stime;
            if (sprite.getPosition().x < 3650)
            {
                sprite.move(1.5 * stime, 0);
            }
        }
        if (((!(Keyboard::isKeyPressed(Keyboard::Left)) && !(Keyboard::isKeyPressed(Keyboard::Right))) && !(Keyboard::isKeyPressed(Keyboard::Up))))
        {
            sprite.setRotation(0);
            if (Hero_Right)
            {
                sprite.setTextureRect(IntRect(14780, 198, 325, 925));
            }
            if (Hero_Left)
            {
                sprite.setPosition(sprite.getPosition().x, y - 20);
                sprite.setTextureRect(IntRect((14780 + 325), 198, -325, 925));
            }
        }
        if (sprite.getPosition().x > 900 and sprite.getPosition().x < 2790)//3840
        {
            sViev.setCenter(sprite.getPosition().x + 80, 540);
        }
        if (!Hero_On_Ground)
        {
            if (sprite.getPosition().y < GroundSpot)
            {
                sprite.move(0, 1.3 * (stime));
            }
            else
            {
                Hero_On_Ground = true;
            }
        }
        else if ((Keyboard::isKeyPressed(Keyboard::Up)) or IsJump)
        {
            if (Hero_On_Ground)
            {
                IsJump = true;
                if (sprite.getPosition().y > JumpSpot)
                {
                    sprite.move(0, -2 * stime);
                }
                else
                {
                    IsJump = false;
                    Hero_On_Ground = false;
                }
            }
        }
    }
    ~Player()
    {}
};
class Monster :public Being
{
public:
    int start_damage=0,end_damage=0;
    int From_Left_Right;
    bool Near = false;
    Monster()
    {
        srand(time(NULL));
        From_Left_Right = rand() % 2;
    }
    void apear()
    {
        if (From_Left_Right == 1) {
            x = -300;
        }
        else if (From_Left_Right == 0) {
            x = 1940 * 2 + 300;
        }
        sprite.setPosition(x, y);
    }
    void plusY(int q)
    {
        y += q;
    }
    void update()
    {
        switch (dir)
        {
        case 0:dx = speed; dy = 0; break;
        case 1:dx = -speed; dy = 0; break;
        }
        x += dx * aTime;
        y += dy * aTime;
        sprite.setPosition(x, y);
    };
    //virtual void Fight();
};
class Monster_Witch : public Monster
{
public:
    Monster_Witch(float aaTime) :Monster()
    {
        aTime = aaTime;
        ScaleVar = 0.58;
        File = "Monster_Witch.png";
        texture.loadFromFile(File);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(347, 38, 622, 800));
        y = 420;
        speed = 0.1;
        sprite.setScale(ScaleVar, ScaleVar);
        apear();
    }
    void setDefaultY()
    {
        y = 420;
    }
    int getDefaultY() {
        return 420;
    }
    void RotateRight()
    {
        sprite.setTextureRect(IntRect(347, 38, 622, 800));
    }
    void RotateLeft()
    {
        sprite.setTextureRect(IntRect(969, 38, -622, 800));
    }
    void WhereHero(int aX)
    {
        if (sprite.getPosition().x + 210 < aX)
        {
            RotateLeft();
            dir = 0;
            update();
        }
        else if (sprite.getPosition().x - 30 > aX)
        {
            RotateRight();
            dir = 1;
            update();
        }
    }
    void damage(Player& h,Clock &cl)
    {
   end_damage= cl.getElapsedTime().asSeconds();

        if (end_damage-start_damage>=2 && sprite.getPosition().x + 210 >= h.sprite.getPosition().x && sprite.getPosition().x - 30 <= h.sprite.getPosition().x && h.getHp() > 0)
        {
            start_damage= cl.getElapsedTime().asSeconds()+2;
            h.minusHp(20);
        }
    }
};
class Monster_Ghost : public Monster
{
public:
    Monster_Ghost(float aaTime) :Monster()
    {
        ScaleVar = 0.5;
        aTime = aaTime;
        File = "Monster_Ghost.png";
        texture.loadFromFile(File);
        sprite.setTexture(texture);
        y = 500;
        speed = 0.2;
        apear();
        sprite.setScale(ScaleVar, ScaleVar);
    }
    void RotateRight()
    {
        sprite.setTextureRect(IntRect(398, 187, 390, 778));
    }
    void RotateLeft()
    {
        sprite.setTextureRect(IntRect(787, 187, -390, 778));
    }
    void WhereHero(int aX)
    {
        if (sprite.getPosition().x + 90 < aX)
        {
            RotateLeft();
            dir = 0;
            update();
        }
        else if (sprite.getPosition().x - 60 > aX)
        {
            RotateRight();
            dir = 1;
            update();
        }
    }
    void setDefaultY()
    {
        y = 500;
    }
    int getDefaultY() {
        return 500;
    }
    void damage(Player& h,float stime)
    {
       
        if (sprite.getPosition().x + 210 >= h.sprite.getPosition().x && sprite.getPosition().x - 30 <= h.sprite.getPosition().x && h.getHp() > 0 && end_damage==start_damage) 
        {
            h.minusHp(50);
           // cl.getElapsedTime().asSeconds();
            end_damage = start_damage + 20000000;
        }
    }
};

int main()
{
    int start = clock();
    cout << start << endl;
    Clock clock;
    int RECT = 143;
    View viev;
    float Hero_x = 900, Maintime = clock.getElapsedTime().asMicroseconds();;
    Monster_Ghost SomeGhost (Maintime);
    Monster_Witch SomeWitch(Maintime);
    bool Hero_Right = 1, Hero_Left = 0;
    bool escape = 0; bool IsJump = 0;
    int view = 0; 
    int this_view;
    RenderWindow window(VideoMode(1940, 1080), "Supernatural");
    Image icon;
    icon.loadFromFile("Logo.png");
    window.setIcon(90, 64, icon.getPixelsPtr());
    viev.reset(FloatRect(0, 0, 1940, 1080));
    viev.setCenter(970, 540);
    RectangleShape rectangle4, rectangle5;
    RectangleShape  rectangle_backtomap, rectangle_ground, rectangle_resume;
    RectangleShape rectangle_backtomap_escape, rectangle_backtomenu;
    //////////////////////////////////////////////////////////////////////
    //1 symbol 50 font 25 by Y
    rectangle_backtomap_escape.setSize(Vector2f(275, 55));
    rectangle_backtomap_escape.setPosition(858, 355);

    rectangle_resume.setSize(Vector2f(170, 55));
    rectangle_resume.setPosition(900, 300);

    rectangle_ground.setSize(Vector2f(1920, 200));
    rectangle_ground.setPosition(0, 880);
    rectangle_ground.setFillColor(Color(128, 128, 128));

    rectangle_backtomap.setSize(sf::Vector2f(250, 60));
    rectangle_backtomap.setPosition(50, 40);
    rectangle5.setSize(sf::Vector2f(150, 85));
    rectangle5.setPosition(50, 50);
    rectangle4.setSize(Vector2f(250, 60));
    rectangle4.setPosition(870, 680);

    Texture texture_MainMenu, texture_Map, level1, texture_blackground, texture_BackGround, texture_Hero, texture_Flag;
    Texture texture_Level_Factory, texture_Map_Shop, texture_Map_Shop_Shape,texture_PauseBar,texture_Resume_Button;
    Texture texture_Resume_Button_Entered, texture_Settings_Button, texture_Settings_Button_Entered;
    Texture texture_Inventory_Button_Entered, texture_Inventory_Button,texture_Exit_Button, texture_Exit_Button_Entered;
    Texture texture_Level2_Western,texture_heàlthbàr_empty,texture_healthbar_itself;

    texture_healthbar_itself.loadFromFile("healthbar_itself.png");

    texture_heàlthbàr_empty.loadFromFile("heàlthbàr_empty.png");


    texture_Level2_Western.loadFromFile("WesternLevel.png");

    texture_Exit_Button.loadFromFile("Exit_Button.png");
    texture_Exit_Button_Entered.loadFromFile("Exit_Button_Entered.png");
    texture_Inventory_Button.loadFromFile("Inventory_Button.png");
    texture_Inventory_Button_Entered.loadFromFile("Inventory_Button_Entered.png");
    texture_Settings_Button_Entered.loadFromFile("Settings_Button_Entered.png");
    texture_Settings_Button.loadFromFile("Settings_Button.png");
    texture_Resume_Button_Entered.loadFromFile("Resume_Button_Entered.png");
    texture_Resume_Button.loadFromFile("Resume_Button.png");
    texture_PauseBar.loadFromFile("Pause_Bar.png");

    texture_Map_Shop_Shape.loadFromFile("Map_Shop_Shape.png");

    texture_Map_Shop.loadFromFile("Map_Shop.png");

    texture_Level_Factory.loadFromFile("bàckground_fàctory.png");

    texture_Flag.loadFromFile("Flag.png");
    texture_Hero.loadFromFile("Sem_Full.png");
    texture_BackGround.loadFromFile("background.jpg");
    texture_MainMenu.loadFromFile("MainMenu.png");
    texture_blackground.loadFromFile("blackground.png");

    Font font;
    font.loadFromFile("CyrillicOld.ttf");
    Text text_MainMenu_NewGame("", font, 50), text_MainMenu_settings("", font, 50), text_MainMenu_exit("", font, 50), text_MainMenu_LoadGame("", font, 50), text_Back("", font, 80);
    Text text_shop("", font, 65), text_backtomap("Back to map", font, 50);

        texture_Map.loadFromFile("Map.png");
    texture_Map.setSmooth(true);

    Sprite sprite_healthbar_itself(texture_healthbar_itself);
    Sprite sprite_heàlthbàr_empty(texture_heàlthbàr_empty);
    Sprite sprite_Level2_Western(texture_Level2_Western);
    Sprite sprite_Exit_Button;
    Sprite sprite_Inventory_Button;
    Sprite sprite_Settings_Button;
    Sprite sprite_Resume_Button(texture_Resume_Button);
    Sprite sprite_PauseBar(texture_PauseBar);
    Sprite sprite_Map_Shop_Shape(texture_Map_Shop_Shape);
    Sprite sprite_Map_Shop(texture_Map_Shop);
    Sprite sprite_Level_Factory(texture_Level_Factory);
    Sprite sprite_Flag_1(texture_Flag);
    Sprite sprite_Flag_2(texture_Flag);
    Sprite sprite_Flag_3(texture_Flag);
    Sprite sprite_Flag_4(texture_Flag);
    Sprite sprite_Hero(texture_Hero);
    Sprite sprite_Map(texture_Map);
    Sprite sprite_level1(level1);
    Sprite sprite_level2(level1);
    Sprite sprite_level3(level1);
    Sprite sprite_level4(level1);
    Sprite sprite_blackground(texture_blackground);
    Sprite sprite_BackGround(texture_BackGround);

    sprite_blackground.setColor(Color(255, 255, 255, 1));
    sprite_blackground.setScale(1080, 920);

    sprite_Map_Shop_Shape.setColor(Color(255, 255, 255));
    sprite_Flag_1.setColor(Color(150, 0, 0));
    sprite_Flag_2.setColor(Color(100, 100, 100));
    sprite_Flag_3.setColor(Color(100, 100, 100));
    sprite_Flag_4.setColor(Color(100, 100, 100));

    sprite_healthbar_itself.setScale(0.44, 0.44);
    sprite_heàlthbàr_empty.setScale(0.45, 0.45);
    sprite_healthbar_itself.setTextureRect(IntRect(0, 0, 583, 100));

    sprite_Hero.setScale(0.45, 0.45);

    sprite_Map_Shop.setScale(0.22, 0.22);

    sprite_Map_Shop_Shape.setScale(0.228, 0.228);

    sprite_Flag_1.setScale(0.1f, 0.11f);
    sprite_Flag_2.setScale(0.1f, 0.11f);
    sprite_Flag_3.setScale(0.1f, 0.11f);
    sprite_Flag_4.setScale(0.1f, 0.11f);
  

    sprite_Map_Shop_Shape.setPosition(-40, 800);

    sprite_Map_Shop.setPosition(10, 800);

    text_MainMenu_NewGame.setFillColor(Color::White);
    text_MainMenu_NewGame.setString("New Game");
    text_MainMenu_NewGame.setPosition(900, 800);
    text_MainMenu_settings.setFillColor(Color::White);
    text_MainMenu_settings.setString(" Settings");
    text_MainMenu_settings.setPosition(910, 870);
    text_MainMenu_exit.setFillColor(Color::White);
    text_MainMenu_exit.setString(" Exit");
    text_MainMenu_exit.setPosition(965, 940);
    text_MainMenu_LoadGame.setFillColor(Color::White);
    text_MainMenu_LoadGame.setString("Load Game");
    text_MainMenu_LoadGame.setFillColor(Color(128, 128, 128));
    text_Back.setString("Back");
    text_Back.setFillColor(Color::White);
    text_Back.setPosition(50, 30);
    text_shop.setPosition(130, 840);
    text_shop.setString("Shop");
    text_backtomap.setPosition(50, 20);

    texture_MainMenu.setSmooth(true);
    Sprite sprite_MainMenu(texture_MainMenu);
    float CurrentFrame = 0;

    Player Hero;
    int p;
    while (window.isOpen())
    {
        sprite_PauseBar.setPosition(viev.getCenter().x - 550, -100);
        p = viev.getCenter().x - 120;
        sprite_Resume_Button.setPosition(p, 310);
        sprite_Settings_Button.setPosition(p, 410);
        sprite_Inventory_Button.setPosition(p, 510);
        sprite_Exit_Button.setPosition(p, 610);

        sprite_heàlthbàr_empty.setPosition(viev.getCenter().x - 960 -40, -90);
        sprite_healthbar_itself.setPosition(viev.getCenter().x - 960+174,97);
        sprite_healthbar_itself.setTextureRect(IntRect(0, 0, 583 * Hero.getHp(), 100));
        sprite_Map.setPosition(viev.getCenter().x - 960, 0);
        sprite_Flag_1.setPosition(viev.getCenter().x - 960+ 298, 280);
        sprite_Flag_2.setPosition(viev.getCenter().x - 960 + 565, 352);
        sprite_Flag_3.setPosition(viev.getCenter().x - 960 + 800, 445);
        sprite_Flag_4.setPosition(viev.getCenter().x - 960 + 1110, 412);
        text_Back.setPosition(viev.getCenter().x - 970 + 50, 30);

        text_MainMenu_NewGame.setPosition(viev.getCenter().x - 970 + 900, 800);
        text_MainMenu_settings.setPosition(viev.getCenter().x - 970 + 910, 870);
        text_MainMenu_exit.setPosition(viev.getCenter().x - 970 + 965, 940);
        text_MainMenu_LoadGame.setPosition(viev.getCenter().x - 970+900, 730);
        sprite_MainMenu.setPosition(viev.getCenter().x - 960, 0);

        Maintime = clock.getElapsedTime().asMicroseconds(); //äàòü ïðîøåäøåå âðåìÿ â ìèêðîñåêóíäàõ
        clock.restart(); //ïåðåçàãðóæàåò âðåìÿ
        Maintime = Maintime / 1000; //ñêîðîñòü èãðû
        if ((view == 3 || view == 4 || view == 5 || view == 6) && !escape)
        {
            SomeGhost.WhereHero(Hero.sprite.getPosition().x);
            SomeWitch.WhereHero(Hero.sprite.getPosition().x);
            SomeWitch.damage(Hero, clock);
            SomeGhost.damage(Hero,Maintime);
            Hero.Go(Maintime, viev);

        }
        // Îáðàáàòûâàåì ñîáûòèÿ â öèêëå
        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed) {
                if (text_MainMenu_NewGame.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 960, Mouse::getPosition().y+30)) {
                    text_MainMenu_NewGame.setFillColor(Color(21, 117, 90));
                    window.draw(text_MainMenu_NewGame);
                    window.display();
                    Sleep(100);
                    view = 2;
                }
            }
            if (event.type == Event::MouseButtonPressed) {
                if (text_MainMenu_settings.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 960, Mouse::getPosition().y + 35)) {
                    text_MainMenu_settings.setFillColor(Color(21, 117, 90));
                    window.draw(text_MainMenu_settings);
                    window.display();
                    Sleep(100);
                    view = 8;
                }
            }
            if (view == 0 and event.type == Event::MouseButtonPressed) {
                if (text_MainMenu_exit.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 960, Mouse::getPosition().y + 30)) {
                    text_MainMenu_exit.setFillColor(Color(21, 117, 90));
                    window.draw(text_MainMenu_exit);
                    window.display();
                    Sleep(100);
                    window.close();
                }
            }
            if ((view == 8 or view == 2) and event.type == Event::MouseButtonPressed) {

                if (text_Back.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 960, Mouse::getPosition().y-20)) {
                    text_Back.setFillColor(Color(21, 117, 90));
                    window.draw(text_Back);
                    window.display();
                    text_MainMenu_NewGame.setFillColor(Color::White);
                    Sleep(100);
                    text_Back.setFillColor(Color::White);
                    text_MainMenu_settings.setFillColor(Color::White);
                    view = 0;
                }
                if (sprite_Map_Shop.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y) || text_shop.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y)) {
                    text_shop.setFillColor(Color(21, 117, 90));
                    sprite_Map_Shop_Shape.setColor(Color(21, 117, 90));
                    window.draw(sprite_Map_Shop_Shape);
                    window.draw(text_shop);
                    window.display();
                    Sleep(150);
                    view = 7;
                }
                if (sprite_Flag_1.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 960, Mouse::getPosition().y)) {
                    sprite_Flag_1.setColor(Color(21, 117, 90));
                    window.draw(sprite_Flag_1);
                    window.display();
                    Sleep(150);
                    view = 3;
                }
                if (sprite_Flag_2.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 960, Mouse::getPosition().y)) {
                    sprite_Flag_2.setColor(Color(21, 150, 90));
                    window.draw(sprite_Flag_2);
                    window.display();
                    Sleep(150);
                    view = 4;
                }
                if (sprite_Flag_3.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 960, Mouse::getPosition().y)) {
                    sprite_Flag_3.setColor(Color(21, 150, 90));
                    window.draw(sprite_Flag_3);
                    window.display();
                    Sleep(150);
                    view = 5;
                }
                if (sprite_Flag_4.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 960, Mouse::getPosition().y)) {
                    sprite_Flag_4.setColor(Color(21, 150, 90));
                    window.draw(sprite_Flag_4);
                    window.display();
                    Sleep(150);
                    view = 6;
                }
            }
            if (view == 2)
            {
                if (sprite_Map_Shop.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y))
                {
                    sprite_Map_Shop_Shape.setColor(Color(255, 248, 118));
                }
                if (!sprite_Map_Shop.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y))
                {
                    sprite_Map_Shop_Shape.setColor(Color::White);
                }
            }
            if ((view == 3 or view == 4 or view == 5 or view == 6) and escape)
            {
                if (sprite_Resume_Button.getGlobalBounds().contains(Mouse::getPosition().x+viev.getCenter().x-970, Mouse::getPosition().y)) 
                    sprite_Resume_Button.setTexture(texture_Resume_Button_Entered);
                else  sprite_Resume_Button.setTexture(texture_Resume_Button);
                if(sprite_Settings_Button.getGlobalBounds().contains(Mouse::getPosition().x+viev.getCenter().x - 970, Mouse::getPosition().y))
                    sprite_Settings_Button.setTexture(texture_Settings_Button_Entered);
            else   sprite_Settings_Button.setTexture(texture_Settings_Button);
                if (sprite_Inventory_Button.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 970, Mouse::getPosition().y))
                    sprite_Inventory_Button.setTexture(texture_Inventory_Button_Entered);
                else sprite_Inventory_Button.setTexture(texture_Inventory_Button);
                if (sprite_Exit_Button.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 970, Mouse::getPosition().y))
                    sprite_Exit_Button.setTexture(texture_Exit_Button_Entered);
                else sprite_Exit_Button.setTexture(texture_Exit_Button);
            }
            if (view == 7 and event.type == Event::MouseButtonPressed) {

                if (rectangle_backtomap.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y)) {
                    text_backtomap.setFillColor(Color(21, 117, 90));
                    window.draw(text_backtomap);
                    window.display();
                    Sleep(100);
                    sprite_Map_Shop_Shape.setColor(Color::White);
                    text_shop.setFillColor(Color::White);
                    text_backtomap.setFillColor(Color::White);
                    view = 2;
                }
            }

                if ((view == 3 or view == 4 or view == 5 or view == 6) and escape and event.type == Event::MouseButtonPressed) {
                    if (sprite_Settings_Button.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 970, Mouse::getPosition().y))
                    {
                        sprite_Flag_1.setColor(Color(150, 0, 0));
                        sprite_Flag_2.setColor(Color(100, 100, 100));
                        sprite_Flag_3.setColor(Color(100, 100, 100));
                        sprite_Flag_4.setColor(Color(100, 100, 100));
                        Hero.setDefaultPosition();
                        SomeGhost.apear();
                        SomeWitch.apear();
                        escape = false;
                        view = 8;
                    }
                    if (sprite_Resume_Button.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 970, Mouse::getPosition().y)) {
                        Sleep(100);
                        escape = false;
                        view = this_view;
                    }
                    else if (sprite_Exit_Button.getGlobalBounds().contains(Mouse::getPosition().x + viev.getCenter().x - 970, Mouse::getPosition().y)) {
                        Sleep(100);
                        sprite_Flag_1.setColor(Color(150, 0, 0));
                        sprite_Flag_2.setColor(Color(100, 100, 100));
                        sprite_Flag_3.setColor(Color(100, 100, 100));
                        sprite_Flag_4.setColor(Color(100, 100, 100));
                        Hero_x = 810;
                        Hero.setDefaultPosition();
                        SomeGhost.apear();
                        SomeWitch.apear();
                        escape = false;
                        Hero.setDefaultValues();
                        SomeGhost.setDefaultY();
                        SomeWitch.setDefaultY();
                        sprite_healthbar_itself.setTextureRect(IntRect(0, 0, 583, 100));
                        view = 2;
                    }
                }
        }
        if (view == 0)
        {
            window.clear();
            window.draw(sprite_MainMenu);
            window.draw(text_MainMenu_LoadGame);
            window.draw(text_MainMenu_NewGame);
            window.draw(text_MainMenu_settings);
            window.draw(text_MainMenu_exit);
            window.display();
        }
        else
            if (view == 2)//Map
            {
                window.clear();
                window.draw(sprite_Map);
                window.draw(sprite_Flag_1);
                window.draw(sprite_Flag_2);
                window.draw(sprite_Flag_3);
                window.draw(sprite_Flag_4);
                window.draw(sprite_Map_Shop);
                window.draw(sprite_Map_Shop_Shape);
                window.draw(text_shop);
                window.draw(text_Back);
                window.display();
            }
        if (view == 3)//first level
        {
            if (!escape)
            {
                window.clear();
                window.setView(viev);
                window.draw(sprite_Level_Factory);
                window.draw(sprite_heàlthbàr_empty);
                window.draw(sprite_healthbar_itself);
                 window.draw(SomeGhost.sprite);
                window.draw(SomeWitch.sprite);
                window.draw(Hero.sprite);
                window.display();
            }
            if ((Keyboard::isKeyPressed(Keyboard::Escape)))
            {
                escape = 1;
            }
            if (escape)
            {
                window.draw(sprite_blackground);
                window.draw(sprite_PauseBar);
                window.draw(sprite_Resume_Button);
                window.draw(sprite_Settings_Button);
                window.draw(sprite_Inventory_Button);
                window.draw(sprite_Exit_Button);
                window.display();
                this_view = view;
            }
        }
        if (view == 4)//Second level
        {
            if (!escape)
            {
                if (Hero.y == 490)
                    Hero.plusY(130);
                if (SomeGhost.y == SomeGhost.getDefaultY())
                    SomeGhost.plusY(130);
                if (SomeWitch.y == SomeWitch.getDefaultY())
                    SomeWitch.plusY(130);
                window.clear();
                window.setView(viev);
                window.draw(sprite_Level2_Western);
                window.draw(sprite_heàlthbàr_empty);
                window.draw(sprite_healthbar_itself);
                window.draw(SomeGhost.sprite);
                window.draw(SomeWitch.sprite);
                window.draw(Hero.sprite);
                window.display();
            }
            if ((Keyboard::isKeyPressed(Keyboard::Escape)))
            {
                escape = 1;
            }
            if (escape)
            {
                window.draw(sprite_blackground);
                window.draw(sprite_PauseBar);
                window.draw(sprite_Resume_Button);
                window.draw(sprite_Settings_Button);
                window.draw(sprite_Inventory_Button);
                window.draw(sprite_Exit_Button);
                window.display();
                this_view = view;
            }
        }
        if (view == 5)//Third level
        {
            if (!escape)
            {
                window.clear();
                window.draw(sprite_BackGround);
                window.draw(rectangle_ground);
                window.draw(sprite_heàlthbàr_empty);
                window.draw(sprite_healthbar_itself);
                window.draw(SomeGhost.sprite);
                window.draw(SomeWitch.sprite);
                window.draw(Hero.sprite);
                window.display();
            }
            if ((Keyboard::isKeyPressed(Keyboard::Escape)))
            {
                escape = 1;
            }
            if (escape)
            {
                window.draw(sprite_blackground);
                window.draw(sprite_PauseBar);
                window.draw(sprite_Resume_Button);
                window.draw(sprite_Settings_Button);
                window.draw(sprite_Inventory_Button);
                window.draw(sprite_Exit_Button);
                window.display();
                this_view = view;
            }
        }
        if (view == 6)//Fourth level
        {
            if (!escape)
            {
                window.clear();
                window.draw(sprite_BackGround);
                window.draw(rectangle_ground);
                window.draw(sprite_Hero);
                window.display();
            }
            if ((Keyboard::isKeyPressed(Keyboard::Escape)))
            {
                escape = 1;
            }
            if (escape)
            {
                window.draw(sprite_blackground);
                window.display();
                this_view = view;
            }
        }
        if (view == 7)//Shop
        {
            window.clear(Color::Blue);
            window.draw(text_backtomap);
            //window.draw(rectangle_backtomap);
            window.display();
        }
        if (view == 8)//Settings
        {
            window.clear(Color::Blue);
            window.draw(text_Back);
            window.display();
        }
    }

    return 0;
}
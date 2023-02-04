// Raylib Library
#include <raylib.h>

// Dimensions
#define ScreenWidth 800
#define ScreenHeight 450

// Function Declaration
int health_bar();
int background_load(Texture2D);
int damage_value();
int attacks_sounds(Sound, Sound, Sound, Sound, Sound, Sound);
int info_key(Rectangle, Rectangle, Rectangle, Rectangle, Rectangle, Rectangle);
int level_res(Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D, Texture2D);
// int inventory();

// Level at Start
int level = 0;

int score = 0;

// INVENTORY BOOL
bool inventory_bool = false;

// Attack Damages
int punch = 2;
int stone = 4;
int knife = 6;
int sword = 8;
int gun = 10;
int lighting_bolt = 12;

// Positions:
// BG
Vector2 bgpos;


int height1 = 200;
int height2 = 200;
int height3 = 200;
int height4 = 200;
int height5 = 200;
int height6 = 200;
int height7 = 200;
int height8 = 200;
int height9 = 200;
int height10 = 200;



// Enemies
// Enemy1
int e1health = 10;
Vector2 posE1;
// Enemy2
int e2health = 50;
Vector2 posE2;
// Enemy3
int e3health = 100;
Vector2 posE3;
// Enemy4
int e4health = 150;
Vector2 posE4;
// Enemy5
int e5health = 200;
Vector2 posE5;
// Enemy6
int e6health = 250;
Vector2 posE6;
// Enemy7
int e7health = 300;
Vector2 posE7;
// Enemy8
int e8health = 350;
Vector2 posE8;
// Enemy9
int e9health = 400;
Vector2 posE9;
// Enemy10
int e10health = 450;
Vector2 posE10;

// Main Function
int main()
{
    // Window Initialize
    InitWindow(ScreenWidth, ScreenHeight, "Monster Hunter");

    // Audio Device
    InitAudioDevice();

    // Frame Per Sec
    SetTargetFPS(20);

    // Resources:
    // Audio
    Music bgmus = LoadMusicStream("resrc/music/bgmusic.mp3");
    Sound atk1 = LoadSound("resrc/music/punch.mp3");
    Sound atk2 = LoadSound("resrc/music/stone.mp3");
    Sound atk3 = LoadSound("resrc/music/knife.mp3");
    Sound atk4 = LoadSound("resrc/music/sword.mp3");
    Sound atk5 = LoadSound("resrc/music/gun.mp3");
    Sound atk6 = LoadSound("resrc/music/thunder.wav");
    // Enemies
    Texture2D resE1 = LoadTexture("resrc/enemies/pipo-enemy001.png");  // Enemy1
    Texture2D resE2 = LoadTexture("resrc/enemies/pipo-enemy002.png");  // Enemy2
    Texture2D resE3 = LoadTexture("resrc/enemies/pipo-enemy003.png");  // Enemy3
    Texture2D resE4 = LoadTexture("resrc/enemies/pipo-enemy004.png");  // Enemy4
    Texture2D resE5 = LoadTexture("resrc/enemies/pipo-enemy005.png");  // Enemy5
    Texture2D resE6 = LoadTexture("resrc/enemies/pipo-enemy006.png");  // Enemy6
    Texture2D resE7 = LoadTexture("resrc/enemies/pipo-enemy007.png");  // Enemy7
    Texture2D resE8 = LoadTexture("resrc/enemies/pipo-enemy008.png");  // Enemy8
    Texture2D resE9 = LoadTexture("resrc/enemies/pipo-enemy009.png");  // Enemy9
    Texture2D resE10 = LoadTexture("resrc/enemies/pipo-enemy010.png"); // Enemy10
    Texture2D bg1 = LoadTexture("resrc/bg/bg.png");                    // bg
    // Rectangle
    Rectangle rec1 = {10, 380, 100, 50}; // Punch
    Rectangle rec2 = {143, 380, 100, 50};
    Rectangle rec3 = {276, 380, 100, 50};
    Rectangle rec4 = {409, 380, 100, 50};
    Rectangle rec5 = {542, 380, 100, 50};
    Rectangle rec6 = {675, 380, 110, 50};

    // Playing BG Music
    PlayMusicStream(bgmus);

    // Window Loop
    while (!WindowShouldClose())
    {
        // Updating BG Music
        UpdateMusicStream(bgmus);
        attacks_sounds(atk1, atk2, atk3, atk4, atk5, atk6);

        // Resource Display
        BeginDrawing();

        
        // BG Color
        ClearBackground(WHITE);

        // BG
        background_load(bg1);

        // Levels
        level_res(resE1, resE2, resE3, resE4, resE5, resE6, resE7, resE8, resE9, resE10);

        info_key(rec1, rec2, rec3, rec4, rec5, rec6);

        health_bar();

        // Inventory
        // inventory();

        // Ending Display
        EndDrawing();
    }

    // Stopping Music
    StopMusicStream(bgmus);

    // Audio Device Close
    CloseAudioDevice();

    // Window Close
    CloseWindow();

    return 0;
}

// Level and Resources
int level_res(
    Texture2D resE1,
    Texture2D resE2,
    Texture2D resE3,
    Texture2D resE4,
    Texture2D resE5,
    Texture2D resE6,
    Texture2D resE7,
    Texture2D resE8,
    Texture2D resE9,
    Texture2D resE10)
{
    // Level 0
    if (level == 0)
    {
        // Text on Screen
        DrawText("Monster Hunter", ScreenWidth / 3.5, ScreenHeight / 2.5, 50, BLACK);
        DrawText("Minor Project", 335, 230, 20, BLACK);
        DrawText("Press [SPACE] to Start the Game", 325, 395, 10, BLACK);

        // Next Level
        if (IsKeyPressed(KEY_SPACE))
        {
            level++;
        }
    }

    if (level == -1)
    {
        // Text on Screen
        DrawText("Monster Hunter", ScreenWidth / 3.5, ScreenHeight / 2.5, 50, BLACK);
        DrawText("Congratulaions You defeated all the Monsters", 200, 250, 20, BLACK);
        DrawText("Press [Esc] to Exit the Game", 330, 380, 10, BLACK);
    }

    // Level 1
    if (level == 1)
    {
        // Texture and Position Change
        if (damage_value() != 0)
        {
            posE1.x = ScreenWidth / 2 - resE1.width / 2 * .7;
            posE1.y = ScreenHeight / 2 - resE1.height / 2 * .7;
            DrawTextureEx(resE1, posE1, 0, 0.7, RED);
        }
        else
        {
            posE1.x = ScreenWidth / 2 - resE1.width / 2 * .8;
            posE1.y = ScreenHeight / 2 - resE1.height / 2 * .8;
            DrawTextureEx(resE1, posE1, 0, 0.8, WHITE);

        }

        // Deals Damage
        e1health -= damage_value();

        // Next Level
        if (e1health <= 0)
        {
            level++;
        }
    }

    // Level 2
    if (level == 2)
    {
        // Texture and Position Change
        if (damage_value() != 0)
        {
            posE2.x = ScreenWidth / 2 - resE2.width / 2 * .8;
            posE2.y = ScreenHeight / 2 - resE2.height / 2 * .8;
            DrawTextureEx(resE2, posE2, 0, 0.8, RED);
        }
        else
        {
            posE2.x = ScreenWidth / 2 - resE2.width / 2 * .7;
            posE2.y = ScreenHeight / 2 - resE2.height / 2 * .7;
            DrawTextureEx(resE2, posE2, 0, 0.7, WHITE);
        }

        // Deals Damage
        e2health -= damage_value();

        // Next Level
        if (e2health <= 0)
        {
            level++;
        }
    }

    // Level 3
    if (level == 3)
    {
        // Enemy Position
        posE3.x = ScreenWidth / 2 - resE3.width / 2 * .8;
        posE3.y = ScreenHeight / 2 - resE3.height / 2 * .8;

        // Texture Change
        if (damage_value() != 0)
        {
            DrawTextureEx(resE3, posE3, 0, 0.8, RED);
        }
        else
        {
            DrawTextureEx(resE3, posE3, 0, 0.8, WHITE);
        }

        // Deals Damage
        e3health -= damage_value();

        // Next Level
        if (e3health <= 0)
        {
            level++;
        }
    }

    // Level 4
    if (level == 4)
    {
        // Enemy Position
        posE4.x = ScreenWidth / 2 - resE4.width / 2 * .8;
        posE4.y = ScreenHeight / 2 - resE4.height / 2 * .8;

        // Texture Change
        if (damage_value() != 0)
        {
            DrawTextureEx(resE4, posE4, 0, 0.8, RED);
        }
        else
        {
            DrawTextureEx(resE4, posE4, 0, 0.8, WHITE);
        }

        // Deals Damage
        e4health -= damage_value();

        // Next Level
        if (e4health <= 0)
        {
            level++;
        }
    }

    // Level 5
    if (level == 5)
    {
        // Enemy Position
        posE5.x = ScreenWidth / 2 - resE5.width / 2 * .8;
        posE5.y = ScreenHeight / 2 - resE5.height / 2 * .8;

        // Texture Change
        if (damage_value() != 0)
        {
            DrawTextureEx(resE5, posE5, 0, 0.8, RED);
        }
        else
        {
            DrawTextureEx(resE5, posE5, 0, 0.8, WHITE);
        }

        // Deals Damage
        e5health -= damage_value();

        // Next Level
        if (e5health <= 0)
        {
            level++;
        }
    }

    // Level 6
    if (level == 6)
    {
        // Enemy Position
        posE6.x = ScreenWidth / 2 - resE6.width / 2 * .8;
        posE6.y = ScreenHeight / 2 - resE6.height / 2 * .8;

        // Texture Change
        if (damage_value() != 0)
        {
            DrawTextureEx(resE6, posE6, 0, 0.8, RED);
        }
        else
        {
            DrawTextureEx(resE6, posE6, 0, 0.8, WHITE);
        }

        // Deals Damage
        e6health -= damage_value();

        // Next Level
        if (e6health <= 0)
        {
            level++;
        }
    }

    // Level 7
    if (level == 7)
    {
        // Enemy Position
        posE7.x = ScreenWidth / 2 - resE7.width / 2 * .8;
        posE7.y = ScreenHeight / 2 - resE7.height / 2 * .8;

        // Texture Change
        if (damage_value() != 0)
        {
            DrawTextureEx(resE7, posE7, 0, 0.8, RED);
        }
        else
        {
            DrawTextureEx(resE7, posE7, 0, 0.8, WHITE);
        }

        // Deals Damage
        e7health -= damage_value();

        // Next Level
        if (e7health <= 0)
        {
            level++;
        }
    }

    // Level 8
    if (level == 8)
    {
        // Enemy Position
        posE8.x = ScreenWidth / 2 - resE8.width / 2 * .8;
        posE8.y = ScreenHeight / 2 - resE8.height / 2 * .8;

        // Texture Change
        if (damage_value() != 0)
        {
            DrawTextureEx(resE8, posE8, 0, 0.8, RED);
        }
        else
        {
            DrawTextureEx(resE8, posE8, 0, 0.8, WHITE);
        }

        // Deals Damage
        e8health -= damage_value();

        // Next Level
        if (e8health <= 0)
        {
            level++;
        }
    }

    // Level 9
    if (level == 9)
    {
        // Enemy Position
        posE9.x = ScreenWidth / 2 - resE9.width / 2 * .8;
        posE9.y = ScreenHeight / 2 - resE9.height / 2 * .8;

        // Texture Change
        if (damage_value() != 0)
        {
            DrawTextureEx(resE9, posE9, 0, 0.8, RED);
        }
        else
        {
            DrawTextureEx(resE9, posE9, 0, 0.8, WHITE);
        }

        // Deals Damage
        e9health -= damage_value();

        // Next Level
        if (e9health <= 0)
        {
            level++;
        }
    }
    // Level 10
    if (level == 10)
    {
        // Enemy Position
        posE10.x = ScreenWidth / 2 - resE5.width / 2 * .8;
        posE10.y = ScreenHeight / 2 - resE5.height / 2 * .8;

        // Texture Change
        if (damage_value() != 0)
        {
            DrawTextureEx(resE10, posE10, 0, 0.8, RED);
        }
        else
        {
            DrawTextureEx(resE10, posE10, 0, 0.8, WHITE);
        }

        // Deals Damage
        e10health -= damage_value();

        // Next Level
        if (e10health <= 0)
        {
            level = -1;
        }
    }
}

int damage_value()
{
    // Damage Init
    int damage = 0;

    // Punch -> 2 Damage
    if (IsKeyPressed(KEY_ONE) && level >= 1)
    {
        damage = punch;
    }

    // Stone -> 4 Damage
    else if (IsKeyPressed(KEY_TWO) && level >= 3)
    {
        damage = stone;
    }

    // Knife -> 6 Damage
    else if (IsKeyPressed(KEY_THREE) && level >= 4)
    {
        damage = knife;
    }

    // Sword -> 8 Damage
    else if (IsKeyPressed(KEY_FOUR) && level >= 6)
    {
        damage = sword;
    }

    // Gun -> 10 Damage
    else if (IsKeyPressed(KEY_FIVE) && level >= 7)
    {
        damage = gun;
    }

    // Lightinh Bolt -> 12 Damage
    else if (IsKeyPressed(KEY_SIX) && level >= 9)
    {
        damage = lighting_bolt;
    }

    // Final Damage after any Click on keys
    return damage;
}

// Background Image
int background_load(Texture2D bg1)
{
    // Background starts after Start Screen
    if (level > 0)
    {
        bgpos.x = 0;
        bgpos.y = 0;
        DrawTextureEx(bg1, bgpos, 0, 0.21, WHITE);
    }
}

// Attack Sounds
int attacks_sounds(
    Sound attk1,
    Sound attk2,
    Sound attk3,
    Sound attk4,
    Sound attk5,
    Sound attk6)
{
    // Damage Deals
    int damage = damage_value();

    // Punch Sound
    if (damage == punch)
    {
        PlaySound(attk1);
    }

    // Stone Sound
    if (damage == stone)
    {
        PlaySound(attk2);
    }

    // Knife Sound
    if (damage == knife)
    {
        PlaySound(attk3);
    }

    // Sword Sound
    if (damage == sword)
    {
        PlaySound(attk4);
    }

    // Gun Sound
    if (damage == gun)
    {
        PlaySound(attk5);
    }

    // Lighting Bolt Sound
    if (damage == lighting_bolt)
    {
        PlaySound(attk6);
    }
}

// Attack Keys
int info_key(
    Rectangle rec1,
    Rectangle rec2,
    Rectangle rec3,
    Rectangle rec4,
    Rectangle rec5,
    Rectangle rec6)
{
    if (level > 0)
    {
        int damage = damage_value();
        if (level >= 1)
        {
            if (damage == punch)
            {
                DrawRectangleRounded(rec1, 5, 4, BLACK);
                DrawText("PUNCH", 25, 395, 20, WHITE);
            }
            else
            {
                DrawRectangleRounded(rec1, 5, 4, WHITE);
                DrawText("PUNCH", 25, 395, 20, BLACK);
            }
        }
        if (level >= 3)
        {
            if (damage == stone)
            {
                DrawRectangleRounded(rec2, 5, 4, BLACK);
                DrawText("STONE", 158, 395, 20, WHITE);
            }
            else
            {
                DrawRectangleRounded(rec2, 5, 4, WHITE);
                DrawText("STONE", 158, 395, 20, BLACK);
            } 
        }
        if (level >= 4)
        {
            if (damage == knife)
            {
                DrawRectangleRounded(rec3, 5, 4, BLACK);
                DrawText("KNIFE", 295, 395, 20, WHITE);
            }
            else
            {
                DrawRectangleRounded(rec3, 5, 4, WHITE);
                DrawText("KNIFE", 295, 395, 20, BLACK);
            }
        }
        if (level >= 6)
        {
            if (damage == sword)
            {
                DrawRectangleRounded(rec4, 5, 4, BLACK);
                DrawText("SWORD", 424, 395, 20, WHITE);
            }
            else
            {
                DrawRectangleRounded(rec4, 5, 4, WHITE);
                DrawText("SWORD", 424, 395, 20, BLACK);
            }
        }
        if (level >= 7)
        {
            if (damage == gun)
            {
                DrawRectangleRounded(rec5, 5, 4, BLACK);
                DrawText("GUN", 570, 395, 20, WHITE);
            }
            else
            {
                DrawRectangleRounded(rec5, 5, 4, WHITE);
                DrawText("GUN", 570, 395, 20, BLACK);
            }
        }
        if (level >= 9)
        {
            if (damage == lighting_bolt)
            {
                DrawRectangleRounded(rec6, 5, 4, BLACK);
                DrawText("THUNDER", 680, 395, 20, WHITE);
            }
            else
            {
                DrawRectangleRounded(rec6, 5, 4, WHITE);
                DrawText("THUNDER", 680, 395, 20, BLACK);
            }
        }

    }
}

int health_bar()
{
    if (level == 1)
    {
        if (damage_value())
        {
            height1 -= damage_value() * 20;
        }
        Rectangle HB1 = {760, 300, 20, height1};
        Rectangle HBr1 = {760, 300, 20, 200};

        Vector2 HB1vec = {0, 0};
        DrawRectanglePro(HBr1, HB1vec, 180, RED);
        DrawRectanglePro(HB1, HB1vec, 180, WHITE);

    }
    if (level == 2)
    {
        if (damage_value())
        {
            height2 -= damage_value() * 4;
        }
        Rectangle HB1 = {760, 300, 20, height2};
        Rectangle HBr1 = {760, 300, 20, 200};

        Vector2 HB1vec = {0, 0};
        DrawRectanglePro(HBr1, HB1vec, 180, RED);
        DrawRectanglePro(HB1, HB1vec, 180, WHITE);

    }
    if (level == 3)
    {
        if (damage_value())
        {
            height3 -= damage_value() * 2;
        }
        Rectangle HB1 = {760, 300, 20, height3};
        Rectangle HBr1 = {760, 300, 20, 200};

        Vector2 HB1vec = {0, 0};
        DrawRectanglePro(HBr1, HB1vec, 180, RED);
        DrawRectanglePro(HB1, HB1vec, 180, WHITE);

    }
    if (level == 4)
    {
        if (damage_value())
        {
            height4 -= damage_value() * 1.33333;
        }
        Rectangle HB1 = {760, 300, 20, height4};
        Rectangle HBr1 = {760, 300, 20, 200};

        Vector2 HB1vec = {0, 0};
        DrawRectanglePro(HBr1, HB1vec, 180, RED);
        DrawRectanglePro(HB1, HB1vec, 180, WHITE);

    }
    if (level == 5)
    {
        if (damage_value())
        {
            height5 -= damage_value() * 1;
        }
        Rectangle HB1 = {760, 300, 20, height5};
        Rectangle HBr1 = {760, 300, 20, 200};

        Vector2 HB1vec = {0, 0};
        DrawRectanglePro(HBr1, HB1vec, 180, RED);
        DrawRectanglePro(HB1, HB1vec, 180, WHITE);

    }
    if (level == 6)
    {
        if (damage_value())
        {
            height6 -= damage_value() * 0.8;
        }
        Rectangle HB1 = {760, 300, 20, height6};
        Rectangle HBr1 = {760, 300, 20, 200};

        Vector2 HB1vec = {0, 0};
        DrawRectanglePro(HBr1, HB1vec, 180, RED);
        DrawRectanglePro(HB1, HB1vec, 180, WHITE);

    }
    if (level == 7)
    {
        if (damage_value())
        {
            height7 -= damage_value() * 0.666666667;
        }
        Rectangle HB1 = {760, 300, 20, height7};
        Rectangle HBr1 = {760, 300, 20, 200};

        Vector2 HB1vec = {0, 0};
        DrawRectanglePro(HBr1, HB1vec, 180, RED);
        DrawRectanglePro(HB1, HB1vec, 180, WHITE);

    }
    if (level == 8)
    {
        if (damage_value())
        {
            height8 -= damage_value() * 0.571428571;
        }
        Rectangle HB1 = {760, 300, 20, height8};
        Rectangle HBr1 = {760, 300, 20, 200};

        Vector2 HB1vec = {0, 0};
        DrawRectanglePro(HBr1, HB1vec, 180, RED);
        DrawRectanglePro(HB1, HB1vec, 180, WHITE);

    }
    if (level == 9)
    {
        if (damage_value())
        {
            height9 -= damage_value() * 0.5;
        }
        Rectangle HB1 = {760, 300, 20, height9};
        Rectangle HBr1 = {760, 300, 20, 200};

        Vector2 HB1vec = {0, 0};
        DrawRectanglePro(HBr1, HB1vec, 180, RED);
        DrawRectanglePro(HB1, HB1vec, 180, WHITE);

    }
    if (level == 10)
    {
        if (damage_value())
        {
            height10 -= damage_value() * 0.444444444;
        }
        Rectangle HB1 = {760, 300, 20, height10};
        Rectangle HBr1 = {760, 300, 20, 200};

        Vector2 HB1vec = {0, 0};
        DrawRectanglePro(HBr1, HB1vec, 180, RED);
        DrawRectanglePro(HB1, HB1vec, 180, WHITE);

    }
}
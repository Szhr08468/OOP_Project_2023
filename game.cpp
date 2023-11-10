#include "game.h"
#include "pieces.h"
#include "money.h"
#include <vector>
#include <cstdio>

const int MARGIN = 250;  // Define the margin here

Game::Game() : gWindow(NULL), gRenderer(NULL), backgroundTexture(NULL), backgroundMusic(NULL), screenWidth(0), screenHeight(0)
{
}

Game::~Game()
{
}


bool Game::InitializeSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        // Handle initialization error
        return false;
    }
    return true;
}


bool Game::Init(int screenWidth, int screenHeight, const char* windowTitle)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    gWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;

    return true;
}


bool Game::LoadAssets(const char* backgroundImageFile, const char* backgroundMusicFile)
{
    SDL_Surface* loadedSurface = IMG_Load(backgroundImageFile);
    if (loadedSurface == NULL)
    {
        printf("Unable to load background image! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    // Scale the background image to fit the screen while keeping 100 pixels on the left and right
    int scaledWidth = screenWidth - (2 * MARGIN);
    int scaledHeight = (scaledWidth * loadedSurface->h) / loadedSurface->w;

    SDL_Surface* scaledSurface = SDL_CreateRGBSurface(0, scaledWidth, scaledHeight, loadedSurface->format->BitsPerPixel, loadedSurface->format->Rmask, loadedSurface->format->Gmask, loadedSurface->format->Bmask, loadedSurface->format->Amask);
    SDL_BlitScaled(loadedSurface, NULL, scaledSurface, NULL);

    backgroundTexture = SDL_CreateTextureFromSurface(gRenderer, scaledSurface);
    if (backgroundTexture == NULL)
    {
        printf("Unable to create texture from background image! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    SDL_FreeSurface(loadedSurface);
    SDL_FreeSurface(scaledSurface);

    backgroundRect.x = MARGIN;
    backgroundRect.y = (screenHeight - scaledHeight) / 2;
    backgroundRect.w = scaledWidth;
    backgroundRect.h = scaledHeight;

    backgroundMusic = Mix_LoadMUS(backgroundMusicFile);
    if (backgroundMusic == NULL)
    {
        printf("Unable to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }
    

    return true;
}

SDL_Texture* Game::LoadTexture(const char* filePath)
{
    SDL_Surface* loadedSurface = IMG_Load(filePath);
    if (!loadedSurface)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", filePath, IMG_GetError());
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    if (!texture)
    {
        printf("Unable to create texture from image %s! SDL Error: %s\n", filePath, SDL_GetError());
        return nullptr;
    }

    return texture;
}


void Game::DisplayStartingScreen(Uint32 duration)
{
    SDL_Texture* startingScreenTexture = LoadTexture("assets/Screen/home.jpg"); // Implement LoadTexture according to your setup
    if (!startingScreenTexture)
    {
        return;
    }

    // Render the starting screen image
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, startingScreenTexture, NULL, NULL);
    SDL_RenderPresent(gRenderer);

    // Wait for the specified duration (in milliseconds)
    Uint32 startTime = SDL_GetTicks();
    while (SDL_GetTicks() - startTime < duration)
    {
        // Optionally, you can handle user input during this time
        HandleEvents();
    }

    // Release the starting screen texture
    SDL_DestroyTexture(startingScreenTexture);
}

bool Game::DisplayCardForBuy(const char* filePath)
{
    bool BUY = false;

    SDL_Texture* startingScreenTexture = LoadTexture(filePath); // Implement LoadTexture according to your setup
    if (!startingScreenTexture)
    {
        printf("Error in DisplayCardForBuy\n");
        return false;
    }

    // Set the position and dimensions of the card
    int cardWidth = 300;
    int cardHeight = 400;
    int cardX = (screenWidth - cardWidth) / 2;
    int cardY = (screenHeight - cardHeight) / 2;

    // Create a flag to control the loop
    bool exitLoop = false;

    while (!exitLoop)
    {
        // Render the starting screen image
        SDL_RenderClear(gRenderer);

        // Render the card in the center
        SDL_Rect cardRect = {cardX, cardY, cardWidth, cardHeight};
        SDL_RenderCopy(gRenderer, startingScreenTexture, NULL, &cardRect);

        SDL_RenderPresent(gRenderer);

        // Check for events
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_b)
                {
                    BUY = true;
                    exitLoop = true; // Exit the loop on 'B' press
                }
                else if (e.key.keysym.sym == SDLK_n)
                {
                    BUY = false;
                    exitLoop = true; // Exit the loop on 'N' press
                }
            }
        }
    }

    // Release the starting screen texture
    SDL_DestroyTexture(startingScreenTexture);

    return BUY;
}

void Game::DisplayChanceOrComunnityChest(const char* filePath)
{
    SDL_Texture* startingScreenTexture = LoadTexture(filePath); // Implement LoadTexture according to your setup
    if (!startingScreenTexture)
    {
        return;
    }

    // Set the position and dimensions of the card
    int cardWidth = 500;
    int cardHeight = 300;
    int cardX = (screenWidth - cardWidth) / 2;
    int cardY = (screenHeight - cardHeight) / 2;

    SDL_Rect cardRect = {cardX, cardY, cardWidth, cardHeight};

    // Render the starting screen image
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, startingScreenTexture, NULL, &cardRect);
    SDL_RenderPresent(gRenderer);

    Uint32 duration = 3000;

    // Wait for the specified duration (in milliseconds)
    Uint32 startTime = SDL_GetTicks();
    while (SDL_GetTicks() - startTime < duration)
    {
        // Optionally, you can handle user input during this time
        HandleEvents();
    }

    // Release the starting screen texture
    SDL_DestroyTexture(startingScreenTexture);
}


bool Game::IsKeyPressed(SDL_Scancode key)
{
    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    // Use keyState[key] to check the state of the key
    return keyState[key] != 0;
}


void Game::InitializeGamePieces() {
    
    Piece piece1(gRenderer); // Create a piece with the given renderer
    piece1.SetPosition(890, 620);
    piece1.SetSize(20, 20); 
    gamePieces.push_back(piece1);

    Piece piece2(gRenderer); // Create a piece with the given renderer
    piece2.SetPosition(920, 620);
    piece2.SetSize(20, 20);
    gamePieces.push_back(piece2); 

    Piece piece3(gRenderer); // Create a piece with the given renderer
    piece3.SetPosition(890, 650);
    piece3.SetSize(20, 20); 
    gamePieces.push_back(piece3);

    Piece piece4(gRenderer); // Create a piece with the given renderer
    piece4.SetPosition(920, 650);
    piece4.SetSize(20, 20); 
    gamePieces.push_back(piece4);


}

void Game::InitializeMoney() {
    for (int i=0;i<4;i++) 
    {
        Money money;
        money.SetAmount(10000);
        PlayerMoney.push_back(money);
    }
}

void Game::PlayBackgroundMusic()
{
    Mix_PlayMusic(backgroundMusic, -1);
}

bool Game::HandleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            return true;
        }
    }
    return false;
}

void Game::RenderPieces() 
{
    SDL_Texture* pieceTexture1 = LoadTexture("assets/Pieces/p1.png");
    SDL_Texture* pieceTexture2 = LoadTexture("assets/Pieces/p2.png");
    SDL_Texture* pieceTexture3 = LoadTexture("assets/Pieces/p3.png");
    SDL_Texture* pieceTexture4 = LoadTexture("assets/Pieces/p4.png");


    for (size_t i = 0; i < gamePieces.size(); i++) {
        SDL_Rect destRect = gamePieces[i].GetRect();
        if (i == 0) {
            SDL_RenderCopy(gRenderer, pieceTexture1, nullptr, &destRect);
        } else if (i == 1) {
            SDL_RenderCopy(gRenderer, pieceTexture2, nullptr, &destRect);
        } else if (i == 2) {
            SDL_RenderCopy(gRenderer, pieceTexture3, nullptr, &destRect);
        } else {
            SDL_RenderCopy(gRenderer, pieceTexture4, nullptr, &destRect);
        }
    }

    SDL_DestroyTexture(pieceTexture1);
    SDL_DestroyTexture(pieceTexture2);
    SDL_DestroyTexture(pieceTexture3);
    SDL_DestroyTexture(pieceTexture4);
}

void Game::RenderPlayerIcons() 
{   
    SDL_Texture* p1_T = LoadTexture("assets/player_icon/p1_Turn.png");
    SDL_Texture* p1_NT = LoadTexture("assets/player_icon/p1_NoTurn.png");
    SDL_Texture* p2_T = LoadTexture("assets/player_icon/p2_Turn.png");
    SDL_Texture* p2_NT = LoadTexture("assets/player_icon/p2_NoTurn.png");
    SDL_Texture* p3_T = LoadTexture("assets/player_icon/p3_Turn.png");
    SDL_Texture* p3_NT = LoadTexture("assets/player_icon/p3_NoTurn.png");
    SDL_Texture* p4_T = LoadTexture("assets/player_icon/p4_Turn.png");
    SDL_Texture* p4_NT = LoadTexture("assets/player_icon/p4_NoTurn.png");

    SDL_Rect Rect1 = {0,0,180,180};
    SDL_Rect Rect2 = {1020,0,180,180};
    SDL_Rect Rect3 = {0,520,180,180};
    SDL_Rect Rect4 = {1020,520,180,180};


    GameState::State currentState = gamestate.GetCurrentState();


    if (currentState==GameState::State::GameStart) 
    {   
        SDL_RenderCopy(gRenderer, p1_NT, NULL, &Rect1);
        SDL_RenderCopy(gRenderer, p2_NT, NULL, &Rect2);
        SDL_RenderCopy(gRenderer, p3_NT, NULL, &Rect3);
        SDL_RenderCopy(gRenderer, p4_NT, NULL, &Rect4);
    }
    else if (currentState==GameState::State::Player1Turn) 
    {
        SDL_RenderCopy(gRenderer, p1_T, NULL, &Rect1);
        SDL_RenderCopy(gRenderer, p2_NT, NULL, &Rect2);
        SDL_RenderCopy(gRenderer, p3_NT, NULL, &Rect3);
        SDL_RenderCopy(gRenderer, p4_NT, NULL, &Rect4);
    } 
    else if (currentState==GameState::State::Player2Turn) 
    {
        SDL_RenderCopy(gRenderer, p1_NT, NULL, &Rect1);
        SDL_RenderCopy(gRenderer, p2_T, NULL, &Rect2);
        SDL_RenderCopy(gRenderer, p3_NT, NULL, &Rect3);
        SDL_RenderCopy(gRenderer, p4_NT, NULL, &Rect4);
    }
    else if (currentState==GameState::State::Player3Turn) 
    {
        SDL_RenderCopy(gRenderer, p1_NT, NULL, &Rect1);
        SDL_RenderCopy(gRenderer, p2_NT, NULL, &Rect2);
        SDL_RenderCopy(gRenderer, p3_T, NULL, &Rect3);
        SDL_RenderCopy(gRenderer, p4_NT, NULL, &Rect4);
    }
    else if (currentState==GameState::State::Player4Turn) 
    {
        SDL_RenderCopy(gRenderer, p1_NT, NULL, &Rect1);
        SDL_RenderCopy(gRenderer, p2_NT, NULL, &Rect2);
        SDL_RenderCopy(gRenderer, p3_NT, NULL, &Rect3);
        SDL_RenderCopy(gRenderer, p4_T, NULL, &Rect4);
    }
    else if (currentState==GameState::State::GameOver)
    {
        SDL_RenderCopy(gRenderer, p1_NT, NULL, &Rect1);
        SDL_RenderCopy(gRenderer, p2_NT, NULL, &Rect2);
        SDL_RenderCopy(gRenderer, p3_NT, NULL, &Rect3);
        SDL_RenderCopy(gRenderer, p4_NT, NULL, &Rect4);
    }

    SDL_DestroyTexture(p1_T);
    SDL_DestroyTexture(p1_NT);
    SDL_DestroyTexture(p2_T);
    SDL_DestroyTexture(p2_NT);
    SDL_DestroyTexture(p3_T);
    SDL_DestroyTexture(p3_NT);
    SDL_DestroyTexture(p4_T);
    SDL_DestroyTexture(p4_NT);

}

void Game::RenderPlayerMoney() 
{
    SDL_Texture* p1_D = LoadTexture("assets/money/p1_dollar.png");
    SDL_Texture* p2_D = LoadTexture("assets/money/p2_dollar.png");
    SDL_Texture* p3_D = LoadTexture("assets/money/p3_dollar.png");
    SDL_Texture* p4_D = LoadTexture("assets/money/p4_dollar.png");
    SDL_Texture* zero = LoadTexture("assets/money/0.png");
    SDL_Texture* one = LoadTexture("assets/money/1.png");
    SDL_Texture* two = LoadTexture("assets/money/2.png");
    SDL_Texture* three = LoadTexture("assets/money/3.png");
    SDL_Texture* four = LoadTexture("assets/money/4.png");
    SDL_Texture* five = LoadTexture("assets/money/5.png");
    SDL_Texture* six = LoadTexture("assets/money/6.png");
    SDL_Texture* seven = LoadTexture("assets/money/7.png");
    SDL_Texture* eight = LoadTexture("assets/money/8.png");
    SDL_Texture* nine = LoadTexture("assets/money/9.png");

    std::vector<SDL_Texture*> tex;
    tex.push_back(zero);
    tex.push_back(one);
    tex.push_back(two);
    tex.push_back(three);
    tex.push_back(four);
    tex.push_back(five);
    tex.push_back(six);
    tex.push_back(seven);
    tex.push_back(eight);
    tex.push_back(nine);

    tex.push_back(p1_D);
    tex.push_back(p2_D);
    tex.push_back(p3_D);
    tex.push_back(p4_D);

    int NestedArray[4][6][4] = {
        {
            // Player 1 RECTS
            {0, 180, 30, 60},
            {30, 180, 30, 60},
            {60, 180, 30, 60},
            {90, 180, 30, 60},
            {120, 180, 30, 60},
            {150, 180, 30, 60}
        },
        {
            // Player 2 RECTS
            {1020, 180, 30, 60},
            {1050, 180, 30, 60},
            {1080, 180, 30, 60},
            {1110, 180, 30, 60},
            {1140, 180, 30, 60},
            {1170, 180, 30, 60}
        },
        {
            // Player 3 RECTS
            {0, 460, 30, 60},
            {30, 460, 30, 60},
            {60, 460, 30, 60},
            {90, 460, 30, 60},
            {120, 460, 30, 60},
            {150, 460, 30, 60}
        },
        {
            // Player 4 RECTS
            {1020, 460, 30, 60},
            {1050, 460, 30, 60},
            {1080, 460, 30, 60},
            {1110, 460, 30, 60},
            {1140, 460, 30, 60},
            {1170, 460, 30, 60}
        }
    };


    for (int i=0;i<4;i++) {
        int money = PlayerMoney[i].GetAmount();

        //Dollar sign
        SDL_Rect Rect_D = {NestedArray[i][0][0],NestedArray[i][0][1],NestedArray[i][0][2],NestedArray[i][0][3]};
        SDL_RenderCopy(gRenderer, tex[i+10], NULL, &Rect_D);

        //TenThousands Digit
        int num = money / 10000;
        SDL_Rect Rect_TTh = {NestedArray[i][1][0],NestedArray[i][1][1],NestedArray[i][1][2],NestedArray[i][1][3]};
        SDL_RenderCopy(gRenderer, tex[num], NULL, &Rect_TTh);
        money %= 10000;

        //Thousands Digit
        num = money / 1000;
        SDL_Rect Rect_Th = {NestedArray[i][2][0],NestedArray[i][2][1],NestedArray[i][2][2],NestedArray[i][2][3]};
        SDL_RenderCopy(gRenderer, tex[num], NULL, &Rect_Th);
        money %= 1000;

        //Hundreds Digit
        num = money / 100;
        SDL_Rect Rect_H = {NestedArray[i][3][0],NestedArray[i][3][1],NestedArray[i][3][2],NestedArray[i][3][3]};
        SDL_RenderCopy(gRenderer, tex[num], NULL, &Rect_H);
        money %= 100;

        //Tens Digit
        num = money / 10;
        SDL_Rect Rect_T = {NestedArray[i][4][0],NestedArray[i][4][1],NestedArray[i][4][2],NestedArray[i][4][3]};
        SDL_RenderCopy(gRenderer, tex[num], NULL, &Rect_T);
        money %= 10;

        //Units Digit
        num = money;
        SDL_Rect Rect_U = {NestedArray[i][5][0],NestedArray[i][5][1],NestedArray[i][5][2],NestedArray[i][5][3]};
        SDL_RenderCopy(gRenderer, tex[num], NULL, &Rect_U);
        
    }

    for (SDL_Texture* texture : tex) {
        SDL_DestroyTexture(texture);
    }
    tex.clear();

    
    SDL_DestroyTexture(p1_D);
    SDL_DestroyTexture(p2_D);
    SDL_DestroyTexture(p3_D);
    SDL_DestroyTexture(p4_D);
    SDL_DestroyTexture(zero);
    SDL_DestroyTexture(one);
    SDL_DestroyTexture(two);
    SDL_DestroyTexture(three);
    SDL_DestroyTexture(four);
    SDL_DestroyTexture(five);
    SDL_DestroyTexture(six);
    SDL_DestroyTexture(seven);
    SDL_DestroyTexture(eight);
    SDL_DestroyTexture(nine);
}

void Game:: RenderBackground() 
{
    // Load the background image as a texture
    SDL_Texture* backgroundTexture = LoadTexture("assets/Screen/wooden_bg.png"); // Replace "background.png" with the path to your image

    if (backgroundTexture == NULL)
    {
        printf("Failed to load the background image! SDL_Error: %s\n", SDL_GetError());
    }

    // Render the background texture
    SDL_RenderCopy(gRenderer, backgroundTexture, NULL, NULL);
}

void Game::Render()
{
    SDL_RenderClear(gRenderer);
    RenderBackground();
    SDL_RenderCopy(gRenderer, backgroundTexture, NULL, &backgroundRect);
    RenderPieces();
    RenderPlayerIcons();
    RenderPlayerMoney();
    SDL_RenderPresent(gRenderer);
}

void Game::Cleanup()
{
    Mix_FreeMusic(backgroundMusic);
    Mix_Quit();

    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    IMG_Quit();
    SDL_Quit();
}

#include "game.h"
#include <cstdio>

const int MARGIN = 200;  // Define the margin here

Game::Game() : gWindow(NULL), gRenderer(NULL), backgroundTexture(NULL), backgroundMusic(NULL), screenWidth(0), screenHeight(0), quit(false)
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

    SDL_SetRenderDrawColor(gRenderer, 205, 133, 63, 255);  // Set background color to brown

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






bool Game::IsKeyPressed(SDL_Scancode key)
{
    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    // Use keyState[key] to check the state of the key
    return keyState[key] != 0;
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



void Game::Render()
{
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, backgroundTexture, NULL, &backgroundRect);
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

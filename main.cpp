#include <SDL2/SDL.h>
#include <stdio.h>
#include "Scene.h"
#include "utils/Point.h"

#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 400;

int main(int argc, char *args[])
{
    bool quit = false;

    // Event handler
    SDL_Event e;

    // The window we'll be rendering to
    SDL_Window *window = NULL;

    // The surface contained by the window
    SDL_Surface *screenSurface = NULL;

    // // Initialize SDL
    // if (SDL_Init(SDL_INIT_VIDEO) < 0)
    // {
    //     printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    //     exit(1);
    // }

    // // Create window
    // window = SDL_CreateWindow("Joe Tracer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // if (window == NULL)
    // {
    //     printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    //     exit(1);
    // }

    // // Get window surface
    // screenSurface = SDL_GetWindowSurface(window);

    // Scene *s = new Scene(SCREEN_WIDTH, SCREEN_HEIGHT);
    // // s->debugAddSphere(1, 0, 0, -5);
    // // s->debugAddSphere(2, 10, 10, -20);
    // s->debugAddCube();
    // int channels = 3;
    // char *pixels = new char[SCREEN_WIDTH * SCREEN_HEIGHT * channels];
    // float i = 0;

    // while (!quit)
    // {
    //     while (SDL_PollEvent(&e) != 0)
    //     {
    //         if (e.type == SDL_QUIT)
    //         {
    //             quit = true;
    //         }
    //     }

    //     PinholeCamera camera(1.0f, 45.0f, Point(0, 0, i));
    //     // pixels = s->render(camera);


    //     SDL_Surface *surface = SDL_CreateRGBSurfaceFrom((void *)pixels,
    //                                                     SCREEN_WIDTH,
    //                                                     SCREEN_HEIGHT,
    //                                                     channels * 8,
    //                                                     SCREEN_WIDTH * channels,
    //                                                     0x0000ff,
    //                                                     0x00ff00,
    //                                                     0xff0000,
    //                                                     0);

    //     SDL_BlitSurface(surface, NULL, screenSurface, NULL);

    //     // Update the surface
    //     SDL_UpdateWindowSurface(window);
    //     i = i + 0.5f;
    //     // std::cout << i << std::endl;
    //     SDL_Delay(500);
    // }

    // // Destroy window
    // SDL_DestroyWindow(window);

    // // Quit SDL subsystems
    // SDL_Quit();

    // return 0;
}
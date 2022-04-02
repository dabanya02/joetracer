#include <SDL2/SDL.h>
#include <stdio.h>
#include "Scene.h"
#include "utils/Point.h"
#include "utils/Light.h"
#include "utils/Sphere.h"
#include "utils/Hittable.h"
#include "utils/Materials/Lambertian.h"
#include "utils/Materials/Metal.h"
#include "utils/Materials/Dielectrics.h"

#include <iostream>

const int SCREEN_WIDTH = 600;
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

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    // Create window
    window = SDL_CreateWindow("Joe Tracer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    // Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    Scene *s = new Scene(SCREEN_WIDTH, SCREEN_HEIGHT);

    Metal *m = new Metal(Point(0.9, 0.9, 0.9), 0);
    Lambertian *l = new Lambertian(Point(0.9, 0.9, 0.9));
    Metal *ma = new Metal(Point(0.9, 0.9, 0.6), 0.5);
    Lambertian *la = new Lambertian(Point(0.5, 0.5, 0.5));
    Lambertian *lred = new Lambertian(Point(0.9, 0.0, 0.0));
    Lambertian *lblue = new Lambertian(Point(0.0, 0.0, 0.9));
    Dielectrics *d = new Dielectrics(1.3);

    s->addSphere(prims::Sphere(2, Point(255, 255, 255), Point(-8, 5, -30), m));
    s->addSphere(prims::Sphere(2, Point(255, 255, 255), Point(8, 5, -30), d));
    // s->addSphere(prims::Sphere(3, Point(255, 255, 255), Point(-7, -3, -15), d));
    s->addSphere(prims::Sphere(3, Point(255, 255, 255), Point(-3, 5, -30), lred));
    s->addSphere(prims::Sphere(3, Point(255, 255, 255), Point(3, 5, -30), lblue));
    s->addSphere(prims::Sphere(2, Point(255, 255, 255), Point(2, 2, -12), ma));
    s->addSphere(prims::Sphere(110, Point(255, 255, 255), Point(0, -110.5, -30), l));
    // s->debugAddCube();
    s->addLight(prims::Light(Point(0, 2, -5), 1000.0, Point(255, 255, 255)));
    s->addLight(prims::Light(Point(0, 0, 0), 1000.0, Point(255, 255, 255)));
    s->addLight(prims::Light(Point(0, 2, -10), 1000.0, Point(255, 255, 255)));
    int channels = 3;
    char *pixels = new char[SCREEN_WIDTH * SCREEN_HEIGHT * channels];
    float i = 45.0f;

    PinholeCamera camera(-1.0f, 90.0f, Point(0, 5, 5), Point(0, 0, -1));
    pixels = s->render(camera);

    SDL_Surface *surface = SDL_CreateRGBSurfaceFrom((void *)pixels,
                                                    SCREEN_WIDTH,
                                                    SCREEN_HEIGHT,
                                                    channels * 8,
                                                    SCREEN_WIDTH * channels,
                                                    0x0000ff,
                                                    0x00ff00,
                                                    0xff0000,
                                                    0);

    SDL_BlitSurface(surface, NULL, screenSurface, NULL);

    // Update the surface
    SDL_UpdateWindowSurface(window);
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        // i = i - 0.01f;
        // std::cout << i << std::endl;
    }

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}
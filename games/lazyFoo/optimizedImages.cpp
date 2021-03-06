#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

// define the attributes of the screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// the sufaces tha will be used
SDL_Surface* message = NULL;
SDL_Surface* background = NULL;
SDL_Surface* screen = NULL;

/**
 * function to load images
 * 
 * @param  filename (path to image.bmp file)
 * @return          (pointer to optimized surface)
 */
SDL_Surface* loadImage(std::string filename)
{
  // the image that's loaded
  SDL_Surface* loadedImage = NULL;

  // the optimized image that will be used
  SDL_Surface* optimizedImage = NULL;

  // load the image using SDL_image
  loadedImage = IMG_Load(filename.c_str());

  // if image was loaded
  if (loadedImage != NULL)
  {
    // create optimized image
    optimizedImage = SDL_DisplayFormat(loadedImage);

    // free the old image
    SDL_FreeSurface(loadedImage);
  }

  // return the optimized image
  return optimizedImage;
}

/**
 * surface blitting function
 * 
 * @param x           (x offset)
 * @param y           (y offset)
 * @param source      (source surface)
 * @param destination (destination surface)
 */
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
  // make a temporary rectangleto hold the offsets
  SDL_Rect offset;

  // give the ffsets to the rectangle
  offset.x = x;
  offset.y = y;

  // blit the surface
  SDL_BlitSurface(source, NULL, destination, &offset);
}

int main(int argc, char* args[])
{
  // initialize all SDL subsytems
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
  {
    return 1;
  }

  // set up the screen
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

  // check for errors in setting up the screen
  if (screen == NULL) {
    return 1;
  }

  // set the window caption
  SDL_WM_SetCaption("Hello World", NULL);

  // load the images
  message = loadImage("hello.bmp");
  background = loadImage("background.bmp");

  // apply the background to the screen
  apply_surface(0, 0, background, screen);
  apply_surface(320, 0, background, screen);
  apply_surface(0, 240, background, screen);
  apply_surface(320, 240, background, screen);

  // apply the message to the screen
  apply_surface(180, 140, message, screen);

  // update the screen
  if (SDL_Flip(screen) == -1) {
    return 1;
  }

  // wait 2 seconds
  SDL_Delay(2000);

  // free the surfaces
  SDL_FreeSurface(message);
  SDL_FreeSurface(background);

  // quit SDL
  SDL_Quit();

  return 0;
}

// g++ -o myprogram mysource.cpp -lSDL -lSDL_image

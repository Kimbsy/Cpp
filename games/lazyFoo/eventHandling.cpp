#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

// screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BBP = 32;

// the surfaces
SDL_Surface* image;
SDL_Surface* screen;

// the event structure that will be used
SDL_Event event;

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

  // the optimized image
  SDL_Surface* optimizedImage = NULL;

  // load the image
  loadedImage = IMG_Load(filename.c_str());

  // if the image loaded
  if (loadImage != NULL)
  {
    // create the optimized image
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
void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
  // temporary rectangle to hold the offsets
  SDL_Rect offset;

  // get the offsets
  offset.x = x;
  offset.y = y;

  // blit the surface
  SDL_BlitSurface(source, NULL, destination, &offset);
}

/**
 * initialization function
 * 
 * @return (returns false if errors)
 */
bool init()
{
  // initialize all the SDL subsystems
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
  {
    return false;
  }

  // set up the screen
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BBP, SDL_SWSURFACE);

  // if there was an error setting up the screen
  if (screen == NULL)
  {
    return false;
  }

  // set the window caption
  SDL_WM_SetCaption("Event Handling", NULL);

  // if everything initialized fine
  return true;
}

/**
 * load the files
 * 
 * @return (returns false if errors)
 */
bool loadFiles()
{
  // load the image
  image = loadImage("x.png");

  // if there was an error in loading the image
  if (image == NULL)
  {
    return false;
  }

  // if everything loaded fine
  return true;
}

/**
 * Frees up the surfaces at the end of the program's execution
 */
void cleanUp()
{
  // Free the image
  SDL_FreeSurface(image);

  // quit SDL
  SDL_Quit();
}

int main (int argc, char* args[])
{
  // make sure the program waits for a quit
  bool quit = false;

  // initialize
  if (init() == false)
  {
    return 1;
  }

  // load the files
  if (loadFiles() == false)
  {
    return 1;
  }

  // apply the surface to the screen
  applySurface(0, 0, image, screen);

  // update the screen
  if (SDL_Flip(screen) == -1)
  {
    return 1;
  }

  // while the user hasn't quit
  while (quit == false)
  {
    // while there's an event to handle
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        // quit the program
        quit = true;
      }
    }
  }

  // free up the surface and quit SDL
  cleanUp();

  return 0;
}









// g++ -o myprogram mysource.cpp -lSDL -lSDL_image
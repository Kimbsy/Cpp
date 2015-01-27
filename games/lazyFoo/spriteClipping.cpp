#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

// screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BBP = 32;

// the surfaces
SDL_Surface* dots = NULL;
SDL_Surface* screen = NULL;

// the event structure that will be used
SDL_Event event;

// the portions of the sprite map to be blitted
SDL_Rect clip[4];

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

    // if the image optimized without problems
    if (optimizedImage != NULL)
    {
      // map the color key
      Uint32 colorKey = SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF);

      // set all pixels of color R=0, G=0xFF, B=0xFF to be transparent
      SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorKey);
    }
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
 * @param clip        (what part of the surface we want to blit)
 */
void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
  // holds offsets
  SDL_Rect offset;

  // get the offsets
  offset.x = x;
  offset.y = y;

  // blit
  SDL_BlitSurface(source, clip, destination, &offset);
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
  dots = loadImage("dots.png");

  // if there was an error in loading the image
  if (dots == NULL)
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
  SDL_FreeSurface(dots);

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

  // clip range for the top left
  clip[0].x = 0;
  clip[0].y = 0;
  clip[0].w = 100;
  clip[0].h = 100;

  // clip range for the top right
  clip[1].x = 100;
  clip[1].y = 0;
  clip[1].w = 100;
  clip[1].h = 100;

  // clip range for the bottom left
  clip[2].x = 0;
  clip[2].y = 100;
  clip[2].w = 100;
  clip[2].h = 100;

  // clip range for the bottom right
  clip[3].x = 100;
  clip[3].y = 100;
  clip[3].w = 100;
  clip[3].h = 100;

  // fill the screen white
  SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

  // apply the surface to the screen
  applySurface(0, 0, dots, screen, &clip[0]);
  applySurface(540, 0, dots, screen, &clip[1]);
  applySurface(0, 380, dots, screen, &clip[2]);
  applySurface(540, 380, dots, screen, &clip[3]);

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

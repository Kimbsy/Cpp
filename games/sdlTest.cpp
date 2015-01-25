#include "SDL/SDL.h"

int main(int argc, char* args[])
{
  // the images
  SDL_Surface* hello = NULL;
  SDL_Surface* screen = NULL;

  // start SDL
  SDL_Init(SDL_INIT_EVERYTHING);
  
  // set up screen
  screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

  // load image
  hello = SDL_LoadBMP("hello.bmp");

  // apply image to the screen
  SDL_BlitSurface(hello, NULL, screen, NULL);

  // update the screen
  SDL_Flip(screen);

  // pause
  SDL_Delay(2000);

  // free the loaded image
  SDL_FreeSurface(hello);

  // quit SDL
  SDL_Quit();
  
  return 0;    
}

// g++ -o myprogram mysource.cpp -lSDL

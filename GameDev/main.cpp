#include <iostream>
#include <SDL2/SDL.h>

#ifdef __MINGW32__
#undef main
#endif

using namespace std;

int main(int argc, char** argv)
{
    SDL_SetMainReady();

    std::cout<<"Hello les bros"<<std::endl;
}

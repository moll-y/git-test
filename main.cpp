#include <SDL2/SDL_error.h>
#include <SDL2/SDL_timer.h>

#include <iostream>

#include "game.h"

int main(int argc, char* args[]) {
  std::cout << "game init attempt\n";
  if (!TheGame::get_instance()->init("Chapter 1", 100, 100, 640, 480, true)) {
    std::cout << "game init failure - " << SDL_GetError() << "\n";
    return -1;
  }

  std::cout << "game init success\n";
  while (TheGame::get_instance()->is_running()) {
    TheGame::get_instance()->handle_events();
    TheGame::get_instance()->update();
    TheGame::get_instance()->render();

    SDL_Delay(10);
  }

  std::cout << "game closing...\n";
  TheGame::get_instance()->clean();
  return 0;
}

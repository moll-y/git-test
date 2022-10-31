#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>

#include "texture_manager.h"

class Game {
 public:
  Game() {}
  ~Game() {}
  bool init(const char*, int, int, int, int, bool);
  void render();
  void update();
  void handle_events();
  void clean();
  bool is_running();

 private:
  bool running;
  SDL_Window* window;
  SDL_Renderer* renderer;
  int currentFrame;
};

#endif

#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include <vector>

#include "game_object.h"
#include "texture_manager.h"

class Game {
 public:
  static Game* get_instance() {
    if (instance == 0) {
      instance = new Game();
      return instance;
    }
    return instance;
  }
  ~Game() {}
  bool init(const char*, int, int, int, int, bool);
  void render();
  void update();
  void handle_events();
  void clean();
  bool is_running();
  SDL_Renderer* get_renderer() const { return this->renderer; };

 private:
  Game() {}
  static Game* instance;

  bool running;
  SDL_Window* window;
  SDL_Renderer* renderer;
  int currentFrame;
  std::vector<GameObject*> game_objects;
};

typedef Game TheGame;

#endif

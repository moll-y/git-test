#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SDL2/SDL_render.h>

#include <string>

#include "loader_params.h"
#include "sdl_game_object.h"

class Player : public SDLGameObject {
 public:
  Player(const LoaderParams* params);
  virtual void draw();
  virtual void update();
  virtual void clean();
};

#endif

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <SDL2/SDL_render.h>

#include <string>

#include "loader_params.h"
#include "sdl_game_object.h"

class Enemy : public SDLGameObject {
 public:
  Enemy(const LoaderParams* params);
  virtual void draw();
  virtual void update();
  virtual void clean();
};

#endif

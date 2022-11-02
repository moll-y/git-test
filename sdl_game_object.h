#ifndef _SDL_GAME_OBJECT_H_
#define _SDL_GAME_OBJECT_H_

#include <string>

#include "game_object.h"
#include "loader_params.h"
class SDLGameObject : public GameObject {
 public:
  SDLGameObject(const LoaderParams* params);
  virtual void draw();
  virtual void update();
  virtual void clean();

 protected:
  int x;
  int y;
  int width;
  int height;
  int current_row;
  int current_frame;

  std::string texture_id;
};

#endif

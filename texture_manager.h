#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_

#include <SDL2/SDL_render.h>

#include <map>
#include <string>

class TextureManager {
 public:
  static TextureManager* get_instance() {
    if (instance == 0) {
      instance = new TextureManager();
      return instance;
    }
    return instance;
  }
  bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
  // draw
  void draw(std::string id, int x, int y, int width, int height,
            SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  // drawframe
  void drawFrame(std::string id, int x, int y, int width, int height,
                 int currentRow, int currentFrame, SDL_Renderer* renderer,
                 SDL_RendererFlip flip = SDL_FLIP_NONE);

 private:
  TextureManager() {}
  std::map<std::string, SDL_Texture*> textureMap;
  static TextureManager* instance;
};

typedef TextureManager TheTextureManager;

#endif

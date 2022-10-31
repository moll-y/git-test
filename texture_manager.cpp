#include "texture_manager.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include <string>

TextureManager* TextureManager::instance = 0;

bool TextureManager::load(std::string filename, std::string id,
                          SDL_Renderer* renderer) {
  SDL_Surface* tmpSurface = IMG_Load(filename.c_str());
  if (tmpSurface == 0) {
    return false;
  }

  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);
  if (texture == 0) {
    return false;
  }

  // Everything went ok, add the texture to our list.
  this->textureMap[id] = texture;
  return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
                          SDL_Renderer* renderer, SDL_RendererFlip flip) {
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(renderer, this->textureMap[id], &srcRect, &destRect, 0, 0,
                   flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width,
                               int height, int currentRow, int currentFrame,
                               SDL_Renderer* renderer, SDL_RendererFlip flip) {
  SDL_Rect srcRect;
  SDL_Rect destRect;
  srcRect.x = width * currentFrame;
  srcRect.y = height * (currentRow - 1);
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;
  SDL_RenderCopyEx(renderer, this->textureMap[id], &srcRect, &destRect, 0, 0,
                   flip);
}

#include "sdl_game_object.h"

#include "game.h"
#include "game_object.h"
#include "loader_params.h"
#include "texture_manager.h"

SDLGameObject::SDLGameObject(const LoaderParams* params) : GameObject{params} {
  this->x = params->get_x();
  this->y = params->get_y();
  this->width = params->get_width();
  this->height = params->get_height();
  this->texture_id = params->get_texture_id();
  this->current_row = 1;
  this->current_frame = 1;
}

void SDLGameObject::draw() {
  TextureManager::get_instance()->drawFrame(
      this->texture_id, this->x, this->y, this->width, this->height,
      this->current_row, this->current_frame,
      TheGame::get_instance()->get_renderer());
}

void SDLGameObject::update() {}

void SDLGameObject::clean() {}

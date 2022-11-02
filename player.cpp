#include "player.h"

#include <SDL2/SDL_timer.h>

#include "loader_params.h"
#include "sdl_game_object.h"

Player::Player(const LoaderParams* params) : SDLGameObject{params} {}

void Player::draw() { SDLGameObject::draw(); }

void Player::update() {
  this->x -= 1;
  this->current_frame = int(((SDL_GetTicks() / 100)) % 60);
}

void Player::clean() {}

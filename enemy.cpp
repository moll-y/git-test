#include "enemy.h"

#include <SDL2/SDL_timer.h>

#include "loader_params.h"
#include "sdl_game_object.h"

Enemy::Enemy(const LoaderParams* params) : SDLGameObject{params} {}

void Enemy::draw() { SDLGameObject::draw(); }

void Enemy::update() {
  this->y += 1;
  this->x += 1;
  this->current_frame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean() {}

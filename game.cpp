#include "game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int height, int width,
                bool fullscreen) {
  // Initialize SDL.
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "SDL init fail\n";
    return false;
  }
  std::cout << "SDL init success\n";

  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  // If succeeded create a window.
  this->window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
  if (this->window == 0) {
    std::cout << "Window creation fail\n";
    return false;
  }
  std::cout << "Window creation success\n";

  // If the window creation succeeded create a renderer.
  this->renderer = SDL_CreateRenderer(this->window, -1, 0);
  if (this->renderer == 0) {
    std::cout << "Renderer creation fail\n";
    return false;
  }
  std::cout << "Renderer creation success\n";
  // Set to black.
  SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
  std::cout << "init() success\n";

  // Everything inited successfully, start the main loop.
  this->running = true;
  return true;
}

void Game::render() {
  // Clear the renderer to the drow color.
  SDL_RenderClear(this->renderer);
  // Draw to the screen.
  SDL_RenderPresent(this->renderer);
}

void Game::update() {}

void Game::handle_events() {
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        this->running = false;
        break;
      default:
        break;
    }
  }
}

void Game::clean() {
  std::cout << "Cleaning game\n";
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
  SDL_Quit();
}

bool Game::is_running() { return this->running; }

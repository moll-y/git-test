#include "game.h"

int main(int argc, char* args[]) {
  Game* g_game = new Game();
  g_game->init("Chapter 1", 100, 100, 640, 480, true);
  while (g_game->is_running()) {
    g_game->handle_events();
    g_game->update();
    g_game->render();
  }
  g_game->clean();
  return 0;
}

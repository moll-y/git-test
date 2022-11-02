#ifndef _LOADER_PARAMS_H_
#define _LOADER_PARAMS_H_

#include <string>
class LoaderParams {
 public:
  LoaderParams(int x, int y, int width, int height, std::string texture_id)
      : x{x}, y{y}, width{width}, height{height}, texture_id{texture_id} {}
  int get_x() const { return this->x; }
  int get_y() const { return this->y; }
  int get_width() const { return this->width; }
  int get_height() const { return this->height; }
  std::string get_texture_id() const { return this->texture_id; }

 private:
  int x;
  int y;
  int width;
  int height;
  std::string texture_id;
};

#endif

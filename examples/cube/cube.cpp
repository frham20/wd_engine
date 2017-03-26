#include "wd.h"
#include <cstdio>

namespace {
void on_main_window_close(wd::window &wnd, bool &allow) {
  ::PostQuitMessage(0);
}
}

int main(int argc, char **argv) {
  wd::engine engine;
  engine.init();

  // create our main window
  wd::window wnd;
  if (!wnd.init("WD Engine Cube Demo", wd::recti(50, 50, 690, 530)))
    return 0;

  wnd.event_close += &on_main_window_close;
  wnd.set_visible(true);

  // wnd.event_close -= &on_main_window_close;

  engine.run();
  engine.close();

  return 0;
}
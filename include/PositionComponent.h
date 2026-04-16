#ifndef PositionComponent_h
#define PositionComponent_h

#include "ECS.h"

class PositionComponent : public Component {
  public:
    int xpos, ypos;

    PositionComponent() { xpos = ypos = 0; }
    PositionComponent(int x, int y) {
        xpos = x;
        ypos = y;
    }

    void update() override {}

    void setPos(int x, int y) {
        xpos = x;
        ypos = y;
    }
};

#endif

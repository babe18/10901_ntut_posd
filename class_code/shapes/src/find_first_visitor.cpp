#include "rectangle.h"
#include "triangle.h"
#include "mixed_shape.h"
#include "find_first_visitor.h"

void FindFirstVisitor::visitRectangle(Rectangle *rect) {
  if(_f(rect))
    _result = rect;
}

void FindFirstVisitor::visitTriangle(Triangle *tri) {
  if(_f(tri))
    _result = tri;
}

void FindFirstVisitor::visitMixedShape(MixedShape *ms) {
  if (_f(ms))
    _result = ms;
  else {
    Iterator *it = ms->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
      it->currentItem()->accept(*this);
    }
  }
}

Shape * FindFirstVisitor::getResult() {
  return _result;
}

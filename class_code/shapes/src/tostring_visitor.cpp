#include "tostring_visitor.h"
#include "rectangle.h"
#include "triangle.h"
#include "mixed_shape.h"

void ToStringVisitor::visitRectangle(Rectangle *r) {
    _result += _indent;
    _result += r->toString();
}
void ToStringVisitor::visitTriangle(Triangle *t) {
    _result += _indent;
    _result += t->toString();
}
void ToStringVisitor::visitMixedShape(MixedShape *m) {
    Iterator * it = m->createIterator();
    _result += _indent;
    _result += m->toString();
    _result += " {\n";
    _indent += "  ";
    for (it->first(); !it->isDone(); it->next()) {
        Shape *shape = it->currentItem();
        shape->accept(*this);
    }
    _indent.pop_back();
    _indent.pop_back();
    _result += _indent;
    _result += "}\n";
}
std::string ToStringVisitor::getResult() {
    return _result;
}
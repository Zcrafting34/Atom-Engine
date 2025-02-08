#ifndef ATOM_MATH_H
#define ATOM_MATH_H
#pragma once
namespace AtomMath {
struct Vector2
{
    float x;
    float y;
};

struct Transform
{
    Vector2 position;
    Vector2 scale;
    float rotation;
};
} // namespace AtomMath

#endif

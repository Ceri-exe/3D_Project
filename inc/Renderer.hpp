#pragma once

#include "Framebuffer.hpp"
#include "Vec3.hpp"
#include "Matrix.hpp"

class Renderer {
    private:
        Framebuffer& fb;
    public:
        Renderer(Framebuffer& framebuffer);

        void drawLine(int x0, int y0, int x1, int y1, const Color& color);

        void drawLine(const Vec2& p0, const Vec2& p1, const Color& color);

        void drawWireframeCube(const Mat4& transform, const Color& color);
};
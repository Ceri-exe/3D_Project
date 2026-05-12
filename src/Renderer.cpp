#include "Renderer.hpp"

Renderer::Renderer(Framebuffer &framebuffer) : fb(framebuffer)
{
}

void Renderer::drawLine(int x0, int y0, int x1, int y1, const Color &color)
{
    // get pixel distance for x.
    int dx = std::abs(x1-x0);
    int dy = -std::abs(y1-y0);
    
    // walk in direction.
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;

    int error = dx+dy;

    while(true)
    {
        fb.setPixels(x0,y0,color);

        // Stop at the end.
        if(x0 == x1 && y0 == y1) break;

        int e2 = 2 * error;

        if(e2 >= dy) {
            if(x0 == x1) break;
            error += dy;
            x0 += sx;
        }
        if(e2 <= dx) {
            if(y0 == y1) break;
            error += dx;
            y0 += sy;
        }
    }
}

void Renderer::drawLine(const Vec2 &p0, const Vec2 &p1, const Color &color)
{
    drawLine
    (
        static_cast<int>(p0.x), static_cast<int>(p0.y),
        static_cast<int>(p1.x), static_cast<int>(p1.y),
        color
    );
}

void Renderer::drawWireframeCube(const Mat4 &transform, const Color &color)
{
    // Define Vertices of a cube
    const Vec3 localVertices[8] = {
        {-1,-1,-1}, {1,-1,-1}, {1,1,-1}, {-1,1,-1}, 
        {-1,-1, 1}, {1,-1, 1}, {1,1, 1}, {-1,1, 1}
    };

    const int edges[12][2] = {
        {0,1}, {1,2}, {2,3}, {3,0}, 
        {4,5}, {5,6}, {6,7}, {7,4}, 
        {0,4}, {1,5}, {2,6}, {3,7}
    };

    Vec2 screenVertices[8];

    float focalLength = 2.0f;
    float halfWidth = fb.width / 2.0f;
    float halfHeight = fb.height / 2.0f;

    for(int i = 0; i< 8; i++) {
        Vec3 transformed = transform * localVertices[i];

        float z = transformed.z == 0.0f ? 0.01f : transformed.z;

        float x_ndc = (transformed.x * focalLength) / z;
        float y_ndc = (transformed.y * focalLength) / z;

        screenVertices[i].x = halfWidth + (x_ndc * halfWidth);
        screenVertices[i].y = halfHeight - (y_ndc * halfHeight);
    }

    // draw calculated edges
    for(int i = 0; i < 12; i++)
    {
        drawLine(screenVertices[edges[i][0]], screenVertices[edges[i][1]], color);
    }
}

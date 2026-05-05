#pragma once

#include <cmath>
#include <cassert>


struct Vec2 {
        float x,y;

        Vec2() : x(0), y(0) {}
        Vec2(float x, float y) : x(x), y(y) {}
        Vec2(float v) : x(v), y(v) {}

        Vec2 operator+(const Vec2& v) const {
            return 
            {
                x+v.x,
                y+v.y
            };
        }

        Vec2 operator-(const Vec2& v) const {
            return 
            {
                x-v.x,
                y-v.y
            };
        }

        Vec2 operator*(float s) const {
            return 
            {
                x*s,
                y*s
            };
        }

        Vec2 operator/(float scalar) const {
            return Vec2
            (
                x / scalar,
                y / scalar
            );
        }

        Vec2& operator/=(float scalar) {
            assert(scalar >= 1e-8f && "Division by near zero value in Vec3");
            
            /*if(scalar == 0.0f)
            {
                return *this;
            }*/

            float inv = 1.0f / scalar;
            x *= inv;
            y *= inv;

            return *this;
        }
        
        // --- Vector Length ---
        float length() const {
            return std::sqrt
            (
                x*x + 
                y*y
            );
        }

        float lengthSquared() const {
            return x*x + y*y;
        }

        // --- Normalization ---
        void normalize() {
            float len = length();
            if (len <= 1e-8f) return;
            x /= len;
            y /= len;
        }

        Vec2 normalize() const {
            float len = length();
            if (len <= 1e-8f) return Vec2(0.0f);
            return *this / len;
        }

        // --- Named operations ---
        float dot(const Vec2 & other) const {
            return 
            x * other.x +
            y * other.y;
        }

        Vec2 cross(const Vec2 & other) const {
            return Vec2
            (
                y * other.x - x * other.y,
                x * other.y - y * other.x 
            );

        }


        ~Vec2() = default;
};
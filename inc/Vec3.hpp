#pragma once

#include "cmath"
#include "cassert"

struct Vec3{
    float x,y,z;

        Vec3() : x(0), y(0), z(0) {}
        Vec3(float v) : x(v), y(v), z(v) {}
        Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
        
        // --- Vector operations ---
        //
        Vec3 operator+(const Vec3& other) const {
            return Vec3
            (
                x + other.x,
                y + other.y,
                z + other.z
            );
        }
        Vec3 operator-(const Vec3& other) const {
            return Vec3
            (
                x - other.x,
                y - other.y,
                z - other.z
            );

        }
        Vec3 operator*(float scalar) const {
            return Vec3
            (
                x * scalar,
                y * scalar,
                z * scalar
            );
        }
        Vec3 operator/(float scalar) const {
            return Vec3
            (
                x / scalar,
                y / scalar,
                z / scalar
            );
        }

        Vec3& operator+=(const Vec3& other) {
            x += other.x;
            y += other.y;
            z += other.z;

        return *this;
        }

        Vec3& operator-=(const Vec3& other) {
                x -= other.x;
                y -= other.y;
                z -= other.z;

            return *this;
        }

        Vec3& operator*=(float scalar) {
                x *= scalar;
                y *= scalar;
                z *= scalar;

            return *this;
        }

        Vec3& operator/=(float scalar) {
            assert(scalar >= 1e-8f && "Division by near zero value in Vec3");
            
            /*if(scalar == 0.0f)
            {
                return *this;
            }*/

            float inv = 1.0f / scalar;
            x *= inv;
            y *= inv;
            z *= inv;

            return *this;
        }
        
        // --- Vector Length ---
        float length() const {
            return std::sqrt
            (
                x*x + 
                y*y + 
                z*z
            );
        }

        float lengthSquared() const {
            return x*x + y*y + z*z;
        }

        // --- Normalization ---
        void normalize() {
            float len = length();
            if (len <= 1e-8f) return;
            x /= len;
            y /= len;
            z /= len;
        }

        Vec3 normalized() const {
            float len = length();
            if (len <= 1e-8f) return Vec3(0.0f);
            return *this / len;
        }

        // --- Named operations ---
        float dot(const Vec3 & other) const {
            return 
            x * other.x +
            y * other.y +
            z * other.z;
        }

        Vec3 cross(const Vec3 & other) const {
            return Vec3
            (
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x 
            );

        }


        ~Vec3() = default;
};

        inline Vec3 operator*(float scalar, const Vec3& v) {
            return v * scalar;
        }
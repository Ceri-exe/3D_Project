#include <cmath> 
#include <iostream>
#include <cstdint>
#include <array>
#include "Vec3.hpp"
#include "Vec2.hpp"

struct Mat3
{
    std::array<float, 9> m = 
    {
        1,0,0,
        0,1,0,
        0,0,1,
    };

    Mat3(float value)
    {
        m.fill(value);
    }

    // --- Matrix Elements ---
    float* operator[](size_t row)
    {
        return &m[row * 4];
    }

    const float* operator[](size_t row) const
    {
        return &m[row * 4];
    }

    // --- Matrix operations ---
    // calculate //Vec3(v.x,v.y,v.z)
    Vec3 operator*(const Vec3& v) const
    {
        return Vec3
        (
            (*this)[0][0] * v.x +
            (*this)[0][1] * v.y +
            (*this)[0][2] * v.z,

            (*this)[1][0] * v.x +
            (*this)[1][1] * v.y +
            (*this)[1][2] * v.z,

            (*this)[2][0] * v.x +
            (*this)[2][1] * v.y +
            (*this)[2][2] * v.z
        );
    }

    friend std::ostream& operator << (std::ostream& os, const Mat4& m) 
    {
        for (size_t row = 0; row < 3; row++) {
            for (size_t col = 0; col < 3; col++) {
                os << m[row][col];
                if(col<2)
                    os <<", ";
            }
            if (row<2)
                os << '\n';
        }
        return os;
    } 
};

struct Mat4
{
    std::array<float, 16> m = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };

    Mat4(float value)
    {
        m.fill(value);
    }

    // --- Matrix Elements ---
    float* operator[](size_t row)
    {
        return &m[row * 4];
    }

    const float* operator[](size_t row) const
    {
        return &m[row * 4];
    }

    // --- Matrix operations ---
    // calculate //Vec4(v.x,v.y,v.z, 1.0f)
    Vec3 operator*(const Vec3& v) const
    {
        return Vec3
        (
            (*this)[0][0] * v.x +
            (*this)[0][1] * v.y +
            (*this)[0][2] * v.z +
            (*this)[0][3],

            (*this)[1][0] * v.x +
            (*this)[1][1] * v.y +
            (*this)[1][2] * v.z +
            (*this)[1][3],

            (*this)[2][0] * v.x +
            (*this)[2][1] * v.y +
            (*this)[2][2] * v.z +
            (*this)[2][3]
        );
    }

    Mat4 operator*(const Mat4& other) const
    {
        Mat4 result(0.0f);

        for(size_t row = 0; row <4; row++)
        {
            for(size_t k = 0; k<4; k++)
            {
                float a = (*this)[row][k];
                for(size_t col = 0; col<4; col++)
                {
                    result[row][col] += a * other[k][col];                        
                }
            }
        }
        return result;
    }

    friend std::ostream& operator << (std::ostream& os, const Mat4& m) 
    {
        for (size_t row = 0; row < 4; row++) {
            for (size_t col = 0; col < 4; col++) {
                os << m[row][col];
                if(col<3)
                    os <<", ";
            }
            if (row<3)
                os << '\n';
        }
        return os;
    } 
};
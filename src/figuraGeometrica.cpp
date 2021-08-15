/**
 *
 * Created by Layza on 15/08/2021
*/

#include "figuraGeometrica.hpp"
#include <cmath>

/**
 * Draw voxel at position (x0,y0,z0) with color (r,g,b,a)
 */
class PutVoxel : public FiguraGeometrica {
protected:
    int x, y, z;
    float r, g, b, a;
public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float a) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    void draw(Sculptor &t) {
        if (this->x >= 0 && this->x < t.nx && this->y >= 0 && this->y < t.ny && this->z >= 0 && this->z < t.nz) {
            t.v[this->x][this->y][this->z].isOn = true;
            t.v[this->x][this->y][this->z].r = this->r;
            t.v[this->x][this->y][this->z].g = this->g;
            t.v[this->x][this->y][this->z].b = this->b;
            t.v[this->x][this->y][this->z].a = this->a;
        }
    }
};

/**
 * Erase voxel at position (x0,y0,z0) with color (r,g,b,a)
 */
class CutVoxel : public FiguraGeometrica {
protected:
    int x, y, z;
public:
    CutVoxel(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void draw(Sculptor &t) {
        if (this->x >= 0 && this->x < t.nx && this->y >= 0 && this->y < t.ny && this->z >= 0 && this->z < t.nz) {
            t.v[x][y][z].isOn = false;
        }
    }
};

/**
 * Draws a parallelepiped delimited by x∈(x0,x1), y∈(y0,y1), z∈(z0,z1) with the color (r,g,b,a)
 */
class PutBox : public FiguraGeometrica {
protected:
    int x0, x1, y0, y1, z0, z1;
    float r, g, b, a;
public:
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a) {
        this->x0 = x0;
        this->x1 = x1;
        this->y0 = y0;
        this->y1 = y1;
        this->z0 = z0;
        this->z1 = z1;
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    void draw(Sculptor &t) {
        for (int i = this->x0; i <= this->x1; i++) {
            for (int j = this->y0; j <= this->y1; j++) {
                for (int k = this->z0; k <= this->z1; k++) {
                    PutVoxel putVoxel(i, j, k, this->r, this->g, this->b, this->a);
                    putVoxel.draw(t);
                }
            }
        }
    }
};

/**
 * Erases a parallelepiped delimited by x∈(x0,x1), y∈(y0,y1), z∈(z0,z1).
 */
class CutBox : public FiguraGeometrica {
protected:
    int x0, x1, y0, y1, z0, z1;
public:
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
        this->x0 = x0;
        this->x1 = x1;
        this->y0 = y0;
        this->y1 = y1;
        this->z0 = z0;
        this->z1 = z1;
    }

    void draw(Sculptor &t) {
        for (int i = this->x0; i <= this->x1; i++) {
            for (int j = this->y0; j <= this->y1; j++) {
                for (int k = this->z0; k <= this->z1; k++) {
                    CutVoxel cutVoxel(i, j, k);
                    cutVoxel.draw(t);
                }
            }
        }
    }
};

/**
 * Draws a sphere with center at point (x0,y0,z0), specified radius and with color (r,g,b,a).
 */
class PutSphere : public FiguraGeometrica {
protected:
    int xcenter, ycenter, zcenter, radius;
    float r, g, b, a;
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a) {
        this->xcenter = xcenter;
        this->ycenter = ycenter;
        this->zcenter = zcenter;
        this->radius = radius;
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    void draw(Sculptor &t) {
        for (int i = 0; i <= t.nx; i++) {
            for (int j = 0; j <= t.ny; j++) {
                for (int k = 0; k <= t.nz; k++) {
                    if (pow(i - this->xcenter, 2) + pow(j - this->ycenter, 2) + pow(k - this->zcenter, 2) <=
                        pow(this->radius, 2)) {
                        PutVoxel putVoxel(i, j, k, this->r, this->g, this->b, this->a);
                        putVoxel.draw(t);
                    }
                }
            }
        }
    }
};

/**
 * Erases a sphere with center at point (x0,y0,z0) and specified radius.
 */
class CutSphere : public FiguraGeometrica {
protected:
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius) {
        this->xcenter = xcenter;
        this->ycenter = ycenter;
        this->zcenter = zcenter;
        this->radius = radius;
    }

    void draw(Sculptor &t) {
        for (int i = 0; i <= t.nx; i++) {
            for (int j = 0; j <= t.ny; j++) {
                for (int k = 0; k <= t.nz; k++) {
                    if (pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2) <= pow(radius, 2)) {
                        CutVoxel cutVoxel(i, j, k);
                        cutVoxel.draw(t);
                    }
                }
            }
        }
    }
};

/**
 * Draws an ellipsoid with center at point (x0,y0,z0), specified radii and with color (r,g,b,a).
 */
class PutEllipsoid : public FiguraGeometrica {
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz;
    float r, g, b, a;
public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a) {
        this->xcenter = xcenter;
        this->ycenter = ycenter;
        this->zcenter = zcenter;
        this->rx = rx;
        this->ry = ry;
        this->rz = rz;
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    void draw(Sculptor &t) {
        float partX, partY, partZ;
        for (int i = 0; i <= t.nx; i++) {
            for (int j = 0; j <= t.ny; j++) {
                for (int k = 0; k <= t.nz; k++) {
                    partX = pow((i - this->xcenter), 2) / pow(this->rx, 2);
                    partY = pow((j - this->ycenter), 2) / pow(this->ry, 2);
                    partZ = pow((k - this->zcenter), 2) / pow(this->rz, 2);
                    if ((partX + partY + partZ) <= 1) {
                        PutVoxel putVoxel(i, j, k, this->r, this->g, this->b, this->a);
                        putVoxel.draw(t);
                    }
                }
            }
        }
    }
};

/**
 * Erases an ellipsoid centered on the point (x0,y0,z0) and specified radii.
 */
class CutEllipsoid : public FiguraGeometrica {
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
        this->xcenter = xcenter;
        this->ycenter = ycenter;
        this->zcenter = zcenter;
        this->rx = rx;
        this->ry = ry;
        this->rz = rz;
    }

    void draw(Sculptor &t) {
        float partX, partY, partZ;
        for (int i = 0; i <= t.nx; i++) {
            for (int j = 0; j <= t.ny; j++) {
                for (int k = 0; k <= t.nz; k++) {
                    partX = pow((i - this->xcenter), 2) / pow(this->rx, 2);
                    partY = pow((j - this->ycenter), 2) / pow(this->ry, 2);
                    partZ = pow((k - this->zcenter), 2) / pow(this->rz, 2);
                    if ((partX + partY + partZ) <= 1) {
                        CutVoxel cutVoxel(i, j, k);
                        cutVoxel.draw(t);
                    }
                }
            }
        }
    }
};
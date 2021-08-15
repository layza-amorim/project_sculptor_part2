/**
 * Class to manipulate the pixels of the 3d matrix
 *  * @author Layza Amorim
 */

#ifndef PROJECT_SCULPTOR_HPP
#define PROJECT_SCULPTOR_HPP


#include "voxel.hpp"

class Sculptor {

public:

    Voxel ***v; /// 3D matrix

    int nx, ny, nz; /// Dimensions

    Sculptor(int _nx, int _ny, int _nz);

    ~Sculptor();

    void writeOFF(const char *filename);
};


#endif //PROJECT_SCULPTOR_HPP

/**
 *
 * Created by Layza on 21/07/2021
*/

#include "sculptor.hpp"
#include <iostream>
#include <fstream>
using namespace std;

/**
 * Class builder
 *
 * @param _nx first dimension of the 3D matrix
 * @param _ny second dimension of the 3D matrix
 * @param _nz third dimension of the 3D matrix
 */
Sculptor::Sculptor(int _nx, int _ny, int _nz) {

    /// Allocate memory blocks of size _nx
    this->v = new Voxel **[_nx];
    /// Allocate variables in memory
    this->nx = _nx;
    this->ny = _ny;
    this->nz = _nz;


    for (int i = 0; i < _nx; i++) {

        /// Allocate memory blocks for
        /// rows of each 2D array
        this->v[i] = new Voxel *[_ny];

        for (int j = 0; j < _ny; j++) {

            /// Allocate memory blocks for
            /// columns of each 2D array
            this->v[i][j] = new Voxel[_nz];

            for (int k = 0; k < _nz; k++) {
                this->v[i][j][k].isOn = false;
            }
        }
    }
}

/**
 * Class destroyer
 */
Sculptor::~Sculptor() {
    /// Deallocate memory
    for (int i = 0; i < this->nx; i++) {
        for (int j = 0; j < this->ny; j++) {
            delete[] this->v[i][j];
        }
        delete[] this->v[i];
    }
    delete[] this->v;
}

/**
 * writes the sculpture in OFF format to file filename
 *
 * @param filename name for the file
 */
void Sculptor::writeOFF(const char *filename) {
    ofstream myFile(filename);

    /// check if the file is not open
    if (!myFile.is_open()) {
        cout << "Failed to open file";
        exit(1);
    }

    int active = 0;
    int countActives = 0;

    /// count the amount of active voxels
    for (int i = 0; i < this->nx; i++) {
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                if (this->v[i][j][k].isOn) {
                    active++;
                }
            }
        }
    }

    /// write the word off in the file
    myFile << "OFF" << endl;
    /// write the number of vertices in the file
    myFile << 8 * active << " " << 6 * active << " 0" << endl;

    /// writes the number of three-dimensional
    /// spatial coordinates of the vertices in the file
    for (int i = 0; i < this->nx; i++) {
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                if (this->v[i][j][k].isOn) {
                    myFile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    myFile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    myFile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    myFile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    myFile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    myFile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    myFile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    myFile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                }
            }
        }
    }

    /// write the specifications of the faces to the file
    for (int i = 0; i < this->nx; i++) {
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                if (this->v[i][j][k].isOn) {
                    myFile << "4 " << countActives * 8 + 0 << " " << countActives * 8 + 3 << " " << countActives * 8 + 2
                           << " " << countActives * 8 + 1 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g
                           << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << countActives * 8 + 4 << " " << countActives * 8 + 5 << " " << countActives * 8 + 6
                           << " " << countActives * 8 + 7 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g
                           << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << countActives * 8 + 0 << " " << countActives * 8 + 1 << " " << countActives * 8 + 5
                           << " " << countActives * 8 + 4 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g
                           << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << countActives * 8 + 0 << " " << countActives * 8 + 4 << " " << countActives * 8 + 7
                           << " " << countActives * 8 + 3 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g
                           << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << countActives * 8 + 3 << " " << countActives * 8 + 7 << " " << countActives * 8 + 6
                           << " " << countActives * 8 + 2 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g
                           << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << countActives * 8 + 1 << " " << countActives * 8 + 2 << " " << countActives * 8 + 6
                           << " " << countActives * 8 + 5 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g
                           << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    countActives++;
                }
            }
        }
    }

    /// close the file
    myFile.close();
}
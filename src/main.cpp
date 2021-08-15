/**
 * Created by Layza on 21/07/2021
 */

#include "Sculptor.hpp"
#include "figuraGeometrica.hpp"
#include "figuraGeometrica.cpp"


int main() {
    Sculptor sculptor(20, 20, 20); ///create a sculptor object

    PutBox putBox(5, 13, 9, 19, 3, 18, 0.6, 0.3, 0.0, 0.8);///activate voxels in interval
    putBox.draw(sculptor);

    CutBox cutBox(5, 13, 19, 19, 3, 8);///disable voxels in interval
    cutBox.draw(sculptor);
    CutBox cutBox2(5, 13, 19, 19, 13, 18);///disable voxels in interval
    cutBox2.draw(sculptor);

    CutBox cutBox3(5, 13, 18, 18, 3, 7);///disable voxels in interval
    cutBox3.draw(sculptor);
    CutBox cutBox4(5, 13, 18, 18, 14, 18);///disable voxels in interval
    cutBox4.draw(sculptor);

    CutBox cutBox5(5, 13, 17, 17, 3, 6);///disable voxels in interval
    cutBox5.draw(sculptor);
    CutBox cutBox6(5, 13, 17, 17, 15, 18);///disable voxels in interval
    cutBox6.draw(sculptor);

    CutBox cutBox7(5, 13, 16, 16, 3, 5);///disable voxels in interval
    cutBox7.draw(sculptor);
    CutBox cutBox8(5, 13, 16, 16, 16, 18);///disable voxels in interval
    cutBox8.draw(sculptor);

    CutBox cutBox9(5, 13, 15, 15, 3, 4);///disable voxels in interval
    cutBox9.draw(sculptor);
    CutBox cutBox10(5, 13, 15, 15, 17, 18);///disable voxels in interval
    cutBox10.draw(sculptor);

    CutBox cutBox11(5, 13, 13, 14, 3, 3);///disable voxels in interval
    cutBox11.draw(sculptor);
    CutBox cutBox12(5, 13, 13, 14, 18, 18);///disable voxels in interval
    cutBox12.draw(sculptor);

    CutBox cutBox13(5, 13, 9, 9, 3, 3);///disable voxels in interval
    cutBox13.draw(sculptor);
    CutBox cutBox14(5, 13, 9, 9, 18, 18);///disable voxels in interval
    cutBox14.draw(sculptor);

    PutBox putBox1(5, 13, 9, 9, 8, 13, 0.9, 0.7, 0.6, 0.8);///character's body
    putBox1.draw(sculptor);
    PutBox putBox2(5, 13, 4, 8, 7, 14, 0.9, 0.7, 0.6, 0.8);///character's body
    putBox2.draw(sculptor);

    PutBox putBox3(4, 4, 11, 14, 7, 7, 0.9, 0.7, 0.6, 0.8);///character's left eye
    putBox3.draw(sculptor);
    PutBox putBox4(4, 4, 11, 12, 9, 9, 0.9, 0.7, 0.6, 0.8);///character's left eye
    putBox4.draw(sculptor);
    PutVoxel putVoxel(4, 11, 8, 0.9, 0.7, 0.6, 0.8);///character's left eye
    putVoxel.draw(sculptor);

    PutBox putBox5(4, 4, 11, 14, 14, 14, 0.9, 0.7, 0.6, 0.8);///character's right eye
    putBox5.draw(sculptor);
    PutBox putBox6(4, 4, 11, 12, 12, 12, 0.9, 0.7, 0.6, 0.8);///character's right eye
    putBox6.draw(sculptor);
    PutVoxel putVoxel2(4, 11, 13, 0.9, 0.7, 0.6, 0.8);///character's right eye
    putVoxel2.draw(sculptor);

    PutVoxel putVoxel3(4, 15, 6, 0.0, 0.0, 0.0, 1.0);///character's left eyebrow
    putVoxel3.draw(sculptor);
    PutVoxel putVoxel4(4, 15, 7, 0.0, 0.0, 0.0, 1.0);///character's left eyebrow
    putVoxel4.draw(sculptor);

    PutVoxel putVoxel5(4, 15, 14, 0.0, 0.0, 0.0, 1.0);///character's right eyebrow
    putVoxel5.draw(sculptor);
    PutVoxel putVoxel6(4, 15, 15, 0.0, 0.0, 0.0, 1.0);///character's right eyebrow
    putVoxel6.draw(sculptor);

    PutBox putBox7(4, 4, 12, 14, 8, 8, 0.0, 0.0, 0.0, 1.0);///character's eye
    putBox7.draw(sculptor);
    PutBox putBox8(4, 4, 12, 14, 13, 13, 0.0, 0.0, 0.0, 1.0);///character's eye
    putBox8.draw(sculptor);

    PutBox putBox9(4, 4, 13, 13, 9, 12, 0.0, 0.0, 0.0, 1.0);///character's eye
    putBox9.draw(sculptor);

    PutSphere putSphere(10, 10, 10, 2, 0.0, 0.0, 0.0, 1.0);///test for the putSphere
    putSphere.draw(sculptor);
    CutSphere cutSphere(10, 10, 10, 2);///test for the putSphere
    cutSphere.draw(sculptor);

    PutBox putBox10(5, 13, 3, 7, 4, 9, 0.0, 0.0, 0.0, 1.0);///character's feet
    putBox10.draw(sculptor);
    PutBox putBox11(5, 13, 3, 7, 12, 17, 0.0, 0.0, 0.0, 1.0);///character's feet
    putBox11.draw(sculptor);

    CutBox cutBox15(5, 13, 3, 3, 4, 4);///character's body
    cutBox15.draw(sculptor);
    CutBox cutBox16(5, 13, 7, 7, 4, 4);///character's body
    cutBox16.draw(sculptor);

    CutBox cutBox17(5, 13, 3, 3, 17, 17);///character's body
    cutBox17.draw(sculptor);
    CutBox cutBox18(5, 13, 7, 7, 17, 17);///character's body
    cutBox18.draw(sculptor);

    PutEllipsoid putEllipsoid(5, 7, 10, 1, 2, 3, 0.9, 0.7, 0.6, 0.8);///character's body
    putEllipsoid.draw(sculptor);
    PutEllipsoid putEllipsoid2(5, 7, 11, 1, 2, 3, 0.9, 0.7, 0.6, 0.8);///character's body
    putEllipsoid2.draw(sculptor);

    CutVoxel cutVoxel(4, 7, 10);///finishes the character's eye
    cutVoxel.draw(sculptor);
    CutVoxel cutVoxel2(4, 7, 11);///finishes the character's eye
    cutVoxel2.draw(sculptor);

    sculptor.writeOFF("sculptor.off");///create the file
    return 0;
}
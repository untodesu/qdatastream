#include "qdstest/pch.hh"

#include "qdstest/dsop.hh"

int main(int argc, char** argv)
{
    Eigen::Affine3d affine;
    affine.linear() = Eigen::Matrix3d::Identity();
    affine.translation() = Eigen::Vector3d(1.0, 2.0, 3.0);

    Eigen::Vector2d vec2d(4.0, 5.0);
    Eigen::Vector3d vec3d(6.0, 7.0, 8.0);

    QByteArray byteArray;

    {
        QDataStream outStream(&byteArray, QIODevice::WriteOnly);
        outStream << affine;
        outStream << vec2d;
        outStream << vec3d;
    }

    Eigen::Affine3d readAffine;
    Eigen::Vector2d readVec2d;
    Eigen::Vector3d readVec3d;

    {
        QDataStream inStream(&byteArray, QIODevice::ReadOnly);
        inStream >> readAffine;
        inStream >> readVec2d;
        inStream >> readVec3d;
    }

    qDebug() << "affine comparison:" << affine.isApprox(readAffine);
    qDebug() << "vec2d comparison:" << vec2d.isApprox(readVec2d);
    qDebug() << "vec3d comparison:" << vec3d.isApprox(readVec3d);

    return EXIT_SUCCESS;
}

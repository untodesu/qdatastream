#include "qdstest/pch.hh"

#include "qdstest/dsop.hh"

QDataStream& operator<<(QDataStream& stream, const Eigen::Affine3d& affine)
{
    stream << Eigen::Vector3d(affine.linear().col(0));
    stream << Eigen::Vector3d(affine.linear().col(1));
    stream << Eigen::Vector3d(affine.linear().col(2));
    stream << Eigen::Vector3d(affine.translation());
    return stream;
}

QDataStream& operator<<(QDataStream& stream, const Eigen::Vector2d& vector)
{
    stream << vector.x();
    stream << vector.y();
    return stream;
}

QDataStream& operator<<(QDataStream& stream, const Eigen::Vector3d& vector)
{
    stream << vector.x();
    stream << vector.y();
    stream << vector.z();
    return stream;
}

QDataStream& operator>>(QDataStream& stream, Eigen::Affine3d& affine)
{
    Eigen::Vector3d x_axis;
    Eigen::Vector3d y_axis;
    Eigen::Vector3d z_axis;
    Eigen::Vector3d translation;

    stream >> x_axis;
    stream >> y_axis;
    stream >> z_axis;
    stream >> translation;

    affine.linear().col(0) = x_axis;
    affine.linear().col(1) = y_axis;
    affine.linear().col(2) = z_axis;
    affine.translation() = translation;

    return stream;
}

QDataStream& operator>>(QDataStream& stream, Eigen::Vector2d& vector)
{
    stream >> vector.x();
    stream >> vector.y();
    return stream;
}

QDataStream& operator>>(QDataStream& stream, Eigen::Vector3d& vector)
{
    stream >> vector.x();
    stream >> vector.y();
    stream >> vector.z();
    return stream;
}

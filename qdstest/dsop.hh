#pragma once

// Declare QDataStream operators for Eigen::Affine3d, Vector2d and Vector3d

QDataStream& operator<<(QDataStream& stream, const Eigen::Affine3d& affine);
QDataStream& operator<<(QDataStream& stream, const Eigen::Vector2d& vector);
QDataStream& operator<<(QDataStream& stream, const Eigen::Vector3d& vector);

QDataStream& operator>>(QDataStream& stream, Eigen::Affine3d& affine);
QDataStream& operator>>(QDataStream& stream, Eigen::Vector2d& vector);
QDataStream& operator>>(QDataStream& stream, Eigen::Vector3d& vector);

Q_DECLARE_METATYPE(Eigen::Affine3d)
Q_DECLARE_METATYPE(Eigen::Vector2d)
Q_DECLARE_METATYPE(Eigen::Vector3d)

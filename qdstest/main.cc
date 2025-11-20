#include "qdstest/pch.hh"

#include "qdstest/dsop.hh"

constexpr static std::string_view QDSTEST_FILENAME_WIN32("qdstest_win32.dat");
constexpr static std::string_view QDSTEST_FILENAME_LINUX("qdstest_linux.dat");

#if defined(_WIN32)
constexpr static std::string_view QDSTEST_FILENAME = QDSTEST_FILENAME_WIN32;
#else
constexpr static std::string_view QDSTEST_FILENAME = QDSTEST_FILENAME_LINUX;
#endif

int main(int argc, char** argv)
{
    if(argc < 2) {
        qDebug() << "!!! argc";

        return EXIT_FAILURE;
    }

    std::string_view mode(argv[1], std::strlen(argv[1]));

    Eigen::Affine3d affine;
    affine.linear() = Eigen::Matrix3d::Identity();
    affine.translation() = Eigen::Vector3d(1.0, 2.0, 3.0);

    Eigen::Vector2d vec2d(4.0, 5.0);
    Eigen::Vector3d vec3d(6.0, 7.0, 8.0);

    std::filesystem::path working_dir(std::filesystem::current_path());

    if(0 == mode.compare("save")) {
        std::filesystem::path filepath(working_dir / QDSTEST_FILENAME);

        QFile file(QString::fromStdString(filepath.string()));

        if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            QDataStream stream(&file);
            stream.setVersion(QDataStream::Qt_6_5);

            stream << affine;
            stream << vec2d;
            stream << vec3d;

            file.close();

            return EXIT_SUCCESS;
        }

        qDebug() << "!!! save open write";

        return EXIT_FAILURE;
    }
    else if(0 == mode.compare("check")) {
        if(argc < 3) {
            qDebug() << "!!! check argc";

            return EXIT_FAILURE;
        }

        std::string_view filecheck(argv[2], std::strlen(argv[2]));
        std::filesystem::path filecheck_path;

        if(0 == filecheck.compare("win32")) {
            filecheck_path = working_dir / QDSTEST_FILENAME_WIN32;
        }
        else if(0 == filecheck.compare("linux")) {
            filecheck_path = working_dir / QDSTEST_FILENAME_LINUX;
        }
        else {
            qDebug() << "!!! check filecheck";

            return EXIT_FAILURE;
        }

        QFile file(QString::fromStdString(filecheck_path.string()));

        if(file.open(QIODevice::ReadOnly)) {
            QDataStream stream(&file);
            stream.setVersion(QDataStream::Qt_6_5);

            Eigen::Affine3d readAffine;
            Eigen::Vector2d readVec2d;
            Eigen::Vector3d readVec3d;

            stream >> readAffine;
            stream >> readVec2d;
            stream >> readVec3d;

            file.close();

            qDebug() << "affine comparison:" << affine.isApprox(readAffine);
            qDebug() << "vec2d comparison:" << vec2d.isApprox(readVec2d);
            qDebug() << "vec3d comparison:" << vec3d.isApprox(readVec3d);

            return EXIT_SUCCESS;
        }

        qDebug() << "!!! read";

        return EXIT_FAILURE;
    }

    qDebug() << "!!! mode";

    return EXIT_FAILURE;
}

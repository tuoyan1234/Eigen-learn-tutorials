/*
 * @Author: tyz 1872516355@qq.com
 * @Date: 2026-04-24 20:57:59
 * @LastEditors: tyz 1872516355@qq.com
 * @LastEditTime: 2026-04-24 21:00:38
 * @FilePath: /Eigen/eigen_error/eigen_error.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <Eigen/Dense>

int main(){
    // 特殊矩阵的eigen初始化
    Eigen::MatrixXd matrix4d = Eigen::MatrixXd::Identity(4, 4);
    matrix4d << 1, 2, 3, 4,
                5, 6, 7, 8,
                9, 10, 11, 12,
                13, 14, 15, 16;

    /*
    matrix原本按列存储，matrix4d.data()输出的还是原列存储内容
    */
    std::cout << "matrix4d:\n" << matrix4d << std::endl;
    Eigen::Matrix4d matrix4d_temp1 = Eigen::Matrix4d::Identity(4, 4);
    matrix4d_temp1 = Eigen::Map<Eigen::Matrix4d>(matrix4d.data());
    std::cout << "matrix4d_temp1:\n" << matrix4d_temp1 << std::endl;

    /*
    matrix原本按列存储，使用Map时指定了存储方式为行存储（即：将列存储内容转换为行存储，即转置）
    */
    Eigen::Matrix4d matrix4d_temp2 = Eigen::Matrix4d::Identity(4, 4);
    matrix4d_temp2 = Eigen::Map<const Eigen::Matrix<double, 4, 4, Eigen::RowMajor>>(matrix4d.data());
    std::cout << "matrix4d_temp2:\n" << matrix4d_temp2 << std::endl;

    return 0;
}

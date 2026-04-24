/*
 * @Author: tyz 1872516355@qq.com
 * @Date: 2026-04-24 20:54:40
 * @LastEditors: tyz 1872516355@qq.com
 * @LastEditTime: 2026-04-24 20:57:02
 * @FilePath: /Eigen/6_tutorials/special_init.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <Eigen/Dense>

int main(){
    // 特殊矩阵的eigen初始化
    Eigen::MatrixXd matrix4d = Eigen::MatrixXd::Zero(4, 4);
    std::cout << "Zero matrix:\n" << matrix4d << std::endl;
    // Identity
    Eigen::Matrix4d matrix_4d = Eigen::Matrix4d::Identity();
    std::cout << "Identity matrix:\n" << matrix_4d << std::endl;
    // Random
    Eigen::Matrix3d matrix_3d = Eigen::Matrix3d::Random();
    std::cout << "Random matrix:\n" << matrix_3d << std::endl;
    // COnstant
    Eigen::Matrix3d matrix_3d_const = Eigen::Matrix3d::Constant(3.14);
    std::cout << "Constant matrix:\n" << matrix_3d_const << std::endl;

    return 0;
}

/*
 * @Author: tyz 1872516355@qq.com
 * @Date: 2026-04-20 21:50:53
 * @LastEditors: tyz 1872516355@qq.com
 * @LastEditTime: 2026-04-20 22:25:23
 * @FilePath: /Eigen/1_tutorials/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <Eigen/Dense>

int main(){
    // Eigen::MatrixXd
    Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << "2*2: " << std::endl << m << std::endl;

    // Eigen::Matrix3d * Eigen::Vector3d
    Eigen::Matrix3d matrix_3d;
    matrix_3d << 1,2,3,
                 4,5,6,
                 7,8,9;
    std::cout << "matrix_3d: " << std::endl << matrix_3d << std::endl;
    Eigen::Vector3d v_3d{7,15,26};
    Eigen::Vector3d result_3d = matrix_3d * v_3d;
    std::cout << "result_3d: " << std::endl << result_3d << std::endl;
    
}
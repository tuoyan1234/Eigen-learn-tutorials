/*
 * @Author: tyz 1872516355@qq.com
 * @Date: 2026-04-20 21:50:53
 * @LastEditors: tyz 1872516355@qq.com
 * @LastEditTime: 2026-04-20 22:44:55
 * @FilePath: /Eigen/1_tutorials/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
MATRIX类:
    1.Matrix类有6个模板参数，主要使用前3个，分别是：数据类型、行数、列数：
        如： typedef Matrix<double, 3,3> Matrix3d; // 定义一个3行3列的double类型矩阵
            typedef Matrix<float, 2,2> Matrix2f; // 定义一个2行2列的float类型矩阵>
    2.定义向量
        如：
            typedef Eigen::Matrix<double, 3,1> Vector3d; // 定义一个3行1列的double类型向量
            typedef Eigen::Matrix<float, 2,1> Vector2f; // 定义一个2行1列的float类型向量
            // 定义行向量
            Eigen::Matrix<double,1,3> row_vector_13; // 定义一个1行3列的double类型行向量
*/
#include <iostream>
#include <Eigen/Dense>

int main(){
    Eigen::Matrix<double, 2, 3> matrix_23;
    matrix_23 << 1,2,3,
                 4,5,6;
    std::cout << "matrix_23(1): " << matrix_23(1) << " ,matrix_23(1,0): " << matrix_23(1,0) << std::endl; // 按照列优先的方式访问元素，输出4
    std::cout << "matrix_23: " << std::endl << matrix_23 << std::endl;
    // 定义3行一列的向量，二者相乘
    Eigen::Matrix<double, 3,1> matrix_31;
    matrix_31 << 1,2,3;
    std::cout << "matrix_31: " << std::endl << matrix_31 << std::endl;
    Eigen::Matrix<double, 2, 1> result_21 = matrix_23 * matrix_31;
    std::cout << "result_21: " << std::endl << result_21 << std::endl;
    // 定义行向量与矩阵相乘
    Eigen::Matrix<double,1,2> row_vector_12;
    row_vector_12 << 1,2;
    std::cout << "row_vector_12: " << std::endl << row_vector_12 << std::endl;
    Eigen::Matrix<double,1,3> result_13 = row_vector_12 * matrix_23;
    std::cout << "result_13: " << std::endl << result_13 << std::endl;
    // Xd
    Eigen::VectorXd x_d;
    x_d = row_vector_12 * matrix_23;
    std::cout << "x_d: " << std::endl << x_d << std::endl;

    return 0;
}
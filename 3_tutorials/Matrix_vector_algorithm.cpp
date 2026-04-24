/*
 * @Author: tyz 1872516355@qq.com
 * @Date: 2026-04-24 20:48:13
 * @LastEditors: tyz 1872516355@qq.com
 * @LastEditTime: 2026-04-24 20:53:12
 * @FilePath: /Eigen/3_tutorials/Matrix_vector_algorithm.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <Eigen/Dense>

int main()
{
    // 1.加法、减法
    Eigen::Matrix2d matrix_2d_1;
    matrix_2d_1 << 1,2,
                   3,4;
    Eigen::Matrix2d matrix_2d_2;
    matrix_2d_2 << 5,6,
                   7,8;
    std::cout << "matrix_2d_1: " << std::endl << matrix_2d_1 << std::endl;
    std::cout << "matrix_2d_2: " << std::endl << matrix_2d_2 << std::endl;
    Eigen::Matrix2d matrix_2d_res;
    matrix_2d_res = matrix_2d_1 + matrix_2d_2;
    std::cout << "matrix_2d_1 + matrix_2d_2: " << std::endl << matrix_2d_res << std::endl;
    // 2.减法
    matrix_2d_res = matrix_2d_1 - matrix_2d_2;
    std::cout << "matrix_2d_1 - matrix_2d_2: " << std::endl << matrix_2d_res << std::endl;
    // 3.标量乘法
    matrix_2d_res = matrix_2d_1 * 2;
    std::cout << "matrix_2d_1 * 2: " << std::endl << matrix_2d_res << std::endl;
    matrix_2d_res = 2 * matrix_2d_res;
    std::cout << "2 * matrix_2d_1 * 2: " << std::endl << matrix_2d_res << std::endl;
    // 4.标量除法
    matrix_2d_res = matrix_2d_1 / 2;
    std::cout << "matrix_2d_1 / 2: " << std::endl << matrix_2d_res << std::endl;
    // 5.矩阵的转置、共轭、伴随(共轭转置)…对于实数矩阵，conjugate不执行任何操作，adjoint等价于transpose
    Eigen::Matrix2d matrix_2d;
    matrix_2d << 1,2,
                 3,4;
    std::cout << "matrix_2d: " << std::endl << matrix_2d << std::endl;
    std::cout << "matrix_2d的转置矩阵: " << std::endl << matrix_2d.transpose() << std::endl;
    std::cout << "matrix_2d的共轭矩阵: " << std::endl << matrix_2d.conjugate() << std::endl;
    std::cout << "matrix_2d的转置矩阵: " << std::endl << matrix_2d.adjoint() << std::endl;
    // 注意：不能写成 matrix_2d = matrix_2d.transpose();
    // 因为 transpose() 返回的是引用原数据的代理对象，赋值时会出现别名(aliasing)问题，
    // 即写入新值会污染尚未读取的原信息，Eigen会触发断言失败（Aborted）。
    // 正确做法 1: 使用原地转置
    matrix_2d.transposeInPlace();
    // 正确做法 2 (等价): matrix_2d = matrix_2d.transpose().eval();
    std::cout << "matrix_2d的转置矩阵: " << std::endl << matrix_2d << std::endl;
    // vectorXd
    Eigen::Vector2d vector_2d;
    vector_2d << 1,2;
    std::cout << "vector_2d: " << std::endl << vector_2d << std::endl;
    Eigen::Matrix<double,1,2> vector_2d_row;
    vector_2d_row << 1,2;
    std::cout << "vector_2d_row: " << std::endl << vector_2d_row << std::endl;
    // 矩阵相乘
    Eigen::Matrix3d matrix_3d_1;
    matrix_3d_1 << 1,2,3,4,5,6,7,8,9;
    Eigen::Matrix3d matrix_3d_2;
    matrix_3d_2 << 1,2,3,4,5,6,7,8,9;
    std::cout << "matrix_3d_1: " << std::endl << matrix_3d_1 << std::endl;
    std::cout << "matrix_3d_2: " << std::endl << matrix_3d_2 << std::endl;
    // Eigen::MatrixXd matrix_3d_res = matrix_3d_1 * matrix_3d_2;
    Eigen::MatrixXd matrix_3d_res = matrix_3d_1 * matrix_3d_2;
    std::cout << "matrix_3d_1.dot(matrix_3d_2): " << std::endl << matrix_3d_res << std::endl;
    // 向量/矩阵点乘与叉乘
    Eigen::Vector3d vector_3d_1;
    vector_3d_1 << 1,2,3;
    Eigen::Vector3d vector_3d_2;
    vector_3d_2 << 4,5,6;
    std::cout << "vector_3d_1: " << std::endl << vector_3d_1 << std::endl;
    std::cout << "vector_3d_2: " << std::endl << vector_3d_2 << std::endl;
    Eigen::Vector3d vector_3d_res = vector_3d_1.cross(vector_3d_2);
    std::cout << "vector_3d.cross(vector_3d_2): " << std::endl << vector_3d_res << std::endl;
    std::cout << "vector_3d_1.dot(vector_3d_2): " << std::endl << vector_3d_1.dot(vector_3d_2) << std::endl;

    // Eigen提供了一些归约函数把一个给定的矩阵或向量化为一个值，比如
    /*
    求和函数 (sum()): 矩阵中所有元素的求和
    求积函数 (prod()): 矩阵中所有元素的乘积
    平均值 (mean()): 矩阵中所有元素的平均值
    最大值 (maxCoeff()): 矩阵中所有元素的最大值，也可以返回最大值的位置
    最小值 (minCoeff()): 矩阵中所有元素的最小值，也可以返回最小值的位置
    迹 (trace()): 一个矩阵中对角线元素的和，也可以用.diagonal().sum()进行计算。
    */
    // 注意:MatrixXd 是动态尺寸矩阵，默认是 0x0，必须先 resize 再用 << 填充
    // 否则会向未分配的内存写入数据，导致 Segmentation fault (exit code 139).
    Eigen::MatrixXd matrix_xd(4, 4); // 或者 matrix_xd.resize(4, 4);
    matrix_xd << 1,2,3,4,
                 5,6,7,8,
                 9,10,11,12,
                 13,14,15,16;
    std::cout << "matrix_xd: " << std::endl << matrix_xd << std::endl;
    std::cout << "matrix_xd.sum(): " << std::endl << matrix_xd.sum() << std::endl;
    std::cout << "matrix_xd.prod(): " << std::endl << matrix_xd.prod() << std::endl;
    std::cout << "matrix_xd.mean(): " << std::endl << matrix_xd.mean() << std::endl;
    std::cout << "matrix_xd.maxCoeff(): " << std::endl << matrix_xd.maxCoeff() << std::endl;
    std::cout << "matrix_xd.minCoeff(): " << std::endl << matrix_xd.minCoeff() << std::endl;
    std::cout << "matrix_xd.trace(): " << std::endl << matrix_xd.trace() << std::endl;

    return 0;
}

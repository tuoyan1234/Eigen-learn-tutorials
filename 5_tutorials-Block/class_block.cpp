/*
Block of size (p,q), starting at (i,j)	matrix.block(i,j,p,q);	matrix.block<p,q>(i,j);
*/
#include <iostream>
#include <Eigen/Dense>

int main(){
    Eigen::Matrix4d matrix_4;
    matrix_4 << 1, 2, 3, 4,
                5, 6, 7, 8,
                9, 10, 11, 12,
                13, 14, 15, 16; // 初始化Matrix的元素
    std::cout << "matrix_4 = " << std::endl << matrix_4 << std::endl; // 输出Matrix
    std::cout << "----------------------------" << std::endl; //
    std::cout << "block in the middle" << std::endl; // 输出Matrix
    std::cout << matrix_4.block<2,2>(1,1) << std::endl; // 输出Matrix
    for(int index = 1; index <= 4; index++){
        std::cout << "Block of size" << index << "x" << index << std::endl;
        std::cout << matrix_4.block(0,0,index,index) << std::endl;
    }
    // matrix的行和列
    Eigen::MatrixXd matrix_5(3, 4); // 定义一个3行4列的Matrix
    matrix_5 << 1, 2, 3, 4,
                5, 6, 7, 8,
                9, 10, 11, 12; // 初始化Matrix的元素
    std::cout << "matrix_5 = " << std::endl << matrix_5 << std::endl; // 输出Matrix
    std::cout << "----------------------------" << std::endl; //
    std::cout << "matrix_5.rows() = " << matrix_5.rows() << std::endl; // 输出Matrix的行数
    std::cout << "matrix_5.cols() = " << matrix_5.cols() << std::endl; // 输出Matrix的列数
    std::cout << "第一行,从0索引:" << matrix_5.row(0) << std::endl; // 输出Matrix的第一行
    std::cout << "第二列：" << matrix_5.col(1) << std::endl; // 输出Matrix的第二列
    matrix_5.row(0) = matrix_5.row(0) * 2; // 将Matrix的第一行元素乘以2
    std::cout << "matrix_5 = " << std::endl << matrix_5 << std::endl; // 输出Matrix
    Eigen::MatrixXd matrix_m(2,2); // 定义一个4行4列的Matrix
    matrix_m << 1, 2,
                3, 4; // 初始化Matrix的元素
    matrix_5.block<2,2>(0,1) = matrix_m;
    std::cout << "matrix_5 = " << std::endl << matrix_5 << std::endl; // 输出Matrix

    return 0;
}
/*
Eigen::Array<type, rows, cols>
Array<float, Dynamic,1> ArrayXf; // 定义一个动态大小的float类型列向量
Array<float, Dynamic, Dynamic> ArrayXXf; // 定义一个动态大小的float类型矩阵,相当于二维数组
*/
#include <iostream>
#include <Eigen/Dense>

int main(){
    // 访问Array中的元素
    Eigen::ArrayXXf array_1(2, 3); // 定义一个2行3列的Array
    array_1 << 1, 2, 3,
             4, 5, 6; // 初始化Array的元素
    std::cout << "array_1(0, 0) = " << array_1(0, 0) << std::endl; // 访问Array中的元素
    std::cout << "----------------------------" << std::endl; // 访问Array中的元素
    Eigen::ArrayXf array_2(5); // 定义一个动态大小的float类型列向量
    array_2 << 1, 2, 3, 4, 5; // 初始化Array的元素
    std::cout << "array_2(0) = " << array_2(0) << std::endl; // 访问Array中的元素   
    // Array中的加减法是对应元素相加减法、乘除法是对应元素相乘除法
    Eigen::ArrayXf array_3(5); // 定义一个动态大小的float类型列向量
    array_3 << 1, 2, 3, 4, 5; // 初始化Array的元素
    Eigen::ArrayXf array_4(5); // 定义一个动态大小的float类型列向量
    array_4 << 5, 4, 3, 2, 1; // 初始化Array的元素
    std::cout << "array_3 + array_4 = " << array_3 + array_4 << std::endl; // 对应元素相加
    std::cout << "array_3 - array_4 = " << array_3 - array_4 << std::endl; // 对应元素相减
    std::cout << "array_3 * array_4 = " << array_3 * array_4 << std::endl; // 对应元素相乘
    std::cout << "array_3 / array_4 = " << array_3 / array_4 << std::endl; // 对应元素相除
    // Array中定义的约数法则
    /*
        1.abs
        2.sqrt
        3.min(.) 对于具有相同大小的矩阵，选取对应位置的较小的元素生成新的Array
    */
    Eigen::ArrayXf array_5(5); // 定义一个动态大小的float类型列向量
    array_5 << 1, 2, 3, 4, 5; // 初始化Array的元素
    std::cout << "abs(array_5) = " << array_5.abs() << std::endl; // 取绝对值
    std::cout << "sqrt(array_5) = " << array_5.sqrt() << std::endl; // 开平方
    std::cout << "min(array_5) = " << array_5.min(array_5.sqrt()) << std::endl; // 取最小值
    // Array和Matrix之间的转换
    Eigen::ArrayXXf array_6(2, 3); // 定义一个2行3列的Array
    array_6 << 1, 2, 3,
             4, 5, 6; // 初始化Array的元素
    Eigen::MatrixXf matrix_1 = array_6.matrix(); // 将Array转换为Matrix
    std::cout << "matrix_1 = " << matrix_1 << std::endl; // 输出Matrix  
    array_6 = matrix_1.array(); // 将Matrix转换为Array
    std::cout << "array_6 = " << array_6 << std::endl; // 输出Array


    return 0;
}
/*
 * @Author: tyz 1872516355@qq.com
 * @Date: 2026-04-22 21:42:20
 * @LastEditors: tyz 1872516355@qq.com
 * @LastEditTime: 2026-04-22 22:23:16
 * @FilePath: /Eigen/6_tutorials_spaceTrans/sapce_transfor.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <Eigen/Dense>
using namespace std;
//this test show how to use eigen to compute coordinate transform
int main(int argc, char *argv[])
{
	// Eigen::Quaterniond q1 = Eigen::Quaterniond(1.0, 0.0, 0.0, 0.0).normalized();
	Eigen::Quaterniond q1 = Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitZ()) * 
							Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitY()) * 
							Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitX());
    std::cout << "q1.eular: " << q1.matrix().eulerAngles(0,1,2).transpose() << std::endl; 
    // Eigen::Quaterniond q2 = Eigen::Quaterniond(0.92388, 0.0, 0.0, 0.382683).normalized();
	Eigen::Quaterniond q2 = Eigen::AngleAxisd(3.141593, Eigen::Vector3d::UnitZ()) * 
							Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitY()) * 
							Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitX());
    std::cout << "q2.eular: " << q2.matrix().eulerAngles(0,1,2).transpose() << std::endl; 

    Eigen::Quaterniond q3 = Eigen::AngleAxisd(3.141593/4.0, Eigen::Vector3d::UnitZ()) * 
							Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitY()) * 
							Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitX());
    std::cout << "q3.eular: " << q3.matrix().eulerAngles(0,1,2).transpose() << std::endl;
    Eigen::Quaterniond qe = q1 * q2 * q3;
    std::cout << "qe.eular: " << qe.matrix().eulerAngles(0,1,2).transpose() << std::endl;
    Eigen::Vector3d eulerAngle_e = qe.matrix().eulerAngles(0,1,2);
    cout <<"qe: \n"<< qe.coeffs() << "\n";
    cout <<"eulerAngle_e: \n"<< eulerAngle_e.transpose() << "\n";
    //平移向量
    Eigen::Vector3d t1 = Eigen::Vector3d(1, 1, 0.0);
    Eigen::Vector3d t2 = Eigen::Vector3d(2, 2, 0.0);
    Eigen::Vector3d t3 = Eigen::Vector3d(2, 2, 0.0);
    Eigen::Vector3d p0 = Eigen::Vector3d(1, 0.0, 0.0);
    Eigen::Vector3d pe;
    pe = q1 * (q2 * (q3 * p0 + t3) + t2) + t1;
    cout <<"pe: \n"<< pe.transpose() << "\n";
    //目标向量
    Eigen::Vector3d p1 = Eigen::Vector3d(2, 2, 0.0);
    Eigen::Vector3d p2;
	Eigen::Vector3d pw;
    //打印输出
    cout <<"q1: \n"<< q1.coeffs() << "\n"
         <<"q2: \n"<< q2.coeffs() << "\n"
         <<"t1: \n"<< t1.transpose() << "\n"
         <<"t2: \n"<< t2.transpose() << endl;
	pw = q1 * p1 + t1;
	cout <<"pw: \n"<< pw.transpose() << endl;
	//pw = q2 * p2 + t2; => q2 * p2 + t2 = q1 * p1 + t1  =>  p2 = q2^-1*(q1 * p1 + t1 - t2)
	//四元数求解
	p2 = q2.inverse() * (q1 * p1 + t1 - t2);
	cout << "四元数求解" << endl;
    cout <<"p2: \n"<< p2.transpose() << endl;
	//欧拉矩阵
    Eigen::Isometry3d T1 = Eigen::Isometry3d::Identity();
    Eigen::Isometry3d T2 = Eigen::Isometry3d::Identity();
    T1.rotate(q1.toRotationMatrix());
    T1.pretranslate(t1);
    T2.rotate(q2.toRotationMatrix());
    T2.pretranslate(t2);
    // cout << T1.matrix() << endl;
    // cout << T2.matrix() << endl;
    //欧拉矩阵求解
    p2 = T2.inverse() * T1 * p1;
    cout << "欧拉矩阵求解" << endl;
	cout <<"p2: \n"<< p2.transpose() << endl;

    // 验证测试
    cout << "验证测试" << endl;
    Eigen::Quaterniond qx = Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitZ()) * 
							Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitY()) * 
							Eigen::AngleAxisd(58.0/180.0*M_PI, Eigen::Vector3d::UnitX());
    std::cout << "qx.eular: " << qx.matrix().eulerAngles(0,1,2).transpose() << std::endl; 
    // Eigen::Quaterniond q2 = Eigen::Quaterniond(0.92388, 0.0, 0.0, 0.382683).normalized();
	Eigen::Quaterniond qy = Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitZ()) * 
							Eigen::AngleAxisd(78.0/180.0*M_PI, Eigen::Vector3d::UnitY()) * 
							Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitX());
    std::cout << "qy.eular: " << qy.matrix().eulerAngles(0,1,2).transpose() << std::endl; 
    Eigen::Quaterniond qz = Eigen::AngleAxisd(120.0/180.0*M_PI, Eigen::Vector3d::UnitZ()) * 
							Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitY()) * 
							Eigen::AngleAxisd(0.0, Eigen::Vector3d::UnitX());
    std::cout << "qz.eular: " << qz.matrix().eulerAngles(0,1,2).transpose() << std::endl;
    // 平移向量
    Eigen::Vector3d t_;
    t_ << 1.0, 2.0, 3.0;
    Eigen::Quaterniond q_res = qz * qy * qx;
    Eigen::Matrix4d T_res = Eigen::Matrix4d::Identity();
    T_res.block<3,3>(0,0) = q_res.matrix();
    T_res.block<3,1>(0,3) = t_;
    std::cout << "T_res: " << std::endl << T_res << std::endl;




	return 0;
}

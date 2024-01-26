//
// Created by ziyu on 24-1-25.
//

#ifndef MULTITHREADINGCVFRAMEWORK_FRAMEWORK_H
#define MULTITHREADINGCVFRAMEWORK_FRAMEWORK_H

#include <chrono>
#include <memory>
#include <opencv2/opencv.hpp>

/**
 * 注意
 * 使用框架需继承该类并重写以下三个函数
 * 继承派生类下列三个重写函数其所调用的函数不允许写入该派生类变量，只允许读取 ！！！
 */

class Framework {
public:
    Framework() = default;

    /**
     * 重写该函数进行图像采集
     * @param img 输出的图像，采集的结果
     * @return
     */
    virtual bool input(cv::Mat & img) = 0;

    /**
     * 重写该函数进行图像的处理和其他算法
     * @param img 输入的图像，框架自动传参
     * @param output 输出，指针需要使用 static_pointer_cast 转化为自定义类型
     * @return
     */
    virtual bool operation(cv::Mat & img, std::shared_ptr<void> & output) = 0;

    /**
     * 重写该函数对输出进行处理
     * @param output 输出，是上面函数的结果
     * @param time 运行时间，用于计算帧率
     * @return
     */
    virtual bool output(std::shared_ptr<void> & output, double time) = 0;
};


#endif //MULTITHREADINGCVFRAMEWORK_FRAMEWORK_H

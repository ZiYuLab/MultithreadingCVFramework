//
// Created by ziyu on 24-1-25.
//

#include "TestClass.h"
#include <stdio.h>
#include <opencv2/opencv.hpp>

TestClass::TestClass(const cv::VideoCapture& cap)
    :_cap(cap)
{

}


bool TestClass::input(cv::Mat &img)
{
    _cap >> img;
    return true;
}

bool TestClass::operation(cv::Mat &img, std::shared_ptr<void> & output)
{
    std::shared_ptr<cv::Mat> result(new cv::Mat());
    //usleep(1000000);
    // 在此进行图像操作
    *result = img;
    output = std::static_pointer_cast<void>(result); // 指针类型的转化，转化为存放你输出结果的类型
    return true;
}

bool TestClass::output(std::shared_ptr<void> & output, double time)
{
    auto result = std::static_pointer_cast<cv::Mat>(output);

    // 读取并显示帧率
    const std::string str = "FPS: " + std::to_string((int)round(1000.0 / time));
    cv::putText(*result, str, cv::Point(20, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0 ,255, 0), 1);

    cv::imshow("test", *result);
    if (cv::waitKey(1) == 27)
    {
        return false; // 三个函数任何一个return false 所有线程均会停止
    }

    return true;
}


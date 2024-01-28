//
// Created by ziyu on 24-1-25.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include "MulThrCV.h"
#include "TestClass.h"

int main()
{
    using namespace cv;
    // 初始化
    auto cap = VideoCapture(0);
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
    cap.set(cv::CAP_PROP_BRIGHTNESS, 20);
    cap.set(cv::CAP_PROP_FPS, 30);
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 960);

    if (cap.isOpened())
    {
        TestClass testClass(cap);
        MulThrCV mulThrCv(testClass, 10, 10, 5);
        mulThrCv.generateInputThread();
        mulThrCv.generateOperationThread();
        mulThrCv.generateOutputThread();

        // 卡住主线程，主线程也可进行其他操作
        while (!mulThrCv.threadIsStop());
    }

    return 0;
}
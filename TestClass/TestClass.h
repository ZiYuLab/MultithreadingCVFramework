//
// Created by ziyu on 24-1-25.
//

#ifndef MULTITHREADINGCVFRAMEWORK_TESTCLASS_H
#define MULTITHREADINGCVFRAMEWORK_TESTCLASS_H

#include "Framework.h"

class TestClass : public Framework{
private:
    cv::VideoCapture _cap;

public:
    TestClass() = default;
    TestClass(const cv::VideoCapture& cap);

    // 三个函数参数含义见父类
    bool input(cv::Mat & img) override;
    bool operation(cv::Mat & img, std::shared_ptr<void> & output) override;
    bool output(std::shared_ptr<void> & output, double time) override;
};


#endif //MULTITHREADINGCVFRAMEWORK_TESTCLASS_H

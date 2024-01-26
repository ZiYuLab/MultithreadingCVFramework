# 多线程图像处理框架，OpenCV

### 利用多线程显著提升图像采集和图像处理的速度

***

## 要求
* C++ 11 及以上
* OpenCV 4 (4以下不清楚是否可以)

***

## 目录
```
.
├── CMakeLists.txt
├── Framework
│   ├── Framework.h #模板基类
│   ├── MulThrCV.cpp #多线程图像处理类
│   └── MulThrCV.h
├── main.cpp #示例主函数
├── README.md
└── TestClass #测试例
    ├── TestClass.cpp
    └── TestClass.h

```

***

## 使用
* 配置相关环境，修改CMakeLists.txt
* 按照TestClass的测试例重写相关函数
* 按照main.cpp示例编写主函数

#include "impls.h"


std::vector<std::vector<cv::Point>> find_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用cv::findContours函数，从输入图像（3个通道）中找出所有的最内层轮廓。
     * 将它们保存起来作为函数返回值就行。contours的中文意思就是轮廓。
     * 
     * 提示：
     * 1. 使用cv::imshow来查看输入图像。
     * 2. 使用cv::drawContours来在一张图上绘制轮廓。
     * 3. 直接使用原图一般而言不利于轮廓的寻找，可以做一些简单的处理。
     * 4. findContours函数可以返回轮廓的层次结构，理解层次结构的保存方式并使用它（重点）。
     * 
     * 通过条件：
     * 运行测试点，你找到的轮廓与答案的轮廓一样就行。
     */
    
    std::vector<std::vector<cv::Point>> res;
    // IMPLEMENT YOUR CODE HERE
     std::vector<cv::Vec4i> hierarchy;
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::Mat binary;
    cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY_INV);
    cv::findContours(binary, res, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    cv::Mat drawing = input.clone();
    for (size_t i = 0; i < res.size(); i++) {
        cv::drawContours(drawing, res, (int)i, cv::Scalar(0, 255, 0), 2, cv::LINE_8, hierarchy, (int)hierarchy[i][0]);
    }
    cv::imshow("Input Image", input);
    cv::imshow("Contours", drawing);
    cv::waitKey(0);
    std::vector<std::vector<cv::Point>> innerContours;
    for (size_t i = 0; i < hierarchy.size(); i++) {
        if (hierarchy[i][3] == -1) {
            innerContours.push_back(res[i]);
        }
    }
    return innerContours;
    
}
#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
   std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::Mat gray;
    cv::Mat binary;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY_INV);
    cv::findContours(binary, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    cv::Rect boundingRect;
    cv::RotatedRect minAreaRect;
    for (size_t i = 0; i < contours.size(); i++) {
        cv::Rect rect = cv::boundingRect(contours[i]);
        cv::RotatedRect rotatedRect = cv::minAreaRect(contours[i]);
        if (boundingRect.area() == 0 || rect.area() < boundingRect.area()) {
            boundingRect = rect;
        }
        if (minAreaRect.size.area() == 0 || rotatedRect.size.area() < minAreaRect.size.area()) {
            minAreaRect = rotatedRect;
        }
    }
    return std::make_pair(boundingRect, minAreaRect);
}
   

#include "impls.h"


std::vector<cv::Mat> erode(const cv::Mat& src_erode, const cv::Mat& src_dilate) {
    /**
     * TODO: 先将图像转换为灰度图像, 然后二值化，然后进行腐蚀操作，具体内容：
     *  1. 将彩色图片 src_erode 转换为灰度图像
     *  2. 将灰度图像进行二值化
     *  3. 将二值化后的两张图片 分别进行 腐蚀 和 膨胀操作
     *  此任务需要你不断调整 erode 和 dilate 函数 的参数，以达到目标效果
     * 
     *   PS: 这里的 二值化函数的参数需要看设置为 thresh = 50, maxval = 255, type = THRESH_BINARY
     *   GOAL:
     *     1. 腐蚀结果图片中，女孩头发里的白点被消除了(类似答案中的样子)
     *     2. dilate 之后的图像中，图中的小脚被消除了(类似答案中的样子)
     *     以上两个检查点需要自己检查，满足条件 则输入 p 通过, 否则输入 f 表示不通过
     */
    cv::Mat dst_erode, dst_dilate;

    // TODO: 在这里实现你的代码 
  cv::Mat gray_erode, gray_dilate;
    cv::cvtColor(src_erode, gray_erode, cv::COLOR_BGR2GRAY);
    cv::cvtColor(src_dilate, gray_dilate, cv::COLOR_BGR2GRAY);
    cv::Mat binary_erode, binary_dilate;
    cv::threshold(gray_erode, binary_erode, 50, 255, cv::THRESH_BINARY);
    cv::threshold(gray_dilate, binary_dilate, 50, 255, cv::THRESH_BINARY);
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(4, 4));
    cv::erode(binary_erode, dst_erode, kernel, cv::Point(-1,-1), 2);
    cv::dilate(binary_dilate, dst_dilate, kernel, cv::Point(-1,-1), 2);
    return {dst_erode, dst_dilate};
}

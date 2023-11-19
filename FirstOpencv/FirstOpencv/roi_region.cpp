#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char** argv)
{
    // �̹��� ������ �о�ɴϴ�.
    cv::Mat image = cv::imread("puppy.bmp");
    if (image.empty())
    {
        std::cout << "�̹��� ������ �о���� �� ������ �߻��߽��ϴ�." << std::endl;
        return 1;
    }

    // �ΰ� �̹��� ������ �о�ɴϴ�.
    cv::Mat logo = cv::imread("smalllogo.png");
    if (logo.empty())
    {
        std::cout << "�ΰ� �̹��� ������ �о���� �� ������ �߻��߽��ϴ�." << std::endl;
        return 1;
    }

    // �̹����� ������ �ϴܿ� �ΰ� �����ϱ� ���� ROI(Region of Interest)�� �����մϴ�.
    cv::Mat imageROI(image, cv::Rect(image.cols - logo.cols, image.rows - logo.rows, logo.cols, logo.rows));

    // �ΰ� �̹����� �����մϴ�.
    logo.copyTo(imageROI);

    // �̹����� ǥ���� â�� �����մϴ�.
    cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);

    // �̹����� ȭ�鿡 ǥ���մϴ�.
    cv::imshow("Image", image);

    // ����ڰ� Ű �Է��� ��ٸ��ϴ�.
    cv::waitKey(0);

    // ���� �̹����� �ٽ� �о�ɴϴ�.
    image = cv::imread("puppy.bmp");
    if (image.empty())
    {
        std::cout << "�̹��� ������ �ٽ� �о���� �� ������ �߻��߽��ϴ�." << std::endl;
        return 1;
    }

    // �ΰ� ������ ROI�� �������մϴ�.
    imageROI = image(cv::Range(image.rows - logo.rows, image.rows),
        cv::Range(image.cols - logo.cols, image.cols));

    // �ΰ��� ����ũ �̹����� ����ϴ�.
    cv::Mat mask(logo);

    // �ΰ� �̹����� �����մϴ�. �ΰ� �̹��� ���� �ȼ� ���� ����˴ϴ�.
    logo.copyTo(imageROI, mask);

    // �̹����� ȭ�鿡 �ٽ� ǥ���մϴ�.
    cv::imshow("Image", image);

    // ����ڰ� Ű �Է��� ��ٸ��ϴ�.
    cv::waitKey(0);

    // ��� â�� �ݽ��ϴ�.
    cv::destroyAllWindows();

    return 0;
}

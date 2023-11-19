#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

// �Լ��� ȣ���Ͽ� ���ο� �̹����� �����ϴ� �Լ�
cv::Mat function_img()
{
    // 500x500 ũ���� 8��Ʈ ���� ä�� ����� �����ϰ�, �ȼ� ���� 50���� ����
    cv::Mat img(500, 500, CV_8U, 50);

    return img;
}

int main(int argc, char** argv)
{
    // Step 1: �̹��� ������ ǥ��
    cv::Mat image1(240, 320, CV_8U, 100);
    cv::imshow("Image", image1);
    cv::waitKey(0);

    // Step 2: �̹��� ũ�� ���� �� �� ����
    image1.create(200, 200, CV_8U);
    image1 = 200;
    cv::imshow("Image", image1);
    cv::waitKey(0);

    // Step 3: 3ä�� �÷� �̹��� ������ ǥ��
    cv::Mat image2(240, 320, CV_8UC3, cv::Scalar(0, 0, 255));
    cv::imshow("ColorImage", image2);
    cv::waitKey(0);

    // Step 4: �̹��� ���� �ҷ�����
    cv::Mat image3 = cv::imread("dog.jpg");

    if (image3.empty())
    {
        std::cout << "�̹��� ������ �д� �� ���� �߻�." << std::endl;
        return 1;
    }

    // Step 5: �̹��� ���� �� ��Ī ����
    cv::Mat image4(image3);
    image1 = image3;

    // �̹��� ����
    image3.copyTo(image2);

    // �̹��� Ŭ��
    cv::Mat image5 = image3.clone();

    // �̹��� �¿� ����
    cv::flip(image3, image3, 1);

    // ������ �̹��� ǥ��
    cv::imshow("Image 3", image3);
    cv::imshow("Image 1", image1);
    cv::imshow("Image 2", image2);
    cv::imshow("Image 4", image4);
    cv::imshow("Image 5", image5);

    cv::waitKey(0);

    // Step 6: �Լ��� ȣ���Ͽ� �׷��̽����� �̹��� ����
    cv::Mat gray_img = function_img();
    cv::imshow("GrayImage", gray_img);
    cv::waitKey(0);

    // Step 7: �̹����� �ҷ��ͼ� ������ ���� ��ȯ
    image1 = cv::imread("dog.jpg");
    image1.convertTo(image2, CV_32F, 1 / 255.0, 0.0);
    cv::imshow("ImageGray", image2);
    cv::waitKey(0);

    return 0;
}

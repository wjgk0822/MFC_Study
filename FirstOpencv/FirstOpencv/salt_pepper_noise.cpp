#include <iostream>
#include <random>

#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

// �ұݰ� ���� ����� �߰��ϴ� �Լ� ����
void salt_pepper_noise(cv::Mat image, int num)
{
    // C++�� <random> ����� ����Ͽ� ���� ����
    std::default_random_engine generator;
    // �̹����� ��(row) ��ǥ ������ ����
    std::uniform_int_distribution<int> randomRow(0, image.rows - 1);
    // �̹����� ��(column) ��ǥ ������ ����
    std::uniform_int_distribution<int> randomCol(0, image.cols - 1);

    // �־��� Ƚ����ŭ �ұݰ� ���� ����� �߰�
    for (int k = 0; k < num; ++k)
    {
        // ������ ��(row) �� ��(column) ��ǥ�� ����
        int row_coordinate = randomRow(generator);
        int col_coordinate = randomCol(generator);

        if (image.type() == CV_8UC1)
        {
            // �׷��̽����� �̹����� ������ �߰�
            image.at<uchar>(row_coordinate, col_coordinate) = 255;
        }
        else if (image.type() == CV_8UC3)
        {
            // �÷� �̹����� ������ �߰� (��� ä�ο� ��� �ȼ�)
            image.at<cv::Vec3b>(row_coordinate, col_coordinate)[0] = 255;
            image.at<cv::Vec3b>(row_coordinate, col_coordinate)[1] = 255;
            image.at<cv::Vec3b>(row_coordinate, col_coordinate)[2] = 255;
        }
    }
}

// �ұ� ����� �߰��ϴ� �Լ� ���� (�׷��̽����� �̹������� ����)
void salt_noise(cv::Mat image, int n)
{
    CV_Assert(image.type() == CV_8UC1); // �׷��̽����� �̹������� Ȯ��

    // C++�� <random> ����� ����Ͽ� ���� ����
    std::default_random_engine generator;
    // �̹����� ��(row) ��ǥ ������ ����
    std::uniform_int_distribution<int> randomRow(0, image.rows - 1);
    // �̹����� ��(column) ��ǥ ������ ����
    std::uniform_int_distribution<int> randomCol(0, image.cols - 1);

    // �־��� Ƚ����ŭ �ұ� ����� �߰�
    cv::Mat_<uchar> img(image);
    for (int k = 0; k < n; ++k)
    {
        // ������ ��(column) �� ��(row) ��ǥ�� ����
        int x = randomCol(generator);
        int y = randomRow(generator);

        // �ش� ��ǥ�� ��� �ȼ�(255)�� �����Ͽ� �ұ� ������ �߰�
        img(y, x) = 255;
    }
}

int main(int argc, char** argv)
{
    // �̹��� ������ �о�ɴϴ�.
    cv::Mat image = cv::imread("boldt.jpg", 1); // 1�� �÷� �̹����� �б⸦ ����

    // �ұݰ� ���� ����� �̹����� �߰�
    salt_pepper_noise(image, 3000);

    // �����츦 �����ϰ� �̹����� ȭ�鿡 ǥ���մϴ�.
    cv::namedWindow("SaltImage");
    cv::imshow("SaltImage", image);

    // �̹����� ���Ϸ� �����մϴ�.
    cv::imwrite("salted.bmp", image);

    // ����� �Է��� ��ٸ��ϴ�.
    cv::waitKey(0);

    // �̹����� �ٽ� �׷��̽����Ϸ� �о�ɴϴ�.
    image = cv::imread("boldt.jpg", 0); // 0�� �׷��̽����� �̹����� �б⸦ ����

    // �ұ� ����� �̹����� �߰� (�׷��̽����� �̹����� ����)
    salt_noise(image, 500);

    // �ٽ� �����츦 �����ϰ� �̹����� ȭ�鿡 ǥ���մϴ�.
    cv::namedWindow("SaltImage");
    cv::imshow("SaltImage", image);

    // ����� �Է��� ��ٸ��ϴ�.
    cv::waitKey();

    // ��� â�� �ݽ��ϴ�.
    cv::destroyAllWindows();

    return 0;
}



//salt_pepper_noise �Լ��� �־��� �̹����� ��� �ȼ�(255)�� �������� �߰��Ͽ� �ұݰ� ���� ����� �����ϰ�, 
//salt_noise �Լ��� �׷��̽����� �̹����� �ұ� ����� �߰��մϴ�. 
//����, �̹����� ȭ�鿡 ǥ���ϰ� ���Ϸ� �����ϴ� ���� �۾��� �����մϴ�.
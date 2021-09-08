/*
������ �������

� ������ ����� ����������� ������� 13� ������ ����������� � ���. ������ ������� ����� �������, �� ��������� ����� ������ �� �� �����. �� ����� �������� �� � ������� �����-�� ������� ������� �����, � ��������� �� ������ � ��������, � ��������� �������� ��������� ���������. ������� �������� ����� ������� �������� ����� ����������� ������� ����� � ����, ��� �� ���� ������ �������. ������� ����� ��������, ������� ����� ������, ���� �� � ��� ���� ��������� � ����� �������������. ��� ����� ������ �������� ����� ��������, ��� ����� ����� ����� ����� ������ � ��� � ��������, �� ���� ����� ����� ����������� �������� �������, ����������� ��� ������.
������ ������� ������
������ ������ �������� ���� ����� ����� n (1 <= n <= 105) � ���������� �������� 13�, ��������� �� ����.
������ ������ �������� n ����� ����� a1, a2, ..., an (1 <= ai <= 109) � ���� ���������� � ��� �������, � ������� ��� ������ ����������.
������ �������� ������
�������� n ����� ����� ����� ������, ��� i-� ����� � ������������ ����� �������� �������, ����������� ��������� ����� i.

�������
����������� ���� ����������� �����
5
7 4 2 2 10

3 3 3 1 1


5
2 4 6 4 2

1 1 3 3 3

*/

#include <iostream>

int main()
{
    // ��������� ������������� ��� ��������
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;

    int* counters = new int[n], curSeqLen = 1, curSeqStart=0, previousHeight;

    std::cin >> previousHeight;

    for (int i = 0; i < n; i++)
        counters[i] = 0;


    for (int i = 1,height; i < n; i++) {
        std::cin >> height;

        if (height < previousHeight) {
            curSeqLen++;
        }
        else {
            while(curSeqStart<i)
                counters[curSeqStart++] = curSeqLen;

            curSeqLen = 1;
            curSeqStart = i;
        }

        previousHeight = height;

    }

    while (curSeqStart < n)
        counters[curSeqStart++] = curSeqLen;

    for (int i = 0; i < n; i++) {
        std::cout << counters[i] << ' ';
    }

}
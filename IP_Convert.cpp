#include <iostream>
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <sstream>
#include <bitset> // Thư viện để xuất nhị phân
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    // Khởi tạo Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "Winsock initialization failed." << endl;
        return 1;
    }

    // Thay mã số sinh viên vào đây
    int maSV = 106210216;  
    int x = (maSV % 255) + 1;

    // Tạo địa chỉ IP dạng chuỗi
    ostringstream ipStream;
    ipStream << "127.0.0." << x;
    string ipStr = ipStream.str();

    // Sử dụng inet_pton để chuyển đổi IP
    struct in_addr inAddr;
    if (inet_pton(AF_INET, ipStr.c_str(), &inAddr) != 1) {
        cout << "inet_pton failed." << endl;
        WSACleanup();
        return 1;
    }

    // Xuất địa chỉ IP dưới dạng nhị phân
    cout << "inet_pton: " << ipStr << " -> "
        << bitset<32>(ntohl(inAddr.s_addr)) << " (binary)" << endl;

    // Dọn dẹp Winsock
    WSACleanup();

    return 0;
}

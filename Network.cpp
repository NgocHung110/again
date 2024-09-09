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
}

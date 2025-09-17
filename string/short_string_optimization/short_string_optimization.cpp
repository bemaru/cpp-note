#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <utility>

class ShortString {
public:
    // SSO �ִ� ���� ����
    static const size_t SSO_MAX_LENGTH = 15;

    ShortString() : is_small(true), length(0) {
        data.small[0] = '\0'; // �� ���ڿ� �ʱ�ȭ
    }

    ShortString(const char* str) {
        size_t len = std::strlen(str);
        if (len < SSO_MAX_LENGTH) {
            is_small = true;
            length = len;
            std::strcpy(data.small, str); // ���ÿ� ����
        } else {
            is_small = false;
            length = len;
            data.large = new char[len + 1]; // ���� ����
            std::strcpy(data.large, str);
        }
    }

    ShortString(const ShortString& other) {
        length = other.length;
        is_small = other.is_small;
        if (is_small) {
            std::strcpy(data.small, other.data.small);
        } else {
            data.large = new char[length + 1];
            std::strcpy(data.large, other.data.large);
        }
    }

    ShortString& operator=(const ShortString& other) {
        if (this != &other) {
            if (!is_small && data.large) {
                delete[] data.large; // ���� �� �޸� ����
            }
            length = other.length;
            is_small = other.is_small;
            if (is_small) {
                std::strcpy(data.small, other.data.small);
            } else {
                data.large = new char[length + 1];
                std::strcpy(data.large, other.data.large);
            }
        }
        return *this;
    }

    ~ShortString() {
        if (!is_small) {
            delete[] data.large; // �� �޸� ����
        }
    }

    const char* c_str() const {
        return is_small ? data.small : data.large;
    }

    size_t size() const {
        return length;
    }

private:
    union Data {
        char small[SSO_MAX_LENGTH + 1]; // SSO�� ���� ���� ����
        char* large; // ���� ���� ������
        Data() : large(nullptr) {} // �ʱ�ȭ
    } data;

    bool is_small; // SSO ��� ����
    size_t length; // ���ڿ� ����
};

int main() {
    ShortString shortStr("Hello, World!"); // SSO ���
    ShortString longStr("This is a very long string that exceeds the limit."); // �� �޸� ���

    std::cout << "Short String: " << shortStr.c_str() << " (size: " << shortStr.size() << ")\n";
    std::cout << "Long String: " << longStr.c_str() << " (size: " << longStr.size() << ")\n";

    return 0;
}

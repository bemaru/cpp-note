#include <string>
#include <vector>

class StringConstants {
public:
	// 1. static const�� ����� ����
	// �� ����� ��� �ν��Ͻ����� �����˴ϴ�.
	static const std::string greeting_message;

	// 2. constexpr�� ����� ����
	// ������ Ÿ�ӿ� �򰡵Ǵ� ����Դϴ�.
	static constexpr const char* goodbye_message = "Goodbye, World!";

	// 3. inline�� ����� ���� �� ����
	// ����� ���Ǹ� ���ÿ� �ϸ�, �ߺ� ���Ǹ� �����մϴ�.
	static inline const std::string error_message = "An error has occurred.";
	static inline const std::vector<std::string> fruit_list = { "apple", "banna", "cherry" };

	// 4. consteval�� ����� �޼���
	// ������ Ÿ�ӿ� �򰡵Ǵ� �޼����Դϴ�.
	static consteval const char* get_dynamic_greeting() {
		return "Hello, from a dynamic context!";
	}
};

// 1. static const�� ���� ����
const std::string StringConstants::greeting_message = "Hello, World!";

// ��� ����
#include <iostream>

int main() {
	std::cout << StringConstants::greeting_message << std::endl; // "Hello, World!"
	std::cout << StringConstants::goodbye_message << std::endl; // "Goodbye, World!"
	std::cout << StringConstants::error_message << std::endl; // "An error has occurred."
	std::cout << StringConstants::get_dynamic_greeting() << std::endl; // "Hello, from a dynamic context!"

	return 0;
}

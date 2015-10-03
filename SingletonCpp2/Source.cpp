#include <iostream>
#include <memory>


using namespace std;

int main(char args[])
{
	std::weak_ptr<int> w_ptr;
	std::cout << "w_ptr.use_count() out of scope: " << w_ptr.expired() << '\n';
	{
		auto ptr = std::make_shared<int>();
		w_ptr = ptr;
		std::cout << "w_ptr.use_count() inside scope: " << w_ptr.expired() << '\n';
	}

	std::cout << "w_ptr.use_count() out of scope: " << w_ptr.expired() << '\n';
}
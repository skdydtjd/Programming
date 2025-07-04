#include <iostream>
#include <array>
#include <type_traits>

using namespace std;

template<typename ... Args>

auto build_array(Args&&... args) -> array<typename common_type<Args...>::type, sizeof...(args) >
{
	using commonType = typename common_type<Args...>::type;

	return {forward<commonType>((Args&&)args)...};
}

void main()
{
	auto data = build_array(1, 0u, 'a', 3.2f, false);
	// auto data2 = build_array(1, "Packt", 2.0);


	for (auto i : data)
	{
		cout << i << " ";

		cout << endl;
	}
}
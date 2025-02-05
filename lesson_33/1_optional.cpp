#include <optional>
#include <iostream>

// https://en.cppreference.com/w/cpp/utility/optional

bool get_name_by_uid(int uid, std::string& name)
{
	if (uid == 0)
	{
		name = "root";
		return true;
	}
	return false;
}

std::optional<std::string> get_name_by_uid(int uid)
{
	if (uid == 0)
	{
		return "root";
	}
	return std::nullopt;
}

int main()
{
	{
		std::string name;
		if (get_name_by_uid(0, name))
		{
			std::cerr << "name: " << name << '\n';
		}
		else
		{
			std::cerr << "No name\n";
		}


		if (get_name_by_uid(1, name))
		{
			std::cerr << "name: " << name << '\n';
		}
		else
		{
			std::cerr << "No name\n";
		}
	}

	{
		const auto name = get_name_by_uid(0);
		if (name.has_value()) {
			std::cerr << "name: " << name.value() << '\n';
		}
		else {
			std::cerr << "No name\n";
		}

		if (name) {
			std::cerr << "name: " << *name << '\n';
		}
		else {
			std::cerr << "No name\n";
		}
	}

	{
		const auto name = get_name_by_uid(1);
		try
		{
			const auto real_name = name.value_or("No name");
			std::cerr << "name: " << real_name << '\n';

			const auto error_name = name.value();
		}
		catch (std::bad_optional_access &ex)
		{
			std::cerr << "std::bad_optional_access exception! what: " << ex.what() << '\n';
		}
	}
}

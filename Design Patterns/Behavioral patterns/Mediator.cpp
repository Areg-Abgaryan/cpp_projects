#include <iostream>
#include <vector>
#include <memory>

template <class T>
class Container_Node
{
private:
	T value{};

public:
	Container_Node(const T temp) : value{ temp } {}

	T get_value() const { return value; }

	~Container_Node() = default;
};

template <class T>
class Container
{
private:
	std::vector<std::unique_ptr<Container_Node<T>>> obj;

	void check_size()
	{
		if (obj.size() % 100 == 0)
		{
			obj.resize(obj.size() + 100);
		}
	}

public:
	Container() { obj.reserve(100); }

	void push_back_node(std::unique_ptr<Container_Node<T>> n)
	{
		obj.emplace_back(std::move(n));
		check_size();
	}

	void erase_node(const T value)
	{
		for (auto it = obj.begin(); it != obj.end(); ++it)
		{
			if ((*it)->get_value() == value)
			{
				obj.erase(it);
				break;
			}
		}
	}

	void print()
	{
		for (int i = 0; i < obj.size(); ++i)
		{
			std::cout << obj[i]->get_value() << "  ";
		}
		std::cout << '\n';
	}

	~Container() = default;
};

int main()
{
	Container<double> list{};

	std::unique_ptr<Container_Node<double>> n1 = std::make_unique<Container_Node<double>>(5.5);
	std::unique_ptr<Container_Node<double>> n2 = std::make_unique<Container_Node<double>>(1.1);
	std::unique_ptr<Container_Node<double>> n3 = std::make_unique<Container_Node<double>>(9.9);

	list.push_back_node(std::move(n1));
	list.push_back_node(std::move(n2));
	list.push_back_node(std::move(n3));

	list.print();
}

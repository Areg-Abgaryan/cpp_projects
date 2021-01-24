#include <iostream>
#include <vector>
#include <memory>

class File
{
private:
	double file_sz_in_mb{};
	std::string file_name{};
	std::string file_extension{};

public:
	File(const double fsz, const std::string& fn, const std::string& fe)
		: file_sz_in_mb{ fsz }, file_name{ fn }, file_extension{ fe }  {}

	virtual double get_file_size() const { return file_sz_in_mb; }
	virtual std::string get_file_name() { return file_name; }

	virtual void traverse() const = 0;
	virtual bool is_composite() const = 0;

	virtual ~File() = default;
};

class Text : public File
{
public:
	using File::File;
	Text() = delete;

	void traverse() const override { std::cout << "A text file\n"; }

	bool is_composite() const override { return false; }

	~Text() = default;
};

class Image : public File
{
public:
	using File::File;
	Image() = delete;

	void traverse() const override { std::cout << "An image\n"; }

	bool is_composite() const override { return false; }

	~Image() = default;
};

class Application : public File
{
public:
	using File::File;
	Application() = delete;

	void traverse() const override { std::cout << "An application\n"; }

	bool is_composite() const override { return false; }

	~Application() = default;
};

class Folder : public File
{
private:
	std::vector<std::unique_ptr<File>> elements{};

public:
	using File::File;
	Folder() = delete;

	bool is_composite() const override { return true; }

	void add_element(std::unique_ptr<File> ptr)
	{
		elements.emplace_back(std::move(ptr));
	}

	void delete_element(const int index)
	{
		elements.erase(elements.begin() + index);
	}

	void traverse() const override
	{
		std::cout << "A folder\n";
		
		for (const auto& x : elements)
		{
			x->traverse();
		}
	}

	double get_file_size() const override
	{
		double folder_size{ 0 };
		
		for (const auto& x : elements)
		{
			folder_size += x->get_file_size();
		}
		return folder_size;
	}
};

int main()
{
	std::unique_ptr<File> img = std::make_unique<Image>(3.05, "img", ".jpg");
	std::unique_ptr<File> txt = std::make_unique<Text>(0.02, "txt", ".doc");
	std::unique_ptr<File> app = std::make_unique<Application>(25.6, "app", ".exe");

	Folder x(0, "folder", "");
	x.add_element(move(img));
	x.add_element(move(txt));

	std::unique_ptr<File> folder = std::make_unique<Folder>(std::move(x));

	std::vector<std::unique_ptr<File>> filesystem;

	filesystem.emplace_back(std::move(folder));
	filesystem.emplace_back(std::move(app));

	double filesystem_size{ 0 };

	for (size_t i = 0; i < filesystem.size(); ++i)
		filesystem_size += filesystem[i]->get_file_size();

	std::cout << filesystem_size;
}

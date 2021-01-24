#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <memory>

class Observer;

class XiaomiItem
{
public:
	virtual void addObserver(std::unique_ptr<Observer> observer) {}
	virtual void removeObserver(std::unique_ptr<Observer> observer) {}
	virtual void getItemInfo() const {};
	virtual void notifyObservers(const std::string& message) const {};

	virtual ~XiaomiItem() = default;
};

class Observer
{
private:
	std::shared_ptr<XiaomiItem> item{};
	std::string first_name{};
	std::string second_name{};
	std::vector<std::string> item_updates{};

public:
	Observer() = delete;

	~Observer()
	{
		item->removeObserver(std::make_unique<Observer>(*this));
	}

	Observer(const std::string& fn, const std::string& sn, std::shared_ptr<XiaomiItem> it)
		: first_name{ fn }, second_name{ sn }, item{ it }
	{
		item->addObserver(std::make_unique<Observer>(*this));
	}

	void getItemUpdate(const std::string& message)
	{
		item_updates.push_back(message);
	}

	void seeAllUpdates() const
	{
		for (const auto &x : item_updates)
			std::cout << x << "\n";
	}
};

class XiaomiSmartphone : public XiaomiItem
{
};

class XiaomiRedmiNote9Pro : public XiaomiSmartphone
{
private:
	static std::list<std::unique_ptr<Observer>> redmi_note_9_pro_observers_list;

public:
	XiaomiRedmiNote9Pro() = default;
	~XiaomiRedmiNote9Pro() final = default;

	void addObserver(std::unique_ptr<Observer> observer) final
	{
		redmi_note_9_pro_observers_list.emplace_back(std::move(observer));
	}

	void removeObserver(std::unique_ptr<Observer> observer) final
	{
		redmi_note_9_pro_observers_list.remove(observer);
	}

	void getItemInfo() const final
	{
		std::cout << "\nSome Info About Redmi Note 9 Pro\n";
	}

	void notifyObservers(const std::string& message) const final
	{
		for (const auto& x : redmi_note_9_pro_observers_list)
			x->getItemUpdate(message);
	}

	static size_t observerCount()
	{
		return redmi_note_9_pro_observers_list.size();
	}
};

std::list<std::unique_ptr<Observer>> XiaomiRedmiNote9Pro::redmi_note_9_pro_observers_list{};

int main()
{
	std::shared_ptr<XiaomiRedmiNote9Pro> sp = std::make_shared<XiaomiRedmiNote9Pro>();
	std::unique_ptr<Observer> newObserver = std::make_unique<Observer>("Areg", "Abgaryan", sp);

	std::cout << sp->observerCount();
	sp->getItemInfo();
	sp->notifyObservers("New MI UI Version 12.5");
	newObserver->seeAllUpdates();
}

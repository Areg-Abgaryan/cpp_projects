#include <iostream>
#include <memory>

class Golf_Club
{
protected:
	Golf_Club() = default;

public:
	virtual void description() = 0;
	virtual ~Golf_Club() = default;
};

class Golf_Iron : public Golf_Club
{
public:
	Golf_Iron() = default;
	~Golf_Iron() = default;

	void description() override
	{
		std::cout << "a golf iron:\n" << "Less distance, more accuracy.\n";
	}
};

class Golf_Wood : public Golf_Club
{
public:
	Golf_Wood() = default;
	~Golf_Wood() = default;

	void description() override
	{
		std::cout << "a golf wood:\n" << "More distance, less accuracy.\n";
	}
};

class Golf_Ball
{
public:
	virtual void hit_the_ball(const std::unique_ptr<Golf_Club>& gc) = 0;
	virtual ~Golf_Ball() = default;
};

class Ball_On_Tee_Box
{
private:
	void put_tee_box() { "The tee box is put on the grass\n"; }

public:
	Ball_On_Tee_Box() = default;
	~Ball_On_Tee_Box() = default;

	void effectively_hit_the_ball()
	{
		put_tee_box();
	}
};

class Golf_Ball_Adapter : public Golf_Ball
{
private:
	std::unique_ptr<Ball_On_Tee_Box> botb;

public:
	Golf_Ball_Adapter(std::unique_ptr<Ball_On_Tee_Box>& ptr) : botb{ ptr.release() } {}
	~Golf_Ball_Adapter() = default;

	void hit_the_ball(const std::unique_ptr<Golf_Club>& pgc) override
	{
		std::cout << "Hit the ball with ";
		pgc->description();
		botb->effectively_hit_the_ball();
	}
};

int main()
{
	std::unique_ptr<Ball_On_Tee_Box> botb = std::make_unique<Ball_On_Tee_Box>();
	std::unique_ptr<Golf_Ball> gb = std::make_unique<Golf_Ball_Adapter>(botb);
	std::unique_ptr<Golf_Club> gc = std::make_unique<Golf_Wood>();
	gb->hit_the_ball(gc);
}

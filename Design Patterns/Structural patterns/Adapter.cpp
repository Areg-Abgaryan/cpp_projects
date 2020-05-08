#include <iostream>
#include <memory>

using namespace std;

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
	void description() override
	{
		cout << "a golf iron:\n" << "Less distance, more accuracy.\n";
	}
	~Golf_Iron() = default;
};

class Golf_Wood : public Golf_Club
{
public:
	Golf_Wood() = default;
	void description() override
	{
		cout << "a golf wood:\n" << "More distance, less accuracy.\n";
	}
	~Golf_Wood() = default;
};

class Golf_Ball
{
public:
	virtual void hit_the_ball(const unique_ptr<Golf_Club>& gc) = 0;
	virtual ~Golf_Ball() = default;
};

class Ball_On_Tee_Box
{
private:
	void put_tee_box() { "The tee box is put on the grass\n"; }
public:
	Ball_On_Tee_Box() = default;
	void effectively_hit_the_ball()
	{
		put_tee_box();
	}
	~Ball_On_Tee_Box() = default;
};

class Golf_Ball_Adapter : public Golf_Ball
{
private:
	unique_ptr<Ball_On_Tee_Box> botb;
public:
	Golf_Ball_Adapter(unique_ptr<Ball_On_Tee_Box>& ptr) : botb{ ptr.release() } {}
	void hit_the_ball(const unique_ptr<Golf_Club>& pgc) override
	{
		cout << "Hit the ball with ";
		pgc->description();
		botb->effectively_hit_the_ball();
	}
	~Golf_Ball_Adapter() = default;
};

int main()
{
	unique_ptr<Ball_On_Tee_Box> botb = make_unique<Ball_On_Tee_Box>();
	unique_ptr<Golf_Ball> gb = make_unique<Golf_Ball_Adapter>(botb);
	unique_ptr<Golf_Club> gc = make_unique<Golf_Wood>();
	gb->hit_the_ball(gc);
}
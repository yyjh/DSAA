#include <string>
#include <memory>
#include <iostream>

struct S
{
	int i;
	std::string s;
	double d;

	S(int ii, std::string ss, double dd) :
		i(ii)
		, s(ss)
		, d(dd)
	{}

	~S()
	{

	}
};


class Girl;
class Boy;

class Girl
{
public:
	explicit Girl() : boy_friend(nullptr) {};
	auto set(std::shared_ptr<Boy> &boy)
	{
		boy_friend = boy;
	}
	~Girl()
	{
		std::cout << "girl destruct" << std::endl;
	}

	std::shared_ptr<Boy> boy_friend;
};

class Boy
{
public:
	explicit Boy() : girl_friend(std::shared_ptr<Girl>(nullptr)) {};
	auto set(std::shared_ptr<Girl> &girl)
	{
		girl_friend = girl;
	}
	~Boy()
	{
		std::cout << "boy destruct" << std::endl;
	}

	std::weak_ptr<Girl> girl_friend;
	std::shared_ptr<Girl> girl_friend2;
};

void test_ptr()
{
	auto p = std::make_shared<S>(0, "Ankh Morpork", 4.65);
	std::shared_ptr<S> p1{ new S(1, "Ankh Morpork", 4.65) };
	std::unique_ptr<S> p2 = std::make_unique<S>(2, "Ankh Morpork", 4.65);
	
	auto p3 = p;
	auto p4 = std::move(p2);
	int n = p.use_count();
	int n1 = p1.use_count();

	/*p4.reset(nullptr);
	p4.reset();*/
	p4.release();

	auto girl = std::make_shared<Girl>();
	auto boy = std::make_shared<Boy>();
	girl->set(boy);
	boy->set(girl);

	// ÎÞ·¨ÊÍ·Å
	boy->girl_friend2 = boy->girl_friend.lock();
}
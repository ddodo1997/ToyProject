#pragma once
//해당 클래스를 상속받으면 자식클래스는 싱글턴 클래스가 된다
template<typename T>
class Singleton 
{
protected:
	//객체가 단 하나여야 하기 때문에 생성자들을 프로텍티드에 놓는다
	Singleton() = default;
	virtual ~Singleton() = default;
	//복사생성자와 이동연산자를 삭제
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}
};

//싱글턴의 단점
//멀티 스레드 환경에서 생성할 때 여러개 생성될 위험이 있다.
//뮤텍스락을 잘못걸면 오작동의 위험이 있다.
#pragma once
//�ش� Ŭ������ ��ӹ����� �ڽ�Ŭ������ �̱��� Ŭ������ �ȴ�
template<typename T>
class Singleton 
{
protected:
	//��ü�� �� �ϳ����� �ϱ� ������ �����ڵ��� ������Ƽ�忡 ���´�
	Singleton() = default;
	virtual ~Singleton() = default;
	//��������ڿ� �̵������ڸ� ����
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}
};

//�̱����� ����
//��Ƽ ������ ȯ�濡�� ������ �� ������ ������ ������ �ִ�.
//���ؽ����� �߸��ɸ� ���۵��� ������ �ִ�.
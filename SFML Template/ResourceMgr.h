#pragma once
#include "stdafx.h"

template<typename T> 
class ResourceMgr : public Singleton<ResourceMgr<T>>
{
	friend Singleton<ResourceMgr<T>>;
protected:
	std::unordered_map<std::string, T*> resources;
	ResourceMgr() = default;
	~ResourceMgr()
	{
		UnloadAll();
	}
	ResourceMgr(const ResourceMgr&) = delete;
	ResourceMgr& operator=(const ResourceMgr&) = delete;
public:
	static T Empty;

	void UnloadAll()
	{
		for (const auto& pair : resources)
		{
			delete pair.second;
		}
		resources.clear();
	}

	bool Load(const std::string& id)
	{
		if (resources.find(id) != resources.end())
			return false;
		T* resource = new T();
		if (resource->loadFromFile(id))
		{
			resources.insert({ id, resource });
		}
		else {
			delete resource;
		}


		return true;
	}

	bool FLoad(const std::string& fname)
	{
		std::ifstream inFile(fname);

		if (!inFile.is_open()) {
			std::cerr << "파일을 열 수 없습니다." << std::endl;
			return 1;
		}

		std::string line;
		while (std::getline(inFile, line)) {

			if (resources.find(line) != resources.end())
				return false;
			T* resource = new T();
			if (resource->loadFromFile(line))
			{
				resources.insert({ line, resource });
			}
			else {
				delete resource;
			}
		}

		inFile.close();
		return true;
	}

	bool UnLoad(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end())
			return false;
		
		delete it->second;
		resources.erase(it);
		return true;
	}

	bool FUnLoad(const std::string& fname)
	{
		std::ifstream inFile(fname);

		if (!inFile.is_open()) {
			std::cerr << "파일을 열 수 없습니다." << std::endl;
			return 1;
		}

		std::string line;
		while (std::getline(inFile, line)) {
			auto it = resources.find(line);
			if (it == resources.end())
				return false;

			delete it->second;
			resources.erase(it);
		}

		inFile.close();
		return true;
	}
	T& Get(const std::string& id)
	{
		auto it = resources.find(id);

		if (it == resources.end())
		{
			return Empty;
		}
		return *(it->second);
	}
};

template<typename T>
T ResourceMgr<T>::Empty;
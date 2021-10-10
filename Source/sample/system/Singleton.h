#pragma once

class SingletonFinalizer
{
public:
	typedef void(*FinalizerFunc)();

	static void AddFinalizer(FinalizerFunc func);
	static void Finalize();
};

template <typename T>
class Singleton final
{
public:

	static T& GetInstance()
	{
		check(s_mpInstance);
		return *s_mpInstance;
	}
	static bool IsValid()
	{
		return s_mpInstance != nullptr;
	}
	static T& Create()
	{
		check(s_mpInstance == nullptr);
		s_mpInstance = new T();
		SingletonFinalizer::AddFinalizer(&Singleton<T>::Destroy);
		return *s_mpInstance;
	}

	static void Destroy()
	{
		delete s_mpInstance;
		s_mpInstance = nullptr;
	}

	static T* s_mpInstance;
};

template <typename T> T* Singleton<T>::s_mpInstance = nullptr;
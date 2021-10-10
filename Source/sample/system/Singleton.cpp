#include "Singleton.h"

namespace
{
	constexpr int32 kMaxFinalizersSize = 256;
	static SingletonFinalizer::FinalizerFunc gs_finalizers[kMaxFinalizersSize];
	static int32 gs_NumFinalizersSize = 0;
}


void SingletonFinalizer::AddFinalizer(FinalizerFunc func)
{
	check(gs_NumFinalizersSize < kMaxFinalizersSize);
	gs_finalizers[gs_NumFinalizersSize++] = func;
}

void SingletonFinalizer::Finalize()
{
	for (int32 i = gs_NumFinalizersSize - 1; i >= 0; --i)
	{
		(*gs_finalizers[i])();
	}
	gs_NumFinalizersSize = 0;
}
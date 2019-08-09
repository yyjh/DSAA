#pragma once
// 1.13
template<typename T>
void changeLength1D(T* &a, int oldLength, int newLength)
{
	if (newLength < 0)
	{
		return;
	}
	T* b = new T[newLength];
	int length = oldLength < newLength ? oldLength : newLength;
	for (int i = 0; i < length; ++i)
	{
		b[i] = a[i];
	}
	delete[] a;
	a = b;
}
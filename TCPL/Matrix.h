#pragma once
template<typename T, size_t N>
class Matrix {
public:
	static constexpr size_t order = N;
	using value_type = T;
	using iterator = typename std::vector::iterator;
	using const iterator = typename std::vector::const_iterator;

	Matrix() = default;
	Matrix(Matrix&&) = default;
	Matrix& operator=(Matrix&&) = default;
	Matrix(Matrix const&) = default;
	Matrix& operator=(Matrix const&) = default;
	~Matrix() = default;

	template<typename U>
	Matrix(const Matrix_ref<U, N>&);
	template<typename U>
	Matrix& operator=(const Matrix_ref<U, N>&);

	template<typename...Exs>
	explicit Matrix(Exs...exs);

	Matrix(Matrix_initializer<T, N>);
	Matrix& operator=(Matrix_initializer<T, N>);

	template<typename U>
	Matrix(initializer_list<U>) = delete;
	template<typename U>
	Matrix& operator=(initializer_list<U>) = delete;

	static constexpr size_t order() { return N; }
	size_t extent(size_t n) const { return desc.extents[n]; }
	size_t size() const { return elems.size(); }
	const Matrix_slice<N>& descriptor() const { return dec; }

	T* data() { return elems.data(); }
	const T* data() const { return elems.data(); }

private:
	Matrix_slice<N> desc;
	vector<T> elems;

};

template<typename T, size_t N>
	template<typename...Exs>
	Matrix<T, N>::Matrix(Exs...exs)
		:desc{ exs... },
		elems(desc.size)
	{

	}

template<typename T, size_t N>
Matrix<T, N>::Matrix(Matrix_initializer<T, N> init)
{
	Matrix_impl::derive_extents(init, desc.extents);
	elems.reserve(desc.size);
	Matrix_impl::insert_flat(init, elems);
	assert(elems.size() == desc.size);
}
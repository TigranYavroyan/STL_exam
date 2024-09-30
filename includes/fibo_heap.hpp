#ifndef FIBO_HEAP_HPP
#define FIBO_HEAP_HPP

#include <iostream>
#include <list>
#include <memory>
#include <algorithm>
#include <cmath>

template <typename T, typename Compare = std::less<T>>
class ft_priority_queue {
public:
	using value_type = T;
	using pointer = T*;
	using const_pointer = const T*;
	using reference = T&;
	using const_reference = const T&;
	using r_reference = T&&;
	using size_type = std::size_t;
private:
	struct Node {
		std::shared_ptr<Node> parent;
		std::shared_ptr<Node> prev;
		std::shared_ptr<Node> next;
		std::shared_ptr<Node> child;
		value_type key;
		int degree; // number of children

		Node(const_reference _key);
		Node();
	};

	std::list<std::shared_ptr<Node>> root_list;
	Compare cmp;
	std::shared_ptr<Node> prior;
	size_type n; // total nodes count
public:
	ft_priority_queue() : ft_priority_queue(Compare()) {}

    explicit ft_priority_queue(const Compare& compare);

    ft_priority_queue(const ft_priority_queue& other);

    ft_priority_queue(ft_priority_queue&& other);

    template<class InputIt>
    ft_priority_queue(InputIt first, InputIt last, const Compare& compare = Compare());

    template<class Alloc>
    explicit ft_priority_queue(const Alloc& alloc);

    template<class Alloc>
    ft_priority_queue(const Compare& compare, const Alloc& alloc);

    template<class Alloc>
    ft_priority_queue(const ft_priority_queue& other, const Alloc& alloc);

    template<class Alloc>
    ft_priority_queue(ft_priority_queue&& other, const Alloc& alloc);

    template<class InputIt, class Alloc>
    ft_priority_queue(InputIt first, InputIt last, const Alloc& alloc);

    template<class InputIt, class Alloc>
    ft_priority_queue(InputIt first, InputIt last, const Compare& compare, const Alloc& alloc);

	~ft_priority_queue() noexcept;

public:
	ft_priority_queue& operator= (const ft_priority_queue& other);
	ft_priority_queue& operator= (ft_priority_queue&& other);
	const_reference top() const;
	bool empty() const;
	size_type size() const;
	void push(const_reference key);
	void push(r_reference key);
	void pop();
	void swap(ft_priority_queue& other) noexcept;
	// void merge(ft_priority_queue& other);

	template <typename... Args>
	void emplace(Args&&... args);
private:
	std::shared_ptr<Node> _push_back(std::shared_ptr<Node>& tmp, std::shared_ptr<Node>& it);
	void _set_prior (std::shared_ptr<Node>& curr);
	void _heapify ();
	void _set_min ();
	void _add_child(std::shared_ptr<Node>& parent, std::shared_ptr<Node>& child);
	void _connect(std::vector<std::shared_ptr<Node>>& degrees, std::shared_ptr<Node>& it);
};

#include "../srcs/fibo_heap.cpp"

#endif // FIBO_HEAP_HPP
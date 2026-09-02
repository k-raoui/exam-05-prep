#pragma once
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"


class set {
    private:
        searchable_bag& bag;
    public:
    set() = delete;
    ~set();
    set(const set& o) = default;
    set(searchable_bag& bag);
    set& operator=(const set& o) = default;

    void insert (int);
	void insert (int *, int);
	void print() const;
	void clear();
    bool has(int) const;
    const searchable_bag& get_bag() const;
};
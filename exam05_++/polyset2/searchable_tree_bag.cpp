#include "searchable_tree_bag.hpp"


searchable_tree_bag::searchable_tree_bag(): tree_bag(){

}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& o): tree_bag(o){

};
searchable_tree_bag::~searchable_tree_bag(){

}
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& o){
    if(this == &o)
        return *this;
    tree_bag::operator=(o);
    return *this;
}
bool searchable_tree_bag::has(int n) const{
    node *curr = tree;
   
    while (curr)
    {
        if(curr->value == n) return true;
        if(curr->value < n){
            curr = curr->r;
        }
        else
            curr = curr->l;
    }
    return false;
}

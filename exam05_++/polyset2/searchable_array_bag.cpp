#include "searchable_array_bag.hpp"


searchable_array_bag::searchable_array_bag(): array_bag(){

}
searchable_array_bag::searchable_array_bag(const searchable_array_bag& o): array_bag(o){

};
searchable_array_bag::~searchable_array_bag(){

}
searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& o){
    if(this == &o)
        return *this;
    array_bag::operator=(o);
    return *this;
}
bool searchable_array_bag::has(int n) const{
    for(int i = 0; i < size; i++){
        if(data[i] == n)
            return true;
    }
    return false;
}

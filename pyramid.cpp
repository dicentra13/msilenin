#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
    Block() : w(0), h(0) {} // default constructor
    
    Block(size_t w_, size_t h_) : w(w_), h(h_) {} // another constructor
/*
    Block()
    {
        w = 0;
        h = 0;
    }
*/
    bool operator < (const Block& b2) const
    {
        return w < b2.w;
    }    
    bool operator > (const Block& b2) const
    {
        return w > b2.w;
    }
    
    size_t w;
    size_t h;
};

// let`s write an assortment of comparison functions
// just for example
// !!! there can be only 1 operator< and only 1 operator> in any struct/class
// but you can write any number of free comparison functions for any need

// analogous to Block::operator< but a free function
bool less_w(const Block& b1, const Block& b2)
{
    return b1.w < b2.w;
}

// analogous to Block::operator> but a free function
bool greater_w(const Block& b1, const Block& b2)
{
    return b1.w > b2.w;
}

// compare for < but by height
bool less_h(const Block& b1, const Block& b2)
{
    return b1.h < b2.h;
}

// compare for > but by height
bool greater_h(const Block& b1, const Block& b2)
{
    return b1.h > b2.h;
}

int main() {
    size_t n;
    cin >> n;
    
    vector<Block> blocks(n, Block());
    
    for (size_t i = 0; i < n; ++i) {
        cin >> blocks[i].w;
        cin >> blocks[i].h;
        
        /*
        
        // or:
        size_t w, h;
        cin >> w;
        cin >> h;
        blocks[i] = Block(w, h);
        
        */
    }
    
    // sort blocks by w in increasing order
    sort(blocks.begin(), blocks.end());   

    /* 
    // we could do it another way, explicitly giving sort a comparison function:
    sort(blocks.begin(), blocks.end(), less_w);
    
    // we could also sort by height in increasing order:
    sort(blocks.begin(), blocks.end(), less_h);
    
    // or sort blocks in decreasing order
    sort(blocks.begin(), blocks.end(), greater_w); // by width
    sort(blocks.begin(), blocks.end(), greater_h); // by height
    
    */
    
    size_t pyramidHeight = 0;
    
    // !!! all 3 variants of code below will work only when !blocks.empty()
    
    // way 1 - using iterator
    // more universal, will work in more cases when container type changes
    // will work for all container types where iterators have ++/-- AND +/- operations
    /*
    vector<Block>::const_iterator it = blocks.begin();
    size_t maxHeight = it->h; // same as (*it).h
    for (++it; it != blocks.end(); ++it) {
        if (it->w == (it - 1)->w) {
            maxHeight = max(maxHeight, it->h);
        } else {
            pyramidHeight += maxHeight;
            maxHeight = it->h;
        }
    }
    pyramidHeight += maxHeight;
    
 	*/
 	
    // way 1* - using 2 iterators
    // even more universal, will work in more cases when container type changes
    // will work for all container types where iterators have only ++ operation
    
    vector<Block>::const_iterator it = blocks.begin();
    vector<Block>::const_iterator prevIt = it;
    size_t maxHeight = prevIt->h;
    for (++it; it != blocks.end(); ++it, ++prevIt) {
        if (it->w == prevIt->w) {
            maxHeight = max(maxHeight, it->h);
        } else {
            pyramidHeight += maxHeight;
            maxHeight = it->h;
        }
    }
    pyramidHeight += maxHeight;
    
    
    // way 2 - using indices
    // less universal, will work in less cases when container type changes
    // will work only for containers which support indexing operation - []
    
    /*
    
    size_t i = 0;    
    size_t maxHeight = blocks[i].h;
    for (++i; i < n; ++i) {
        if (blocks[i].w == blocks[i - 1].w) {
            maxHeight = max(maxHeight, blocks[i].h);
        } else {
            pyramidHeight += maxHeight;
            maxHeight = blocks[i].h;
        }
    }
    pyramidHeight += maxHeight;
    
    */
    
    cout << pyramidHeight;
    return 0;
    
}

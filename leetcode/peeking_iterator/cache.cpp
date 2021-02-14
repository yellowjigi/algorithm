//
//  2021-02-14
//  LeetCode
//  284. Peeking Iterator
//  Accepted

#include <iostream>
#include <vector>

using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */
class Iterator {
   struct Data;
   Data* data;
public:
   Iterator(const vector<int>& nums);
   Iterator(const Iterator& iter);

   // Returns the next element in the iteration.
   int next();

   // Returns true if the iteration has more elements.
   bool hasNext() const;
};

class PeekingIterator : public Iterator {
    int cache;
    bool peeked;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        peeked = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (peeked) {
            return cache;
        }

        if (Iterator::hasNext()) {
            peeked = true;
            cache = Iterator::next();
            return cache;
        }

        return Iterator::next();
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (peeked) {
            peeked = false;
            return cache;
        }

        return Iterator::next();
    }

    bool hasNext() const {
        if (peeked) {
            return true;
        }

        return Iterator::hasNext();
    }
};

int main() {
    const vector<int> nums{ 1, 2, 3 };
    PeekingIterator pit(nums);

    while (pit.hasNext()) {
        cout << pit.next() << endl;
        cout << pit.peek() << endl;
    }

    return 0;
}
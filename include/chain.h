#ifndef chain_h
#define chain_h

class chain{
	private:
		struct link{
			int mItem;
			link* mNextLink;
			link* mPreviousLink;
			link(int,link*,link*);
		};
		int mSize;
		link* mChainHead;
		link* mChainTail;
	public:
		chain();
		~chain();
		int size();
		void push_front(int);
		void push_back(int);
		void pop(unsigned int);
		const int operator[](unsigned int);
		void clear();
		void insert(int value, unsigned int);
		const int front();
		const int back();

};


#endif
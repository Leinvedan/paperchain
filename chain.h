#ifndef chain_h
#define chain_h

#include <stdexcept>

class chain{
	private:
		struct link{
			int mItem;
			link* mNextlink;
			link(int,link*);
		};
		int mSize;
		link* mChainHead;
	public:
		chain();
		~chain();
		int size();
		void add(int);
		void remove(int);
		const int operator[](unsigned int);
};

chain::~chain(){
	chain::link* pLinkA = chain::mChainHead;
	chain::link* pLinkB = 0;
	while(pLinkA){
		pLinkB = pLinkA;
		pLinkA = pLinkA->mNextlink;
		delete pLinkB;
	}
}

chain::link::link(int item,chain::link* next){
	chain::link::mItem = item;
	chain::link::mNextlink = next;

}



chain::chain(){
	mSize = 0;
	mChainHead = 0;
}


int chain::size(){
	return(mSize);
}

void chain::add(int value){
	//Inserts at the first position
	if (chain::mChainHead == 0)
		chain::mChainHead = new link(value,0);
	else{
		chain::link* pLink = chain::mChainHead;
		chain::mChainHead = new link(value,pLink);
	}
	chain::mSize++;
}

void chain::remove(int index){
	if (index <0 || index > chain::mSize)throw std::runtime_error("Invalid index");
	else{
		chain::link* pLinkA = chain::mChainHead;
		if (index == 0){
			chain::mChainHead = chain::mChainHead->mNextlink;
			delete pLinkA;

		}
		else{
			chain::link* pLinkB = 0;
			while(index != 0 && pLinkA != 0){
				pLinkB = pLinkA;
				pLinkA = pLinkA->mNextlink;
				index--;
			}
			pLinkB->mNextlink = pLinkA->mNextlink;
			delete pLinkA;
		}
		chain::mSize--;
	}
}

const int chain::operator[](unsigned int index){
	if (index <0 || index > chain::mSize)throw std::runtime_error("Invalid index");
	else{
		chain::link* pLink = chain::mChainHead;
		while(index != 0 && pLink != 0){
			pLink = pLink->mNextlink;
			index--;
		}
		return(pLink->mItem);
	}
}



#endif
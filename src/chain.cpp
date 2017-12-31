
#include "chain.h"
#include <stdexcept>

/**
 * REMEMBER TO NULLIFY USED POINTERS, IF NEEDED, AFTER USING DELETE!
 */


chain::link::link(int item,chain::link* next,chain::link* prev){
	chain::link::mItem = item;
	chain::link::mNextLink = next;
	chain::link::mPreviousLink = prev;
}

chain::chain(){
	chain::mSize = 0;
	chain::mChainHead = 0;
	chain::mChainTail = 0;
}

chain::~chain(){
	chain::clear();
}

int chain::size(){
	return(mSize);
}

void chain::push_front(int value){
	if (chain::mChainHead){
		chain::mChainHead->mPreviousLink = new chain::link(value,chain::mChainHead,0);
		chain::mChainHead = chain::mChainHead->mPreviousLink;
	}
	else{
		chain::mChainHead = new chain::link(value,0,0);
		chain::mChainTail = mChainHead;
	}
	chain::mSize++;
}

void chain::push_back(int value){
	if (chain::mChainTail){
		chain::mChainTail->mNextLink = new chain::link(value,0,chain::mChainTail);
		chain::mChainTail = chain::mChainTail->mNextLink;
	}
	else{
		chain::mChainTail = new chain::link(value,0,0);
		chain::mChainHead = mChainTail;
	}
	chain::mSize++;
}

void chain::pop(unsigned int index){
	if (index > chain::mSize)throw std::runtime_error("Index out of bounds.");
	else{
		chain::link* pLinkA = chain::mChainHead;
		if (index == 0){
			chain::mChainHead = chain::mChainHead->mNextLink;
			delete pLinkA;
			if (chain::mChainHead){
				chain::mChainHead->mPreviousLink = 0;
			}
			else{
				//If the head is null, so does the tail
				chain::mChainTail = 0;
			}
		}
		else if (index == chain::size()-1){
			chain::mChainTail = chain::mChainTail->mPreviousLink;
			delete chain::mChainTail->mNextLink;
			mChainTail->mNextLink = 0;
		}

		else{
			chain::link* pLinkB = 0;
			while(index != 0 && pLinkA != 0){
				pLinkA = pLinkA->mNextLink;
				index--;
			}
			pLinkB = pLinkA->mPreviousLink;
			pLinkB->mNextLink = pLinkA->mNextLink;
			pLinkA->mNextLink->mPreviousLink = pLinkB;
			delete pLinkA;
		}
        
		chain::mSize--;
	}
}

const int chain::operator[](unsigned int index){
	//TODO: make this faster
	if (index >= chain::mSize)throw std::runtime_error("Index out of bounds.");
	else{
		chain::link* pLink = chain::mChainHead;
		while(index != 0 && pLink != 0){
			pLink = pLink->mNextLink;
			index--;
		}
		return(pLink->mItem);
	}
}

void chain::clear(){
	chain::link* pLinkA = chain::mChainHead;
	chain::link* pLinkB = 0;
	while(pLinkA){
		pLinkB = pLinkA;
		pLinkA = pLinkA->mNextLink;
		delete pLinkB;
	}
	chain::mSize = 0;
	chain::mChainHead = 0;
	chain::mChainTail = 0;
}

void chain::insert(int value, unsigned int index){
	if (index <0 || index > chain::mSize)throw std::runtime_error("Index out of bounds.");
	if (index == 0) chain::push_front(value);
	else if (index == chain::size()) chain::push_back(value);
	else{
		chain::link* pLinkA = chain::mChainHead;
		while(index > 0){
			pLinkA = pLinkA->mNextLink;
			index--;
		}
		chain::link* pLinkB = pLinkA->mPreviousLink;
		pLinkB->mNextLink = new chain::link(value,pLinkA,pLinkA->mPreviousLink);
		pLinkA->mPreviousLink = pLinkB->mNextLink;
		chain::mSize++;
	}
}

const int chain::front(){
	if(chain::mChainHead)
		return(chain::mChainHead->mItem);
	else
		return 0;

}

const int chain::back(){
	if (chain::mChainTail)
		return(chain::mChainTail->mItem);
	else
		return 0;
}
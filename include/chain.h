#ifndef chain_h
#define chain_h

#include <stdexcept>

template <class T>
class chain{
	private:
		struct link{
			T mItem;
			link* mNextLink;
			link* mPreviousLink;
			link(T,link*,link*);
		};
		int mSize;
		link* mChainHead;
		link* mChainTail;
	public:
		chain();
		~chain();
		int size();
		void push_front(T);
		void push_back(T);
		void pop(unsigned int);
		void pop_front();
		void pop_back();
		const T operator[](unsigned int);
		void clear();
		void insert(T, unsigned int);
		const T front();
		const T back();

};



/*--------------------------DECLARATIONS--------------------------
 * REMEMBER TO NULLIFY USED POINTERS, IF NEEDED, AFTER USING DELETE!
 */

template <class T>
chain<T>::link::link(T item,chain::link* next,chain::link* prev){
	chain::link::mItem = item;
	chain::link::mNextLink = next;
	chain::link::mPreviousLink = prev;
}

template <class T>
chain<T>::chain(){
	chain::mSize = 0;
	chain::mChainHead = 0;
	chain::mChainTail = 0;
}

template <class T>
chain<T>::~chain(){
	chain::clear();
}

template <class T>
int chain<T>::size(){
	return(mSize);
}

template <class T>
void chain<T>::push_front(T value){
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

template <class T>
void chain<T>::push_back(T value){
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

template <class T>
void chain<T>::pop(unsigned int index){
	if (index > chain::mSize)throw std::runtime_error("Index out of bounds.");
	else{
		chain::link* pLinkA = chain::mChainHead;
		if (index == 0) pop_front();
		else if (index == chain::size()-1) pop_back();
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

template <class T>
void chain<T>::pop_front(){
	if (chain::mChainHead){
		chain::link* pLinkA = chain::mChainHead;
		chain::mChainHead = chain::mChainHead->mNextLink;
		delete pLinkA;
		if (chain::mChainHead){
			chain::mChainHead->mPreviousLink = 0;
		}
		//If it's null, you deleted the last link, so the tail is null now
		else{
			chain::mChainTail = 0;
		}
		chain::mSize--;
	}
	else{
		throw std::runtime_error("This chain has no front.");
	}
}

template <class T>
void chain<T>::pop_back(){
	if (chain::mChainTail){
		chain::link* pLinkA = chain::mChainTail;
		chain::mChainTail = chain::mChainTail->mPreviousLink;
		delete pLinkA;
		if (chain::mChainTail){
			chain::mChainTail->mNextLink = 0;
		}
		else{
			chain::mChainHead = 0;
		}
		chain::mSize--;

	}
	else{
		throw std::runtime_error("This chain has no back.");
	}
	
}

template <class T>
const T chain<T>::operator[](unsigned int index){
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

template <class T>
void chain<T>::clear(){
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

template <class T>
void chain<T>::insert(T value, unsigned int index){
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

template <class T>
const T chain<T>::front(){
	if(chain::mChainHead)
		return(chain::mChainHead->mItem);
	else
		return 0;

}

template <class T>
const T chain<T>::back(){
	if (chain::mChainTail)
		return(chain::mChainTail->mItem);
	else
		return 0;
}


#endif
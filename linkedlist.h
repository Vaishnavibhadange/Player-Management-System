
#include"node.cpp"

template<class T>
class LinkedList
{

	Node<T>* start;
	
	public:
		
	LinkedList();
		
		void storeData(T, int);
		void searchByJerseyNumber(int );
		void searchByPlayerName(const char*);
		void updateDetails(int);
		void sortData();
		void deletePlayer(int);
		void displayPlayer();
		~LinkedList();				
};
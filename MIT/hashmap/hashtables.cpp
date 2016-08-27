/**
 *
 * Implementation of Hash tables
 *
 * @author 	Eshan Shafeeq
 * @version	v0.1
 * @date 	25 April 2016
 *
 **/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

#define DEBUG

/**
 *
 * Hash Chain
 *
 * In case the hash table has a collision we will solve this
 * with a link list like structure which i will call it hash chain.
 *
 *
 **/
class HashChain {

	private:
		int key;
		int data;
		HashChain * next;

	public:

		HashChain( int key, int data ){
			this->key = key;
			this->data = data;
			this->next = nullptr;
		}

		int get_key(){
			return this->key;
		}
		int get_data(){
			return this->data;
		}
		void set_data( int data ){
			this->data = data;
		}
		HashChain * get_next(){
			return this->next;
		}
		void set_next( HashChain * next ){
			this->next = next;
		}

};

/**
 *
 * Hash Map
 *
 * This class will contain an array table which will store all our data
 * after hashing the key, and use the hash as an index.
 *
 **/
class HashMap{
	private:
		size_t table_size;
		size_t count;
		long int num_a;
		long int num_b;
		long int prime;
		HashChain **table;


/**
 * Init Hash Function
 *
 * Cusom hash function requires 2 random integers and a
 * prime number. Got this formula from the MIT Open courseware
 * 6.006 algorithms class.
 *
 **/
		void init_hash_function(){

			std::srand( std::time( 0 ) );
			this->prime = get_prime( table_size );
			this->num_a = std::rand() % ( prime );
			this->num_b = std::rand() % ( prime );

#ifdef DEBUG
			std::cout << "prime number : " << this->prime << std::endl;
			std::cout << "num a : " << this->num_a << std::endl;
			std::cout << "num b : " << this->num_b << std::endl;
#endif

		}

/**
 *
 * Get Prime
 *
 * A prime number generation function. Works pretty well for numbers not too huge.
 *
 **/
		long int get_prime( long int n ){

			long int prime;
			long int num=2, c, counter;
			bool status=true;

			for( counter=2; counter<=n; ){
				for( c=2; c<=(int)sqrt(num); c++ ){
					if( num%c == 0 ){
						status = false;
						break;
					}
				}
				if( status ){
					prime = num;
					counter++;
				}
				status = true;
				num++;
			}
		}

/**
 *
 * Custom Hash Function
 *
 * Uses the formula:
 * h(key) = [ ( num_a x key + num_b ) % prime ] % table_size
 *
 * this formula puts the collision probability at 1 / table_size
 *
 **/
		int hash_f( int key ){

			return ( ( this->num_a * key + num_b ) % this->prime ) % this->table_size;
		}
/**
 *
 * Remove chain
 *
 * Removes the whole chain in a given index of the table
 * Recursively.
 *
 **/
		void remove_chain( HashChain * hc ){
			if( hc == nullptr )
				return;
			remove_chain( hc->get_next() );
			delete hc;
		}

	public:

/**
 *
 * Hash Map
 *
 * Default Constructor. Sets the table size to 128.
 *
 **/
		HashMap(){
			this->table_size = 128;
			this->count = 0;
			init_hash_function();
			table = new HashChain*[table_size];
			for( size_t i=0; i<table_size; i++ )
				table[i] = nullptr;
		}
/**
 *
 * Hash Map
 *
 * Overloaded Constructor. Use this constructor to have a different table size
 * Other than 128. It can help save memory.
 *
 **/
		HashMap( size_t size ){
			this->table_size = size;
			this->count = 0;
			init_hash_function();
			table = new HashChain*[table_size];
			for( size_t i=0; i<table_size; i++ )
				table[i] = nullptr;
		}


/**
 *
 * Get
 *
 * This function will retrieve the element based on the key provided.
 *
 **/
		int get( int key ){

			int h = hash_f( key );
#ifdef DEBUG
			std::cout << "Hashing key : " << key << " hash value : " << h << std::endl;
#endif
			if( this->table[h] == nullptr ){

				return -1;

			}else{

				HashChain * iter = table[h];
				while( iter != nullptr && iter->get_key() != key ){

					iter = iter->get_next();

				}

				if( iter == nullptr ){

					return -1;

				}else{

					return iter->get_data();

				}
			}

		}

/**
 *
 * Insert
 *
 * This function will insert the data into the hash table
 * after hashing the key and using it as the index for the table.
 *
 **/
		void insert( int key, int data ){

			int h = hash_f( key );
			if( table[h] == nullptr ){

				table[h] = new HashChain( key, data );
				this->count++;
#ifdef DEBUG
				std::cout << "current number of elements : " << this->count << std::endl;
#endif

			}else{

				HashChain * iter = table[h];
				while( iter->get_next() != nullptr ){

					iter = iter->get_next();
					if( iter->get_key() == key ){
						iter->set_data( data );
						return;

					}

				}

				iter->set_next( new HashChain( key, data ));
			}
		}
/**
 *
 * Remove
 *
 * This function will remove an element based on the key. It will also fix the
 * link list linking when removing an element from the middle.
 *
 **/
		void remove( int key ){

			int h = hash_f( key );
			if( table[h] != nullptr ){

				HashChain * pre = nullptr;
				HashChain * iter = table[h];

				while( iter->get_next() != nullptr && iter->get_key() != key ){
					pre = iter;
					iter = iter->get_next();
				}
				if( iter->get_key() == key ){
					if( pre == nullptr ){
						table[h] = iter->get_next();
						delete iter;
					}else{
						pre->set_next( iter->get_next() );
						delete iter;
					}
				}
			}

		}

/**
 *
 * Destructor
 *
 * This function will completely destroy the hash table row by row.
 *
 **/
		~HashMap(){
#ifdef DEBUG
			std::cout << "Destroying Hash Map" << std::endl;
#endif
			for( size_t i=0; i<this->table_size; i++ ){
				if( table[i] != nullptr ){
					remove_chain( table[i] );
				}
			}
			delete[] table;

		}
};

/**
 *
 * Main
 *
 * Testing the hash table by inserting some numbers and
 * retrieving them.
 *
 **/
int main( void ){

	int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	HashMap hm(10);
	for( size_t i=0; i<11; i++ ){
		hm.insert( i, i );
	}
	hm.remove(7);
	for( size_t i=0; i<11; i++ ){
		std::cout << hm.get( i ) << std::endl;
	}



}



#ifndef _HASH_MAP_HPP_
#define _HASH_MAP_HPP_

#include <vector>
#include <list>
#include <string>

template <
	class K,
	class V,
	class Hash=std::hash<K>
>
class HashMap
{
private:
	template <typename K, typename V>
	struct Bucket
	{		
		typedef std::list< std::pair<K,V> > ItemList;
		ItemList items;
	};

	const static size_t DEFAULT_N_BUCKETS = 1028;

public:
	explicit HashMap(const size_t bucketN = DEFAULT_N_BUCKETS)
	    :_bucketN(bucketN),_size(0) 
	{		
		_buckets.resize(_bucketN);
	}
	
	bool insert(const std::pair<K,V>& item)
	{		
		Bucket<K,V>& bucket = _buckets[calcBucketIndex(item.first)];
		for (Bucket<K,V>::ItemList::iterator it = bucket.items.begin();
			 it != bucket.items.end();
			 ++it)			
		{		
			if (it->first == item.first)
			{
				return false; 
			}						
		}

		bucket.items.push_back(item);
		_size++;
		return true;
	}

	bool erase(const K& key)
	{
		Bucket<K,V>& bucket = _buckets[calcBucketIndex(key)];
		for (Bucket<K,V>::ItemList::iterator it = bucket.items.begin();
			 it != bucket.items.end();
			 ++it)			
		{		
			if (it->first == key)			
			{
				bucket.items.erase(it);
				_size--;
				return true;
			}						
		}

		return false;
	}

	std::pair<bool,V> find(const K& key)
	{
		Bucket<K,V>& bucket = _buckets[calcBucketIndex(key)];
		for (Bucket<K,V>::ItemList::iterator it = bucket.items.begin();
			 it != bucket.items.end();
			 ++it)			
		{		
			if (it->first == key)			
			{
				return std::make_pair(true, it->second);
			}						
		}

		return std::make_pair(false, V());
	}

	size_t size() const 
	{
		return _size; 
	}

private:
	size_t calcBucketIndex(const K& key)
	{	
		return (Hash()(key) % _bucketN);
	} 

private:
	typedef std::vector< Bucket<K,V> > BucketMap;
	BucketMap _buckets;
	size_t _bucketN;
	size_t _size;
};

namespace test
{
	void go()
	{
		HashMap<std::string, std::string> testMap;
		testMap.insert(std::make_pair("key1", "val1"));
		testMap.erase("key1");	
		std::cout << testMap.size();
	}
}

#endif // _HASH_MAP_HPP_
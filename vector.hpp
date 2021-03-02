#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <stdlib.h>
#include <conio.h>

struct Exception {
	static const char* out_of_range;
};

const char* Exception::out_of_range = "[Error]: Out of range";

template < typename T >//estructura llamada "vector" con argumentos no especificados
struct vector {
	typedef T myType;//define un tipo y le asigna nombre
public:
	vector() {
		m_vector = (myType*) malloc ( sizeof( myType ) );//crea un vector del tamaño del tipo MyType
		m_position = 0;//variable de tipo MyType inicializada en 0
	}
	template < typename ... Ts >
	vector(myType head, Ts ... tail) {
		m_position = 0;
		m_vector = (myType*) malloc( (sizeof ...( tail ) + 1) * sizeof( myType ) );
		this->push_back(head);
		(this->push_back(tail),...);
	}
	~vector() {
		free(m_vector);
		m_vector = NULL;
	}
	void push_back( myType value ) {
		if( m_position == 0 ) {
			m_vector[ m_position ] = value;
		} else {
			m_vector = (myType*) realloc(m_vector, (m_position+1) * sizeof(myType));
			m_vector[ m_position ] = value;
		}
		m_position++;
	}

	void pop_back() {
		--m_position;
		m_vector = (myType*)realloc( m_vector, m_position * sizeof (myType) );
	}

	myType at( size_t pos ) {
		try {
			if (pos < m_position)
				return m_vector[ pos ];
			else throw Exception::out_of_range;
		} catch (const char* e) {
			printf("%s", e);
			return (myType){};
		}
	}

	inline myType& front() { return *m_vector; }
	inline myType& back() { return *(m_vector + size() -1); }
	inline myType* data() { return m_vector; }

	inline myType* begin() { return m_vector; }
	inline myType* end() { return (m_vector + size()); }

	inline myType operator[](size_t pos) { return m_vector[ pos ]; }
	inline size_t size() { return m_position; }
	inline bool empty () { return (begin() == end()? true:false); }

private:
	myType* m_vector;
	size_t m_position;
};

template < typename T >
std::ostream& operator<<(std::ostream& os, vector<T>& v) {
	os << "[";
	for(int i = 0; i < v.size() - 1; ++i)
		os << v[i] << ", ";
	os << v[ v.size() - 1 ] <<"]";
	return os;
}
#endif

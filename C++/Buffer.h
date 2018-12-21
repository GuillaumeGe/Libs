//move to a super common file
#ifndef uint8_t
	#define uint8_t 	unsigned char
#endif
#ifndef uint16_t
	#define uint16_t 	unsigned short
#endif
#ifndef uint32_t
	#define uint32_t 	unsigned long
#endif

template <class GenericType>
class Buffer
{
	private:
		uint16_t 		_size;
	 	GenericType*	_data;
	public:
		Buffer(const GenericType* data = nullptr,const uint16_t size = 0);
/**
 * copy constructor
 *
 * @param other: buffer copy reference
 */
		Buffer(const Buffer<GenericType> &other);
/**
 * destructor
 *
 */
		~Buffer();
/**
 * Resize the Buffer
 *
 * @param newSize: size of new buffer
 * @param saveData: keep current data or erase all
 */
		void resize(uint16_t newSize, bool saveData = true);

/**
 * Returns size of the Buffer
 *
 */
		uint16_t getSize();

/**
* set Buffer's raw data
*
* Overwrites previous data and adapts on the new size given
*
* @param data: new data pointer
* @param size: length of new data array
*/
		void setData(GenericType* newData, const uint16_t newSize);
/**
* returns Buffer's raw data
*
*/
	 	GenericType * getData();
/**
* appends a single value to the Buffer's raw data
*
* @param value: value to append
*/
		void append(GenericType value);

/**
* appends data array to the Buffer's raw data
*
* @param extraData: data pointer
* @param extraSize : number of elements to adds
*/
		void append(GenericType *extraData, uint16_t extraSize);
/**
* appends another Buffer to the Buffer (Buffer + Buffer)
*
* @param extraBuffer: Buffer to append
*/
		void append(Buffer<GenericType> &extraBuffer);
/**
* returns the value at the specified index
*
* @param index: data array index
*/
	 	GenericType operator[](const uint16_t index);
/**
* returns a new resulted Buffer by addition of raw's data concatened
*
* @param other: Buffer to add
*/
	 	Buffer operator+(const Buffer<GenericType> &other);

	 	void crop(const uint16_t index);

	 	void fill(const GenericType value);

	 	void fill(const GenericType value, const uint16_t size);

	 	void reverse();



};

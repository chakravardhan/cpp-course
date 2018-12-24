


class SDCard
{
public:
	SDCard(int cap);
	virtual ~SDCard();

	int getCapacity() const;

private:
	const int capacity;
};


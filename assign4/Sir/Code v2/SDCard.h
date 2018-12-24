


class SDCard
{
public:
	SDCard(int cap);
	virtual ~SDCard();

	int getCapacity() const;

	void print(ostream& os) const;

private:
	const int capacity;
};


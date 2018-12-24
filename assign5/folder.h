class folder
{
	private:
		vector <file *> files;
	public:
		string name;
		int getNoFiles()
		{
			return files.size();
		}
		file * getFile(int i)
		{
			return files[i];
		}
		void pushFile(file * f)
		{
			files.push_back(f);
		}
}
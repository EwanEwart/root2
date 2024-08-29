auto string_handling
{
	[](string const & s1, string const & s2)
	{
		auto s3{s1+"/"+s2};
		cout << s3 << endl;
	}
};

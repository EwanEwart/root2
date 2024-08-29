// be aware of the last element
//
void next_iterator() // sort of main(); named filename name
{

   // list lst {7,23,47,13,19};
   list lst {"Kate","Mater","Ann","Schnickllisl"};

   for(auto it=lst.begin(); it!=lst.end();++it)
   {
      cout << *it;
      if(next(it) != lst.end()) // if next iterator doesn't point to last element
         cout<<" / ";   // append " / "
	}
   cout << endl;
}


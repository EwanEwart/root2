// what it does for page length 15, jobs 80:
// cout<<80/15<<" "<<80%15<<endl;
auto no_of_pages_and_jobs
{
   [](int no_of_jobs, int jobs_per_page=15)
   {
      auto pages{no_of_jobs/jobs_per_page};
      auto add_jobs{no_of_jobs%jobs_per_page};
      cout << pages << (pages > 1?" pages ":" page ");
      if(add_jobs>0)
      {
         cout<<" + "<<add_jobs <<" job"<< (add_jobs==1?"":"s") <<endl;}
      else
      {
         cout<<endl;
      }
   }
};

void maths()
{
   cout<<"no_of_pages_and_jobs(int no_of_jobs, int jobs_per_page=15)"<<endl;
}


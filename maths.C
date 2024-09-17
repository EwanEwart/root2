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
auto fahrenheit_to_centigrade(double f) { return (f-32)*5/9; }
auto centigrade_to_fahrenheit(double c) { return c*9/5+32; }

void maths()
{
   cout<<"no_of_pages_and_jobs(int no_of_jobs, int jobs_per_page=15)"<<endl;
   cout<<"fahrenheit_to_centigrade(double fahrenheit)"<<endl;
   cout<<"centigrade_to_fahrenheit(double centigrade)"<<endl;
}

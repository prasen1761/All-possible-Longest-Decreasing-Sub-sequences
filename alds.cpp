#include<iostream>
#include<vector>
using namespace std;

std::vector<int> array;

std::vector<int> counter;

int max(int a, int b)
{
  return (a>b)?a:b;
}

std::vector<std::vector<int>> alis_array;

void alds()
{
  alis_array.push_back(std::vector<int>());
  alis_array[0].push_back(array[0]);
  int count=0;
  int c=0;
  int findex=0;
  for(int i=1;i<array.size();i++)
    {
      c=0;
      for(int j=0;j<alis_array.size();j++)
	{
	  count=0;
	  for(int k=0;k<alis_array[j].size();k++)
	    {
	      if(alis_array[j][k]>array[i])count++;
	    }
	  if(count==alis_array[j].size())
	    {
	      c++;
	      findex++;
	      alis_array.push_back(std::vector<int>());
	      for(int k=0;k<alis_array[j].size();k++)
		{
		  alis_array[findex].push_back(alis_array[j][k]);
		}
	      alis_array[findex].push_back(array[i]);
	    }
	}
     
     findex++;
     alis_array.push_back(std::vector<int>());
     alis_array[findex].push_back(array[i]);	
    }

  for(int i=0;i<alis_array.size();i++)
    {
      for(int j=0;j<alis_array[i].size();j++)
	cout<<alis_array[i][j]<<" ";
      cout<<endl;
    }
}

int lds()
{
  int ml_index=0,ml=0;
  int count=0;
  std::vector<std::vector<int>> lds_array(array.size());
  lds_array[0].push_back(array[0]);
  for(int i=1;i<array.size();i++)
    {
      for(int j=0;j<i;j++)
	{
	  for(int k=0;k<lds_array[j].size();k++)
	    {
	      if(lds_array[j][k]>array[i])count++;
	    }
	  if(count==lds_array[j].size())
	    {
	      counter.push_back(j);
	    }
	  count=0;
	}
      if(counter.size()>0)
	{
	  for(int m=0;m<counter.size();m++)
	    {
	      if(lds_array[counter[m]].size()>ml)
		{
		  ml_index=counter[m];
		  ml=lds_array[counter[m]].size();
		}
	    }
	  for(int h=0;h<lds_array[ml_index].size();h++)
	    lds_array[i].push_back(lds_array[ml_index][h]);
	  ml_index=0;
	  ml=0;
	}
      lds_array[i].push_back(array[i]);
      counter.clear();
    }
  int max_len=0;
  int max_index=0;
  for(int i=0;i<lds_array.size();i++)
    {
      if(lds_array[i].size()>max_len)
	{
	  max_len=lds_array[i].size();
	  max_index=i;
	}
      for(int j=0;j<lds_array[i].size();j++)
	cout<<lds_array[i][j]<<" ";
      cout<<endl;
    }
  return max_len;
}

int main(int argc, char *argv[])
{
  cout<<"Enter the number of elements in the array"<<endl;
  int n,val;
  cin>>n;
  cout<<"\nEnter the elements in the array\n";
  for(int i=0;i<n;i++)
    {
      cin>>val;
      array.push_back(val);
    }
  cout<<endl;
  cout<<"\nLDS length is "<<lds()<<endl;
  cout<<"\nAll possible LDS sequences are\n";
  alds();
  return 0;
}

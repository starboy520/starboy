// There is a linked list of numbers of length N.
// N is very large and you don’t know N. 
// You have to write a function that will return k
// random numbers from the list.
// Numbers should be completely random.

/*
First record samples until you have filled the reservoir(K samples).
Once you have the first K samples the probability of each sample being in the final result was K/K or 100%.

Now when the K+i sample appears the probability of the new sample appearing in one _PARTICULAR_ output slot becomes 1/K+i. Since there are K potential output slots there is K/(K+i) chance of it being in the output and i/(K+i) chance that it wont be.

So choosing whether or not to add the new sample is easy we toss the dice. If we decide that the new sample is in the output then one of the existing items needs to be removed. Since all the items that where added to output and have equal chance of being present they also have equal chance of being removed. Hence we can simply choose to remove one of the existing samples with a 1/K probability. 

This make sense logically but how do we prove it. 
Assuming the prior stage worked correctly each element in the output should have K/(K+i-1) chance of being present.
There is i/(K+i) chance that prior output will be unchanged this round. Hence each element has Ki/(K+i)(K+i-1) chance of being output if the unchanging choice is made for this stage.
There is K/(K+i) chance that this something in the output will change
And for each element there is (K-1)/K chance it will not be replaced thus a total of (K-1)/K * K/(K+i) * K/(K+i-1) chance it will not be removed.
So conversely there is a 1/K * K/(K+i) * K/(K+i-1) chance that it will be replaced.

Hence the net chance of the existing elements making it to the next round is the sum of the chance that nothing changed with the chance that it was not the one that changed.
= Ki/(K+i)(K+i-1) + (K-1)K/(K+i-1)(K+i)
=> (Ki + (K-1)K)/(K+i-1)(K+i)
=> K(i+K-1)/(K+i-1)(K+i)
=> K/(K+i)
Q.E.D.

And of course the chance of the new element making to the output was K/(K+i). As you can see it has nicely balanced out for the possible output items for this stage. 

BUT HERE IS THE CATCH.. Note that the mathematics/algorithm considered only the choice between output and non-output state of the samples. IT MADE NO STATEMENT AS TO THE OUTPUTS ORDERING. Hence the output samples need to be randomly shuffled in the final stages of the algorithm or there will be an issue with the ordering of the samples.
*/


#include <iostream>
using namespace std;
 
int reservoirSample(int sample, int* samples, int size, int count)
{
  if(count < size)
    samples[count] = sample;
  else
    if((rand()%count) < size)
      samples[rand()%size] = sample;
   
  return ++count;
}
 
#define SIZE 10
// #define STREAM_AVERAGE 300
#define STREAM_AVERAGE 10
int main()
{
  int count = 0;
  int samples[SIZE];
  int sample;
  int i = 0;
 
  srand(time(NULL));
 
  cout << "Sample Stream: " << endl;
  while( (count < SIZE) ||  (rand()%STREAM_AVERAGE > 0)) {
      sample = rand()%1000;
      cout << sample << " ";
 
      count = reservoirSample(sample, samples, SIZE, count);
  }

  cout << endl;
  cout << "Total samples: " << count << endl;
 
  cout << "Output samples: " << endl;
  for(i = 0;i < SIZE;i++)
    cout << samples[i] << " ";
  cout << endl;
}

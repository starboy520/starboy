// In a party of N people, only one person is known to everyone.
// Such a person may be present in the party, if yes,
// (s)he doesn’t know anyone in the party.
// We can only ask questions like “does A know B? “.
// Find the stranger (celebrity) in minimum number of questions.
//

int CelebrityUsingStack(int size) {
   // Handle trivial case of size = 2
   list<int> stack; // Careful about naming
   int i;
   int C; // Celebrity
 
   i = 0;
   while( i < size )
   {
      stack.push_back(i);
      i = i + 1;
   }
 
   int A = stack.back();
   stack.pop_back();
 
   int B = stack.back();
   stack.pop_back();
 
   while( stack.size() != 1 )
   {
      if( HaveAcquiantance(A, B) )
      {
         A = stack.back();
         stack.pop_back();
      }
      else
      {
         B = stack.back();
         stack.pop_back();
      }
   }
 
   // Potential candidate?
   C = stack.back();
   stack.pop_back();
 
   // Last candidate was not examined, it leads one excess comparison (optimise)
   if( HaveAcquiantance(C, B) )
      C = B;
 
   if( HaveAcquiantance(C, A) )
      C = A;
 
   // I know these are redundant,
   // we can simply check i against C
   i = 0;
   while( i < size )
   {
      if( C != i )
      stack.push_back(i);
      i = i + 1;
   }
 
   while( !stack.empty() )
   {
      i = stack.back();
      stack.pop_back();
 
      // C must not know i
      if( HaveAcquiantance(C, i) )
         return -1;
 
      // i must know C
      if( !HaveAcquiantance(i, C) )
         return -1;
   }
 
   return C;
}
